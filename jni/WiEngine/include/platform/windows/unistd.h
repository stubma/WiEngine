#if WINDOWS

#ifndef __unistd_h__  
#define __unistd_h__  

#include <io.h>  
#include <process.h>  
#include <process.h> /* for getpid() and the exec..() family */

// types
#define ssize_t int

#endif // __unistd_h__

#endif // #if WINDOWS