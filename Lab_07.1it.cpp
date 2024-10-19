#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Функції для створення, друку, сортування та обчислення
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int col1, const int col2, const int rowCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    // Вхідні дані
    int Low = -34;
    int High = 26;
    int rowCount = 8;
    int colCount = 6;

    // Створення матриці
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // 1. Створення матриці з випадковими елементами
    Create(a, rowCount, colCount, Low, High);

    // Виведення початкової матриці
    cout << "Initial matrix:" << endl;
    Print(a, rowCount, colCount);

    // 2. Сортування матриці за заданими ключами
    Sort(a, rowCount, colCount);

    // Виведення відсортованої матриці
    cout << "Sorted matrix:" << endl;
    Print(a, rowCount, colCount);

    // 3. Обчислення суми та кількості елементів за критерієм (додатні або непарні)
    int S = 0; // Сума
    int k = 0; // Кількість
    Calc(a, rowCount, colCount, S, k);

    // Виведення результатів
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    // Виведення модифікованої матриці (після заміни елементів на нулі)
    cout << "Modified matrix" << endl;
    Print(a, rowCount, colCount);

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Створення матриці з випадковими значеннями
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Виведення матриці на екран
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

// Функція сортування стовпців матриці за ключами
void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < colCount - 1; i0++)
        for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
            if ((a[0][i1] < a[0][i1 + 1]) || // Перший ключ - елементи першого рядка за спаданням
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] < a[1][i1 + 1]) || // Другий ключ - елементи другого рядка за спаданням
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] == a[1][i1 + 1] && a[2][i1] < a[2][i1 + 1])) // Третій ключ - елементи третього рядка за спаданням
                Change(a, i1, i1 + 1, rowCount);
}

// Функція перестановки стовпців
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

// Функція для обчислення суми і кількості елементів за критерієм та їх заміни на нулі
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            // Критерій: всі додатні або непарні числа
            if (a[i][j] > 0 || a[i][j] % 2 != 0)
            {
                S += a[i][j]; // Додаємо елемент до суми
                k++; // Збільшуємо кількість
                a[i][j] = 0; // Заміна елемента на 0
            }
}
