#ifndef button_hpp
#define button_hpp

#include <gameGlobals/extend.hpp>
#include <SFML/Graphics.hpp>

namespace gui
{
    class button : public extend::drawable
    {
    public:
        button( const std::string title ) { _myName = title; };
        ~button() {};

        virtual void draw( sf::RenderWindow & Win ) { Win.draw( _me ); };

        const bool isUnderMouse()
        {
            if( _me.getGlobalBounds().contains( sf::Mouse::getPosition().x, sf::Mouse::getPosition().y ) )
                return true;
            else
                return false;
        };

        void setTexture( sf::Texture & newTexture ) { _myTexture = &newTexture; _me.setTexture( *_myTexture ); };
        void setPosition( const float x, const float y ) { _me.setPosition( x, y ); };

    private:
        std::string _myName = "NONE";

        sf::Sprite _me;
        sf::Texture * _myTexture = NULL;
    };
}

#endif // button_hpp
