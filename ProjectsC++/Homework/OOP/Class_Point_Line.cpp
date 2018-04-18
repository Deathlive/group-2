#include <iostream>
#include <cmath>
#include <iomanip>

class Point {
    protected:
        double x, y;
        
    public:
        Point() {
            x = 0;
            y = 0;   
        }
        Point(double x, double y) {
            this->x = x;
            this->y = y;   
        }
        ~Point() {
        
        }
        
        double getX() {
            return x;
        }
        double getY() {
            return y;
        }
        
        void setX(float x) {
            this->x = x; 
        }
        void setY(float y) {
            this->y = y;
        }
        
        void printPoint() {
            std::cout << " x = "<< x << std::setw(6) << "y = " << y;
        }
};

class Circle : public Point {

    private:
        float r;
    public:
        Circle() {

        }
        ~Circle() {
            
        }
        
        float getR() {
            return r;
        }
        float getL() {
            return 2 * M_PI * r;
        }
        
        void setR(float r) {
            this->r = r;
        }
};

class Line: public Point {
    private:
        Point p1, p2;
        
    public:
        Line(): p1(), p2() {
            
        }
        Line(Point p1, Point p2 ): p1(p1), p2(p2) {
            
        }
        ~Line() {
            
        }
        
        Point getP1() {
            return p1;
        }
        Point getP2() {
            return p2;
        }
        
        void setP1(Point a) {
            p1 = a;
        }
        void setP2(Point b) {
            p2 = b;
        }
        
        void printLine() {
            p1.printPoint();
            p2.printPoint();
        }
};

class Rectangle {
    protected:
        int length;
        int height;
        
    public:
        Rectangle() {  
            length = 0;
            height = 0;
        } 
        Rectangle(int len, int hei) {
            length = len; 
            height = hei;
        }
        ~Rectangle() {
            
        }
        
        int getLength() { 
            return length;
        }
        int getHeigth() { 
            return height; 
        }
        
        void setLength(int len) { 
            length = len; 
        }
        void setHeight(int hei) { 
            height = hei; 
        }
        
        int sqare() { 
            return length * height; 
        }
};

int main() {
    double x1 = 5, y1 = 5, x2 = 15, y2 = 15;
    double k = (y2 - y1) / (x2 - x1);

    for (int i = x1 + 1; i < x2; ++i) {
        std::cout << "x = " << i << std::setw(6) << "y = " << k * (i - x1) + y1 << "\n";
    }
    std::cout << "\n"; 

    Point a(5,5);
    Line b;
    Circle c;
    Rectangle d(6, 8);

    std::cout << "Point Coordinates: "; 
    a.printPoint();

    std::cout << "\nLine Coordinates: "; 

    b.printLine();


    c.setR(8);
    std::cout << "\n\nCircle Length: " << c.getL() << "\n";

    std::cout << "\nRectangle sqare: " << d.sqare() << "\n";

    return 0;   
    }