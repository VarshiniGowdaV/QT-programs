#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    v.push_back(4);

    for (int i : v) {
        cout << i << " ";
    }
    return 0;
}

// #include <iostream>
// #include <list>
// using namespace std;

// int main() {
//     list<int> l = {10, 20, 30};
//     l.push_front(5);
//     l.push_back(40);

//     for (int i : l) {
//         cout << i << " ";
//     }
//     return 0;
// }

// #include <iostream>
// #include <map>
// using namespace std;

// int main() {
//     map<string, int> marks;
//     marks["ani"] = 85;
//     marks["Bbo"] = 92;

//     for (auto pair : marks) {
//         cout << pair.first << ": " << pair.second << endl;
//     }

//     return 0;
// }
