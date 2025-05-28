#include <iostream>
#define PI 3.14
#define SQUARE(x) ((x)*(x))
using namespace std;

int main()
{
    double radius=5.0;
    double area=PI * SQUARE(radius);
    std::cout<<"Radius: "<<radius<<std::endl;
    std::cout<<"Area: "<<area<<std::endl;
    int num =6;
    std::cout<<"square of "<<num<<" is: "<<SQUARE(num)<<std::endl;
    return 0;
}
