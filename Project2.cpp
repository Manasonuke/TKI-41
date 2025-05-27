#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <locale.h>

int main() {
    // Для корректного вывода русских символов в Windows
    setlocale(LC_ALL, "Russian");

    // Считываем **все** целые числа из стандартного ввода
    std::istream_iterator<int> input(std::cin);
    std::istream_iterator<int> eof;

    std::vector<int> V(input, eof);

    // Проверяем, что количество элементов чётное и больше 0
    if (V.size() == 0 || V.size() % 2 != 0) {
        std::cerr << "Ошибка: количество элементов должно быть положительным и чётным!" << std::endl;
        return 1;
    }

    // Итератор вывода с пробелом
    std::ostream_iterator<int> output(std::cout, " ");

    // Выводим вторую половину
    std::copy(V.begin() + V.size() / 2, V.end(), output);
    // Затем первую половину
    std::copy(V.begin(), V.begin() + V.size() / 2, output);

    std::cout << std::endl;

    return 0;
}

