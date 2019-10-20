#include <stdio.h>
#include <iostream>

#include "catch.hpp"
#include "../Algo/LeastRecentlyUsed.h"

TEST_CASE( "Test Least Recenty Used Push" )
{
    SECTION("push up to max")
    {
        algo::LeastRecentlyUsed<char, 5> lru;
        lru.Push(1, 'A');
        lru.Push(2, 'B');
        lru.Push(3, 'C');
        lru.Push(4, 'D');
        lru.Push(5, 'E');
     
        std::vector< std::pair<int, char> > values;
        values.emplace_back(std::pair<int, char>{5, 'E'});
        values.emplace_back(std::pair<int, char>{4, 'D'});
        values.emplace_back(std::pair<int, char>{3, 'C'});
        values.emplace_back(std::pair<int, char>{2, 'B'});
        values.emplace_back(std::pair<int, char>{1, 'A'});
        
        int i = 0;
        for(const auto& kv : lru.m_cache)
        {
            CHECK(kv.first == values[i].first);
            CHECK(kv.second == values[i].second);
            CHECK(lru.m_lookup.find(kv.first) != lru.m_lookup.end());
            ++i;
        }
    }

    SECTION("push pass max")
    {
        algo::LeastRecentlyUsed<char, 5> lru;
        lru.Push(1, 'A');
        lru.Push(2, 'B');
        lru.Push(3, 'C');
        lru.Push(4, 'D');
        lru.Push(5, 'E');
        lru.Push(6, 'F');
     
        std::vector< std::pair<int, char> > values;
        values.emplace_back(std::pair<int, char>{6, 'F'});
        values.emplace_back(std::pair<int, char>{5, 'E'});
        values.emplace_back(std::pair<int, char>{4, 'D'});
        values.emplace_back(std::pair<int, char>{3, 'C'});
        values.emplace_back(std::pair<int, char>{2, 'B'});
        
        int i = 0;
        for(const auto& kv : lru.m_cache)
        {
            CHECK(kv.first == values[i].first);
            CHECK(kv.second == values[i].second);
            CHECK(lru.m_lookup.find(kv.first) != lru.m_lookup.end());
            ++i;
        }
    }
    
    
SECTION("update least recently used")
{
    algo::LeastRecentlyUsed<char, 5> lru;
    lru.Push(1, 'A');
    lru.Push(2, 'B');
    lru.Push(3, 'C');
    lru.Push(4, 'D');
    lru.Push(5, 'E');
    lru.Push(1, 'Q');
 
    std::vector< std::pair<int, char> > values;
    values.emplace_back(std::pair<int, char>{1, 'Q'});
    values.emplace_back(std::pair<int, char>{5, 'E'});
    values.emplace_back(std::pair<int, char>{4, 'D'});
    values.emplace_back(std::pair<int, char>{3, 'C'});
    values.emplace_back(std::pair<int, char>{2, 'B'});
    
    int i = 0;
    for(const auto& kv : lru.m_cache)
    {
        CHECK(kv.first == values[i].first);
        CHECK(kv.second == values[i].second);
        CHECK(lru.m_lookup.find(kv.first) != lru.m_lookup.end());
        ++i;
    }
}
}

TEST_CASE( "Test Least Recenty Used Pop" )
{
    SECTION("pop three items")
    {
        algo::LeastRecentlyUsed<char, 5> lru;
        lru.Push(1, 'A');
        lru.Push(2, 'B');
        lru.Push(3, 'C');
        lru.Push(4, 'D');
        lru.Push(5, 'E');
     
        std::vector< std::pair<int, char> > values;
        values.emplace_back(std::pair<int, char>{2, 'B'});
        values.emplace_back(std::pair<int, char>{5, 'E'});
        values.emplace_back(std::pair<int, char>{3, 'C'});
        values.emplace_back(std::pair<int, char>{4, 'D'});
        values.emplace_back(std::pair<int, char>{1, 'A'});
        
        CHECK(lru.Get(3).value() == 'C');
        CHECK(lru.m_cache.front().first == 3);
        CHECK(lru.m_cache.front().second == 'C');
        
        CHECK(lru.Get(5).value() == 'E');
        CHECK(lru.m_cache.front().first == 5);
        CHECK(lru.m_cache.front().second == 'E');

        CHECK(lru.Get(2).value() == 'B');
        CHECK(lru.m_cache.front().first == 2);
        CHECK(lru.m_cache.front().second == 'B');
        
        int i = 0;
        for(const auto& kv : lru.m_cache)
        {
            CHECK(kv.first == values[i].first);
            CHECK(kv.second == values[i].second);
            CHECK(lru.m_lookup.find(kv.first) != lru.m_lookup.end());
            ++i;
        }
    }
}


TEST_CASE( "Test Least Recenty Used Push and Pop" )
{
    SECTION("push and pop")
    {
        algo::LeastRecentlyUsed<char, 5> lru;
        lru.Push(1, 'A');
        lru.Push(2, 'B');
        CHECK(lru.Get(1) == 'A');
        CHECK(lru.m_cache.front().first == 1);
        CHECK(lru.m_cache.front().second == 'A');
        
        lru.Push(3, 'C');
        lru.Push(4, 'D');
        CHECK(lru.Get(3) == 'C');
        CHECK(lru.m_cache.front().first == 3);
        CHECK(lru.m_cache.front().second == 'C');
        
        lru.Push(5, 'E');
        lru.Push(6, 'F');
        
        std::vector< std::pair<int, char> > values;
        values.emplace_back(std::pair<int, char>{6, 'F'});
        values.emplace_back(std::pair<int, char>{5, 'E'});
        values.emplace_back(std::pair<int, char>{3, 'C'});
        values.emplace_back(std::pair<int, char>{4, 'D'});
        values.emplace_back(std::pair<int, char>{1, 'A'});
        
        int i = 0;
        for(const auto& kv : lru.m_cache)
        {
            CHECK(kv.first == values[i].first);
            CHECK(kv.second == values[i].second);
            CHECK(lru.m_lookup.find(kv.first) != lru.m_lookup.end());
            ++i;
        }
    }
    
    SECTION("pop and push")
    {
        algo::LeastRecentlyUsed<char, 5> lru;
        CHECK(lru.Get(1) == std::nullopt);
        CHECK(lru.m_cache.size() == 0);
        
        lru.Push(1, 'A');
        CHECK(lru.Get(1).value() == 'A');
        CHECK(lru.m_cache.front().first == 1);
        CHECK(lru.m_cache.front().second == 'A');
        CHECK(lru.m_cache.size() == 1);
    }
}
