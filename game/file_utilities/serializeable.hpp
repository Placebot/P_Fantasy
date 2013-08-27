#ifndef serializeable_hpp
#define serializeable_hpp

#include <file_utilities/save.hpp>
#include <file_utilities/load.hpp>

namespace file
{
    class serializeable
    {
    private:
        ~serializeable() {};
        serializeable() {};
        serializeable * operator=( const serializeable & ) {};
        serializeable(const serializeable &) {};
    public:
        virtual bool save() = 0;
        virtual bool load( const std::string path, bool directFromString = false ) = 0;
    };
}

#endif // serializeable_hpp
