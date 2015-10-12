#ifndef _IMAGE_PROCESS_H_
#define _IMAGE_PROCESS_H_

#include "BaseType.h"

typedef struct
{
    l32 l32Width;
    l32 l32Height;
}TImgProcParam;

typedef struct
{

}TImgProcIn;

typedef struct
{

}TImgProcOut;

class CImageProcess
{
public:
    virtual l32 Open(TImgProcParam *ptParam) = 0;
    virtual l32 SetParam(char *ps8Param) = 0;
    virtual l32 Process(TImgProcIn *ptIn, TImgProcOut *ptOut) = 0;
    virtual l32 Close() = 0;
};

EXPORT l32 ImgProcInit();
#endif
