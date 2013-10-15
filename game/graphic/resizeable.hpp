#ifndef resizeable_hpp
#define resizeable_hpp

namespace graphic
{
    class resizeable
    {
    public:
        virtual void setSize( float x, float y ) = 0;
        virtual void setScale( float scale ) = 0;
    };
}

#endif // resizeable_hpp
