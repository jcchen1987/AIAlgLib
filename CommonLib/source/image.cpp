#include "image.h"
#include <string.h>

TImage::TImage()
{
    m_pvBuffer = NULL;
    m_l32Width = 0;
    m_l32Height = 0;
    m_eType = IMG_TYPE_I420;
    m_d64TimeStamp = 0;
    bCreated = false;
}
TImage::TImage(void *pvBuf, l32 l32Width, l32 l32Height, EImageType eImgType, d64 d64TimeStamp)
{
    m_pvBuffer = pvBuf;
    m_l32Width = l32Width;
    m_l32Height = l32Height;
    m_eType = eImgType;
    m_d64TimeStamp = d64TimeStamp;
    bCreated = false;
}
TImage::TImage(l32 l32Width, l32 l32Height, EImageType eImgType, d64 d64TimeStamp)
{
    Create(l32Width, l32Height, eImgType, d64TimeStamp);
}
TImage::~TImage()
{
    if (bCreated && m_pvBuffer)
    {
        delete[]m_pvBuffer;
        m_pvBuffer = NULL;
    }
}

void TImage::Create(l32 l32Width, l32 l32Height, EImageType eImgType, d64 d64TimeStamp)
{
    l32 l32BufSize = 0;
    if (l32Width <= 0 || l32Height <= 0) return;
    switch (eImgType)
    {
    case IMG_TYPE_GRAY:
        l32BufSize = l32Width  * l32Height;
        break;
    case IMG_TYPE_RGB24:
    case IMG_TYPE_BGR24:
    case IMG_TYPE_HSV:
        l32BufSize = l32Width * l32Height * 3;
        break;
    case IMG_TYPE_I420:
    case IMG_TYPE_NV12:
        l32BufSize = l32Width  * l32Height * 3 / 2;
        break;
    default:
        l32BufSize = 0;
        break;
    }
    if (l32BufSize <= 0) return;

    m_pvBuffer = new u8[l32BufSize];
    if (NULL == m_pvBuffer) return;

    m_l32Width = l32Width;
    m_l32Height = l32Height;
    m_eType = eImgType;
    m_d64TimeStamp = d64TimeStamp;  
    bCreated = true;
}