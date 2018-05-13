#include "../src/wincli.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
	SetConsoleTitle("Color list");

    using namespace wc::helpers;
    using std::cout;

    cout << "Gold  : " << yellow << "500" << white << ".\n";
    cout << "Wood  : " << dark_green << "350" << white << ".\n";
    cout << "Stone : " << gray << "16" << white << ".\n";
    cout << "Water : " << blue << "2000" << white << ".\n";
}