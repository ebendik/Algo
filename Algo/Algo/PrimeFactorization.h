#pragma once

#include <vector>


namespace algo
{
    bool is_prime(int num)
    {
        bool isPrime = true;
        for(int i = 2; i <= num / 2; ++i)
        {
            if(num % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        
        return isPrime;
    }
    
    
    void work(int num, std::vector<int>& prime_nums)
    {
        for(int i = 2; i <= num; ++i)
        {
            if(!is_prime(i))
            {
                continue;
            }
            
            double res = (double)num / (double)i;
            if(static_cast<int>(num / i) == res)
            {
                prime_nums.push_back(i);
                return work(res, prime_nums);
            }
            
            if(res == 1)
            {
                prime_nums.push_back(num);
            }
        }
    }
    
    std::vector<int> PrimeFactorization(int num)
    {
        std::vector<int> prime_nums;
        
        work(num, prime_nums);
        
        return prime_nums;
    }
}
