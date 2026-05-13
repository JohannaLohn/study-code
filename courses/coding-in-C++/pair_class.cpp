// voir correction !!!!!!

#include <iostream>
#include <string>

template <typename Wert1, typename Wert2>

class Pair : public Base<int> // a voir ce que ca change.
{

private:
    Wert1 first; //can change first and second for another word.
    Wert2 second;

public:
    Pair(const Wert1& firstValue, const Wert2& secondValue) // just Wert1 first oder mit const und & nach Wert
        : first(firstValue), second(secondValue) {}


    const Wert1& getFirst() const {
        return first;
    }

    const Wert2& getSecond() const {
        return second;
    }

    void setFirst(const Wert1& value) {
        first = value;
    }

    void setSecond(const Wert2& value) {
        second = value;
    }
};

int main() {
    Pair<int, std::string> p(42, "Hallo");
    std::cout << "Erster Wert: " << p.getFirst() << "\n";
    std::cout << "Zweiter Wert: " << p.getSecond() << "\n";

    p.setFirst(100);
    p.setSecond("Welt");
    std::cout << "Nach Set: " << p.getFirst() << ", " << p.getSecond() << "\n";

    return 0;
}
