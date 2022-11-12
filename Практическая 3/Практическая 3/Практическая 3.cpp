#include <iostream>
#include <string>
#include <thread>
#include <Windows.h>

using namespace std;

//Функция для перемещения по координатам консоли

void XY(short x, short y, int n = 0)
{
    COORD p = { x, y };  //Структура, определяющая координаты в буфере консоли
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
    this_thread::sleep_for(chrono::milliseconds(100));
}

void out(int N, int* pArr)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (*pArr >= 0 && *pArr <= 9) {
                cout << *(pArr++) << "     ";
            }
            else if (*pArr >= 10 || (*pArr <= -1 && *pArr >= -9)) {
                cout << *(pArr++) << "    ";
            }
            else {
                cout << *(pArr++) << "   ";
            }

        }
        cout << "\n";
    }
    cout << "\n";
}

void spiral(int N, int* pArr, short x, short y)
{
    int n = N--;    // n = N, N = N - 1
    x = -4;
    pArr--;
    for (int i = 0; i < n; i++) {
        pArr++;
        *pArr = 1 + rand() % (N * N);
        x += 6; XY(x, y);
        cout << *pArr;
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < N; i++) {
            pArr += n;
            *pArr = 1 + rand() % (N * N);
            y += 1; XY(x, y);
            cout << *pArr;
        }
        for (int i = 0; i < N; i++) {
            pArr--;
            *pArr = 1 + rand() % (N * N);
            x -= 6; XY(x, y);
            cout << *pArr;
        }
        N--;
        for (int i = 0; i < N; i++) {
            pArr -= n;
            *pArr = 1 + rand() % (N * N);
            y -= 1; XY(x, y);
            cout << *pArr;
        }
        for (int i = 0; i < N; i++) {
            pArr++;
            *pArr = 1 + rand() % (N * N);
            x += 6; XY(x, y);
            cout << *pArr;
        }
        N--;
    }
    y += (n / 2 + 1); x = 0; XY(x, y);
}

void snake(const int N, int* pArr, short x, short y)
{
    x = 1;
    *pArr = 1 + rand() % (N * N);
    XY(x, y); cout << *pArr;
    for (int i = 0; i < N / 2; i++) {
        for (int j = 1; j < N; j++) {
            pArr += N;
            *pArr = 1 + rand() % (N * N);
            y += 1; XY(x, y);
            cout << *pArr;
        }
        pArr++; *pArr = 1 + rand() % (N * N);
        x += 6; XY(x, y);
        cout << *pArr;
        for (int j = 1; j < N; j++) {
            pArr -= N;
            *pArr = 1 + rand() % (N * N);
            y -= 1; XY(x, y);
            cout << *pArr;
        }
        pArr++;
        if (i != N / 2 - 1) {
            *pArr = 1 + rand() % (N * N);
            x += 6; XY(x, y);
            cout << *pArr;
        }
    }
    y += N + 1; x = 0; XY(x, y);
}

void transpositionA(const int N, int* pArr) //Меняет подматрицы по часовой стрелке
{
    int* p1Arr = pArr, * p2Arr = pArr + N / 2, * p3Arr = pArr, * p4Arr = pArr + N * N / 2, * p5Arr = pArr + N * N / 2, * p6Arr = p4Arr + N / 2;
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            swap(*(p1Arr++), *(p2Arr++));
        }
        p1Arr += N / 2, p2Arr += N / 2;
    }
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            swap(*(p3Arr++), *(p4Arr++));
        }
        p3Arr += N / 2, p4Arr += N / 2;
    }
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            swap(*(p5Arr++), *(p6Arr++));
        }
        p5Arr += N / 2, p6Arr += N / 2;
    }
    cout << "Новый массив:\n"; out(N, pArr);
}

void transpositionB(const int N, int* pArr) //Меняет диагональные подматрицы
{
    int* p1Arr = pArr, * p3Arr = pArr + N / 2, * p4Arr = pArr + N * N / 2, * p2Arr = p4Arr + N / 2;
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            swap(*(p1Arr++), *(p2Arr++));
        }
        p1Arr += N / 2, p2Arr += N / 2;
    }
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            swap(*(p3Arr++), *(p4Arr++));
        }
        p3Arr += N / 2, p4Arr += N / 2;
    }
    cout << "Новый массив:\n"; out(N, pArr);
}

