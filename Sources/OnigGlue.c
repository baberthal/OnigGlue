#include "include/OnigGlue.h"

CFStringRef SwiftOnig_stringFromErrorCode(int code)
{
  OnigUChar buffer[ONIG_MAX_ERROR_MESSAGE_LEN];
  int strlen = onig_error_code_to_str(buffer, code);
  if (strlen == 0) { return CFSTR(""); }

  return CFStringCreateWithBytes(kCFAllocatorDefault,
                                 buffer,
                                 strlen,
                                 kCFStringEncodingUTF8,
                                 false);
}

CFStringRef SwiftOnig_stringFromErrorCodeAndInfoP(int code, OnigErrorInfo *p)
{
  OnigUChar buffer[ONIG_MAX_ERROR_MESSAGE_LEN];
  int strlen = onig_error_code_to_str(buffer, code, &p);
  if (strlen == 0) { return CFSTR(""); }

  return CFStringCreateWithBytes(kCFAllocatorDefault,
                                 buffer,
                                 strlen,
                                 kCFStringEncodingUTF8,
                                 false);
}

CFStringRef SwiftOnig_stringFromErrorCodeAndInfo(int code, OnigErrorInfo info)
{
  OnigUChar buffer[ONIG_MAX_ERROR_MESSAGE_LEN];
  int strlen = onig_error_code_to_str(buffer, code, info);
  if (strlen == 0) { return CFSTR(""); }

  return CFStringCreateWithBytes(kCFAllocatorDefault,
                                 buffer,
                                 strlen,
                                 kCFStringEncodingUTF8,
                                 false);
}

void SwiftOnig_defaultWarningFunction(const char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

__attribute__((constructor)) void SwiftOnig_InitializeLibrary(void)
{
  OnigEncoding encodings[] = {
    ONIG_ENCODING_ASCII, ONIG_ENCODING_UTF8, ONIG_ENCODING_UTF16_LE,
  };
  int ok = onig_initialize(encodings, sizeof(encodings) / sizeof(encodings[0]));
  if (ok != 0) {
    // TODO: Handle the error here
  }
}
