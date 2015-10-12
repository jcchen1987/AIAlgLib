#include "Rect.h"
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