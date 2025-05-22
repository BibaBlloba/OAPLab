#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Point {
protected:
    double x, y;
public:
    Point(double xCoord = 0, double yCoord = 0) : x(xCoord), y(yCoord) {}
    
    void display() const {
        cout << "Точка с координатами: (" << x << ", " << y << ")" << endl;
    }
};

class Segment : public Point {
protected:
    double endX, endY;
    double length;
public:
    Segment(double startX, double startY, double endX, double endY) 
        : Point(startX, startY), endX(endX), endY(endY) {
        calculateLength();
    }
    
    void calculateLength() {
        length = sqrt(pow(endX - x, 2) + pow(endY - y, 2));
    }
    
    void display() const {
        cout << "Отрезок:" << endl;
        cout << "  Начало: (" << x << ", " << y << ")" << endl;
        cout << "  Конец: (" << endX << ", " << endY << ")" << endl;
        cout << "  Длина: " << length << endl;
    }
};

class Circle : public Segment {
private:
    double area;
    string purpose;
    string fuelType;
    bool isOrbital;
public:
    Circle(double startX, double startY, double endX, double endY, 
           const string& purpose, const string& fuelType, bool orbital)
        : Segment(startX, startY, endX, endY), 
          purpose(purpose), fuelType(fuelType), isOrbital(orbital) {
        calculateArea();
    }
    
    void calculateArea() {
        area = 3.14159 * pow(length, 2);
    }
    
    void display() const {
        cout << "Круг:" << endl;
        cout << "  Центр: (" << x << ", " << y << ")" << endl;
        cout << "  Радиус (длина отрезка): " << length << endl;
        cout << "  Площадь: " << area << endl;
        cout << "  Назначение: " << purpose << endl;
        cout << "  Тип топлива: " << fuelType << endl;
        cout << "  Тип: " << (isOrbital ? "Орбитальная" : "Межпланетная") << endl;
    }
};

int main() {
    Point point(1, 2);
    Segment segment(1, 2, 4, 6);
    Circle circle(1, 2, 4, 6, "Исследовательский", "Ионный", true);
    
    cout << "Характеристики объектов:" << endl;
    cout << "------------------------" << endl;
    point.display();
    cout << endl;
    segment.display();
    cout << endl;
    circle.display();
    
    return 0;
}