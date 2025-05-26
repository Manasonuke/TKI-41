#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

int main() {
    // �������� ������� ������
    std::ifstream file1("name1.txt");
    std::ifstream file2("name2.txt");

    if (!file1 || !file2) {
        std::cerr << "������ �������� ������!" << std::endl;
        return 1;
    }

    // ��������� ��� ������ ������������ �����
    std::istream_iterator<double> it1(file1), end;
    std::istream_iterator<double> it2(file2);

    // ������� ��� �������� ��������� ������
    std::vector<double> A(it1, end); // ������ �� file1
    std::vector<double> B(it2, end); // ������ �� file2

    // ��������, ��� ���������� ����� ���������
    if (A.size() != B.size()) {
        std::cerr << "����� �������� ������ ���������� �����!" << std::endl;
        return 2;
    }

    // ������ ��� �������� ���������
    std::vector<double> result(A.size());

    // ���������� ��������� B[i] - A[i]
    std::transform(B.begin(), B.end(), A.begin(), result.begin(),
        [](double b, double a) { return b - a; });

    // ����� ����������
    std::ostream_iterator<double> out(std::cout, "\n");
    std::copy(result.begin(), result.end(), out);

    return 0;
}

