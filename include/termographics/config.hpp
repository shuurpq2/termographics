#pragma once

namespace termg
{

enum class OS
{
    WINDOWS,
    LINUX
};

class Config
{
public:
    static OS get_current_os() { return m_os; }

private:
    inline static const OS m_os =
    #if defined(_WIN32)
        OS::WINDOWS;
    #elif defined(__linux__)
        OS::LINUX;
    #endif
};
}