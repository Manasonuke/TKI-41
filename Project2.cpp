#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <locale.h>

int main() {
    // Для русских символов в Windows
    setlocale(LC_ALL, "Russian");

    int N;
    std::cout << "Введите чётное количество чисел: ";
    std::cin >> N;

    if (N % 2 != 0 || N <= 0) {
        std::cerr << "Ошибка: количество должно быть положительным и чётным!" << std::endl;
        return 1;
    }

    std::cout << "Введите " << N << " целых чисел: ";

    // Читаем ровно N чисел через istream_iterator
    std::istream_iterator<int> input(std::cin);
    std::vector<int> V;
    V.reserve(N);

    for (int i = 0; i < N; ++i, ++input)
        V.push_back(*input);

    // Один итератор вывода для всей строки
    std::ostream_iterator<int> output(std::cout, " ");

    // Выводим вторую половину
    std::copy(V.begin() + N / 2, V.end(), output);
    // Сразу же — первую половину
    std::copy(V.begin(), V.begin() + N / 2, output);

    std::cout << std::endl;

    return 0;
}
