#include <iostream>

using namespace std;

class Entity {
public:
    float X = 0.0f, Y = 0.0f;

    void Move(float xa, float ya) {
        X += xa;
        Y += ya;
    }

    void PrintPosition() {
        cout << "Position: (" << X << ", " << Y << ")" << endl;
    }
};

class Player : public Entity {
public:
    const char* Name;

    void printname() {
        cout << "Player Name: " << Name << endl;
    }
};

int main() {
    Player play;
    play.Name = "varshi";
    play.Move(0.22f, 0.33f);
    play.printname();
    play.PrintPosition();
    return 0;
}
