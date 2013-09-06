#ifndef playlist_hpp
#define playlist_hpp

#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <vector>

namespace audio
{
    class musicPlayer;
    class playlist
    {
    friend class musicPlayer;
    public:
        playlist( const std::string myName ) { name = myName; };
        ~playlist() {};

        void addSong( const std::string filename )
        {
            songList.push_back( filename );
        };

        void removeSong( const std::string filename )
        {
            if( songList.size() )
            {
                for( unsigned int i = 0; i < songList.size(); i++ )
                {
                    if( songList[i] == filename )
                        songList.erase( songList.begin() + i );
                }
            }
        };

    private:
        std::string name;
        std::vector< std::string > songList;
        unsigned int next = 0;
    };
}

#endif // playlist_hpp
