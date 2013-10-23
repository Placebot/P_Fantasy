#ifndef styleable_hpp
#define styleable_hpp

namespace graphic
{
    class style;
    class styleable
    {
    public:
        virtual const bool setStyle( const graphic::style style ) = 0;
    };
}
#endif // styleable_hpp
