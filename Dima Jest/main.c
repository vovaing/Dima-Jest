#include <stdio.h>                      //Лаба 4, задание 1
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int random) {
    if (random) {
        srand(time(NULL));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = rand() % 100; // случайные числа от 0 до 99
            }
        }
    } else {
        printf("Введите элементы матрицы:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                while (1) {
                    printf("matrix[%d][%d]: ", i, j);
                    if (scanf("%d", &matrix[i][j]) == 1) {
                        break; // корректный ввод, выходим из цикла
                    } else {
                        printf("Ошибка ввода. Пожалуйста, введите целое число.\n");
                        while (getchar() != '\n'); // очистка буфера ввода
                    }
                }
            }
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Матрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int countNonZeroRows(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        int hasZero = 0;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                hasZero = 1;
                break;
            }
        }
        if (!hasZero) {
            count++;
        }
    }
    return count;
}

int findMaxRepeatingNumber(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int freq[100] = {0}; // массив для подсчета частоты каждого числа
    int maxRepeating = -1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            freq[matrix[i][j]]++;
            if (freq[matrix[i][j]] > 1 && matrix[i][j] > maxRepeating) {
                maxRepeating = matrix[i][j];
            }
        }
    }

    return maxRepeating;
}

int main() {
    int rows, cols, random;
    int matrix[MAX_SIZE][MAX_SIZE];
    
    printf("Введите количество строк и столбцов матрицы (не более %d): ", MAX_SIZE);
    while (1) {
        if (scanf("%d %d", &rows, &cols) == 2 && rows > 0 && cols > 0 && rows <= MAX_SIZE && cols <= MAX_SIZE) {
            break;
        } else {
            printf("Некорректный ввод. Пожалуйста, введите два положительных целых числа не превышающих %d.\n", MAX_SIZE);
            while (getchar() != '\n'); // очистка буфера ввода
        }
    }
    
    printf("Заполнить матрицу случайными числами? (1 - да, 0 - нет): ");
    while (1) {
        if (scanf("%d", &random) == 1 && (random == 0 || random == 1)) {
            break;
        } else {
            printf("Некорректный ввод. Пожалуйста, введите 0 или 1.\n");
            while (getchar() != '\n'); // очистка буфера ввода
        }
    }
    
    fillMatrix(matrix, rows, cols, random);
    
    printMatrix(matrix, rows, cols);
    
    int nonZeroRows = countNonZeroRows(matrix, rows, cols);
    int maxRepeating = findMaxRepeatingNumber(matrix, rows, cols);
    
    if (maxRepeating == -1) {
        printf("В матрице нет чисел, встречающихся более одного раза.\n");
    } else {
        printf("Количество строк без нулей: %d\n", nonZeroRows);
        printf("Максимальное число, встречающееся более одного раза: %d\n", maxRepeating);
    }
    
    return 0;
}hlinen
typedef <#returnType#>(^<#name#>)(<#arguments#>);
