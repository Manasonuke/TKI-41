#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    // Для корректного вывода русских символов в Windows
    setlocale(LC_ALL, "Russian");

    std::vector<int> V = { 1, 2, 3, 4, 2, 3 }; // пример, можно заменить 

    if (V.size() % 2 != 0) {
        std::cerr << "Ошибка: количество элементов должно быть четным." << std::endl;
        return 1;
    }

    size_t half = V.size() / 2;

    // Создаем множества из первой и второй половины вектора
    std::set<int> first_half(V.begin(), V.begin() + half);
    std::set<int> second_half(V.begin() + half, V.end());

    // Проверяем с помощью std::includes, входит ли вторая половина в первую
    bool result = std::includes(
        first_half.begin(), first_half.end(),
        second_half.begin(), second_half.end()
    );

    std::cout << (result ? "true" : "false") << std::endl;

    return 0;
}

