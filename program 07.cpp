#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual void draw() const = 0;

    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        cout << "Drawing Circle with radius "
             << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
        : length(l), width(w) {}

    void draw() const override {
        cout << "Drawing Rectangle "
             << length << " x " << width << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h)
        : base(b), height(h) {}

    void draw() const override {
        cout << "Drawing Triangle with base "
             << base << " and height " << height << endl;
    }
};

int main() {
    vector<Shape*> shapes;

    Circle c(5);
    Rectangle r(10, 6);
    Triangle t(8, 4);

    shapes.push_back(&c);
    shapes.push_back(&r);
    shapes.push_back(&t);

    cout << "=== CAD Drawing System ===" << endl;

    for (const auto& shape : shapes) {
        shape->draw();
    }

    return 0;
}
