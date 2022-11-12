#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(0, "Rus");
	cout << "Задание 1:" << "\n";                                           // Заданеие 1
	cout << "Тип данных int занимает в памяти " << sizeof(int) << " бита." << "\n";
	cout << "Тип данных short int занимает в памяти " << sizeof(short int) << " бита." << "\n";
	cout << "Тип данных long int занимает в памяти " << sizeof(long int) << " бита." << "\n";
	cout << "Тип данных float занимает в памяти " << sizeof(float) << " бита." << "\n";
	cout << "Тип данных double занимает в памяти " << sizeof(double) << " бита." << "\n";
	cout << "Тип данных long double занимает в памяти " << sizeof(long double) << " бита." << "\n";
	cout << "Тип данных char занимает в памяти " << sizeof(char) << " бита." << "\n";
	cout << "Тип данных bool занимает в памяти " << sizeof(bool) << " бита." << "\n";

	cout << "\n" << "\n" << "Задание 2:" << "\n";                           // Заданеие 2
	cout << "1 - запусть программу; 0 - остановить программу\n";
	while (true) {
		int n;
		cin >> n;
		if (n == 1) {
			int number;
			int order = sizeof(int) * 8;
			unsigned mask = 1 << (order - 1);
			cout << "Введите натуральное число: ";
			cin >> number;
			for (int i = 1; i <= order; ++i)
			{
				cout << "\x1B[33m";
				putchar(number & mask ? '1' : '0');
				mask >>= 1;
				if (i == 1 || i % 8 == 0) {
					putchar(' ');
				}
			}
			cout << "\x1B[37m" << endl;
		}
		if (n == 0) {
			break;
		}
		if (n != 0 && n != 1)
			cout << "Ошибка" << endl;
	}

	cout << "\n" << "\n" << "Задание 3:" << "\n";                           // Заданеие 3
	cout << "1 - запусть программу; 0 - остановить программу\n";
	while (true) {
		int n;
		cin >> n;
		if (n == 1) {
			int order = sizeof(float) * 8;
			unsigned mask = 1 << (order - 1);
			union {
				int number;
				float numberf;
			};
			cout << "Введите вещественное число: ";
			cin >> numberf;
			for (int i = 1; i <= order; ++i)
			{
				if (i == 1) {
					cout << "\x1B[36m";
				}
				else if ((i > 1) && (i <= 9)) {
					cout << "\x1B[34m";
				}
				else {
					cout << "\x1B[35m";
				}
				putchar(number & mask ? '1' : '0');
				mask >>= 1;
				if (i == 1 || i == 9) {
					putchar(' ');
				}
			}
			cout << "\x1B[37m" << endl;
		}
		if (n == 0) {
			break;
		}
		if (n != 0 && n != 1)
			cout << "Ошибка" << endl;
	}

	cout << "\n" << "\n" << "Задание 4:" << "\n";                           // Заданеие 4
	cout << "1 - запусть программу; 0 - остановить программу\n";
	while (true) {
		int n;
		cin >> n;
		if (n == 1) {
			union {
				int Array[2];
				double number;
			};
			int order = sizeof(double) * 8;
			unsigned mask = 1 << (order - 1);
			order = (sizeof(double) * 8) / 2;
			cout << "Введите вещественное число: ";
			cin >> number;
			int j = 1;
			for (int i = 1; i <= order; ++i) {
				if (i == 1) {
					cout << "\x1B[36m";
				}
				else if ((i > 1) && (i <= 12)) {
					cout << "\x1B[34m";
				}
				else {
					cout << "\x1B[35m";
				}
				putchar(Array[j] & mask ? '1' : '0');
				mask >>= 1;
				if (i == 1 || i == 12) {
					putchar(' ');
				}
			}
			j = 0;
			mask = 1 << (order - 1);
			for (int i = 1; i <= order; ++i) {
				putchar(Array[j] & mask ? '1' : '0');
				mask >>= 1;
			}
			cout << "\x1B[37m" << endl;
		}
		if (n == 0) {
			break;
		}
		if (n != 0 && n != 1)
			cout << "Ошибка" << endl;
	}

	// 13
	// Если число отрицательное, то необходимо поменять значение четных битов на 0, 
	// если положительное, то поменять значение нечетных битов на 1
	setlocale(0, "Rus");
	cout << "\x1B[33m" << "\n" << "\n" << "ИДЗ №13:" << "\n";
	cout << "У введённого числа, если оно отрицательное, поменяется значение четныхбитов на 0,\n";
	cout << "если оно положительное, поменятся значение нечетных битов на 1\n";
	cout << "Выберите тип вводимого числа:\n";
	cout << "i - тип дыннх int; f - тип дыннх float; d - тип дыннх double; c - остановить программу\n";   // a
	cout << "\x1B[37m";
	while (true) {
		string a;
		cin >> a;

		if (a == "i") {
			cout << "Введите натуральное число: ";
			int number;
			cin >> number;
			int order = sizeof(int) * 8;
			unsigned mask = 1 << (order - 1);
			if (number >= 0) {
				for (int i = 1; i <= order; i += 2) {
					if (!(mask & number)) {
						number = mask | number;
					}
					mask >>= 2;
				}
			}
			else {
				mask = 1 << (order - 2);
				for (int i = 1; i <= order; i += 2) {
					if (mask & number) {
						number = ~(mask)&number;
					}
					mask >>= 2;
				}
			}
			cout << "\x1B[32m" << number << "\x1B[37m" << endl;
		}

		else if (a == "f") {
			union {
				int number;
				float number_f;
			};
			int order = sizeof(float) * 8;
			unsigned mask = 1 << (order - 1);
			cout << "Введите вещественное число: ";
			cin >> number_f;
			if (number >= 0) {
				for (int i = 1; i <= order; i += 2) {
					if (!(mask & number)) {
						number = mask | number;
					}
					mask >>= 2;
				}
			}
			else {
				mask = 1 << (order - 2);
				for (int i = 1; i <= order; i += 2) {
					if (mask & number) {
						number = (~mask) & number;
					}
					mask >>= 2;
				}
			}
			cout << "\x1B[32m" << number << "\x1B[37m" << endl;
		}

		else if (a == "d") {
			union {
				int Array[2];
				double number;
			};
			int order = sizeof(double) * 8 / 2;
			cout << "Введите вещественное число: ";
			cin >> number;

			if (number >= 0) {
				unsigned mask = 1 << (order - 1);
				for (int i = 1; i <= order; i += 2) {
					if (!(mask & Array[1])) {
						Array[1] = mask | Array[1];
					}
					mask >>= 2;
				}
				mask = 1 << (order - 1);
				for (int i = 1; i <= order; i += 2) {
					if (!(mask & Array[0])) {
						Array[0] = mask | Array[0];
					}
					mask >>= 2;
				}
			}
			else {
				unsigned mask = 1 << (order - 2);
				for (int i = 1; i <= order; i += 2) {
					if (mask & Array[1]) {
						Array[1] = (~mask) & Array[1];
					}
					mask >>= 2;
				}
				mask = 1 << (order - 2);
				for (int i = 1; i <= order; i += 2) {
					if (mask & Array[0]) {
						Array[0] = (~mask) & Array[0];
					}
					mask >>= 2;
				}
			}
			cout << "\x1B[32m" << number << "\x1B[37m" << endl;

		}
		else if (a == "c") {
			cout << "Конец" << endl;
			break;
		}
		else {
			cout << "Ошибка" << endl;
		}
	}
}