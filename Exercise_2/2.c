// Необходимые библиотеки
#include <stdio.h>
#include <math.h>
#include <locale.h>

// Константа pi
#define PI 3.141592653589793

// Функция для вычисления arccos через сумму N членов ряда
double arccos_n(double x, int N) {
    double sum = x;  // начинаем с x

    for (int n = 1; n < N; n++) {
        // Числитель
        double chislitel = 1.0;
        for (int i = 1; i <= n; i++) {
            chislitel = chislitel * (2.0 * i - 1.0);
        }

        // Знаменатель
        double znamenatel = 1.0;
        for (int i = 1; i <= n; i++) {
            znamenatel = znamenatel * (2.0 * i);
        }

        // x^(2n+1)
        double x_power = 1.0;
        for (int j = 0; j < (2 * n + 1); j++) {
            x_power = x_power * x;
        }

        // Член ряда
        double term = (chislitel * x_power) / (znamenatel * (2 * n + 1));
        sum = sum + term;
    }

    // arccos(x) = π/2 - сумма
    return PI / 2.0 - sum;
}

// Функция для вычисления arccos с заданной точностью
double arccos_eps(double x, double eps) {
    double sum = x;
    int n = 1;
    int count = 0;

    while (1) {
        // Числитель
        double chislitel = 1.0;
        for (int i = 1; i <= n; i++) {
            chislitel = chislitel * (2.0 * i - 1.0);
        }

        // Знаменатель
        double znamenatel = 1.0;
        for (int i = 1; i <= n; i++) {
            znamenatel = znamenatel * (2.0 * i);
        }

        // x^(2n+1)
        double x_power = 1.0;
        for (int j = 0; j < (2 * n + 1); j++) {
            x_power = x_power * x;
        }

        // Член ряда
        double term = (chislitel * x_power) / (znamenatel * (2 * n + 1));

        // Проверка точности
        if (term < 0) {
            term = -term;
        }

        if (term < eps) {
            break;
        }

        sum = sum + term;
        n = n + 1;
        count = count + 1;

        if (count > 1000) {
            break;
        }
    }

    // arccos(x) = π/2 - сумма
    return PI / 2.0 - sum;
}

// Основная функция
int main() {
    // Русская локаль
    setlocale(LC_CTYPE, "RUS");

    // Инициализация переменных
    double x, eps;
    int N;

    // Ввод данных
    printf("Введите x (от -1 до 1): ");
    scanf("%lf", &x);

    // Проверка ввода
    if (x < -1 || x > 1) {
        printf("Ошибка! x должен быть от -1 до 1.\n");
        return 0;
    }

    printf("Введите количество членов ряда N: ");
    scanf("%d", &N);

    printf("Введите точность eps (например, 0.000001): ");
    scanf("%lf", &eps);

    printf("\n");

    // 1. Стандартная функция
    double acos_std = acos(x);
    printf("1. Стандартная функция acos(x):\n");
    printf("   arccos(%.3f) = %.10f градусов\n\n", x, acos_std * 180.0 / PI);

    // 2. Используем функцию arccos_n
    double result_n = arccos_n(x, N);
    printf("2. Функция arccos_n(x, N):\n");
    printf("   arccos(%.3f) = %.10f градусов\n", x, result_n * 180.0 / PI);
    printf("   Погрешность: %.10f градусов\n\n",
        fabs(acos_std * 180.0 / PI - result_n * 180.0 / PI));

    // 3. Используем функцию arccos_eps
    double result_eps = arccos_eps(x, eps);
    printf("3. Функция arccos_eps(x, eps):\n");
    printf("   arccos(%.3f) = %.10f градусов\n", x, result_eps * 180.0 / PI);
    printf("   Погрешность: %.10f градусов\n\n",
        fabs(acos_std * 180.0 / PI - result_eps * 180.0 / PI));

    // Сравнение результатов
    printf("Сравнение результатов:\n");
    printf("|---------------------|---------------------|\n");
    printf("| Метод               | Значение (град)     |\n");
    printf("|---------------------|---------------------|\n");
    printf("| Стандартный acos()  | %-19.10f |\n", acos_std * 180.0 / PI);
    printf("| arccos_n (N=%d)      | %-19.10f |\n", N, result_n * 180.0 / PI);
    printf("| arccos_eps (%.0e)  | %-19.10f |\n", eps, result_eps * 180.0 / PI);
    printf("|---------------------|---------------------|\n");

    return 0;
}