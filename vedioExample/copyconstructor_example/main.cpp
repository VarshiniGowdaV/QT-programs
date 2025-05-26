#include <iostream>
#include <string>
using namespace std;
struct vector2
{
    float x,y;
    vector2() {}
};
int main()
{
    vector2* a = new vector2();
    vector2* b=a;
    b->x=2;

    return 0;
}
// class string
// {
// private:
//     char* m_buffer;
//     unsigned int m_size;
// public:
//     string(const char* string)
//     {
//         m_size = strlen(string);
//         m_buffer = new char[m_size];
//         for(int i=0;i<m_size;i++)
//             m_buffer = new char[m_size];


//     }
// };
