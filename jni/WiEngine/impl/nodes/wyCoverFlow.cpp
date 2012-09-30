/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "wyLog.h"
#include "wyGlobal.h"
#include "wyTypes.h"
#include "wyCoverFlow.h"
#include "wyCoverFlowAction.h"

wyCover::wyCover(wyTexture2D* tex) :
		m_posX(0),
		m_posY(0),
		m_rotateDegreeY(0),
		m_scale(1.0f),
		m_tex(tex),
		m_next(NULL),
		m_prev(NULL),
		m_autoUpdate(true) {
    wyObjectRetain(m_tex);
}

wyCover::~wyCover() {
    wyObjectRelease(m_tex);
}

wyCover* wyCover::make(wyTexture2D* tex) {
	wyCover* c = WYNEW wyCover(tex);
	return (wyCover*)c->autoRelease();
}

void wyCover::setTexture(wyTexture2D* tex) {
	wyObjectRetain(tex);
	wyObjectRelease(m_tex);
	m_tex = tex;
}

void wyCover::transform() {
    glTranslatef(m_posX, m_posY, m_posZ);
    glRotatef(m_rotateDegreeY, 0.0f, 1.0f, 0.0f);
    glScalef(m_scale, m_scale, 1.0f);
}

wyVertex3D wyCover::getPosition() {
    wyVertex3D rt = {m_posX, m_posY, m_posZ};
    return rt;
}

wyCoverFlow::wyCoverFlow() :
		m_uiVbo(-1),
		m_uiAllIndexVbo(-1),
		m_coverListHead(NULL),
		m_coverListTail(NULL),
		m_frontCover(NULL),
		m_frontCenterX(0.0f),
		m_frontCenterY(0.0f),
		m_frontWidth(0.0f),
		m_frontHeight(0.0f),
		m_depthZ(0.0f),
		m_countLeftVisible(4),
		m_countRightVisible(4),
		m_leftCoverCenterDelta(0.0f),
		m_rightCoverCenterDelta(0.0f),
		m_firstLeftCoverCenterOffset(0.0f),
		m_firstRightCoverCenterOffset(0.0f),		
		m_rotateDegreeLeft(70.0f),
		m_rotateDegreeRight(-70.0f),    
		m_bMirrorEnabled(true),
		m_fBorderPercent(0.1),
		m_bIsShowing(false),
		m_bVerticeInited(false),
		m_fVBOSupported(false),
		m_fVersionGot(false),
		m_isMatrixValid(false), 
		m_isMartixQuerySupported(true),
		m_heightFromMirror(0),
		m_brightLevelOfMirror(0.5f) {
	memset(m_projectionMatrix, 0, sizeof(m_projectionMatrix));
    memset(m_modelViewMatrix, 0, sizeof(m_modelViewMatrix));
}

wyCoverFlow::~wyCoverFlow() {
    wyCover* temp = m_coverListHead;
    while(temp) {
        wyCover* temp2 = temp->getNext();
        wyObjectRelease(temp);
        temp = temp2;
    }
}

wyCoverFlow* wyCoverFlow::make() {
	wyCoverFlow* n = WYNEW wyCoverFlow();
	return (wyCoverFlow*)n->autoRelease();
}

void wyCoverFlow::addCover(wyCover* cover) {
    if(!cover)
        return;

    wyObjectRetain(cover);

    if(m_coverListHead) {
        m_coverListTail->setNext(cover);
        cover->setPrev(m_coverListTail);
        m_coverListTail = cover;
    } else {
        m_coverListHead = m_coverListTail = cover;
    }
}

void wyCoverFlow::removeCover(wyCover* cover) {
    if(!cover)
        return;

    wyCover* temp = m_coverListHead;
    while(temp) {
        if(temp == cover) {
            temp->getPrev()->setNext(temp->getNext());
            temp->getNext()->setPrev(temp->getPrev());
            wyObjectRelease(cover);
            break;
        }
        temp = temp->getNext();
    }
}

void wyCoverFlow::insertCoverBefore(wyCover* cover, wyCover* after) {
    if(!cover)
        return;

    wyCover* temp = m_coverListHead;
    bool bFound = false;
    while(temp) {
        if(temp == after) {
            bFound = true;
            break;
        }
        temp = temp->getNext();
    }

    if(!bFound)
        return;

    wyObjectRetain(cover);
    wyCover* prev = after->getPrev();
    if(prev) {
        prev->setNext(cover);
        cover->setPrev(prev);
    } else {
        m_coverListHead = cover;

    }
    cover->setNext(after);
    after->setPrev(cover);
}

int wyCoverFlow::getIndex(wyCover* cover) {
    if(!cover)
        return -1;
    
    wyCover* temp = m_coverListHead;
    int index = -1;
    int i = 0;
    while(temp) {
        if(temp == cover) {
            index = i;
            break;
        }
        temp = temp->getNext();
        i++;
    }

    return index;
}

