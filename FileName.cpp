#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <locale> // ��� setlocale

int main() {
    // ��� ����������� ������ ������� �������� � Windows
    setlocale(LC_ALL, "Russian");

    // ��������� ����� ��� ������
    std::ifstream file1("name1.txt");
    std::ifstream file2("name2.txt");

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "������ �������� ������!" << std::endl;
        return 1;
    }

    // ������� ���� ���� 1 � ������ v1
    std::vector<double> v1((std::istream_iterator<double>(file1)), std::istream_iterator<double>());

    // ������� ���� ���� 2 � ������ v2
    std::vector<double> v2((std::istream_iterator<double>(file2)), std::istream_iterator<double>());

    // ��������� �������, ����� �������� ������
    size_t size = std::min(v1.size(), v2.size());

    std::vector<double> results;
    results.reserve(size);

    // ��������� �������� �� ����� �������� �������
    std::transform(v2.begin(), v2.begin() + size,
        v1.begin(), std::back_inserter(results),
        [](double b, double a) { return b - a; });

    // ������� ����������
    std::ostream_iterator<double> out_it(std::cout, "\n");
    std::copy(results.begin(), results.end(), out_it);

    return 0;
}

