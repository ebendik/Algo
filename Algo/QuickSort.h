#pragma once

namespace algo
{
    template <typename T>
    void sort(std::vector<T>& arr, int left, int right)
    {
        if(left >= right)
            return;
        
        T pivot = arr[right];
        
        int i = left;
        int j = left;
        while(j < right)
        {
            if(arr[j] < pivot)
            {
                std::swap(arr[j], arr[i]);
                ++i;
            }
            ++j;
        }
        
        if(arr[i] < pivot)
        {
            std::swap(arr[i], arr[right]);
        }
        
        sort(arr, left, i - 1);
        sort(arr, i + 1, right);
    }

    template <typename T>
    void QuickSort(std::vector<T>& arr)
    {
        sort(arr, 0, static_cast<int>(arr.size() - 1));
    }
}