void transpositionC(const int N, int* pArr)  //Меняет верхние и нижние подматрицы
{
    int* p1Arr = pArr, * p2Arr = pArr + N * N / 2;
    for (int i = 0; i < N * N / 2; i++) {
        swap(*(p1Arr++), *(p2Arr++));
    }
    cout << "Новый массив:\n"; out(N, pArr);
}

void transpositionD(const int N, int* pArr) //Меняет правые и левые подматрицы
{
    int* p1Arr = pArr, * p2Arr = pArr + N / 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            swap(*(p1Arr++), *(p2Arr++));
        }
        p1Arr += N / 2, p2Arr += N / 2;
    }
    cout << "Новый массив:\n"; out(N, pArr);
}

void _plus(int N, int* pArr, int value) {
    for (int i = 0; i < N * N; i++) {
        *(pArr + i) += value;
    }
    cout << "\n"; out(N, pArr);
}

void _minus(int N, int* pArr, int value) {
    for (int i = 0; i < N * N; i++) {
        *(pArr + i) -= value;
    }
    cout << "\n"; out(N, pArr);
}

void _multiply(int N, int* pArr, int value) {
    for (int i = 0; i < N * N; i++) {
        *(pArr + i) *= value;
    }
    cout << "\n"; out(N, pArr);
}

void _divide(int N, int* pArr, int value) {
    for (int i = 0; i < N * N; i++) {
        *(pArr + i) /= value;
    }
    cout << "\n"; out(N, pArr);
}

void sort(const int N, int* pArr)
{
    int t;
    for (int i = 0; i < N * N; i++) {
        for (int j = i + 1; j < N * N; j++) {
            if (*(pArr + j) < *(pArr + i)) {
                swap(*(pArr + j), *(pArr + i));
            }
        }
    }
    cout << "Отсортированный массив:\n"; out(N, pArr);
}

void individualtask10()
{
    const int N = 3;
    int Arr[N][N];
    int* pArr = &Arr[0][0];
    int det;
    for (int i = 0; i < N * N; i++) {
        *pArr = -30 + rand() % 61;
        pArr++;
    }
    pArr -= N * N;
    cout << "\nМатрица 3x3: \n";
    out(N, pArr);
    det = Arr[0][0] * Arr[1][1] * Arr[2][2] + Arr[0][1] * Arr[1][2] * Arr[2][0]
        + Arr[1][0] * Arr[2][1] * Arr[0][2] - Arr[2][0] * Arr[1][1] * Arr[0][2] -
        Arr[2][1] * Arr[1][2] * Arr[0][0] - Arr[1][0] * Arr[0][1] * Arr[2][2];
    cout << "Подсчитаем определитель\n";
    cout << "(" << Arr[0][0] << " * " << Arr[1][1] << " * " << Arr[2][2] << ")" << " + " << "(" << Arr[0][1] << " * " << Arr[1][2] << " * " << Arr[2][0] << ")"
        " + " << "(" << Arr[1][0] << " * " << Arr[2][1] << " * " << Arr[0][2] << ")" << " - " << "(" << Arr[2][0] << " * " << Arr[1][1] << " * " << Arr[0][2] << ")" << " - " << "(" <<
        Arr[2][1] << " * " << Arr[1][2] << " * " << Arr[0][0] << ")" << " - " << "(" << Arr[1][0] << " * " << Arr[0][1] << " * " << Arr[2][2] << ")" << " = " << det;
    cout << "\n\nОпределитель равен: " << det << "\n\n\n";
}

void individualtask5()
{
    const int N = 6;
    int Arr[N][N];
    int* pArr = &Arr[0][0];
    cout << "\nМатрица, заполненная случайными числами от 1 до N*N:\n";
    for (int i = 0; i < N * N; i++) {
        *pArr = 1 + rand() % (N * N);
        pArr++;
    }
    pArr -= N * N;
    out(N, pArr);

    int Arr2[N][N];
    int* pArr2 = &Arr2[0][0];
    cout << "Вторая матрица, заполненная случайными числами от 1 до N*N:\n";
    for (int i = 0; i < N * N; i++) {
        *pArr2 = 1 + rand() % (N * N);
        pArr2++;
    }
    pArr2 -= N * N;
    out(N, pArr2);

    //ввчесть из второй матрицы первую
    for (int i = 0; i < N * N; i++) {
        *(pArr++) -= *(pArr2++);
    }
    pArr -= N * N;
    cout << "Вычтем из второй сгенерированной матрицы первую\n";
    cout << "Теперь матрица имеет вид: \n";
    out(N, pArr);
}

