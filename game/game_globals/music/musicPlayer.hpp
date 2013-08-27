#ifndef musicPlayer_hpp
#define musicPlayer_hpp

#include <string>
#include <iostream>
#include <game_globals/music/playlist.hpp>
#include <SFML/Audio.hpp>


namespace audio
{
    class musicPlayer
    {
    private:
        musicPlayer() {};
        musicPlayer( const musicPlayer & conf ) {};
        musicPlayer * operator=( const musicPlayer & conf ) {};
        ~musicPlayer() {};
    public:
        static musicPlayer & getPlayer() { static musicPlayer instance; return instance; };


        void setFadeoutValue( const float secToEnd ) { if( secToEnd != 0 && secToEnd != 0.0 ) _fadeout = secToEnd; };
        const sf::Music::Status getCurrentSongStatus() const { if( _activeSong != NULL ) return _activeSong->getStatus(); };
        void update()
        {
            if( getCurrentSongStatus() == sf::Music::Stopped )
            {
                if( _activePlaylist->next < _activePlaylist->songList.size() )
                {
                    _activeSong = NULL;
                    delete _activeSong;
                    _activeSong = new sf::Music();
                    if( !_activeSong->openFromFile( _activePlaylist->songList[ _activePlaylist->next ] ) )
                    {
                        //error
                    }
                    if( _fadeout == 0 || _fadeout == 0.0 )
                    {
                        _activeSong->play();
                    }
                    else
                    {
                        _activeSong->setVolume( 0.0 );
                        _activeSong->play();
                    }
                }
                else
                {
                    _activePlaylist->next = 0;
                    update();
                    return;
                }
            }
            else if( getCurrentSongStatus() == sf::Music::Playing )
            {

            }
        };

    private:
        float _fadeout = 0.0;
        sf::Music * _activeSong = NULL;
        audio::playlist * _activePlaylist = NULL;
    };
}
#endif // musicPlayer_hpp