#ifndef _BASETYPE_H_
#define _BASETYPE_H_

typedef char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef float f32;
typedef double d64;

typedef long               l32;
typedef unsigned long      u32;

#if defined ARCH_X86_LINUX || defined ARCH_X64_LINUX //linux system
typedef long long          s64;
typedef unsigned long long u64;
#define EXPORT

#elif defined _WINDOWS //windows system
typedef __int64			   s64;
typedef unsigned __int64   u64;
#define EXPORT __declspec(dllexport)
#endif

#ifndef MIN
#define MIN(a, b)   (((a) > (b) ? (b) : (a)))
#endif
#ifndef MAX
#define MAX(a, b)   (((a) > (b) ? (a) : (b)))
#endif
#ifndef ABS
#define ABS(a) ((a) > 0 ? (a) :(-(a)))
#endif
#ifndef BETWEEN
#define BETWEEN(x, a, b) ((x) >= (a) && (x) < (b))
#endif

struct TPoint
{
    l32 l32X;
    l32 l32Y;
};

#endif
