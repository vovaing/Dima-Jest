//#include <stdio.h>                  //Лаба 4 задание 1
//#include <stdlib.h>
//#include <time.h>
//
//#define MAX_SIZE 100
//
//// Функция для безопасного ввода целого числа
//int input_integer(const char* prompt) {
//    int value;
//    char term;
//    while (1) {
//        printf("%s", prompt);
//        if (scanf("%d%c", &value, &term) == 2 && term == '\n') {
//            return value;
//        } else {
//            printf("Ошибка ввода. Попробуйте снова.\n");
//            while (getchar() != '\n'); // Очищаем ввод
//        }
//    }
//}
//
//// Функция для вычисления характеристики строки
//int calculate_row_characteristic(int row[], int cols) {
//    int sum = 0;
//    for (int i = 0; i < cols; i++) {
//        if (row[i] > 0 && row[i] % 2 == 0) {
//            sum += row[i];
//        }
//    }
//    return sum;
//}
//
//// Функция для сортировки строк матрицы по характеристикам
//void sort_rows(int matrix[][MAX_SIZE], int rows, int cols) {
//    int characteristics[MAX_SIZE];
//    
//    // Вычисляем характеристики для каждой строки
//    for (int i = 0; i < rows; i++) {
//        characteristics[i] = calculate_row_characteristic(matrix[i], cols);
//    }
//    
//    // Сортируем строки матрицы по возрастанию характеристик
//    for (int i = 0; i < rows - 1; i++) {
//        for (int j = 0; j < rows - i - 1; j++) {
//            if (characteristics[j] > characteristics[j + 1]) {
//                // Меняем строки местами
//                for (int k = 0; k < cols; k++) {
//                    int temp = matrix[j][k];
//                    matrix[j][k] = matrix[j + 1][k];
//                    matrix[j + 1][k] = temp;
//                }
//                // Меняем местами характеристики
//                int temp = characteristics[j];
//                characteristics[j] = characteristics[j + 1];
//                characteristics[j + 1] = temp;
//            }
//        }
//    }
//}
//
//// Функция для вывода матрицы
//void print_matrix(int matrix[][MAX_SIZE], int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            printf("%4d ", matrix[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//// Функция для инициализации матрицы случайными значениями
//void initialize_matrix_random(int matrix[][MAX_SIZE], int rows, int cols, int max_value) {
//    srand(time(NULL));
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            matrix[i][j] = rand() % (2 * max_value + 1) - max_value; // Случайные числа в диапазоне [-max_value, max_value]
//        }
//    }
//}
//
//// Функция для ввода матрицы с клавиатуры
//void input_matrix(int matrix[][MAX_SIZE], int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            char prompt[50];
//            sprintf(prompt, "Введите элемент [%d][%d]: ", i + 1, j + 1);
//            matrix[i][j] = input_integer(prompt);
//        }
//    }
//}
//
//int main() {
//    int matrix[MAX_SIZE][MAX_SIZE];
//    int rows, cols, choice;
//
//    while (1) {
//        rows = input_integer("Введите количество строк (1-100): ");
//        if (rows > 0 && rows <= MAX_SIZE) break;
//        printf("Неверное значение. Попробуйте снова.\n");
//    }
//
//    while (1) {
//        cols = input_integer("Введите количество столбцов (1-100): ");
//        if (cols > 0 && cols <= MAX_SIZE) break;
//        printf("Неверное значение. Попробуйте снова.\n");
//    }
//
//    while (1) {
//        choice = input_integer("Выберите способ заполнения матрицы (1 - Ввод с клавиатуры, 2 - Случайные числа): ");
//        if (choice == 1 || choice == 2) break;
//        printf("Неверное значение. Попробуйте снова.\n");
//    }
//
//    if (choice == 1) {
//        input_matrix(matrix, rows, cols);
//    } else if (choice == 2) {
//        int max_value;
//        while (1) {
//            max_value = input_integer("Введите максимальное значение для случайных чисел (>0): ");
//            if (max_value > 0) break;
//            printf("Максимальное значение должно быть больше 0. Попробуйте снова.\n");
//        }
//        initialize_matrix_random(matrix, rows, cols, max_value);
//    }
//
//    printf("\nИсходная матрица:\n");
//    print_matrix(matrix, rows, cols);
//
//    sort_rows(matrix, rows, cols);
//
//    printf("\nМатрица после сортировки строк по характеристикам:\n");
//    print_matrix(matrix, rows, cols);
//
//    return 0;
//}



