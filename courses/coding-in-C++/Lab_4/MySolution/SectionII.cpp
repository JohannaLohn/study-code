#include <iostream>
#include <cmath> // for M_PI

class Shape {
public:
    virtual double area() const { return 0.0; }
    virtual ~Shape() {}
};

class Circle: public Shape{
    private:
    double radius;

    public:
    Circle(double radius) : radius (radius) {} //constructor
    double area() const override
    


}

class Rectangle: public Shape{
    private:
    double width, height;

    public:
    Rectangle(double width, double height): width(width), height(height) {};


}

int main




















class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

int main() {
    Circle c(5.0);
    Rectangle r(4.0, 6.0);
    
    std::cout << "Circle area: " << c.area() << std::endl;
    std::cout << "Rectangle area: " << r.area() << std::endl;
    
    return 0;
}