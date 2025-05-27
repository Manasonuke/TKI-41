#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <locale> // для setlocale

int main() {
    // Для корректного вывода русских символов в Windows
    setlocale(LC_ALL, "Russian");

    // Открываем файлы для чтения
    std::ifstream file1("name1.txt");
    std::ifstream file2("name2.txt");

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Ошибка открытия файлов!" << std::endl;
        return 1;
    }

    // Считаем весь файл 1 в вектор v1
    std::vector<double> v1((std::istream_iterator<double>(file1)), std::istream_iterator<double>());

    // Считаем весь файл 2 в вектор v2
    std::vector<double> v2((std::istream_iterator<double>(file2)), std::istream_iterator<double>());

    // Проверяем размеры, чтобы избежать ошибок
    size_t size = std::min(v1.size(), v2.size());

    std::vector<double> results;
    results.reserve(size);

    // Вычисляем разности по длине меньшего вектора
    std::transform(v2.begin(), v2.begin() + size,
        v1.begin(), std::back_inserter(results),
        [](double b, double a) { return b - a; });

    // Выводим результаты
    std::ostream_iterator<double> out_it(std::cout, "\n");
    std::copy(results.begin(), results.end(), out_it);

    return 0;
}