wyCover* wyCoverFlow::getCoverAt(int index) {
    if(index < 0)
        return NULL;

    wyCover* temp = m_coverListHead;

    while(temp && index-- > 0) {
        temp = temp->getNext();
    }

    return temp;
}

void wyCoverFlow::setFrontCoverSize(float width, float height, bool updateOthers) {
    m_frontWidth = width;
    m_frontHeight = height;

    if(updateOthers) {
        m_firstLeftCoverCenterOffset = m_frontWidth * 1.2f;
        m_firstRightCoverCenterOffset = m_frontWidth * 1.2f;
        m_leftCoverCenterDelta = m_frontWidth / 2;
        m_rightCoverCenterDelta = m_frontWidth / 2 ;
        m_depthZ = -m_frontWidth * 1.2f;
    }
    
    m_bVerticeInited = false;
}

void wyCoverFlow::stepLeftUpdate(float t) {
    wyCover* curFrontCover = getFrontCover();
    wyCover* nextFrontCover = curFrontCover->getNext();

    if(!nextFrontCover)
        return;
    
    int indexFront = getIndex(curFrontCover);

    float curFrontStep = m_firstLeftCoverCenterOffset * t;
    float nextFrontCoverStep = m_firstRightCoverCenterOffset * t;
    float stepLeftCovers = 0.0f;
    float stepRightCovers = 0.0f;
    float newX = 0.0f;
    float originalPosX = 0.0f;

    //update left covers
    if(curFrontStep > m_firstLeftCoverCenterOffset - m_leftCoverCenterDelta) {
        stepLeftCovers = curFrontStep - (m_firstLeftCoverCenterOffset - m_leftCoverCenterDelta);
    }
    wyCover* temp = getMostLeftToShow();

    while(temp) {
        int indexCur = getIndex(temp);
        int indexRelativeFront = indexCur - indexFront;

        originalPosX = -m_firstLeftCoverCenterOffset + (indexRelativeFront + 1) * m_leftCoverCenterDelta;
        newX = originalPosX - stepLeftCovers;

        if(temp->getAutoUpdate()) {
            temp->setPosition(newX, 0.0f, m_depthZ);
            temp->setRotateY(m_rotateDegreeLeft);
        }

        temp = temp->getNext();
        if(temp == curFrontCover)
            break;
    }

    //update current frontCover
    newX = 0 - curFrontStep;
    if(curFrontCover->getAutoUpdate()) {
        curFrontCover->setPosition(newX, 0.0f, fabs(newX) / m_firstLeftCoverCenterOffset * m_depthZ);
        curFrontCover->setRotateY(m_rotateDegreeLeft * fabs(newX) / m_firstLeftCoverCenterOffset);
    }
    
    //update next frontCover
    newX = m_firstRightCoverCenterOffset - nextFrontCoverStep;
    if(nextFrontCover->getAutoUpdate()) {
        nextFrontCover->setPosition(newX, 0.0f, fabs(newX) / m_firstRightCoverCenterOffset * m_depthZ);
        nextFrontCover->setRotateY(m_rotateDegreeRight * fabs(newX) / m_firstRightCoverCenterOffset);
    }
    if(newX == 0.0f)
        setFrontCover(nextFrontCover);

    //update right covers
    if(nextFrontCoverStep > m_firstRightCoverCenterOffset - m_rightCoverCenterDelta) {
        stepRightCovers = nextFrontCoverStep - (m_firstRightCoverCenterOffset - m_rightCoverCenterDelta);
    }
    temp = nextFrontCover->getNext();
    while(temp) {
        int indexCur = getIndex(temp);
        int indexRelativeFront = indexCur - indexFront;

        originalPosX = m_firstRightCoverCenterOffset + (indexRelativeFront - 1) * m_rightCoverCenterDelta;
        newX = originalPosX - stepRightCovers;
        if(temp->getAutoUpdate()) {
            temp->setPosition(newX, 0.0f, m_depthZ);
            temp->setRotateY(m_rotateDegreeRight);
        }
        temp = temp->getNext();
    }            
}

