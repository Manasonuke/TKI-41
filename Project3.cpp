#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <locale.h>

int main() {
    // Для корректного вывода русских символов в Windows
    setlocale(LC_ALL, "Russian");

    // Считываем все целые числа из стандартного ввода
    std::istream_iterator<int> input(std::cin);
    std::istream_iterator<int> eof;

    std::vector<int> V(input, eof);

    // Проверяем, что количество элементов четное и больше 0
    if (V.empty() || V.size() % 2 != 0) {
        std::cerr << "Ошибка: количество элементов должно быть положительным и четным." << std::endl;
        return 1;
    }

    size_t half = V.size() / 2;

    // Создаем множества из первой и второй половины
    std::set<int> first_half(V.begin(), V.begin() + half);
    std::set<int> second_half(V.begin() + half, V.end());

    // Проверяем, входит ли вторая половина во первую
    bool result = std::includes(
        first_half.begin(), first_half.end(),
        second_half.begin(), second_half.end()
    );

    std::cout << (result ? "true" : "false") << std::endl;

    return 0;
}

