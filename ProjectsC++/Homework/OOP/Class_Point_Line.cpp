#include <iostream>
#include <cmath>

class Point {
    protected:
        double x, y;
    public:
        Point(double x = 0, double y = 0) 
        {
            this->x = x;
            this->y = y;
        }
        Point(const Point &obj) 
        {
            x = obj.x;
            y = obj.y;
        }
        
        ~Point() {}
        
        double getX() {
            return x;
        }
        double getY() {
            return y;
        }
        
        void setX(double x) {
            this->x = x; 
        }
        void setY(double y) {
            this->y = y;
        }
        
        void printPoint() {
            std::cout << " x = "<< x << "  " << "y = " << y;
        }
};

class Circle: public Point {
    private:
        double r;
    public:
        Circle(double x = 0, double y = 0, double r = 1): Point(x, y) {
            this->r = r;
        }
        Circle (const Circle &obj): Point(obj)
        {
            r = obj.r;
        }
        
        ~Circle() {}
        
        double getR() {
            return r;
        }
        double getL() {
            return 2 * M_PI * r;
        }
        double getS() {
            return r * r * M_PI;
        }
        
        void setR(double r) {
            this->r = r;
        }
        
        void print() {
            std::cout << "Circle: (" << getX() << " , " << getY() << ")\n";
            std::cout << "L = " << getL() << "\n";
            std::cout << "S = " << getS() << "\n";
        }
};

class Line: public Point {
    private:
        double a, b;
    public:
        Line(double a = 0, double b = 0, double x = 0, double y = 0): Point(x, y) 
        {
            this->a = a;
            this->b = b;
        }
        Line(const Line &obj): Point(obj)
        {
            a = obj.a;
            b = obj.b;
        }
        
        ~Line() {}
        
        double getB() {
            return b;
    	}
        double getA() {
            return a;
        }
        
        void setA(double a) {
            this->a = a;
        }
        void setB(double b) {
            this->b = b;
        }
        
        double line_L() {
            double L = sqrt(pow(getA() - getX(), 2) + pow(getB() - getY(), 2)); 
            return L;
        }
        void foo() {
            std::cout << "\n";
            double k = (getY() - b) / (getX() - a);
            for (int i = a + 1; i < x; ++i) {
                std::cout << "(" << i << " , " << k * (i - a) + b << ")\n";
            }
            std::cout << "\n";
        }
};

class Rectangle: public Point {
    private:
        Point p1;
    public:
        Rectangle(Point p1, Point b): Point(b)
        {
            this->p1 = p1;
        }
        Rectangle(const Rectangle &obj): Point(obj)
        {
            p1 = obj.p1;
        }
        
        ~Rectangle() {}
        
        Point getP1() {
            return p1;
        }
        
        void setP1(Point p1) {
            this->p1 = p1;
        }
        
        double length() {
            return  std::abs( p1.getX() - Point::getX() );
        }
        double width() {
            return  std::abs( p1.getY() - Point::getY() );
        }
        double recArea() {
            return length() * width();
        }
        double recPerimeter() {
            return 2 * (length() + width());
        }
        void print() {
            for (int i = 0; i < length(); ++i) {
                for (int i = 0; i < width(); ++i) {
                    std::cout << "* ";
                }
                std::cout << '\n';
            }
        }
};

class Triangle: public Point {
    private:
        double a, b, c;
    public:
        Triangle(double a = 4, double b = 4, double c = 4)
        {
            this->a = a;
            this->b = b;
            this->c = c;
            Point(0, 0);
            Point(a, 0);
            Point(a / 2, b);
        }
        Triangle(const Triangle &obj)
        {
            a = obj.a;
            b = obj.b;
            c = obj.c;
            Point(0, 0);
            Point(a, 0);
            Point(a / 2, b);
        }
        
        ~Triangle() {}
        
        double get_A() {
            return a;
        }
        double get_B() {
            return b;
        }
        double get_C() {
            return c;
        }
        
        void set_A(double a) {
            this->a = a;
        }
        void set_B(double b) {
            this->b = b;
        }
        void set_C(double c) {
            this->c = c;
        }
        double triArea() {
            double p = (get_A() + get_B() + get_C()) / 2;
            return sqrt(p * (p - get_A()) * (p - get_B()) * (p - get_C()));
        }
        double triPerimeter() {
            return get_A() + get_B() + get_C(); 
        }
};

int main() {
    double x1, y1, x2, y2;

    std::cout << "Input x1 : ";
    std::cin >> x1;
    std::cout << "Input y1 : ";
    std::cin >> y1;
    Point p1(x1, y1);
    std::cout << "Input x2 : ";
    std::cin >> x2;
    std::cout << "Input y2 : ";
    std::cin >> y2;
    Point p2(x2, y2);
    std::cout << "\n";

    Rectangle obj1(p1, p2);
    std::cout << "Rectangle Area(S): " << obj1.recArea() << "\n";
    std::cout << "Rectangle Perimeter(P): " << obj1.recPerimeter() <<"\n";
    obj1.print();
    std::cout << "\n";

    Circle obj2(x1, y1);
    obj2.print();
    std::cout << "\n";

    Triangle obj3;
    std::cout << "Triangle Area(S): " << obj3.triArea() << "\n";
    std::cout << "Triangle Perimeter(P): " << obj3.triPerimeter() << "\n";

    Line obj4(x1, y1, x2, y2);
    std::cout << "\nLine Coordinates";
    obj4.foo();

    return 0;   
}