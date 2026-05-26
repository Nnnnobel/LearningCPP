#include <iostream>

// Practice 04: Count live objects
//
// Task:
// Complete Entity.
// Every constructor should increase s_Count.
// The destructor should decrease s_Count.

class Entity
{
private:
    static int s_Count;

public:
    Entity()
    {
        // TODO: Increase s_Count.
    }

    ~Entity()
    {
        // TODO: Decrease s_Count.
    }

    static int GetCount()
    {
        // TODO: Return s_Count.
        return 0;
    }
};

// TODO: Define Entity::s_Count here.

int main()
{
    Entity a;
    Entity b;

    std::cout << "Count: " << Entity::GetCount() << std::endl;

    {
        Entity c;
        std::cout << "Count in scope: " << Entity::GetCount() << std::endl;
    }

    std::cout << "Count after scope: " << Entity::GetCount() << std::endl;

    std::cin.get();
}
