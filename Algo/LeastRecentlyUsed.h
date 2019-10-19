#pragma once

#include <unordered_map>
#include <list>

template <typename T, int N>
class LeastRecentlyUsed
{
public:
    LeastRecentlyUsed()
        : m_max_size(N)
    {}
    
    void Push(int key, T value)
    {
        if(m_cache.size() < m_max_size)
        {
            m_cache.push_front(value);
            m_lookup.insert()
        }
    }
    
    T Get(int key)
    {
        return {};
    }
    
private:
    std::unordered_map<int, T> m_lookup;
    std::list<T> m_cache;
    int m_max_size;
};
