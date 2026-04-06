// Задача 2: Магическая сумма 3
// Суммировать нечётные числа, содержащие цифру 3

#include <iostream>
#include <vector>
#include <string>

// Проверяет, содержит ли число цифру 3
bool containsDigit3(int n) {
    if (n < 0) n = -n; // работаем с модулем
    std::string s = std::to_string(n);
    for (char c : s)
        if (c == '3') return true;
    return false;
}

int magicSum3(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        if (num % 2 != 0 && containsDigit3(num)) {
            sum += num;
        }
    }
    return sum;
}

int main() {
    // Тест 1: [3, 12, 5, 8, 30, 13] -> 16
    std::vector<int> arr1 = {3, 12, 5, 8, 30, 13};
    std::cout << "Массив: [3, 12, 5, 8, 30, 13]\n";
    std::cout << "Магическая сумма 3: " << magicSum3(arr1) << " (ожидается 16)\n\n";

    // Тест 2: нет подходящих чисел
    std::vector<int> arr2 = {2, 4, 6, 8};
    std::cout << "Массив: [2, 4, 6, 8]\n";
    std::cout << "Магическая сумма 3: " << magicSum3(arr2) << " (ожидается 0)\n\n";

    // Тест 3: пользовательский ввод
    int n;
    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    std::vector<int> arr3(n);
    std::cout << "Введите элементы: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr3[i];

    std::cout << "Магическая сумма 3: " << magicSum3(arr3) << "\n";
    return 0;
}
