#pragma once
#ifndef WINCLI_WINCLI_HPP
#define WINCLI_WINCLI_HPP

#define WINCLI_LIB

#	ifdef _WIN32

#include <windows.h>

#include "colors\wincolor.hpp"
#include "winpos.hpp"
#include "ConsoleWindow.h"

namespace wc {
}

#	endif // ifdef _WIN32
#endif // guard : WINCLI_WINCLI_HPP