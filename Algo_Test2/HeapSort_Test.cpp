#include <stdio.h>
#include <iostream>

#include "catch.hpp"
#include "../Algo/HeapSort.h"

TEST_CASE( "Test Heap Sort" )
{
    SECTION("non-empty array")
    {
        std::vector<int> arr { 1, 44, 3, 2, 88, 9, 100 };
        algo::HeapSort(arr);
        
        std::vector<int> expected_arr{arr};
        std::sort(expected_arr.begin(), expected_arr.end());
        CHECK(arr == expected_arr);
    }

    SECTION("single item array")
    {
        std::vector<int> arr { 1 };
        algo::HeapSort(arr);
        
        std::vector<int> expected_arr{arr};
        std::sort(expected_arr.begin(), expected_arr.end());
        CHECK(arr == expected_arr);
    }
    
    SECTION("empty array")
    {
        std::vector<int> arr;
        CHECK_NOTHROW(algo::HeapSort(arr));
    }
}