void wyCoverFlow::stepRightUpdate(float t) {
    wyCover* curFrontCover = getFrontCover();
    wyCover* nextFrontCover = curFrontCover->getPrev();

    if(!nextFrontCover)
        return;
    
    int indexFront = getIndex(curFrontCover);

    float curFrontStep = m_firstRightCoverCenterOffset * t;
    float nextFrontCoverStep = m_firstLeftCoverCenterOffset * t;
    float stepRightCovers = 0.0f;
    float newX = 0.0f;
    float originalPosX = 0.0f;

    //update right covers
    if(curFrontStep > m_firstRightCoverCenterOffset - m_rightCoverCenterDelta) {
        stepRightCovers = curFrontStep - (m_firstRightCoverCenterOffset - m_rightCoverCenterDelta);
    }
    wyCover* temp = getMostRightToShow();

    while(temp) {
        int indexCur = getIndex(temp);
        int indexRelativeFront = indexCur - indexFront;

        originalPosX = m_firstRightCoverCenterOffset + (indexRelativeFront - 1) * m_rightCoverCenterDelta;
        newX = originalPosX + stepRightCovers;
        if(temp->getAutoUpdate()) {
            temp->setPosition(newX, 0.0f, m_depthZ);
            temp->setRotateY(m_rotateDegreeRight);
        }

        temp = temp->getPrev();
        if(temp == curFrontCover)
            break;
    }

    //update current frontCover
    newX = curFrontStep;
    if(curFrontCover->getAutoUpdate()) {
        curFrontCover->setPosition(newX, 0.0f, fabs(newX) / m_firstRightCoverCenterOffset * m_depthZ);
        curFrontCover->setRotateY(m_rotateDegreeRight * fabs(newX) / m_firstRightCoverCenterOffset);
    }
    
    //update next frontCover
    newX = -(m_firstLeftCoverCenterOffset - nextFrontCoverStep);
    if(nextFrontCover->getAutoUpdate()) {
        nextFrontCover->setPosition(newX, 0.0f, fabs(newX) / m_firstLeftCoverCenterOffset* m_depthZ);
        nextFrontCover->setRotateY(m_rotateDegreeLeft * fabs(newX) / m_firstLeftCoverCenterOffset);
    }
    if(newX == 0.0f)
        setFrontCover(nextFrontCover);

    //update left covers
    if(nextFrontCoverStep > m_firstLeftCoverCenterOffset - m_leftCoverCenterDelta) {
        stepRightCovers = nextFrontCoverStep - (m_firstLeftCoverCenterOffset - m_leftCoverCenterDelta);
    }
    temp = nextFrontCover->getPrev();
    while(temp) {
        int indexCur = getIndex(temp);
        int indexRelativeFront = indexCur - indexFront;

        originalPosX = -m_firstLeftCoverCenterOffset + (indexRelativeFront + 1) * m_leftCoverCenterDelta;
        newX = originalPosX + stepRightCovers;
        if(temp->getAutoUpdate()) {
            temp->setPosition(newX, 0.0f, m_depthZ);
            temp->setRotateY(m_rotateDegreeLeft);
        }
        temp = temp->getPrev();
    }            
}

void wyCoverFlow::showCover(wyCover* cover, float duration) {
    if(m_bIsShowing || !cover || m_frontCover == cover) {
        return;
    }

    if(0.0f >= duration) {
        //update front cover position
        setFrontCover(cover);
        if(m_frontCover->getAutoUpdate()) {
            m_frontCover->setPosition(0.0f, 0.0f, 0.0f);
            m_frontCover->setRotateY(0.0f);
        }

        //update left covers
        wyCover* temp = m_frontCover->getPrev();
        float newPosX = 0.0f;
        while(temp) {
            if(newPosX == 0.0f) {
                newPosX = -m_firstLeftCoverCenterOffset;
            } else {
                newPosX -= m_leftCoverCenterDelta;
            }

            if(temp->getAutoUpdate()) {
                temp->setPosition(newPosX, 0.0f, m_depthZ);
                temp->setRotateY(m_rotateDegreeLeft);
            }

            if(temp == getMostLeftToShow())
                break;

            temp = temp->getPrev();
        }

        //update right covers
        temp = m_frontCover->getNext();
        newPosX = 0.0f;
        while(temp) {
            if(newPosX == 0.0f) {
                newPosX = m_firstRightCoverCenterOffset;
            } else {
                newPosX += m_rightCoverCenterDelta;
            }

            if(temp->getAutoUpdate()) {
                temp->setPosition(newPosX, 0.0f, m_depthZ);
                temp->setRotateY(m_rotateDegreeRight);
            }

            if(temp == getMostRightToShow())
                break;

            temp = temp->getNext();
        }        
    } else {
        m_bIsShowing = true;
        wyAction* action = wyCoverFlowAction::make(duration, cover);
        runAction(action);
    }
}

void wyCoverFlow::moveLeft(float duration) {
    showCover(m_frontCover->getNext(), duration);
}

void wyCoverFlow::moveRight(float duration) {
    showCover(m_frontCover->getPrev(), duration);
}

wyCover* wyCoverFlow::getMostLeftToShow() {
    wyCover* temp = m_frontCover;
    int count = 0;
    while(temp && temp != m_coverListHead) {
        if(count++ >= m_countLeftVisible)
            break;

        temp = temp->getPrev();
    }

    return (temp == m_frontCover ? NULL : temp);   
}

wyCover* wyCoverFlow::getMostRightToShow() {
    wyCover* temp = m_frontCover;
    int count = 0;
    while(temp && temp != m_coverListTail) {
        if(count++ >= m_countRightVisible)
            break;

        temp = temp->getNext();
    }
    return (temp == m_frontCover ? NULL : temp);
}

