#pragma once

namespace algo
{
    template <typename T>
    void InsertionSort(std::vector<T>& arr)
    {
        for(std::size_t i = 1; i < arr.size(); ++i)
        {
            std::size_t j = i;
            while(j >= 1 && arr[j-1] > arr[j])
            {
                std::swap(arr[j -1], arr[j]);
                --j;
            }
        }
    }
}
