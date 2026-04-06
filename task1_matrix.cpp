// Задача 1: Найти сумму наибольших элементов матрицы N*M
// (сумма максимальных элементов каждой строки)

#include <iostream>
#include <vector>
#include <climits>

int main() {
    int N, M;
    std::cout << "Введите размер матрицы N и M: ";
    std::cin >> N >> M;

    std::vector<std::vector<int>> matrix(N, std::vector<int>(M));

    std::cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> matrix[i][j];

    // Вывод матрицы
    std::cout << "\nМатрица:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }

    // Найти максимальный элемент каждой строки и суммировать
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int maxVal = INT_MIN;
        for (int j = 0; j < M; j++)
            if (matrix[i][j] > maxVal)
                maxVal = matrix[i][j];
        std::cout << "Максимум строки " << i + 1 << ": " << maxVal << "\n";
        sum += maxVal;
    }

    std::cout << "\nСумма наибольших элементов: " << sum << "\n";
    return 0;
}
