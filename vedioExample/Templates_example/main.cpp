// #include <iostream>
// using namespace std;

// template <typename T>
// T add(T a, T b) {
//     return a + b;
// }

// int main() {
//     cout << "Int: " << add(3, 4) << endl;
//     cout << "Float: " << add(3.5f, 2.1f) << endl;
//     cout << "Double: " << add(5.5, 6.3) << endl;
//     return 0;
// }
#include <iostream>
using namespace std;

template <class T>
class Box {
private:
    T value;
public:
    void set(T val) {
        value = val;
    }
    T get() {
        return value;
    }
};

int main() {
    Box<int> intBox;
    intBox.set(10);
    cout << "IntBox: " << intBox.get() << endl;

    Box<string> strBox;
    strBox.set("Hello, World!");
    cout << "StrBox: " << strBox.get() << endl;

    return 0;
}
