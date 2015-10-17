#ifndef _LOG_H_
#define _LOG_H_

#include "basetype.h"
#define LOG_MAX_LEN 1024

#define ERROR_BASE   0x80000000
#define WARNING_BASE 0x40000000
#define INFO_BASE    0x20000000

#define ERROR_USER   ERROR_BASE   + 0x0fffffff
#define WARNING_USER WARNING_BASE + 0x0fffffff
#define INFO_USER    INFO_BASE    + 0x0fffffff


enum ELogLevel
{
    ELOG_ERROR = 0x1000,
    ELOG_WARNING = 0x2000,
    ELOG_INFO = 0x3000
};

class CLog
{
public:
    CLog(u32 u32Code, s8 *ps8Info);
    ~CLog();

    ELogLevel GetLogLevel();
    void Set(u32 u32Code, s8 *ps8Info);
    void Get(u32 &u32Code, s8 *&ps8Info);
    void Record(s8 *ps8LogFile = NULL);
    
private:
    u32 m_u32Code;
    s8 m_as8Info[LOG_MAX_LEN];
};
#endif
