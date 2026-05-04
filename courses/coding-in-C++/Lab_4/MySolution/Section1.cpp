//part 1 should be done in 10 minutes btw.
#include <iostream>
#include <cmath>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D() //default constructor
        : x(0.0), y(0.0)
    {
    }

    Vector2D(double xValue, double yValue) //parameterized constructor.
        : x(xValue), y(yValue)
    {
    }

    double getX() const //getter methods. const heisst wir geben nur was zurrück und ändern das objekt nicht.
    {
        return x;
    }

    double getY() const // wichtig deshalb constant machen.
    {
        return y;
    }

    void print() const
    {
        std::cout << "Vector2D(" << x << ", " << y << ")\n";
    }

    double getMagnitude() const
    {
        return std::sqrt(x * x + y * y);
    }

    double length(int precision) const
    {
        double exactLength = std::sqrt(x * x + y * y);
        double factor = std::pow(10.0, precision);
        return std::round(exactLength * factor) / factor;
    }
};

int main()
{
    Vector2D defaultVector;
    Vector2D customVector(3.5, -2.1);

    std::cout << "Default vector: ";
    defaultVector.print();

    std::cout << "Custom vector: ";
    customVector.print();

    std::cout << "Custom X = " << customVector.getX() << ", Y = " << customVector.getY() << "\n";

    std::cout << "Exact length of custom vector: " << customVector.length() << "\n";
    std::cout << "Length rounded to 2 decimal places: " << customVector.length(2) << "\n";
    std::cout << "Length rounded to 4 decimal places: " << customVector.length(4) << "\n";

    return 0;
}
