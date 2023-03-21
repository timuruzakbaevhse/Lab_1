#include <iostream>
#include <string>
using namespace std;

//Структура с информацией о студенте
struct Student {
    string surname; //фамилия
    string name; //имя
    int math_grade; //оценка по математике
    int physics_grade; //оценка по физике
    int programming_grade; //оценка по программированию
};

//Функция сортировки 
template<typename T>
void mergeSort(T arr[], int l, int r) {
    if (r <= l) return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    T* tmp = new T[r - l + 1];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (arr[i].math_grade + arr[i].physics_grade + arr[i].programming_grade < arr[j].math_grade + arr[j].physics_grade + arr[j].programming_grade) {
            tmp[k] = arr[i];
            i++;
        }
        else {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        tmp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        tmp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = l; i <= r; i++) {
        arr[i] = tmp[i - l];
    }
    delete[] tmp;
}

int main() {
    const int N = 5;
    Student students[N] = {
        {"Ivanov","Ivan", 5, 4, 3},
        {"Petrov", "Petr", 3, 3, 3},
        {"Sidorov","Sidor", 5, 5, 5},
        {"Kozlov", "Kozel", 4, 4, 5},
        {"Smirnov","Smir", 5, 5, 4}
    };
    mergeSort(students, 0, N - 1); //сортировка
    for (int i = 0; i < N; i++) {
        cout << students[i].surname << " " << students[i].name << " " << (students[i].math_grade + students[i].physics_grade + students[i].programming_grade) / 3.0 << endl;
    }
    return 0;
}