#include <iostream>

using  namespace std;

class Shape{
    string name;
    public:
    Shape(){}
    Shape(string name) : name(name){}
    string get_name(){
        return this->name;
    }
    virtual double area() const{
        return 0;
    }
};

class Square : public Shape{
    double a;
    public:
    Square(double a) : Shape("SQUARE"), a(a) {}
    double area() const{
        return a*a;
    }
};

class Triangle : public Shape{
    double a;
    double b;
    public:
    Triangle(double a, double b) : Shape("TRIANGLE"), a(a), b(b) {}
    double area() const{
        return (a*b)/2;
    }
};

void sprint(Shape s){
    cout << s.get_name() << ": " << s.area() <<endl;
}

int main(){
    Triangle t = {3,4};
    Square s = {2};

    sprint(t);
    sprint(s);

    return 0;
}