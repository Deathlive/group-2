#include <iostream>
#include <cmath>

class Shape {
    public:
        virtual double getL() = 0;
        virtual double getS() = 0;
        virtual double getP() = 0;
};

class Point: public Shape {
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
        
        double distanceFrom(Point obj)
        {
            double dx = obj.x - x; 
            double dy = obj.y - y; 
            return(sqrt((dx*dx)+(dy*dy)));
        }
        void printPoint() {
            std::cout << " x = "<< x << "  " << "y = " << y;
        }
        virtual double getL() {
            std::cout << "Point does not have a L: ";
            return -1;
        }
        virtual double getS() {
            std::cout << "Point does not have a S: ";
            return -1;
        }
        virtual double getP() {
            std::cout << "Point does not have a P: ";
            return -1;
        }
        void foo() {
            std::cout << "POINT!\n";
        }
        virtual void boo() {
            std::cout << "Virtual POINT!\n";
        }
};

class Circle: public Point {
    private:
        double r;
    public:
        Circle(Point a, double r): Point (a) {
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
        virtual double getS() {
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
        void foo() {
            std::cout << "CIRCLE!\n";
        }
        virtual void boo() {
            std::cout << "Virtual CIRCLE!\n";
        }
};

class Line: public Point {
    private:
        Point a;
    public:
        Line(Point a, Point b): Point(b) {
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
        Point getB() {
            return Point(Point::getX(), Point::getY());
        }
        
        void setA(Point a) {
            this->a = a;
        }
        void setB(Point b) {
            Point::setX(b.getX());
            Point::setY(b.getY());
        }
        
        virtual double getL() {
            return a.distanceFrom(getB());
        }
        void printCoordinate() {
            std::cout << "\n";
            double k = (getY() - a.getY()) / (getX() - a.getX());
            for (int i = a.getX() + 1; i < x; ++i) {
                std::cout << "(" << i << " , " << k * (i - a.getX()) + a.getY() << ")\n";
            }
            std::cout << "\n";
        }
        void foo() {
            std::cout << "LINE!\n";
        }
        virtual void boo() {
            std::cout << "Virtual LINE!\n";
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
        Point getB() {
            return Point(Point::getX(), Point::getY());
        }
        
        void setP1(Point p1) {
            this->p1 = p1;
        }
        void setB(Point b) {
            Point::setX(b.getX());
            Point::setY(b.getY());
        }
        
        double length() {
            return  std::abs( p1.getX() - Point::getX() );
        }
        double width() {
            return  std::abs( p1.getY() - Point::getY() );
        }
        virtual double getS() {
            return length() * width();
        }
        virtual double getP() {
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
        void foo() {
            std::cout << "RECTANGLE!\n";
        }
        virtual void boo() {
            std::cout << "Virtual RECTANGLE!\n";
        }
};

class Triangle: public Point {
    private:
        Point a, b;
    public:
        Triangle(Point a, Point b, Point c): Point(c)
        {
            this->a = a;
            this->b = b;
        }
        Triangle(const Triangle &obj): Point(obj)
        {
            a = obj.a;
            b = obj.b;
        }
        
        ~Triangle() {}
        
        Point getA() {
            return a;
        }
        Point getB() {
            return b;
        }
        Point getC() {
            return Point(Point::getX(), Point::getY());
        }
        
        void setA(Point a) {
            this->a = a;
        }
        void setB(Point b) {
            this->b = b;
        }
        void setC(Point c) {
            Point::setX(c.getX());
            Point::setY(c.getY());
        }
        
        virtual double getS() {
            double p = (a.distanceFrom(b) + b.distanceFrom(getC()) + Point::distanceFrom(a)) / 2;
            return std::sqrt(p * (p - a.distanceFrom(b)) * (p - b.distanceFrom(getC())) * (p - Point::distanceFrom(a)));
        }
        
        virtual double getP() {
            return a.distanceFrom(b) + b.distanceFrom(getC()) + Point::distanceFrom(a);
        }
        void foo() {
            std::cout << "TRIANGLE!\n";
        }
        virtual void boo() {
            std::cout << "Virtual TRIANGLE!\n";
        }
};

void printL(Shape* obj) {
    std::cout << obj->getL();
}

void printgetS(Shape* obj) {
    std::cout << obj->getS();
}

void printgetP(Shape* obj) {
    std::cout << obj->getP();
}

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
    
    Circle obj2(p1, r);
    obj2.print();
    
    std::cout << "\n";
    
    Line obj4(p1, p2);
    std::cout << "Line Length: " << obj4.getL() << "\n";
    std::cout << "Line Coordinates";
    obj4.printCoordinate();
    
    Rectangle obj1(p1, p2);
    std::cout << "Rectangle getS(S): " << obj1.getS() << "\n";
    std::cout << "Rectangle getP(P): " << obj1.getP() <<"\n";
    obj1.print();
    
    std::cout << "\n";
    
    Triangle obj3(p1, p2, p3);
    std::cout << "Triangle getS(S): " << obj3.getS() << "\n";
    std::cout << "Triangle getP(P): " << obj3.getP() << "\n";

    std::cout << "\n^^^^^*****VIRTUAL SHAPE PRINT*****^^^^^\n\n";

    Point* shp1 = &p1;
    shp1->foo();
    shp1->boo();
    printL(&p1);
    std::cout << "\n"; 
    printgetS(&p1);
    std::cout << "\n"; 
    printgetP(&p1);
    
    std::cout << "\n\n";
    
    Line* shp2 = &obj4;
    shp2->foo();
    shp2->boo();
    std::cout << "Line Length: ";
    printL(&obj4);
    
    std::cout << "\n\n";
    
    Rectangle* shp3 = &obj1;
    shp3->foo();
    shp3->boo();
    std::cout << "Rectangle getS(S): ";
    printgetS(&obj1);
    std::cout << "\nRectangle getP(P): ";
    printgetP(&obj1);
    
    std::cout << "\n\n";
    
    Triangle* shp4 = &obj3;
    shp4->foo();
    shp4->boo();
    std::cout << "Triangle getS(S): ";
    printgetS(&obj3);
    std::cout << "\nTriangle getP(P): ";
    printgetP(&obj3);
    
    std::cout << "\n\n";
    
    Circle* shp5 = &obj2;
    shp5->foo();
    shp5->boo();
    std::cout << "L = ";
    printL(&obj2);
    std::cout << "\nS = ";
    printgetS(&obj2);
    std::cout << "\n"; 
    
    return 0;   
}