#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

template <typename T>
void quickSort(std::vector<T>& arr, int left, int right)
{
    if (left < right)
    {
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> dist(left, right);
        int pivotIndex = dist(rng);
        T pivotValue = arr[pivotIndex];

        std::swap(arr[pivotIndex], arr[right]);

        int storeIndex = left;
        for (int i = left; i <= right - 1; i++)
        {
            if (arr[i] < pivotValue)
            {
                std::swap(arr[i], arr[storeIndex]);
                storeIndex++;
            }
        }

        std::swap(arr[right], arr[storeIndex]);

        quickSort(arr, left, storeIndex - 1);
        quickSort(arr, storeIndex + 1, right);
    }
}

int main()
{
    std::vector<int> arr = { 5, 3, 7, 8, 1, 2, 9, 4, 6 };
    quickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
