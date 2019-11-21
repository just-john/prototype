#ifndef b64_hpp
#define b64_hpp

#include <string>

namespace b64
{

std::string encode(std::string const & input);
std::string decode(std::string const & input);

}

#endif