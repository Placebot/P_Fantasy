#ifndef serializeable_hpp
#define serializeable_hpp

#include <file_utilities/save.hpp>
#include <file_utilities/load.hpp>

namespace file
{
    class serializeable
    {
    public:
        virtual const bool save( const std::string path ) = 0;
        virtual const bool load( const std::string path, bool directFromString = false ) = 0;
    };
}

#endif // serializeable_hpp
