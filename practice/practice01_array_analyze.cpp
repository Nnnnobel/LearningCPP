#include <iostream>

// Practice 01: Array max value and average
//
// Task:
// Complete AnalyzeArray.
// It should find the max value and average value of arr,
// then return them through reference parameters.

void AnalyzeArray(const int* arr, int size, int& maxValue, double& average)
{
    // TODO: Handle invalid input if size <= 0 or arr == nullptr.

    // TODO: Find the max value.

    // TODO: Calculate the average value.
}

int main()
{
    int nums[5] = {10, 25, 3, 99, 42};

    int maxValue = 0;
    double average = 0.0;

    AnalyzeArray(nums, 5, maxValue, average);

    std::cout << "Max: " << maxValue << std::endl;
    std::cout << "Average: " << average << std::endl;

    std::cin.get();
}
