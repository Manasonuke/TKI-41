#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <locale>
#ifdef _WIN32
#include <windows.h> // для SetConsoleOutputCP
#endif

class Point {
private:
    int x;
    int y;
    std::string s;

public:
    // Конструктор по умолчанию
    Point() : x(0), y(0), s("") {}

    // Конструктор с параметрами (необязательно)
    Point(int x_, int y_, const std::string& s_) : x(x_), y(y_), s(s_) {}

    // Геттеры (если нужно где-то получить значения)
    int getX() const { return x; }
    int getY() const { return y; }
    const std::string& getS() const { return s; }

    // Оператор меньше для сортировки
    bool operator<(const Point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }

    // Друзья для операторов ввода/вывода, чтобы иметь доступ к private членам
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

// Оператор чтения
std::istream& operator>>(std::istream& is, Point& p) {
    return is >> p.x >> p.y >> p.s;
}

// Оператор записи
std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << p.x << ' ' << p.y << ' ' << p.s;
}

int main() {
    // Устанавливаем русскую локаль и кодировку консоли Windows-1251
    setlocale(LC_ALL, "Russian");
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    const std::string filename = "points.txt";

    // Открываем файл для чтения
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Ошибка: не удалось открыть файл для чтения: " << filename << std::endl;
        return 1;
    }

    // Считываем все точки из файла
    std::istream_iterator<Point> in_iter(fin), end_iter;
    std::vector<Point> points(in_iter, end_iter);
    fin.close();

    // Сортируем с помощью stable_sort
    std::stable_sort(points.begin(), points.end());

    // Записываем обратно в файл
    std::ofstream fout(filename);
    if (!fout) {
        std::cerr << "Ошибка: не удалось открыть файл для записи: " << filename << std::endl;
        return 1;
    }

    std::ostream_iterator<Point> out_iter(fout, "\n");
    std::copy(points.begin(), points.end(), out_iter);
    fout.close();

    std::cout << "Файл успешно отсортирован и перезаписан." << std::endl;
    return 0;
}

