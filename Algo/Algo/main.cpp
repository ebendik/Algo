#include <iostream>
#include "prime_factorization.h"
#include "gcd.h"


void test_prime_factorization()
{
    auto prim_fac = prime_factorization(1560000000);
    
    for(const auto& num: prim_fac)
    {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

void test_greatest_commond_divisor()
{
    std::cout << greatest_common_divisor(20, 3) << std::endl;
}

int main(int argc, const char * argv[]) {

//    test_prime_factorization();
    test_greatest_commond_divisor();
    
    
    return 0;
}
