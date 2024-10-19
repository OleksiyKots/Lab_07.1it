#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.1it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest071
{
	TEST_CLASS(UnitTest071)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 3;
            const int colCount = 3;
            int S = 0, k = 0;
            int** matrix = new int* [rowCount];

            // Створюємо тестову матрицю
            for (int i = 0; i < rowCount; i++) {
                matrix[i] = new int[colCount];
            }

            // Заповнюємо матрицю значеннями
            matrix[0][0] = 5;  matrix[0][1] = -7;  matrix[0][2] = 12;
            matrix[1][0] = 3;  matrix[1][1] = 14;  matrix[1][2] = 19;
            matrix[2][0] = -1; matrix[2][1] = 4;   matrix[2][2] = 6;

            Calc(matrix, rowCount, colCount, S, k);

            // Перевіряємо правильність результатів
            Assert::AreEqual(55, S);  
            Assert::AreEqual(9, k);   
		}
	};
}