//#include <stdio.h>                  //Задание 2 Лаба 4
//#include <stdlib.h>
//#include <time.h>
//
//#define MAX_SIZE 100
//
//// Функция для безопасного ввода целого числа
//int input_integer(const char* prompt) {
//    int value;
//    char term;
//    while (1) {
//        printf("%s", prompt);
//        if (scanf("%d%c", &value, &term) == 2 && term == '\n') {
//            return value;
//        } else {
//            printf("Ошибка ввода. Попробуйте снова.\n");
//            while (getchar() != '\n'); // Очищаем ввод
//        }
//    }
//}
//
//// Функция для ввода матрицы с клавиатуры
//void input_matrix(int matrix[][MAX_SIZE], int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            char prompt[50];
//            sprintf(prompt, "Введите элемент [%d][%d]: ", i + 1, j + 1);
//            matrix[i][j] = input_integer(prompt);
//        }
//    }
//}
//
//// Функция для инициализации матрицы случайными числами
//void initialize_matrix_random(int matrix[][MAX_SIZE], int rows, int cols, int max_value) {
//    srand(time(NULL));
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            matrix[i][j] = rand() % (2 * max_value + 1) - max_value; // Случайные числа в диапазоне [-max_value, max_value]
//        }
//    }
//}
//
//// Функция для вывода матрицы
//void print_matrix(int matrix[][MAX_SIZE], int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            printf("%4d ", matrix[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//// Функция для поиска первой строки с отрицательным элементом
//int find_row_with_negative(int matrix[][MAX_SIZE], int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            if (matrix[i][j] < 0) {
//                return i; // Возвращаем номер строки (индекс с 0)
//            }
//        }
//    }
//    return -1; // Если таких строк нет
//}
//
//// Функция для уменьшения всех элементов столбца вдвое
//void halve_column(int matrix[][MAX_SIZE], int rows, int col_index) {
//    for (int i = 0; i < rows; i++) {
//        matrix[i][col_index] /= 2;
//    }
//}
//
//int main() {
//    int matrix[MAX_SIZE][MAX_SIZE];
//    int rows, cols, choice;
//
//    // Ввод количества строк и столбцов с проверкой
//    while (1) {
//        rows = input_integer("Введите количество строк (1-100): ");
//        if (rows > 0 && rows <= MAX_SIZE) break;
//        printf("Неверное значение. Попробуйте снова.\n");
//    }
//
//    while (1) {
//        cols = input_integer("Введите количество столбцов (1-100): ");
//        if (cols > 0 && cols <= MAX_SIZE) break;
//        printf("Неверное значение. Попробуйте снова.\n");
//    }
//
//    // Выбор способа заполнения матрицы
//    while (1) {
//        choice = input_integer("Выберите способ заполнения матрицы (1 - Ввод с клавиатуры, 2 - Случайные числа): ");
//        if (choice == 1 || choice == 2) break;
//        printf("Неверное значение. Попробуйте снова.\n");
//    }
//
//    if (choice == 1) {
//        input_matrix(matrix, rows, cols);
//    } else if (choice == 2) {
//        int max_value;
//        while (1) {
//            max_value = input_integer("Введите максимальное значение для случайных чисел (>0): ");
//            if (max_value > 0) break;
//            printf("Максимальное значение должно быть больше 0. Попробуйте снова.\n");
//        }
//        initialize_matrix_random(matrix, rows, cols, max_value);
//    }
//
//    printf("\nИсходная матрица:\n");
//    print_matrix(matrix, rows, cols);
//
//    // Поиск строки с отрицательным элементом
//    int row_index = find_row_with_negative(matrix, rows, cols);
//
//    if (row_index == -1) {
//        printf("\nВ матрице нет строк с отрицательными элементами.\n");
//    } else {
//        printf("\nПервая строка с отрицательным элементом: %d\n", row_index + 1);
//
//        // Уменьшаем элементы столбца вдвое
//        halve_column(matrix, rows, row_index);
//
//        printf("\nМатрица после изменения:\n");
//        print_matrix(matrix, rows, cols);
//    }
//
//    return 0;
//}


#include <stdio.h>                         //Лаба 5 задание 1
#include <stdlib.h>
#include <time.h>

// Проверка корректного ввода
int get_valid_int(const char* prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            return value;
        } else {
            printf("Некорректный ввод. Попробуйте снова.\n");
            while (getchar() != '\n'); // Очистка ввода
        }
    }
}

