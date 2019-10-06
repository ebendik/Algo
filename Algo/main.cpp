#include <iostream>

#include "PrimeFactorization.h"
#include "GreatestCommonDivisor.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "QuickSort.h"


void test_prime_factorization()
{
    auto prim_fac = algo::PrimeFactorization(1560000000);
    
    for(const auto& num: prim_fac)
    {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

void test_greatest_commond_divisor()
{
    std::cout << algo::GreatestCommonDivisor(20, 3) << std::endl;
}

void test_insertion_sort()
{
    std::vector<int> arr{12, 3, 2, 100, 55, 34};
    algo::InsertionSort(arr);
    for(const auto& num: arr)
    {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    
}

void test_selection_sort()
{
    std::vector<int> arr{12, 3, 2, 100, 55, 34};
    algo::SelectionSort(arr);
    for(const auto& num: arr)
    {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    
}

void test_heap_sort()
{
    std::vector<int> arr{12, 3, 2, 100, 55, 34};
    algo::HeapSort(arr);
    for(const auto& num: arr)
    {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    
}

void test_quick_sort()
{
    std::vector<int> arr{12, 3, 2};
    algo::QuickSort(arr);
    for(const auto& num: arr)
    {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    
}

int main(int argc, const char * argv[]) {

//    test_prime_factorization();
//    test_greatest_commond_divisor();
//    test_insertion_sort();
//    test_selection_sort();
//    test_heap_sort();
    test_quick_sort();
    
    
    return 0;
}
