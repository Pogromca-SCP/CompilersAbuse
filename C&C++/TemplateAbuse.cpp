#include <iostream>

// Templates can also be used to make calculations at compile-time
// This template executes single calculation step
template<unsigned int N, unsigned int V>
class FactorialStep : public FactorialStep<N - 1, V * N> {};

// This specialized template will stop calculations
template<unsigned int V>
struct FactorialStep<1, V>
{
    static constexpr unsigned int Result = V;
};

// This is initial template which starts calculations
template<unsigned int N>
class Factorial : public FactorialStep<(N > 2 ? N : 1), (N > 2 ? 1 : N)> {};

int main()
{
    // Thanks to that, each result is stored in memory and we don't neeed to make calculations at runtime
    std::cout << Factorial<0>::Result << std::endl;
    std::cout << Factorial<1>::Result << std::endl;
    std::cout << Factorial<2>::Result << std::endl;
    std::cout << Factorial<3>::Result << std::endl;
    std::cout << Factorial<5>::Result << std::endl;
    std::cout << Factorial<7>::Result << std::endl;
    std::cout << Factorial<9>::Result << std::endl;
    return 0;
}
