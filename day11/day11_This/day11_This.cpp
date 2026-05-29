#include <iostream>

void PrintEntity(const Entity& e);

class Entity
{
public:
    int x, y;

    Entity(int x, int y)
    {
        //Entity* e =this;
        // e -> x = x;

        this -> x = x;
        this -> y = y;

        PrintEntity(*this);
    }

    int GetX() const
    {
        return x;
    }
};

void PrintEntity(const Entity& e){

}

int main()
{


    std::cin.get();

}