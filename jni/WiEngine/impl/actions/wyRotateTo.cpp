#include "wyRotateTo.h"
#include "wyNode.h"

wyAction* wyRotateTo::copy() {
	return wyRotateTo::make(m_duration, m_startAngle, m_endAngle);
}

wyAction* wyRotateTo::reverse() {
	return wyRotateTo::make(m_duration, m_endAngle, m_startAngle);
}

void wyRotateTo::update(float t) {
	m_target->setRotation(m_startAngle + m_delta * t);

	// super only call callback
	wyIntervalAction::update(t);
}

wyRotateTo::~wyRotateTo() {
}

wyRotateTo::wyRotateTo(float duration, float startAngle, float endAngle) :
		wyIntervalAction(duration),
		m_startAngle(startAngle),
		m_endAngle(endAngle),
		m_delta(endAngle - startAngle) {
}

wyRotateTo* wyRotateTo::make(float duration, float startAngle, float endAngle) {
	wyRotateTo* a = WYNEW wyRotateTo(duration, startAngle, endAngle);
	return (wyRotateTo*)a->autoRelease();
}
