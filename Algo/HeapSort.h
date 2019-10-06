#pragma once

namespace algo
{
    template<typename T>
    void Heapify(std::vector<T>& arr, int n, int i)
    {
        T largest = i;
        T l_child = i * 2 + 1;
        T r_child = i * 2 + 2;
        
        if(l_child < n && arr[l_child] > arr[largest])
            largest = l_child;
        
        if(r_child < n && arr[r_child] > arr[largest])
            largest = r_child;
        
        if(largest != i)
        {
            std::swap(arr[largest], arr[i]);
            Heapify(arr, n, largest);
        }
    }

    template<typename T>
    void HeapSort(std::vector<T>& arr)
    {
        if(arr.empty())
            return;
        
        int mid = static_cast<int>(arr.size() / 2);
        for(int i = mid; i >= 0; --i)
        {
            Heapify(arr, static_cast<int>(arr.size()), i);
        }
        
        int last = static_cast<int>(arr.size() - 1);
        while(last)
        {
            std::swap(arr[0], arr[last]);
            Heapify(arr, last, 0);
            --last;
        }
    }
}
