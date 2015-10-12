#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "BaseType.h"

struct TPlane
{
    void Init()
    l32 l32Width;
    l32 l32Height;
    l32 l32Stride;
    void *pvBuffer;
};

class CImage
{
    enum EImageType
    {
        IMG_TYPE_GRAY = 0x1000,
        IMG_TYPE_RGB24,
        IMG_TYPE_RGB32,
        IMG_TYPE_HSV,
        IMG_TYPE_I420,
        IMG_TYPE_NV12
    };
public:
    CImage(l32 l32Width, l32 l32Height, EImageType eImgType);
    ~CImage();
    Zeros(l32 l32Width, l32 l32Height, EImageType eImgType);
    l32 GetWidth();
    l32 GetHeight();
    bool GetPlaneInfo(void *&pvBuffer, l32 &l32Width, l32 &l32Height);

private:
    TPlane m_atPlane[4];
    EImageType m_eImgType;
};

CImage::CImage(l32 l32Width, l32 l32Height, EImageType eImgType)
{
    m_eImgType = eImgType;
    memset(m_atPlane, 0, 4 * sizeof(TPlane));
    switch (eImgType)
    {
    case IMG_TYPE_GRAY: 
        break;
    case IMG_TYPE_RGB24: 
        break;
    case IMG_TYPE_RGB32: 
        break;
    case IMG_TYPE_HSV: 
        break;
    case IMG_TYPE_I420: 
        break;
    case IMG_TYPE_NV12:
        break;
    default:
        break;
    }

}
#endif
