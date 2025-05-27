#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>

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

    // Итераторы для чтения чисел из файлов
    std::istream_iterator<double> iter1(file1);
    std::istream_iterator<double> end1;

    std::istream_iterator<double> iter2(file2);
    std::istream_iterator<double> end2;

    // Вектор для хранения результатов
    std::vector<double> results;

    // Используем transform для вычисления разностей
    std::transform(iter2, end2, iter1, std::back_inserter(results),
        [](double b, double a) { return b - a; });

    // Выводим результаты с помощью ostream_iterator
    std::ostream_iterator<double> out_it(std::cout, "\n");
    std::copy(results.begin(), results.end(), out_it);

    return 0;
}