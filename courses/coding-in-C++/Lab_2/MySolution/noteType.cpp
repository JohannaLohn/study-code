#include <iostream>
#include <string>

class Note
{
private:
    std::string* text;

public:
    Note(std::string text_input)
    {
        text = new std::string;
        *text = text_input;
    }

    Note(const Note& otherNote)
    {
        text = new std::string;
        *text = *otherNote.text;
    }   

    ~Note()
    {
        delete text;
        text = nullptr;
        std::cout << "Memory released" << std::endl;
    }


    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); // ignore remaining input
    std::cin >> std::ws; // ignore leading whitespace