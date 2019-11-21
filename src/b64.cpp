#include "b64.hpp"

#include <iostream>
#include <sstream>

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>


namespace b64
{

std::string encode(std::string const & input)
{
    using namespace boost::archive::iterators;

    typedef
        base64_from_binary<
            transform_width<std::string::const_iterator, 6, 8>
        > base64_enc;

    std::stringstream ss;

    try
    {
        std::copy(
            base64_enc(input.begin()),
            base64_enc(input.end()),
            std::ostream_iterator<char>(ss)
        );
    }
    catch(boost::archive::iterators::dataflow_exception const & e)
    {
        std::cerr << "exception: " << e.what() << "\n";

        ss.str(std::string());
        ss.clear();
    }

    return ss.str();
}

std::string decode(std::string const & input)
{
    using namespace boost::archive::iterators;

    typedef
        transform_width<
            binary_from_base64<std::string::const_iterator>, 8, 6>
        base64_dec;

    std::stringstream ss;

    try
    {
        std::copy(
            base64_dec(input.begin()),
            base64_dec(input.end()),
            std::ostream_iterator<char>(ss)
        );
    }
    catch(boost::archive::iterators::dataflow_exception const & e)
    {
        std::cerr << "exception: " << e.what() << "\n";

        ss.str(std::string());
        ss.clear();
    }

    return ss.str();
}

}
