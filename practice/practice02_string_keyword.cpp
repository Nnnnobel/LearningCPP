#include <iostream>
#include <string>

// Practice 02: String keyword search
//
// Task:
// Complete ContainsKeyword.
// It should return true if text contains keyword.
//
// Advanced:
// If the keyword is found, print its first position.

bool ContainsKeyword(const std::string& text, const std::string& keyword)
{
    // TODO: Use text.find(keyword).
    // Hint:
    // std::string::npos means "not found".

    return false;
}

int main()
{
    std::string text1 = "Hello Nobel";
    std::string text2 = "Learning C++ is interesting";
    std::string text3 = "Virtual function and inheritance";

    std::cout << ContainsKeyword(text1, "Nobel") << std::endl;
    std::cout << ContainsKeyword(text2, "Java") << std::endl;
    std::cout << ContainsKeyword(text3, "function") << std::endl;

    std::cin.get();
}
