#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
    // Открытие входных файлов
    std::ifstream file1("name1.txt");
    std::ifstream file2("name2.txt");

    if (!file1 || !file2) {
        std::cerr << "Ошибка открытия файлов!" << std::endl;
        return 1;
    }

    // Итераторы для чтения вещественных чисел
    std::istream_iterator<double> it1(file1), end;
    std::istream_iterator<double> it2(file2);

    // Векторы для хранения считанных данных
    std::vector<double> A(it1, end); // Чтение из file1
    std::vector<double> B(it2, end); // Чтение из file2

    // Проверка, что количество чисел совпадает
    if (A.size() != B.size()) {
        std::cerr << "Файлы содержат разное количество чисел!" << std::endl;
        return 2;
    }

    // Вектор для хранения разностей
    std::vector<double> result(A.size());

    // Вычисление разностей B[i] - A[i]
    std::transform(B.begin(), B.end(), A.begin(), result.begin(),
        [](double b, double a) { return b - a; });

    // Вывод результата
    std::ostream_iterator<double> out(std::cout, "\n");
    std::copy(result.begin(), result.end(), out);

    return 0;
}

