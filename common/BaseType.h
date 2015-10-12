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

struct TRect
{
    l32  Distance(const TRect &tRect);
    bool PtInRect(const TPoint &tPoint);
    void CropRect(TRect &tRect, l32 l32Width, l32 l32Height);

    l32 l32Left;
    l32 l32Top;
    l32 l32Width;
    l32 l32Height;
};

#define POLY_MAX_PT_NUM 50
struct  TPolygon
{
    bool PtInPolygon(const TPoint &tPoint);
    void GenerateMask(u8 *pu8Mask, l32 l32MaskW, l32 l32MaskH);
    TPoint atPoint[POLY_MAX_PT_NUM];
    l32 l32PtNum;
};


//member function implement
l32 TRect::Distance(const TRect &tRect)
{
    l32 l32OverX = MIN(l32Left + l32Width - tRect.l32Left, tRect.l32Left + tRect.l32Width - l32Left);
    l32 l32OverY = MIN(l32Top + l32Height - tRect.l32Top, tRect.l32Top + tRect.l32Height - l32Top);
    if (l32OverX > 0 && l32OverY > 0)
    {
        return l32OverX + l32OverY;
    }
    return 0;
}

bool TRect::PtInRect(const TPoint &tPoint)
{
    l32 l32dx = tPoint.l32X - l32Left;
    l32 l32dy = tPoint.l32Y - l32Top;
    if (BETWEEN(l32dx, 0, l32Width) && BETWEEN(l32dy, 0, l32Height))
    {
        return true;
    }
    return false;
}

void TRect::CropRect(TRect &tRect, l32 l32Width, l32 l32Height)
{
    l32 l32Left = tRect.l32Left;
    l32 l32Top = tRect.l32Top;
    l32 l32Right = l32Left + tRect.l32Width;
    l32 l32Bottom = l32Top + tRect.l32Height;

    if (l32Left < 0) tRect.l32Left = 0;
    if (l32Top < 0) tRect.l32Top = 0;
    if (l32Right > l32Width - 1) tRect.l32Width = l32Width - 1 - l32Left;
    if (l32Bottom > l32Height - 1) tRect.l32Height = l32Height - 1 - l32Top;
}

bool TPolygon::PtInPolygon(const TPoint &tPoint)
{
    return false;
}

void TPolygon::GenerateMask(u8 *pu8Mask, l32 l32MaskW, l32 l32MaskH)
{
}

#endif
