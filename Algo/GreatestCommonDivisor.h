#pragma once

namespace algo
{
    int GreatestCommonDivisor(int a, int b)
    {
        if(a == 0)
            return b;
        
        if(b == 0)
            return a;
        
        if(a == b)
            return a;
        
        if(a > b)
            return GreatestCommonDivisor(a - b, b);
        
        return GreatestCommonDivisor(b - a, a);
    }
}
