#ifndef SWIFT_ONIGURUMA_GLUE
#define SWIFT_ONIGURUMA_GLUE 1

#include <CoreFoundation/CoreFoundation.h>

#ifndef ONIG_ESCAPE_UCHAR_COLLISION
#define ONIG_ESCAPE_UCHAR_COLLISION
#endif /* ONIG_ESCAPE_UCHAR_COLLISION */
#include "oniguruma.h"

CFStringRef SwiftOnig_stringFromErrorCode(int code);
CFStringRef SwiftOnig_stringFromErrorCodeAndInfoP(int code, OnigErrorInfo *p);
CFStringRef SwiftOnig_stringFromErrorCodeAndInfo(int code, OnigErrorInfo info);

void SwiftOnig_InitializeLibrary(void);

#endif /* ifndef SWIFT_ONIGURUMA_GLUE */
