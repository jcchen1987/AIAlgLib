#ifndef _POLYGON_H_
#define _POLYGON_H_

#include "basetype.h"
#include <vector>
using std::vector;

struct  TPolygon
{
    bool PtInPolygon(const TPoint &tPoint);
    void GenerateMask(u8 *pu8Mask, l32 l32MaskW, l32 l32MaskH);

    vector<TPoint> vtPoint;
};





#endif
