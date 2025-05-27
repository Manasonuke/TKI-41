#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>

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

    // ��������� ��� ������ ����� �� ������
    std::istream_iterator<double> iter1(file1);
    std::istream_iterator<double> end1;

    std::istream_iterator<double> iter2(file2);
    std::istream_iterator<double> end2;

    // ������ ��� �������� �����������
    std::vector<double> results;

    // ���������� transform ��� ���������� ���������
    std::transform(iter2, end2, iter1, std::back_inserter(results),
        [](double b, double a) { return b - a; });

    // ������� ���������� � ������� ostream_iterator
    std::ostream_iterator<double> out_it(std::cout, "\n");
    std::copy(results.begin(), results.end(), out_it);

    return 0;
}