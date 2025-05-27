#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <locale>
#include <windows.h> // для SetConsoleOutputCP

struct point {
    int x, y;
    std::string s;

    bool operator<(const point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

std::istream& operator>>(std::istream& is, point& p) {
    return is >> p.x >> p.y >> p.s;
}

std::ostream& operator<<(std::ostream& os, const point& p) {
    return os << p.x << ' ' << p.y << ' ' << p.s;
}

int main() {
    // Устанавливаем русскую локаль и кодировку консоли Windows-1251
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const std::string name = "points.txt";

    std::ifstream fin(name);
    if (!fin) {
        std::cerr << "Ошибка: не удалось открыть файл для чтения: " << name << std::endl;
        return 1;
    }

    std::istream_iterator<point> in_iter(fin), end_iter;
    std::vector<point> V(in_iter, end_iter);
    fin.close();

    std::stable_sort(V.begin(), V.end());

    std::ofstream fout(name);
    if (!fout) {
        std::cerr << "Ошибка: не удалось открыть файл для записи: " << name << std::endl;
        return 1;
    }

    std::ostream_iterator<point> out_iter(fout, "\n");
    std::copy(V.begin(), V.end(), out_iter);
    fout.close();

    std::cout << "Файл успешно отсортирован и перезаписан." << std::endl;
    return 0;
}
