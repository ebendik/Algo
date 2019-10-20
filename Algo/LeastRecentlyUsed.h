#pragma once

#include <unordered_map>
#include <list>
#include <optional>


namespace algo
{
    template <typename T, int N>
    class LeastRecentlyUsed
    {
    public:
        LeastRecentlyUsed()
            : m_max_size(N)
        {}
        
        void Push(int key, T value)
        {
            auto itr = m_lookup.find(key);
            if(itr != m_lookup.end())
            {
                Update(itr->second, value);
            }
            else
            {
                CheckMax();
                Insert(key, value);
            }
        }
        
        std::optional<T> Get(int key)
        {
            auto itr = m_lookup.find(key);
            if(itr == m_lookup.end())
                return std::nullopt;
            
            auto cache_itr = itr->second;
            m_cache.splice(m_cache.begin(), m_cache, cache_itr);
            
            return cache_itr->second;
        }
        
    private:
        using cache_kv = std::pair<int, T>;
        using iter = typename std::list< cache_kv >::iterator;
        
        void CheckMax()
        {
            if(m_cache.size() == m_max_size)
            {
                int key = m_cache.back().second;
                m_cache.pop_back();
                m_lookup.erase(key);
            }
        }
        
        void Update(iter& cache_itr, const T& value)
        {
            cache_itr->second = value;
            m_cache.splice(m_cache.begin(), m_cache, cache_itr);
        }
        
        void Insert(int key, const T& value)
        {
            m_cache.emplace_front(cache_kv{key, value});
            m_lookup.insert({key, m_cache.begin()});
        }
        
#ifdef TEST
    public:
#else
    private:
#endif
        std::unordered_map<int, iter> m_lookup;
        std::list< cache_kv > m_cache;
        int m_max_size;
    };

}
