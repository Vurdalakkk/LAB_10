// Необходимые библиотеки
#include <stdio.h>
#include <math.h>
#include <locale.h>

// 1 функция
double F1(double x) {
	if (x <= 3)
		return (pow(x, 2) - 3 * x + 9);
	else
		return 1 / (pow(x, 3) + 3);

}
// 2 функция
double F2(double x) {
	return (x * (exp(sin(pow(x, 2)))));
}

// Основная функция
int main() {
	// Русская локаль
	setlocale(LC_CTYPE,"RUS");
	
	// Инициализация переменных
	double x;
	char numb;
	char a;
	// Зацикленность вычисления
	while (1) {

		// Запрос на действие
		printf("Введите значение x и номер операции, которую хотите совершить:\n");
		printf("1. F1(x) = | x^2 - 3x + 9       x <= 3\n");
		printf("           | 1 / (x^3 + 3)      x > 3\n");
		printf("2. F2(x) = x * e ^ (sin (x^2) )\n");
		printf("3. F1(x) - F2(x)\n");
		printf("4. F1(x) * F2(x)\n");
		printf("5. 2 * ( F1(x) + F2(x) )\n");

		scanf("%lf %c", &x, &numb);
		getchar();
		
		// Цикл проверки выбора пользователя

		switch (numb) {
		case '1': {
			printf("F1(%lf) = %lf", x, F1(x));
			break;
		}
		case '2':{
			printf("F2(%lf) = %lf", x,  F2(x));
			break;
		}
		case '3':{
			printf("F1(%lf) - F2(%lf) = %lf", x, x, (F1(x) - F2(x)) );
			break;
		}
		case '4':{
			printf("F1(%lf) * F2(%lf) = %lf", x, x, F1(x) * F2(x));
			break;
		}
		case '5':{
			printf("2 * ( F1(%lf) + F2(%lf) ) = %lf", x, x, 2 * (F1(x) + F2(x)));
			break;
		}
		default:{
			printf("Вы ввели некорректный номер действия");
			break;
		}
		}
		printf("\nХотите продолжить? (Да - y, Нет - n)");
		if ((a = getchar()) == 'n') break;
	
	}
	return 0;
}