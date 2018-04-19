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
        Point a;
        double r;
    public:
        Circle(Point a, double r) {
            this->a = a;
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
            std::cout << "Circle: (" << a.getX() << " , " << a.getY() << ")\n";
            std::cout << "L = " << getL() << "\n";
            std::cout << "S = " << getS() << "\n";
        }
};

class Line: public Point {
    private:
        Point a;
    public:
        Line(Point a,Point b): Point(b) {
            this->a = a;
        }
        Line(const Line &obj): Point(obj)
        {
            a = obj.a;
        }
        
        ~Line() {}
        
        Point getA() {
            return a;
        }
        
        void setA(Point a) {
            this->a = a;
        }
        
        double lineLength() {
            double L = sqrt(pow(a.getX() - getX(), 2) + pow(a.getY() - getY(), 2)); 
            return L;
        }
        void printCoordinate() {
            std::cout << "\n";
            double k = (getY() - a.getY()) / (getX() - a.getX());
            for (int i = a.getX() + 1; i < x; ++i) {
                std::cout << "(" << i << " , " << k * (i - a.getX()) + a.getY() << ")\n";
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
        Point a, b, c;
    public:
        Triangle(Point a, Point b, Point c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        Triangle(const Triangle &obj)
        {
            a = obj.a;
            b = obj.b;
            c = obj.c;
        }
        
        ~Triangle() {}
        
        Point getA() {
            return a;
        }
        Point getB() {
            return b;
        }
        
        void setA(Point a) {
            this->a = a;
        }
        void setB(Point b) {
            this->b = b;
        }
        
        double Length(Point p1, Point p2) {
            double L = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2)); 
            return L;
        }
        double Area() {
            double p = (Length(a, b) + Length(b, c) + Length(c, a)) / 2;
            return std::sqrt(p * (p - Length(a, b)) * (p - Length(b, c)) * (p - Length(c, a)));
        }
        double Perimeter() {
            return Length(a, b) + Length(b, c) + Length(c, a);
        }
};

int main() {
    double x1, y1, x2, y2, x3, y3, r;
    std::cout << "Input R: ";
    std::cin >> r;
    std::cout << "Input x1: ";
    std::cin >> x1;
    std::cout << "Input y1: ";
    std::cin >> y1;
    std::cout << "Input x2: ";
    std::cin >> x2;
    std::cout << "Input y2: ";
    std::cin >> y2;
    std::cout << "Input x3: ";
    std::cin >> x3;
    std::cout << "Input y3: ";
    std::cin >> y3;
    
    Point p1(x1, y1);
    Point p2(x2, y2);
    Point p3(x3, y3);
    std::cout << "\n";

    Rectangle obj1(p1, p2);
    std::cout << "Rectangle Area(S): " << obj1.recArea() << "\n";
    std::cout << "Rectangle Perimeter(P): " << obj1.recPerimeter() <<"\n";
    obj1.print();
    std::cout << "\n";

    Circle obj2(p1, r);
    obj2.print();
    std::cout << "\n";
    
    Triangle obj3(p1, p2, p3);
    std::cout << "Triangle Area(S): " << obj3.Area() << "\n";
    std::cout << "Triangle Perimeter(P): " << obj3.Perimeter() << "\n\n";

    Line obj4(p1, p2);
    std::cout << "Line Length: " << obj4.lineLength() << "\n";
    
    std::cout << "Line Coordinates";
    obj4.printCoordinate();

    return 0;   
}