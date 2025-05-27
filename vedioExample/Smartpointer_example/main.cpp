#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Entity
{
public:
    Entity()
    {
        std::cout<<"Entity constructor called "<<std::endl;
    }
    ~Entity()
    {
        std::cout<<"Entity destructor called"<<std::endl;
    }
    void print(){}
};

int main()
{
    {
    std::unique_ptr<Entity>entity=std::make_unique< Entity>();

        std::shared_ptr<Entity>sharedEntity =std::make_shared<Entity>();
        entity->print();
    }
    cout << "Hello World!" << endl;
    return 0;
}
