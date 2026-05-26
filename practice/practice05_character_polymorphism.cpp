#include <iostream>
#include <string>

// Practice 05: Character inheritance and virtual functions
//
// Task:
// Complete Character, Warrior, and Mage.
// Use virtual functions and override.

class Character
{
public:
    virtual std::string GetName()
    {
        return "Character";
    }

    virtual int GetDamage()
    {
        return 0;
    }
};

class Warrior : public Character
{
public:
    // TODO: Override GetName, return "Warrior".

    // TODO: Override GetDamage, return 80.
};

class Mage : public Character
{
public:
    // TODO: Override GetName, return "Mage".

    // TODO: Override GetDamage, return 120.
};

void PrintCharacterInfo(Character* character)
{
    // TODO: Print character name and damage.
}

int main()
{
    Warrior warrior;
    Mage mage;

    PrintCharacterInfo(&warrior);
    PrintCharacterInfo(&mage);

    std::cin.get();
}