void wyCoverFlow::drawLeftCovers() {
    wyCover* temp = getMostLeftToShow();
    while(temp && temp != m_frontCover) {
        drawCover(temp);
        temp = temp->getNext();
    }
}

void wyCoverFlow::drawRightCovers() {
    wyCover* temp = getMostRightToShow();
    while(temp && temp != m_frontCover) {
        drawCover(temp);
        temp = temp->getPrev();
    }
}

void wyCoverFlow::drawCover(wyCover* cover) {
    if(!cover)
        return;

	// get texture
	wyTexture2D* tex = cover->getTexture();
    if(!tex)
        return;

	// ensure texture is loaded
	tex->load();

	// save matrix
    glPushMatrix();

	// transform
    cover->transform();

	// bind texture
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex->getTexture());
   
	// draw
    drawMesh(tex->getWidth() / tex->getPixelWidth(), tex->getHeight() / tex->getPixelHeight());

	// restore state
    glDisable(GL_TEXTURE_2D);

	// restore matrix
    glPopMatrix();
}

void wyCoverFlow::matrixMulti(Matrix44 m1, Matrix44 m2, Matrix44 result) {
    Matrix44 temp = {0.0f};
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            temp[i][j] = 0.0f;
            for(int k = 0; k < 4; ++k) {
                temp[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }

    memcpy(result, temp, sizeof(temp));
}

void wyCoverFlow::matrixMulti2(Matrix14 m1, Matrix44 m2, Matrix14 result) {
    Matrix14 temp = {0.0f};    
    for(int i = 0; i < 1; ++i) {
        for(int j = 0; j < 4; ++j) {
            temp[i][j] = 0.0f;
            for(int k = 0; k < 4; ++k) {
                temp[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    memcpy(result, temp, sizeof(temp));   
}

void wyCoverFlow::matrixTranslate(Matrix44 curMatrix, Matrix44 result, wyVertex3D v) {
    Matrix44 translateMatrix = { 1.0f, 0.0f, 0.0f, 0.0f,
                                 0.0f, 1.0f, 0.0f, 0.0f,
                                 0.0f, 0.0f, 1.0f, 0.0f,
                                 v.x,  v.y,  v.z,  1.0f };
    matrixMulti(translateMatrix, curMatrix, result);
}

void wyCoverFlow::matrixRotateY(Matrix44 curMatrix, Matrix44 result, float degree) {
    float radian = degree * M_PI / 180;
    float c = cos(radian);
    float s = sin(radian);
    Matrix44 rotateMatrix = { c,    0.0f, -s,   0.0f,
                              0.0f, 1.0f, 0.0f, 0.0f,
                              0.0f, 0.0f, 1.0f, 0.0f,
                              0.0f, 0.0f, 0.0f, 1.0f };    
    matrixMulti(rotateMatrix, curMatrix, result);
}

void wyCoverFlow::matrixScale(Matrix44 curMatrix, Matrix44 result, float scale) {
    Matrix44 scaleMatrix = { scale, 0.0f,  0.0f, 0.0f,
                              0.0f, scale, 0.0f, 0.0f,
                              0.0f, 0.0f,  1.0f, 0.0f,
                              0.0f, 0.0f,  0.0f, 1.0f };    
    matrixMulti(scaleMatrix, curMatrix, result);
}

void wyCoverFlow::convertToNDC(Matrix14 vertex) {
    for(int i = 0; i < 4; ++i) {
        if(vertex[0][3] != 0.0f) {
            vertex[0][i] = vertex[0][i] / vertex[0][3];
            if(vertex[0][i] < -1.0f) {
                vertex[0][i] = -1.0f;
            }
            vertex[0][i] = (vertex[0][i] + 1) / 2;            
        }
    }
}
    
bool wyCoverFlow::getModelviewMatrix(wyCover* cover, Matrix44 ret) {
    if(getIndex(cover) < 0 || !ret || !m_isMatrixValid)
        return false;

    Matrix44 temp;
    memcpy(temp ,m_modelViewMatrix, sizeof(temp));
    wyVertex3D vCenter = {m_frontCenterX, m_frontCenterY, 0.0f};
    matrixTranslate(temp, temp, cover->getPosition());
    matrixRotateY(temp, temp, cover->getRotateY());
    matrixScale(temp, temp, cover->getScale());
    matrixTranslate(temp, temp, vCenter);

    memcpy(ret ,temp, sizeof(temp));
    
    return true;
}

bool wyCoverFlow::getProjectionMatrix(Matrix44 ret) {
    if(!ret || !m_isMatrixValid)
        return false;
    
    memcpy(ret, m_projectionMatrix, sizeof(m_projectionMatrix));

    return true;
}

bool wyCoverFlow::getCoverWindowQuad(wyCover* cover, wyQuad2D* quad) {
    // in case the GPU deosn't support glGetFloatv(GL_MODELVIEW_MATRIX, ..)
    if(!m_isMartixQuerySupported) {
        wyPoint p[4] = {
            m_coverPoints[0].p.x, m_coverPoints[0].p.y,
            m_coverPoints[3].p.x, m_coverPoints[3].p.y,
            m_coverPoints[12].p.x, m_coverPoints[12].p.y,
            m_coverPoints[15].p.x, m_coverPoints[15].p.y,
        };
        wyVertex3D v = cover->getPosition();
        float radian = cover->getRotateY() * M_PI / 180;
        float scale = cover->getScale();

        for(int i = 0; i < 4; ++i) {
            p[i].x = p[i].x * scale * cos(radian) + v.x;
            p[i].x *= 0.8f;
            p[i].y = p[i].y * scale + v.y;
            p[i] = nodeToWorldSpace(p[i]);
        }
            
        quad->tl_x = p[0].x;
        quad->tl_y = p[0].y;
        quad->tr_x = p[1].x;
        quad->tr_y = p[1].y;
        quad->bl_x = p[2].x;
        quad->bl_y = p[2].y;
        quad->br_x = p[3].x;
        quad->br_y = p[3].y; 

        return true;
    } else {
        wyRect viewPort = m_viewPort;

        Matrix44 modelviewMatrix = {0.0f};
        Matrix44 projectionMatrix = {0.0f};

        Matrix14 v0 = {m_coverPoints[0].p.x, m_coverPoints[0].p.y, m_coverPoints[0].p.z, 1.0f};
        Matrix14 v3 = {m_coverPoints[3].p.x, m_coverPoints[3].p.y, m_coverPoints[3].p.z, 1.0f};
        Matrix14 v12 = {m_coverPoints[12].p.x, m_coverPoints[12].p.y, m_coverPoints[12].p.z, 1.0f};
        Matrix14 v15 = {m_coverPoints[15].p.x, m_coverPoints[15].p.y, m_coverPoints[15].p.z, 1.0f};
        
        if(!getModelviewMatrix(cover, modelviewMatrix) || !getProjectionMatrix(projectionMatrix))
            return false;

        // do model view transform
        matrixMulti2(v0, modelviewMatrix, v0);
        matrixMulti2(v3, modelviewMatrix, v3);
        matrixMulti2(v12, modelviewMatrix, v12);
        matrixMulti2(v15, modelviewMatrix, v15);    

        // do projection tranform
        matrixMulti2(v0, projectionMatrix, v0);
        matrixMulti2(v3, projectionMatrix, v3);
        matrixMulti2(v12, projectionMatrix, v12);
        matrixMulti2(v15, projectionMatrix, v15);    

        // do NDC
        convertToNDC(v0);
        convertToNDC(v3);
        convertToNDC(v12);
        convertToNDC(v15);

        // convert to window rect
        quad->tl_x = v0[0][0] * viewPort.width + viewPort.x;
        quad->tl_y = v0[0][1] * viewPort.height + viewPort.y;
        quad->tr_x = v3[0][0] * viewPort.width + viewPort.x;
        quad->tr_y = v3[0][1] * viewPort.height + viewPort.y;
        quad->bl_x = v12[0][0] * viewPort.width + viewPort.x;
        quad->bl_y = v12[0][1] * viewPort.height + viewPort.y;
        quad->br_x = v15[0][0] * viewPort.width + viewPort.x;
        quad->br_y = v15[0][1] * viewPort.height + viewPort.y;

        return true; 
    }
}

bool wyCoverFlow::isPointInsideQuad(float x, float y, wyQuad2D* quad) {
    float vertx[4] = {quad->bl_x, quad->br_x, quad->tr_x, quad->tl_x};
    float verty[4] = {quad->bl_y, quad->br_y, quad->tr_y, quad->tl_y};
    int i;
    int j;
    bool bIsInside = false;
    int nvert = 4;

    for (i = 0, j = nvert-1; i < nvert; j = i++) {
        if (((verty[i] > y) != (verty[j] > y)) &&
         (x < (vertx[j] - vertx[i]) * (y - verty[i]) / (verty[j] - verty[i]) + vertx[i])) {
            bIsInside = !bIsInside;
        }
    }
    
    return bIsInside;
}

wyCover* wyCoverFlow::getTouchedCover(float x, float y) {
    wyQuad2D quadTemp = {0};
    wyCover* coverTemp = NULL;
    wyCover* mostLeftCover = getMostLeftToShow();
    wyCover* mostRightCover = getMostRightToShow();

	// revert coordinates
	if(wyDevice::scaleMode != SCALE_MODE_BY_DENSITY) {
		x = x * wyDevice::baseScaleX;
		y = y * wyDevice::baseScaleY;
	}

    // test front cover
    if(getCoverWindowQuad(m_frontCover, &quadTemp) && isPointInsideQuad(x, y, &quadTemp)) {
        return m_frontCover;
    }
    
    // test right covers
    coverTemp = m_frontCover->getNext();
    while(coverTemp) {
        
        if(getCoverWindowQuad(coverTemp, &quadTemp) && isPointInsideQuad(x, y, &quadTemp)) {
            return coverTemp;
        }
        
        if(coverTemp == mostRightCover) {
            break;
        }

        coverTemp = coverTemp->getNext();
    }
    
    // test left covers
    coverTemp = m_frontCover->getPrev();
    
    while(coverTemp) {   
        if(getCoverWindowQuad(coverTemp, &quadTemp) && isPointInsideQuad(x, y, &quadTemp)) {
            return coverTemp;
        }
        
        if(coverTemp == mostLeftCover) {
            break;
        }
        
        coverTemp = coverTemp->getPrev();
    }

    return NULL;
}

void wyCoverFlow::drawMesh(float ratioX, float ratioY) {
	int stride = sizeof(SVertex);

    glTranslatef(m_frontCenterX, m_frontCenterY, 0);

    if(m_fVBOSupported && ratioX == 1.0f && ratioY == 1.0f) {
    	// bind the VBO for the mesh
    	glBindBuffer(GL_ARRAY_BUFFER, m_uiVbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uiAllIndexVbo);
    	glVertexPointer(3, GL_FLOAT, stride, 0);
    	glNormalPointer(GL_FLOAT, stride, (GLvoid*)offsetof(SVertex, n));
    	glColorPointer(4, GL_FLOAT, stride, (GLvoid*)offsetof(SVertex, c));
    	glTexCoordPointer(2, GL_FLOAT, stride, (GLvoid*)offsetof(SVertex, t));

    	//enable alpha blending just for the borders
    	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        if(m_bMirrorEnabled) {
            glDrawElements(GL_TRIANGLES, 108, GL_UNSIGNED_SHORT, 0);
        } else {
            glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_SHORT, 0);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (GLvoid*)192);
        }
    } else {
    	glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    	glVertexPointer(3, GL_FLOAT, stride, (GLvoid*)m_coverPoints);
    	glNormalPointer(GL_FLOAT, stride, (GLvoid*)((size_t)m_coverPoints + offsetof(SVertex, n)));
    	glColorPointer(4, GL_FLOAT, stride, (GLvoid*)((size_t)m_coverPoints + offsetof(SVertex, c)));

        if(ratioX != 1.0f || ratioY != 1.0f) {
            for(int i = 0; i < 32; ++i) {
                if(ratioX != 1.0f)
                    m_texCoordsReal[i].x = m_coverPoints[i].t.x * ratioX;
                if(ratioY != 1.0f)
                    m_texCoordsReal[i].y = m_coverPoints[i].t.y * ratioY;
            }            
        }

    	glTexCoordPointer(2, GL_FLOAT, 0, (GLvoid*)(m_texCoordsReal));

    	//enable alpha blending just for the borders
    	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        if(m_bMirrorEnabled) {
            glDrawElements(GL_TRIANGLES, 108, GL_UNSIGNED_SHORT, m_indicesAll);
        } else {
            glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_SHORT, m_indicesAll);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, (GLvoid*)((char*)m_indicesAll + 192));
        }
    }
}

void wyCoverFlow::draw() {
    if(m_noDraw) {
        wyNode::draw();
        return;
    }

	// always check viewport update
	int viewPort[4] = {0};
	glGetIntegerv(GL_VIEWPORT, viewPort);
	m_viewPort.x = viewPort[0];
    m_viewPort.y = viewPort[1];
    m_viewPort.width = viewPort[2];
    m_viewPort.height = viewPort[3];

	// vbo has problem in windows, so exlude it in windows platform
#ifndef WINDOWS
    if(!m_fVersionGot) {
        const char* version = (const char*)glGetString(GL_VERSION); 
        m_fVBOSupported = (strstr(version, "1.1") != NULL);
        m_fVersionGot = true;
    }
#endif
    
    initVertices();

    // Clears the color and depth buffer
    glShadeModel(GL_SMOOTH);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // get modelview and projection matrix
    if(m_isMartixQuerySupported) {
        // clear opengl error flag
        glGetError();

        glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)m_modelViewMatrix);
        glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)m_projectionMatrix);

        if(GL_NO_ERROR != glGetError())
            m_isMartixQuerySupported = false;
        else
            m_isMatrixValid = true;
    }

    //do drawing
    drawLeftCovers();
    drawRightCovers();
    drawFrontCover();
    
	// unbind the vertex buffers as we don't need them bound anymore
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
    glShadeModel(GL_FLAT);
}

