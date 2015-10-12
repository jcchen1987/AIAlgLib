#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "basetype.h"
enum EImageType
{
    IMG_TYPE_GRAY = 0x1000,
    IMG_TYPE_RGB24,
    IMG_TYPE_BGR24,
    IMG_TYPE_I420,
    IMG_TYPE_HSV,
    IMG_TYPE_NV12
};

struct TImage
{  
    //operator
    TImage();
    TImage(void *pvBuf, l32 l32Width, l32 l32Height, EImageType eImgType, d64 d64TimeStamp = 0);
    TImage(l32 l32Width, l32 l32Height, EImageType eImgType, d64 d64TimeStamp = 0);
    ~TImage();

    void Create(l32 l32Width, l32 l32Height, EImageType eImgType, d64 d64TimeStamp = 0);

    //data
    void *m_pvBuffer;
    l32 m_l32Width;
    l32 m_l32Height;
    EImageType m_eType;
    d64 m_d64TimeStamp;
    bool bCreated;
};

#endif
