#ifndef __INTERFACE_DEFINE_H__
#define __INTERFACE_DEFINE_H__

#if defined _WIN32 || defined __CYGWIN__
  #ifdef _EXPORTING
    #ifdef __GNUC__
      #define API_PUBLIC __attribute__ ((dllexport))
    #else
      #define API_PUBLIC __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define API_PUBLIC __attribute__ ((dllimport))
    #else
      #define API_PUBLIC __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define API_LOCAL
#else
  #if __GNUC__ >= 4
    #define API_PUBLIC __attribute__ ((visibility ("default")))
    #define API_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define API_PUBLIC
    #define API_LOCAL
  #endif
#endif

#endif