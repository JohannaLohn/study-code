//A revoir : ConfigLoader.cpp vom Prof.
#include <iostream>
#include <stdexcept>

class ConfigError: public std::

class ConfigLoader {
    public:
    bool loaf (std::string filename){
        if (filename.empty())
        {
            throw std::invalid 
        }

        if (filename.lenght() < 4 
    }


}

int main{} {

    ConfigLoader loader;

    try {
        cout << loaf("") << ;
    }
    catch (const exception& error){
        cout << "Error:" << error.what();
    }
    return 0 {}
    }

}