#include <stdio.h>
#include <iostream>

#include "catch.hpp"
#include "../Algo/InsertionSort.h"

TEST_CASE( "Test InsertionSort" )
{
    SECTION("non-empty array")
    {
        std::vector<int> arr { 1, 44, 3, 2, 88, 9, 100 };
        algo::InsertionSort(arr);
        
        std::vector<int> expected_arr{arr};
        std::sort(expected_arr.begin(), expected_arr.end());
        CHECK(arr == expected_arr);
    }
    
    SECTION("empty array")
    {
        std::vector<int> arr;
        CHECK_NOTHROW(algo::InsertionSort(arr));
    }
}
