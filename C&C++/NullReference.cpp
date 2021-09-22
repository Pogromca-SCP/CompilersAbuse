#include <iostream>

// Since references are just pointers "in disguise"
void test(const int& num)
{
    std::cout << num << std::endl;
}

// We can use pointers to get null-reference
int main()
{
    int num = 3;
    test(num);
    int* ptr = &num;
    test(*ptr);
    // uncomment to get an error
    // ptr = nullptr;
    test(*ptr);
    return 0;
}
