#pragma once
#include <iostream>
using namespace std;

class Figure {
public:
    virtual double calculateArea() const = 0; 
    virtual double calculatePerimeter() const = 0; 
};

class Rectangle : public Figure {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
};

class Circle : public Figure {
private:
    double radius;
    const double PI = 3.14159;
public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * PI * radius;
    }
};

class Trapezium : public Figure {
private:
    double base1;
    double base2;
    double height;
public:
    Trapezium(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}

    double calculateArea() const override {
        return (base1 + base2) * height / 2;
    }

    double calculatePerimeter() const override {
       
        return base1 + base2 + 2 * sqrt((base1 - base2) * (base1 - base2) / 4 + height * height);
    }
};
class Task2 {
public:
    static void run() {
        
        Rectangle rectangle(5, 10);
        Circle circle(3);
        Trapezium trapezium(3, 7, 4);

        cout << "Rectangle: Area = " << rectangle.calculateArea() << ", Perimeter = " << rectangle.calculatePerimeter() << endl;
        cout << "Circle: Area = " << circle.calculateArea() << ", Perimeter = " << circle.calculatePerimeter() << endl;
        cout << "Trapezium: Area = " << trapezium.calculateArea() << ", Perimeter = " << trapezium.calculatePerimeter() << endl;
    }
};