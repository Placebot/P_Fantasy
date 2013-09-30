#ifndef serializeable_hpp
#define serializeable_hpp

#include <fileUtilities/save.hpp>
#include <fileUtilities/load.hpp>

namespace file
{
    class serializeable
    {
    public:
        virtual const bool save( const std::string path, unsigned int mode = 0 ) = 0;
        virtual const bool load( const std::string path, bool directFromString = false ) = 0;
    };
}

#endif // serializeable_hpp