// Функция для заполнения массива случайными числами
void fill_array_random(int* arr, int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

// Задача 1: Удалить все элементы массива, кратные 11
void task1() {
    int n = get_valid_int("Введите размер массива: ");
    int random_choice = get_valid_int("Хотите заполнить массив случайными числами? (1 - Да, 0 - Нет): ");

    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    if (random_choice) {
        int min = get_valid_int("Введите минимальное значение: ");
        int max = get_valid_int("Введите максимальное значение: ");
        fill_array_random(arr, n, min, max);
        printf("Сгенерированный массив:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Введите элементы массива:\n");
        for (int i = 0; i < n; i++) {
            arr[i] = get_valid_int("");
        }
    }

    printf("Массив после удаления элементов, кратных 11:\n");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 11 != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    free(arr);
}

// Задача 2: В каждой строке двумерного массива удалить все максимальные элементы
void task2() {
    int rows = get_valid_int("Введите количество строк: ");

    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (!matrix) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    for (int i = 0; i < rows; i++) {
        int cols = get_valid_int("Введите количество чисел в строке (последнее число должно быть 0): ");
        
        matrix[i] = (int*)malloc((cols + 1) * sizeof(int));
        if (!matrix[i]) {
            printf("Ошибка выделения памяти!\n");
            return;
        }

        int random_choice = get_valid_int("Заполнить строку случайными числами? (1 - Да, 0 - Нет): ");
        if (random_choice) {
            int min = get_valid_int("Введите минимальное значение: ");
            int max = get_valid_int("Введите максимальное значение: ");
            fill_array_random(matrix[i], cols, min, max);
            matrix[i][cols] = 0; // Последний элемент — 0
            printf("Сгенерированная строка:\n");
            for (int j = 0; j <= cols; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        } else {
            printf("Введите элементы строки %d (завершите ввод числом 0):\n", i + 1);
            for (int j = 0; j <= cols; j++) {
                matrix[i][j] = get_valid_int("");
            }
        }
    }

    printf("Массив после удаления максимальных элементов в каждой строке:\n");
    for (int i = 0; i < rows; i++) {
        int max_val = matrix[i][0];
        int j = 0;

        while (matrix[i][j] != 0) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
            }
            j++;
        }

        for (j = 0; matrix[i][j] != 0; j++) {
            if (matrix[i][j] != max_val) {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("0\n");
        free(matrix[i]);
    }

    free(matrix);
}

// Задача 3: Удалить строки с более чем 2 нулями подряд
void task3() {
    int n = get_valid_int("Введите количество строк (N): ");
    int m = get_valid_int("Введите количество столбцов (M): ");

    int** matrix = (int**)malloc(n * sizeof(int*));
    if (!matrix) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    srand(time(NULL));
    printf("Изначальная матрица:\n");
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
        if (!matrix[i]) {
            printf("Ошибка выделения памяти!\n");
            return;
        }

        int random_choice = get_valid_int("Заполнить строку случайными числами? (1 - Да, 0 - Нет): ");
        if (random_choice) {
            fill_array_random(matrix[i], m, 0, 4); // случайные числа от 0 до 4
        } else {
            printf("Введите элементы строки %d:\n", i + 1);
            for (int j = 0; j < m; j++) {
                matrix[i][j] = get_valid_int("");
            }
        }

        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Матрица после удаления строк с более чем 2 нулями подряд:\n");
    for (int i = 0; i < n; i++) {
        int zero_count = 0;
        int has_too_many_zeros = 0;

        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                zero_count++;
                if (zero_count > 2) {
                    has_too_many_zeros = 1;
                    break;
                }
            } else {
                zero_count = 0;
            }
        }

        if (!has_too_many_zeros) {
            for (int j = 0; j < m; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        free(matrix[i]);
    }

    free(matrix);
}

int main() {
    int choice = -1;
    while (choice != 0) {
        printf("Выберите задачу:\n");
        printf("1 - Удалить элементы массива, кратные 11\n");
        printf("2 - Удалить максимальные элементы в строках двумерного массива\n");
        printf("3 - Удалить строки с более чем 2 нулями подряд\n");

        choice = get_valid_int("Ваш выбор: ");
        
        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            default:
                printf("Неверный выбор! Попробуйте снова.\n");
        }
    }

    return 0;
}


