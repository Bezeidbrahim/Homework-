// Задача 3: Сортировка Сталина
// Удаляет все элементы, нарушающие порядок возрастания

#include <iostream>
#include <vector>

void stalinSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int i = 1;
    while (i < (int)arr.size()) {
        if (arr[i] < arr[i - 1]) {
            std::cout << "Расстрелять! Элемент " << arr[i] << " нарушает порядок.\n";
            arr.erase(arr.begin() + i);
            // не увеличиваем i, проверяем следующий на той же позиции
        } else {
            i++;
        }
    }
}

void printVector(const std::vector<int>& v) {
    std::cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        std::cout << v[i];
        if (i < (int)v.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

int main() {
    // Тесты из условия
    std::vector<std::vector<int>> tests = {
        {1, 2, 3, 4, 5},
        {5, 3, 1, 2, 4},
        {1, 2, 2, 3, 1, 4},
        {3, 1, 4, 1, 5, 9, 2},
        {}
    };

    for (auto& arr : tests) {
        std::cout << "До: ";
        printVector(arr);
        stalinSort(arr);
        std::cout << "После: ";
        printVector(arr);
        std::cout << "\n";
    }

    // Пользовательский ввод
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    std::vector<int> userArr(n);
    std::cout << "Введите элементы: ";
    for (int i = 0; i < n; i++)
        std::cin >> userArr[i];

    std::cout << "\nДо: ";
    printVector(userArr);
    stalinSort(userArr);
    std::cout << "После: ";
    printVector(userArr);

    return 0;
}
