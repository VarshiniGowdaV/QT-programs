#include <iostream>
#include <array>

using namespace std;

void printArray(const std::array<int, 5>& data)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    std::array<int, 5> data = {2, 0, 0, 0, 1};
    printArray(data);

    cout << "Hello World!" << endl;
    return 0;
}
