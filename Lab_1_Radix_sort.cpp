#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template<typename T>
void radixSort(std::vector<T>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    // найдем самую длинную строку в массиве для определения
    // количества разрядов, которые нужно будет проверять
    int maxLen = 0;
    for (const auto& str : arr) {
        maxLen = std::max(maxLen, static_cast<int>(str.size()));
    }

    // выполняем сортировку 
    for (int digit = maxLen - 1; digit >= 0; --digit) {
        // создаем вектор подсчета
        std::vector<int> count(256, 0);
        for (const auto& str : arr) {
            // если длина текущей строки меньше текущего разряда,
            // то считаем, что этот разряд у нее равен нулю
            const int d = (digit < static_cast<int>(str.size())) ? static_cast<int>(str[digit]) : 0;
            ++count[d];
        }

        // преобразуем вектор подсчета в вектор сумм
        for (int i = 1; i < 256; ++i) {
            count[i] += count[i - 1];
        }

        // создаем временный вектор, который будет содержать
        // отсортированные строки
        std::vector<T> tmp(arr.size());
        for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i) {
            const auto& str = arr[i];
            const int d = (digit < static_cast<int>(str.size())) ? static_cast<int>(str[digit]) : 0;
            --count[d];
            tmp[count[d]] = std::move(arr[i]);
        }

        // копируем временный вектор в основной
        std::copy(tmp.begin(), tmp.end(), arr.begin());
    }
}

int main() {
    std::vector<std::string> arr = { "apple", "banana", "lemon", "orange", "kiwi", "grape", "pear" };
    std::cout << "Before sorting: ";
    for (const auto& str : arr) {
        std::cout << str << " ";
    }
    std::cout << "\n";

    radixSort(arr);

    std::cout << "After sorting: ";
    for (const auto& str : arr) {
        std::cout << str << " ";
    }
    std::cout << "\n";

    return 0;
}
