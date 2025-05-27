#include <iostream>
#include <string>
using namespace std;
template<typename T>
void print(T value)
{
    std::cout<<value<<std::endl;
}
void print(std::string value)
{
    std::cout<<value<<std::endl;

}
int main()
{
    print<int>(5);
    print("hloo");
    cout << "Hello World!" << endl;
    return 0;
}