void wyCoverFlow::initVertices() {
	// this function creates the vertex position, color, normal, and tex coordinate values for one cover.
	/* The covers are made up of 16 vertices, 9 quads, 18 triangles. The four colours of the center vertices are fully opaque while all the
	outside vertices are fully transparent. This produces a thin fade out at the edges which avoids antialiasing.

	0--1------2--3
	|  |      |  |
	4--5------6--7
	|  |      |  |
	|  |      |  |
	|  |      |  |
	8--9-----10--11
	|  |      |  |
	12-13----14--15

	*/

    if(m_bVerticeInited)
        return;

	int i, row, col;
	float width = m_frontWidth;
	float height = m_frontHeight;
    float widthBorderPercent = m_fBorderPercent;
    float heightBorderPercent = m_fBorderPercent;
    
    //initialise vertices to normalised size, can then also be used as uv coorda and scales up after
    const float dim = 0.5f; 

    //size minus the fraction of the border
    if(!m_borderUsePercent) {
        widthBorderPercent = m_fBorderWidth * 2 / width;
        heightBorderPercent = m_fBorderWidth * 2 / height;
    }
	const float dimLessX = 0.5f - (0.5f * widthBorderPercent);
    const float dimLessY = 0.5f - (0.5f * heightBorderPercent);

	wyVertex3D normal = {0.0f, 1.0f, 0.0f}; //all the normals are the same
    unsigned short* m_indicesBlend = m_indicesAll;
	unsigned short* m_indicesOpaque = m_indicesAll + 96;

	m_coverPoints[0].p.x = -dim;
	m_coverPoints[0].p.y = dim;
	m_coverPoints[0].p.z = 0.0f;

	m_coverPoints[1].p.x = -dimLessX;
	m_coverPoints[1].p.y = dim;
	m_coverPoints[1].p.z = 0.0f;

	m_coverPoints[2].p.x = dimLessX;
	m_coverPoints[2].p.y = dim;
	m_coverPoints[2].p.z = 0.0f;

	m_coverPoints[3].p.x = dim;
	m_coverPoints[3].p.y = dim;
	m_coverPoints[3].p.z = 0.0f;

	m_coverPoints[4].p.x = -dim;
	m_coverPoints[4].p.y = dimLessY;
	m_coverPoints[4].p.z = 0.0f;

	m_coverPoints[5].p.x = -dimLessX;
	m_coverPoints[5].p.y = dimLessY;
	m_coverPoints[5].p.z = 0.0f;

	m_coverPoints[6].p.x = dimLessX;
	m_coverPoints[6].p.y = dimLessY;
	m_coverPoints[6].p.z = 0.0f;

	m_coverPoints[7].p.x = dim;
	m_coverPoints[7].p.y = dimLessY;
	m_coverPoints[7].p.z = 0.0f;

	m_coverPoints[8].p.x = -dim;
	m_coverPoints[8].p.y = -dimLessY;
	m_coverPoints[8].p.z = 0.0f;

	m_coverPoints[9].p.x = -dimLessX;
	m_coverPoints[9].p.y = -dimLessY;
	m_coverPoints[9].p.z = 0.0f;

	m_coverPoints[10].p.x = dimLessX;
	m_coverPoints[10].p.y = -dimLessY;
	m_coverPoints[10].p.z = 0.0f;

	m_coverPoints[11].p.x = dim;
	m_coverPoints[11].p.y = -dimLessY;
	m_coverPoints[11].p.z = 0.0f;

	m_coverPoints[12].p.x = -dim;
	m_coverPoints[12].p.y = -dim;
	m_coverPoints[12].p.z = 0.0f;

	m_coverPoints[13].p.x = -dimLessX;
	m_coverPoints[13].p.y = -dim;
	m_coverPoints[13].p.z = 0.0f;

	m_coverPoints[14].p.x = dimLessX;
	m_coverPoints[14].p.y = -dim;
	m_coverPoints[14].p.z = 0.0f;

	m_coverPoints[15].p.x = dim;
	m_coverPoints[15].p.y = -dim;
	m_coverPoints[15].p.z = 0.0f;

	for(i = 0; i < 16; ++i)	{
		m_coverPoints[i].n = normal;
		m_coverPoints[i].c.r = 1.0f;
		m_coverPoints[i].c.g = 1.0f;
		m_coverPoints[i].c.b = 1.0f;
		m_coverPoints[i].c.a = 0.0f;

		// the uvs are matched to the positions (+0.5 for range 0-1)
		m_coverPoints[i].t.x = m_coverPoints[i].p.x + 0.5f;
		m_coverPoints[i].t.y = -m_coverPoints[i].p.y + 0.5f;

		// scale up to desired size
		m_coverPoints[i].p.x = m_coverPoints[i].p.x * width;
		m_coverPoints[i].p.y = m_coverPoints[i].p.y * height;
	}

	//only the center 4 vertices have are fully opaque all the rest around the edge are tranparent
	m_coverPoints[5].c.a = 1.0f;
	m_coverPoints[6].c.a = 1.0f;
	m_coverPoints[9].c.a = 1.0f;
	m_coverPoints[10].c.a = 1.0f;

	//create indices for the 2 triangles for every square
	int i32NumOpaque = 0;
	int i32NumBlend = 0;

	for(row = 0; row < 3; ++row) {
		for(col = 0; col < 3; ++col) {
			int start = (row*4)+col;
			//the center indices are kept in a separate buffer to the border ones as they arew going
			//to be drawn in 2 separate passes.
			if(row == 1 && col == 1) {
				m_indicesOpaque[i32NumOpaque++] = start+1;
				m_indicesOpaque[i32NumOpaque++] = start;
				m_indicesOpaque[i32NumOpaque++] = start+4;
				m_indicesOpaque[i32NumOpaque++] = start+1;
				m_indicesOpaque[i32NumOpaque++] = start+4;
				m_indicesOpaque[i32NumOpaque++] = start+5;
			} else {
				m_indicesBlend[i32NumBlend++] = start+1;
				m_indicesBlend[i32NumBlend++] = start;
				m_indicesBlend[i32NumBlend++] = start+4;
				m_indicesBlend[i32NumBlend++] = start+1;
				m_indicesBlend[i32NumBlend++] = start+4;
				m_indicesBlend[i32NumBlend++] = start+5;
			}
		}
	}


	//adjusted the triangle alignment for two of the corners so that the transparency
	//falls off in the same direction as the other two corners (comment out to see what i mean!)
	//top left
	m_indicesBlend[0] = 1;
	m_indicesBlend[1] = 0;
	m_indicesBlend[2] = 5;
	m_indicesBlend[3] = 0;
	m_indicesBlend[4] = 4;
	m_indicesBlend[5] = 5;

	//bottom right
	m_indicesBlend[42] = 11;
	m_indicesBlend[43] = 10;
	m_indicesBlend[44] = 15;
	m_indicesBlend[45] = 10;
	m_indicesBlend[46] = 14;
	m_indicesBlend[47] = 15;

	//copy the indices for the mirrored versions
	int rowIndex;
	int colIndex;
	for(i = 0; i < 48; ++i)	{
		if(i < 6) {
			rowIndex = m_indicesOpaque[i] / 4;
			colIndex = m_indicesOpaque[i] % 4;
			m_indicesOpaque[i+6] = (3 - rowIndex) * 4 + 16 + colIndex;
			//m_indicesOpaque[i+6] = m_indicesOpaque[i] + 16;
		}

		rowIndex = m_indicesBlend[i] / 4;
		colIndex = m_indicesBlend[i] % 4;
		m_indicesBlend[i+48] = (3 - rowIndex) * 4 + 16 + colIndex;
		//m_indicesBlend[i+48] = m_indicesBlend[i] + 16;
	}
	i32NumBlend *= 2;
	i32NumOpaque *= 2;

	//create the vertex points for the mirrored cover.
	for(row = 0; row < 4; ++row) {
		// the colors on the flip vertices are going to fade out the further away from the mirror they are
		// using the y coordinate of the cover points
		float dark = 1 - ((m_coverPoints[(row * 4)].p.y / height) + 0.5f);
		
		// made a little darker in the reflection to mimic properties of dull mirror
		dark -= (1 - m_brightLevelOfMirror); 

		for(col = 0; col < 4; ++col) {
			// copy the vertices with y values reversed for the mirrored equivalents
			m_coverPoints[((row*4)+col) + 16] = m_coverPoints[((row * 4) + col)];
			m_coverPoints[((row*4)+col) + 16].p.y = m_coverPoints[((row * 4) + col) + 16].p.y * -1.0f;
			m_coverPoints[((row*4)+col) + 16].p.y -= height + m_heightFromMirror;

			m_coverPoints[((row*4)+col) + 16].c.r = dark;
			m_coverPoints[((row*4)+col) + 16].c.g = dark;
			m_coverPoints[((row*4)+col) + 16].c.b = dark;
		}
	}

	for(i = 0; i < 96; ++i)	{
		m_indicesAll[i] = m_indicesBlend[i];
	}

	for(i = 0; i < 12; ++i)	{
		m_indicesAll[i+96] = m_indicesOpaque[i];
	}

    for(i = 0; i < 32; ++i) {
        m_texCoordsReal[i] = m_coverPoints[i].t;
    }

	glGenBuffers(1, &m_uiVbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_uiVbo);
	glBufferData(GL_ARRAY_BUFFER, 32 * sizeof(SVertex), m_coverPoints, GL_STATIC_DRAW);

	glGenBuffers(1, &m_uiAllIndexVbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uiAllIndexVbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 108 * sizeof(short), m_indicesAll, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    m_bVerticeInited = true;
}

void wyCoverFlow::setHeightFromMirror(float height) {
	if(m_heightFromMirror != height) {
		m_heightFromMirror = height;
		m_bVerticeInited = false;
	}
}

void wyCoverFlow::setBrightLevelOfMirror(float level) {
	if(m_brightLevelOfMirror != level) {
		m_brightLevelOfMirror = level;
		m_bVerticeInited = false;
	}
}
