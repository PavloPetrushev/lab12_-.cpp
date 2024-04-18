// lab12_Петрушев.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

void findMaxMin(const vector<vector<int>>& matrix, int& maxRow, int& maxCol, int& minRow, int& minCol) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int maxVal = matrix[0][0];
    int minVal = matrix[0][0];
    maxRow = 0;
    maxCol = 0;
    minRow = 0;
    minCol = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows, cols;
    cout << "Введіть кількість рядків матриці: ";
    cin >> rows;
    cout << "Введіть кількість стовпців матриці: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxRow, maxCol, minRow, minCol;
    findMaxMin(matrix, maxRow, maxCol, minRow, minCol);

    cout << "Максимальний елемент " << matrix[maxRow][maxCol] << ", розташовано на позиції (" << maxRow << ", " << maxCol << ")" << endl;
    cout << "Мінімальний елемент " << matrix[minRow][minCol] << ", розташовано на позиції (" << minRow << ", " << minCol << ")" << endl;

    return 0;
}