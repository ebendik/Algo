#include <iostream>

#include "PrimeFactorization.h"
#include "GreatestCommonDivisor.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "LeastRecentlyUsed.h"


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

void test_least_recently_used()
{
    LeastRecentlyUsed<char, 10> lru;
    lru.Push(1, 'A');
    lru.Push(2, 'B');
    lru.Push(3, 'C');
    lru.Push(4, 'E');
    lru.Push(5, 'F');
    
    lru.Get(1);
    lru.Get(3);
    
    lru.Push(1, 'G');
    lru.Push(6, 'H');
    lru.Push(7, 'I');
    
    lru.Get(4);
}

int main(int argc, const char * argv[]) {

//    test_prime_factorization();
//    test_greatest_commond_divisor();
//    test_insertion_sort();
//    test_selection_sort();
//    test_heap_sort();
//    test_quick_sort();
    test_least_recently_used();
    
    
    return 0;
}