int main()
{
    setlocale(0, "Rus");
    srand(time(0));

    bool flag = true;

    while (flag) {

        short x = 0, y = 0;
        int Arr[100];
        int* pArr = Arr;
        int N = 1;

        cout << "Введите размерность квадратной матрицы 6, 8, 10: ";

        y += 1;

        cin >> N;

        while (N != 6 && N != 8 && N != 10)
        {
            cout << "\nНе корректно. Введите размерность матрицы заново: ";
            cin >> N;
            y += 2;
        }

        cout << "\nВыбирите вариант заполнения матрицы:\n"
            "1. Заполнение матрицы по спирали\n"
            "2. Заполнение матрицы по столбцам\n";

        y += 4;

        int operation = 0;
        cin >> operation;

        while (operation != 1 && operation != 2)
        {
            cout << "\nНе корректно. Введите вариант заполнения заново: ";
            cin >> operation;
            y += 2;
        }

        y += 2;

        switch (operation)
        {
        case 1:
        {
            spiral(N, pArr, x, y);
            break;
        }
        case 2:
        {
            snake(N, pArr, x, y);
            break;
        }
        default:
            break;
        }

        cout <<
            "\n\tВыберите действие:\n"
            "0. Завершение\n"
            "1. Перестановка блоков (a)\n"
            "2. Перестановка блоков (b)\n"
            "3. Перестановка блоков (c)\n"
            "4. Перестановка блоков (d)\n"
            "5. Сортировка матрицы\n"
            "6. Прибавить к элементам матрицы число (+)\n"
            "7. Вычесть из элементов матрицы число (-)\n"
            "8. Умножить элементы матрицы на число (*)\n"
            "9. Разделите элементы матрицы на число (/)\n"
            "10. Задать новый массив\n"
            "11. Индивидуальное задание(10)\n"
            "12. Индивидуальное задание(5)\n\n";
        cout << "Введите номер выбранного варианта: ";

        bool flag_ = true;

        while (flag_) {

            int option = 111;
            cin >> option;

            switch (option)
            {
            case 1:
            {
                transpositionA(N, pArr);
                cout << "\nДля прололжения введите действие: ";
                break;
            }
            case 2:
            {
                transpositionB(N, pArr);
                cout << "\nДля прололжения введите действие: ";
                break;
            }
            case 3:
            {
                transpositionC(N, pArr);
                cout << "\nДля прололжения введите действие: ";
                break;
            }
            case 4:
            {
                transpositionD(N, pArr);
                cout << "\nДля прололжения введите действие: ";
                break;
            }
            case 5:
            {
                sort(N, pArr);
                cout << "\nДля прололжения введите действие: ";
                break;
            }
            case 6:
            {
                int value;
                cout << "(+) Введите число: ";
                cin >> value;
                _plus(N, pArr, value);
                cout << "\nДля прололжения введите действие: ";
                break;
            }
            case 7:
            {
                int value;
                cout << "(-) Введите число: ";
                cin >> value;
                _minus(N, pArr, value);
                cout << "\nДля прололжения введите действие: ";
                break;
            }
            case 8:
            {
                int value;
                cout << "(*) Введите число: ";
                cin >> value;
                _multiply(N, pArr, value);
                cout << "\nДля прололжения введите действие: ";
                break;
            }
            case 9:
            {
                int value;
                cout << "(/) Введите число: ";
                cin >> value;
                _divide(N, pArr, value);
                cout << "\nДля прололжения введите действие: ";
                break;
            }
            case 10:
            {
                flag_ = false;
                system("cls");
                break;
            }
            case 11:
            {
                //Individual task 10
                individualtask10();
                cout << "\nДля прололжения введите действие: ";
                break;
            }
            case 12:
            {
                //Individual task 5
                individualtask5();
                cout << "\nДля прололжения введите действие: ";
                break;
            }
            case 0:
            {
                flag_ = false;
                flag = false;
                break;
            }
            default:
                cout << "\nНе корректно. Введите действие заново: ";
                break;
            }
        }
    }
}