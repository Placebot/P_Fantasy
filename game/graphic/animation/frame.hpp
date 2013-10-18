#ifndef frame_hpp
#define frame_hpp

class frame
{
public:
    frame( sf::Texture & myTexture ) { _myTexture = &myTexture; };
    frame() {};
    ~frame() {};

    sf::Texture & getTexture() { return *_myTexture; };
    sf::Sprite & getSprite() { return _me; };

    const float getTimePeriodSec() const { return _timePeriod; };
    void setTimePeriod( float newTime ) { _timePeriod = newTime; };

private:
    sf::Sprite _me;
    sf::Texture * _myTexture = NULL;

    float _timePeriod = 0.0;
};

#endif // frame_hpp
