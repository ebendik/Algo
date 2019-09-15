#pragma once

namespace algo
{
    template <typename T>
    void SelectionSort(std::vector<T>& arr)
    {
        for(std::size_t i = 0; i < arr.size(); ++i)
        {
            auto min = i;
            for(auto j = i + 1; j < arr.size(); ++j)
            {
                if(arr[j] < arr[min])
                    min = j;
            }
            
            if(min != i)
                std::swap(arr[i], arr[min]);
        }
    }
}
