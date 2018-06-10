#ifndef WINCLI_CONSOLEWINDOW_HPP
#define WINCLI_CONSOLEWINDOW_HPP

#include <Windows.h>

namespace wc {

    class ConsoleWindow
    {
        HANDLE consoleHandle;

    public:
        ConsoleWindow(HANDLE chdl) : consoleHandle{ chdl } {}

    };
} // namespace wc

#endif // guard : WINCLI_CONSOLEWINDOW_HPP