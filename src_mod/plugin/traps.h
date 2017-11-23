///////////////////////////////////////////////////////////////////////////////
// traps.h - definitions for all the functions "imported" from server code.
//      If function was added once - it must exist all the time.
//      You can change inner code. Do not delete functions - old plugins may rely on these.
#pragma once

#include "base.h"
#include <cstdio>
#include <cstdarg>

inline void trap_Com_Printf(const char* const Format_, ...)
{
    char msg[1024];
    va_list ap;
    va_start(ap, Format_);

    vsnprintf(msg, sizeof(msg), Format_, ap);
    va_end(ap);

    syscall(AC_Com_Printf, msg);
}

inline void trap_Com_Error(const char* const Error, ... )
{
	char msg[1024];
    va_list ap;
    va_start(ap, Error);

    vsnprintf(msg, sizeof(msg), Error, ap);
    va_end(ap);

	syscall(AC_Com_Error, msg);
}

inline void trap_Com_PrintError(const char* const Fmt, ... )
{
	char msg[1024];
    va_list ap;
    va_start(ap, Fmt);

    vsnprintf(msg, sizeof(msg), Fmt, ap);
    va_end(ap);

	syscall(AC_Com_PrintError, msg);
}