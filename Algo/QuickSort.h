#pragma once

namespace algo
{
    template <typename T>
    int partition(std::vector<T>& arr, int left, int right)
    {
        int piv = arr[right];
        int i = left - 1;
        for(int j = left; j < right; ++j)
        {
            if(arr[j] < piv)
            {
                ++i;
                std::swap(arr[j], arr[i]);
            }
        }
        
        std::swap(arr[i + 1], arr[right]);
        return i + 1;            
    }

    template <typename T>
    void sort(std::vector<T>& arr, int left, int right)
    {
        if(left >= right)
            return;
        
        int i = partition(arr, left, right);
        
        sort(arr, left, i - 1);
        sort(arr, i + 1, right);
    }

    template <typename T>
    void QuickSort(std::vector<T>& arr)
    {
        sort(arr, 0, static_cast<int>(arr.size() - 1));
    }
}
