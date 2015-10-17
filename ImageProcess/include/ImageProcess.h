#ifndef _IMAGE_PROCESS_H_
#define _IMAGE_PROCESS_H_

#include "commonlib.h"

#define IMAGE_PROCESS_ALG_BASE 0x80000000


#define IS_IMG_PROCESS_ALG(x) (((x) & IMAGE_PROCESS_ALG_BASE) ? true : false)


class CImageProcess
{
public:
    CImageProcess(l32 l32Width, l32 l32Height);
    virtual ~CImageProcess() = 0;
    virtual void SetParam(char *ps8Param) = 0;
    virtual void Process(TImage *ptSrcImg, TImage *ptDstImg, TImage *ptMask) = 0;
    l32 GetLastError();
private:
    l32 m_l32ErrCode;
};

EXPORT CImageProcess* ImgProcInit(l32 l32AlgType);
#endif
