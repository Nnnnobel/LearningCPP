#include <iostream>
#include <string>

// Practice 03: Student class
//
// Task:
// Complete this class with:
// - constructor
// - getters
// - setter for score
// - PrintInfo const method

class Student
{
private:
    std::string m_Name;
    int m_Age;
    double m_Score;

public:
    Student(const std::string& name, int age, double score)
    {
        // TODO: Initialize member variables.
    }

    std::string GetName() const
    {
        // TODO: Return m_Name.
        return "";
    }

    int GetAge() const
    {
        // TODO: Return m_Age.
        return 0;
    }

    double GetScore() const
    {
        // TODO: Return m_Score.
        return 0.0;
    }

    void SetScore(double score)
    {
        // TODO: Change m_Score.
    }

    void PrintInfo() const
    {
        // TODO: Print name, age, and score.
    }
};

int main()
{
    Student student("Nobel", 20, 95.5);

    student.PrintInfo();

    student.SetScore(98.0);
    student.PrintInfo();

    std::cin.get();
}
