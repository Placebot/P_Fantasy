#ifndef save_hpp
#define save_hpp

#include <fstream>

namespace file
{
    class save;
    namespace _private
    {
        enum TYPE
        {
            INT,
            SHORT_INT,
            UNSIGNED_INT,
            CONST_UNSIGNED_INT,
            LONG_INT,
            LONG_UNSIGNED_INT,
            BOOL,
            FLOAT,
            DOUBLE,
            LONG_DOUBLE,
            STRING
        };

        class _data
        {
            friend class file::save;
            _data( int &value, std::string &name ) { _value = &value; _name = &name; _type = INT; };
            _data( short int &value, std::string &name ) { _value = &value; _name = &name; _type = SHORT_INT; };
            _data( unsigned int &value, std::string &name ) { _value = &value; _name = &name; _type = UNSIGNED_INT; };
            _data( long int &value, std::string &name ) { _value = &value; _name = &name; _type = LONG_INT; };
            _data( long unsigned int &value, std::string name ) { _value = &value; _name = &name; _type = LONG_UNSIGNED_INT; };
            _data( bool &value, std::string &name ) { _value = &value; _name = &name; _type = BOOL; };
            _data( float &value, std::string &name ) { _value = &value; _name = &name; _type = FLOAT; };
            _data( double &value, std::string &name ) { _value = &value; _name = &name; _type = DOUBLE; };
            _data( long double &value, std::string &name ) { _value = &value; _name = &name; _type = LONG_DOUBLE; };
            _data( std::string &value, std::string &name ) { _value = &value; _name = &name; _type = STRING; };

            void *_value = NULL;
            const std::string *_name = NULL;
            TYPE _type;
        };
    }

    class save
    {
    public:
        save() {};
        ~save() {};

        void addData( int &value, std::string &name ) { ToSave.push_back( new _private::_data( value, name ) ); };
        void addData( short int &value, std::string &name ) { ToSave.push_back( new _private::_data( value, name ) ); };
        void addData( unsigned int &value, std::string &name ) { ToSave.push_back( new _private::_data( value, name ) ); };
        void addData( long int &value, std::string &name ) { ToSave.push_back( new _private::_data( value, name ) ); };
        void addData( long unsigned int &value, std::string &name ) { ToSave.push_back( new _private::_data( value, name ) ); };
        void addData( bool &value, std::string &name ) { ToSave.push_back( new _private::_data( value, name ) ); };
        void addData( float &value, std::string &name ) { ToSave.push_back( new _private::_data( value, name ) ); };
        void addData( double &value, std::string &name ) { ToSave.push_back( new _private::_data( value, name ) ); };
        void addData( long double &value, std::string &name ) { ToSave.push_back( new _private::_data( value, name ) ); };
        void addData( std::string &value, std::string &name ) { ToSave.push_back( new _private::_data( value, name ) ); };

        void clearSaveData() { unsigned int i = ToSave.size(); if( i ){ do { delete ToSave[i]; i--; }while( i < 0 ); } };
        void deleteData( const void *ptrValue ) { for( unsigned int i = 0; i < ToSave.size(); i++){ if( ToSave[i]->_value == ptrValue ) ToSave.erase( ToSave.begin() + i ); } };
        void setKeychar( const char &keyword ) { _keyword = keyword; };

        bool saveToFile( const std::string &filename ) const
        {
            std::ofstream out;
            out.open( filename.c_str() );
            if( out.good() )
            {
                _private::_data *temp;
                for( unsigned int i = 0; i < ToSave.size(); i++ )
                {
                    temp = ToSave[i];
                    out << *temp->_name;
                    out << this->_keyword;
                    switch( temp->_type )
                    {
                    case file::_private::TYPE::INT:
                        out << *( reinterpret_cast<int*>( temp->_value ) );
                        break;

                    case file::_private::TYPE::SHORT_INT:
                        out << *( reinterpret_cast<short int*>( temp->_value ) );
                        break;

                    case file::_private::TYPE::UNSIGNED_INT:
                        out << *( reinterpret_cast<unsigned int*>( temp->_value ) );
                        break;

                    case file::_private::TYPE::CONST_UNSIGNED_INT:
                        out << *( reinterpret_cast< const unsigned int*>( temp->_value ) );
                        break;

                    case file::_private::TYPE::LONG_INT:
                        out << *( reinterpret_cast<long int*>( temp->_value ) );
                        break;

                    case file::_private::TYPE::LONG_UNSIGNED_INT:
                        out << *( reinterpret_cast<long unsigned int*>( temp->_value ) );
                        break;

                    case file::_private::TYPE::BOOL:
                        out << *( reinterpret_cast<bool*>( temp->_value ) );
                        break;

                    case file::_private::TYPE::FLOAT:
                        out << *( reinterpret_cast<float*>( temp->_value ) );
                        break;

                    case file::_private::TYPE::DOUBLE:
                        out << *( reinterpret_cast<double*>( temp->_value ) );
                        break;

                    case file::_private::TYPE::LONG_DOUBLE:
                        out << *( reinterpret_cast<long double*>( temp->_value ) );
                        break;

                    case file::_private::TYPE::STRING:
                        out << *( reinterpret_cast<std::string*>(temp->_value ) );
                        break;
                    }
                    out << this->_keyword;

                }
                out.close();
                return true;
            }
            else
                return false;
        };

    private:
        std::vector< _private::_data* > ToSave;
        char _keyword = ';';
    };
}

#endif // save_hpp
