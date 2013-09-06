#ifndef load_hpp
#define load_hpp

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>

namespace file
{
    class massLoad;
    namespace _private
    {
        class loadVec
        {
            friend class file::massLoad;
            loadVec() {};
            ~loadVec() {};

            int loadTextures()
            {
                if( !key.empty() )
                {
                    for( unsigned int i = 0; i < filename.size(); i++ )
                    {
                        try
                        {
                            texture.push_back( sf::Texture() );
                            if( !texture[i].loadFromFile( filename[i] ) )
                                throw i;
                        }
                        catch( unsigned int i )
                        {
                            return i;
                        }
                    }
                    return -1;
                }
                return -2;
            }

            std::vector< std::string > filename;
            std::vector< std::string > key;
            std::vector< sf::Texture > texture;
        };
    }

    class massLoad
    {
    public:
        massLoad() {};
        ~massLoad() {};

        bool load() { int result = _data.loadTextures(); if( result == -1 ) return true; else { _error = result; return false; } };
        const int getErrorI() { return _error; };

        void addEntry( std::string key, std::string filename ) { _data.filename.push_back( filename ); _data.key.push_back( key ); };
        //-------------
        std::string getFilename( const std::string key ) const { bool valid = false; unsigned int i = 0; for( i = 0; i < _data.key.size(); i++ ){ if( key == _data.key[i] ){ valid = true; break; } } if( valid ) return _data.filename[i]; else return ""; };
        std::string getKey( const sf::Texture & texture ) const { bool valid = false; unsigned int i = 0; for( i = 0; i < _data.key.size(); i++ ){ if( &texture == &_data.texture[i] ){ valid = true; break; } } if( valid ) return _data.key[i]; else return ""; };
        sf::Texture & getTexture( const std::string key ) { bool valid = false; unsigned int i = 0; for( i = 0; i < _data.key.size(); i++ ){ if( key == _data.key[i] ){ valid = true; break; } } if( valid ) return _data.texture[i]; };

        sf::Texture & operator[]( std::string key ) { return getTexture( key ); };
    private:
        file::_private::loadVec _data;
        int _error = -1;
    };

    class load
    {
    public:
        load( const std::string &filename, const char &keyword )
        {
            _keyword = keyword;
            std::fstream in;
            in.open( filename.c_str() );
            if( in.good() && !in.eof() )
            {
                std::getline( in, _data );
                in.close();
                std::stringstream ss;
                ss << _keyword;
                std::string temp;
                ss >> temp;
                _data_formatted = split( _data, temp);
            }
        };
        load( const std::string &filename )
        {
            std::fstream in;
            in.open( filename.c_str() );
            if( in.good() && !in.eof() )
            {
                std::getline( in, _data );
                in.close();
                std::stringstream ss;
                ss << _keyword;
                std::string temp;
                ss >> temp;
                _data_formatted = split( _data, temp );
            }
        };
        load() {};
        ~load() {};

        bool loadFromFile( const std::string &filename )
        {
            std::fstream in;
            in.open( filename.c_str() );
            if( in.good() && !in.eof() )
            {
                std::getline( in, _data );
                in.close();
                std::stringstream ss;
                ss << _keyword;
                std::string temp;
                ss >> temp;
                _data_formatted = split( _data, temp );
                return true;
            }
            else
                return false;
        };

        bool getData( int &toSet, std::string name ) const { int i = 0; while( true ){ if( _data_formatted[i] == name ) break; if( i >= _data_formatted.size() ) { i = -1; break; } i++; } if( i == -1 ) return false; else { std::stringstream ss; ss << _data_formatted[i+1]; ss >> toSet; return true; } };
        bool getData( short int &toSet, std::string name ) const { int i = 0; while( true ){ if( _data_formatted[i] == name ) break; if( i >= _data_formatted.size() ) { i = -1; break; } i++; } if( i == -1 ) return false; else { std::stringstream ss; ss << _data_formatted[i+1]; ss >> toSet; return true; } };
        bool getData( unsigned int &toSet, std::string name ) const { int i = 0; while( true ){ if( _data_formatted[i] == name ) break; if( i >= _data_formatted.size() ) { i = -1; break; } i++; } if( i == -1 ) return false; else { std::stringstream ss; ss << _data_formatted[i+1]; ss >> toSet; return true; } };
        bool getData( long int &toSet, std::string name ) const { int i = 0; while( true ){ if( _data_formatted[i] == name ) break; if( i >= _data_formatted.size() ) { i = -1; break; } i++; } if( i == -1 ) return false; else { std::stringstream ss; ss << _data_formatted[i+1]; ss >> toSet; return true; } };
        bool getData( unsigned long int &toSet, std::string name ) const { int i = 0; while( true ){ if( _data_formatted[i] == name ) break; if( i >= _data_formatted.size() ) { i = -1; break; } i++; } if( i == -1 ) return false; else { std::stringstream ss; ss << _data_formatted[i+1]; ss >> toSet; return true; } };
        bool getData( bool &toSet, std::string name ) const { int i = 0; while( true ){ if( _data_formatted[i] == name ) break; if( i >= _data_formatted.size() ) { i = -1; break; } i++; } if( i == -1 ) return false; else { std::stringstream ss; ss << _data_formatted[i+1]; ss >> toSet; return true; } };
        bool getData( float &toSet, std::string name ) const { int i = 0; while( true ){ if( _data_formatted[i] == name ) break; if( i >= _data_formatted.size() ) { i = -1; break; } i++; } if( i == -1 ) return false; else { std::stringstream ss; ss << _data_formatted[i+1]; ss >> toSet; return true; } };
        bool getData( double &toSet, std::string name ) const { int i = 0; while( true ){ if( _data_formatted[i] == name ) break; if( i >= _data_formatted.size() ) { i = -1; break; } i++; } if( i == -1 ) return false; else { std::stringstream ss; ss << _data_formatted[i+1]; ss >> toSet; return true; } };
        bool getData( long double &toSet, std::string name ) const { int i = 0; while( true ){ if( _data_formatted[i] == name ) break; if( i >= _data_formatted.size() ) { i = -1; break; } i++; } if( i == -1 ) return false; else { std::stringstream ss; ss << _data_formatted[i+1]; ss >> toSet; return true; } };

        void setKeychar( const char &keyword ) { _keyword = keyword; };

        std::vector< std::string > split( std::string str, std::string deliminator) ///! Zeke's code
        {
            std::vector< std::string > tokens;
            size_t pos = 0;
            while( true )
            {
                size_t nextPos = str.find(deliminator,pos);
                if(nextPos == str.npos) { tokens.push_back( std::string( str.substr( pos, nextPos - pos ) ) ); break; };
                tokens.push_back( std::string( str.substr( pos, nextPos - pos ) ) );
                pos = nextPos + 1;
            }
            return tokens;
        }; ///! Zeke's code
    private:
        std::string _data;
        std::vector< std::string > _data_formatted;
        char _keyword = ';';
    };
}

#endif // load_hpp
