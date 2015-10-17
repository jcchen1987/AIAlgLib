#include "ImageProcess.h"

CImageProcess* ImgProcInit(l32 l32AlgType)
{
    return NULL;
}

CImageProcess::CImageProcess(l32 l32Width, l32 l32Height)
{
    m_l32ErrCode = 0;
}

CImageProcess::~CImageProcess()
{
    m_l32ErrCode = 0;
}

l32 CImageProcess::GetLastError()
{
    return m_l32ErrCode;
}