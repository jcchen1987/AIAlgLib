#ifndef _RECT_H_
#define _RECT_H_

#include "basetype.h"

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

#endif

