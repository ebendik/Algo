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
        if(m_cache.size() == m_max_size)
        {
            int key = m_cache.back().second;
            m_cache.pop_back();
            m_lookup.erase(key);
        }
            
        m_cache.emplace_front(cache_kv{key, value});
        m_lookup.insert({key, m_cache.begin()});
    }
    
    T Get(int key)
    {
        auto itr = m_lookup.find(key);
        if(itr == m_lookup.end())
            return ' ';
        
        auto cache_itr = itr->second;
        m_cache.splice(m_cache.begin(), m_cache, cache_itr);
        
        return cache_itr->second;
    }
    
private:
    using cache_kv = std::pair<int, T>;
    using iter = typename std::list< cache_kv >::iterator;
    
    std::unordered_map<int, iter> m_lookup;
    std::list< cache_kv > m_cache;
    int m_max_size;
};
