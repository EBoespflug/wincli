#include "../src/wincli.hpp"

#include <iostream>


int main(int argc, char* argv[])
{
	SetConsoleTitle("Color list");

	for (int s = (int)wc::color::black; s <= (int)wc::color::white; ++s) {
		wc::set_color(std::cout, (wc::color)s, wc::color::black);
		std::cout << "color " << (int)s << "\n";
	}

    for (int s = (int)wc::color::black; s <= (int)wc::color::white; ++s) {
        wc::set_color(std::cout, wc::color::black, static_cast<wc::color>(s));
        std::cout << "color " << (int)s << "\n";
    }

	system("pause");
}