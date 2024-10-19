#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// ������� ��� ���������, �����, ���������� �� ����������
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int col1, const int col2, const int rowCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    // ����� ���
    int Low = -34;
    int High = 26;
    int rowCount = 8;
    int colCount = 6;

    // ��������� �������
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // 1. ��������� ������� � ����������� ����������
    Create(a, rowCount, colCount, Low, High);

    // ��������� ��������� �������
    cout << "Initial matrix:" << endl;
    Print(a, rowCount, colCount);

    // 2. ���������� ������� �� �������� �������
    Sort(a, rowCount, colCount);

    // ��������� ����������� �������
    cout << "Sorted matrix:" << endl;
    Print(a, rowCount, colCount);

    // 3. ���������� ���� �� ������� �������� �� ������� (������ ��� ������)
    int S = 0; // ����
    int k = 0; // ʳ������
    Calc(a, rowCount, colCount, S, k);

    // ��������� ����������
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    // ��������� ������������ ������� (���� ����� �������� �� ���)
    cout << "Modified matrix" << endl;
    Print(a, rowCount, colCount);

    // ��������� ���'��
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// ��������� ������� � ����������� ����������
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// ��������� ������� �� �����
void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// ������� ���������� �������� ������� �� �������
void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < colCount - 1; i0++)
        for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
            if ((a[0][i1] < a[0][i1 + 1]) || // ������ ���� - �������� ������� ����� �� ���������
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] < a[1][i1 + 1]) || // ������ ���� - �������� ������� ����� �� ���������
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] == a[1][i1 + 1] && a[2][i1] < a[2][i1 + 1])) // ����� ���� - �������� �������� ����� �� ���������
                Change(a, i1, i1 + 1, rowCount);
}

// ������� ������������ ��������
void Change(int** a, const int col1, const int col2, const int rowCount)
{
    int tmp;
    for (int i = 0; i < rowCount; i++)
    {
        tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}

// ������� ��� ���������� ���� � ������� �������� �� ������� �� �� ����� �� ���
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            // �������: �� ������ ��� ������ �����
            if (a[i][j] > 0 || a[i][j] % 2 != 0)
            {
                S += a[i][j]; // ������ ������� �� ����
                k++; // �������� �������
                a[i][j] = 0; // ����� �������� �� 0
            }
}
