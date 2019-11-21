#include <iostream>
#include <string>

#include "b64.hpp"

namespace
{
std::string const quick_fox =
    "The quick brown fox jumps over the lazy dog.";
}


int main(int argc, char const *argv[])
{
    std::cout
        << b64::decode(b64::encode(quick_fox)) << "\n"
        << b64::encode(quick_fox) << "\n";

    return 0;
}