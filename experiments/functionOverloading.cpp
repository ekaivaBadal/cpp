#include <iostream>
#include <cmath>

using namespace std;
float area(int radius)
{
    return 3.14 * pow(radius, 2);
}

int area(int length, int breadth)
{
    return length * breadth;
}

int area(int a, int b, int c)
{
    int s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{

    float circleArea = area(4);
    int rectangleArea = area(10, 5);
    int triangleArea = area(3, 4, 5);

    cout << "Circle Area is : " << circleArea << endl;
    cout << "Rectangle Area is : " << rectangleArea << endl;
    cout << "Triangle Area is : " << triangleArea << endl;

    return 0;
}