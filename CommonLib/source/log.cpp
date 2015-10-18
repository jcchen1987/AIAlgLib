#include "log.h"
#include <string.h>
#include <stdio.h>

CLog::CLog(u32 u32Code, s8 *ps8Info)
{
    m_u32Code = 0;
    memset(m_as8Info, 0, LOG_MAX_LEN);
    Set(u32Code, ps8Info);
}

CLog::~CLog()
{
}

ELogLevel CLog::GetLogLevel()
{
    if (m_u32Code & ERROR_BASE) return ELOG_ERROR;
    if (m_u32Code & WARNING_BASE) return ELOG_WARNING;
    if (m_u32Code & INFO_BASE) return ELOG_INFO;
    return ELOG_INVALID;
}

void CLog::Set(u32 u32Code, s8 *ps8Info)
{
    m_u32Code = m_u32Code;
    if (ps8Info && strlen(ps8Info) <= LOG_MAX_LEN)
    {
        strcpy(m_as8Info, ps8Info);
    }
}
void CLog::Get(u32 &u32Code, s8 *ps8Info)
{
    u32Code = m_u32Code;
    if (ps8Info)
    {
        strcpy(ps8Info, m_as8Info);
    }
}

void CLog::Record(s8 *ps8LogFile)
{    
    if (ps8LogFile) Record2File(ps8LogFile);
    else Print();    
}

void CLog::Record2File(s8 *ps8LogFile)
{
    FILE *pf = NULL;
    pf = fopen(ps8LogFile, "ab");
    if (NULL == pf) return;
    fprintf(pf, "%s, Code=%x\n", m_as8Info, m_u32Code);
    fclose(pf);
}

void CLog::Print()
{
    printf("%s, Code=%x\n", m_as8Info, m_u32Code);
}