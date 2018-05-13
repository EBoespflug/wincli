#pragma once
#ifndef WINCLI_WINCOLOR_HPP
#define WINCLI_WINCOLOR_HPP

#include <windows.h>
#include <iostream>

namespace wc {

    enum class color { current = -1, black = 0, dark_blue, dark_green, dark_cyan, dark_red, dark_purple, dark_yellow, dark_gray, gray, blue, green, cyan, red, purple, yellow, white};

    constexpr WORD foreground_blue = FOREGROUND_BLUE;
    constexpr WORD foreground_green = FOREGROUND_GREEN;
    constexpr WORD foreground_red = FOREGROUND_RED;
    constexpr WORD foreground_intensity = FOREGROUND_INTENSITY;
    constexpr WORD background_blue = BACKGROUND_BLUE;
    constexpr WORD background_green = BACKGROUND_GREEN;
    constexpr WORD background_red = BACKGROUND_RED;
    constexpr WORD background_intensity = BACKGROUND_INTENSITY;

    namespace _internal {

        inline auto get_std_handle(std::ostream& os)
        {
            if (&os == &std::cout)
                return GetStdHandle(STD_OUTPUT_HANDLE);
            if (&os == &std::cerr || &os == &std::clog)
                return GetStdHandle(STD_ERROR_HANDLE);
            return HANDLE{};
        }
    }

    /**
     */
    inline void set_color(std::ostream& os, color text_color, color bg_color)
    {
        auto h_stream = _internal::get_std_handle(os);
        
        CONSOLE_SCREEN_BUFFER_INFO infos;
        GetConsoleScreenBufferInfo(h_stream, &infos);

        if (text_color != color::current)
        {
            auto attrs = (WORD)text_color;
            infos.wAttributes &= (WORD)0xF0;
            infos.wAttributes |= static_cast<WORD>(text_color);
        }
        if (bg_color != color::current)
        {
            auto attrs = (WORD)text_color;
            infos.wAttributes &= (WORD)0x0F;
            infos.wAttributes |= (static_cast<WORD>(bg_color) << 4);
        }

        SetConsoleTextAttribute(h_stream, static_cast<WORD>(infos.wAttributes));
    }

    inline void set_color(std::ostream& os, color text_color)
    {
        set_color(os, text_color, color::current);
    }

    inline void set_bg_color(std::ostream& os, color bg_color)
    {
        set_color(os, color::current, bg_color);
    }

    namespace helpers {
        // Foreground.

        inline std::ostream& black(std::ostream& os) {
            set_color(os, color::black, color::current);
            return os;
        }
        inline std::ostream& dark_blue(std::ostream& os) {
            set_color(os, color::dark_blue, color::current);
            return os;
        }
        inline std::ostream& dark_green(std::ostream& os) {
            set_color(os, color::dark_green, color::current);
            return os;
        }
        inline std::ostream& dark_cyan(std::ostream& os) {
            set_color(os, color::dark_cyan, color::current);
            return os;
        }
        inline std::ostream& dark_red(std::ostream& os) {
            set_color(os, color::dark_red, color::current);
            return os;
        }
        inline std::ostream& dark_purple(std::ostream& os) {
            set_color(os, color::dark_purple, color::current);
            return os;
        }

        inline std::ostream& dark_yellow(std::ostream& os) {
            set_color(os, color::dark_yellow, color::current);
            return os;
        }

        inline std::ostream& dark_gray(std::ostream& os) {
            set_color(os, color::dark_gray, color::current);
            return os;
        }

        inline std::ostream& gray(std::ostream& os) {
            set_color(os, color::gray, color::current);
            return os;
        }

        inline std::ostream& blue(std::ostream& os) {
            set_color(os, color::blue, color::current);
            return os;
        }
        
        inline std::ostream& green(std::ostream& os) {
            set_color(os, color::green, color::current);
            return os;
        }

        inline std::ostream& cyan(std::ostream& os) {
            set_color(os, color::cyan, color::current);
            return os;
        }

        inline std::ostream& red(std::ostream& os) {
            set_color(os, color::red, color::current);
            return os;
        }

        inline std::ostream& purple(std::ostream& os) {
            set_color(os, color::purple, color::current);
            return os;
        }

        inline std::ostream& yellow(std::ostream& os) {
            set_color(os, color::yellow, color::current);
            return os;
        }

        inline std::ostream& white(std::ostream& os) {
            set_color(os, color::white, color::current);
            return os;
        }

        // Background.

        inline std::ostream& bg_black(std::ostream& os) {
            set_color(os, color::current, color::black);
            return os;
        }

        inline std::ostream& bg_dark_blue(std::ostream& os) {
            set_color(os, color::current, color::dark_blue);
            return os;
        }

        inline std::ostream& bg_dark_green(std::ostream& os) {
            set_color(os, color::current, color::dark_green);
            return os;
        }

        inline std::ostream& bg_dark_cyan(std::ostream& os) {
            set_color(os, color::current, color::dark_cyan);
            return os;
        }

        inline std::ostream& bg_dark_red(std::ostream& os) {
            set_color(os, color::current, color::dark_red);
            return os;
        }
        inline std::ostream& bg_dark_purple(std::ostream& os) {
            set_color(os, color::current, color::dark_purple);
            return os;
        }

        inline std::ostream& bg_dark_yellow(std::ostream& os) {
            set_color(os, color::current, color::dark_yellow);
            return os;
        }

        inline std::ostream& bg_dark_gray(std::ostream& os) {
            set_color(os, color::current, color::dark_gray);
            return os;
        }

        inline std::ostream& bg_gray(std::ostream& os) {
            set_color(os, color::current, color::gray);
            return os;
        }

        inline std::ostream& bg_blue(std::ostream& os) {
            set_color(os, color::current, color::blue);
            return os;
        }

        inline std::ostream& bg_green(std::ostream& os) {
            set_color(os, color::current, color::green);
            return os;
        }

        inline std::ostream& bg_cyan(std::ostream& os) {
            set_color(os, color::current, color::cyan);
            return os;
        }

        inline std::ostream& bg_red(std::ostream& os) {
            set_color(os, color::current, color::red);
            return os;
        }

        inline std::ostream& bg_purple(std::ostream& os) {
            set_color(os, color::current, color::purple);
            return os;
        }

        inline std::ostream& bg_yellow(std::ostream& os) {
            set_color(os, color::current, color::yellow);
            return os;
        }

        inline std::ostream& bg_white(std::ostream& os) {
            set_color(os, color::current, color::white);
            return os;
        }
    }

    template <class Elem, class Traits>
    std::basic_ostream<Elem, Traits>&
        operator<<(std::basic_ostream<Elem, Traits>& i, color& c)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdout, c.m_color);
        return i;
    }
}

#endif // guard : WINCLI_WINCOLOR_HPP