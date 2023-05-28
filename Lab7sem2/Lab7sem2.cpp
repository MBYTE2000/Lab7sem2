#include <iostream>
#include <cmath>

using namespace std;

// Функция для вычисления значения функции f(x)
double f(double x) {
    return sin(x) * sin(x) - 3 * cos(x);
}

// Функция для вычисления значения многочлена Лагранжа в точке x
double lagrangeInterpolation(double* x, double* y, int m, double xi) {
    double result = 0.0;
    for (int i = 0; i < m; i++) {
        double term = y[i];
        for (int j = 0; j < m; j++) {
            if (j != i) {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    setlocale(LC_ALL,"ru");
    int m; // Количество точек
    double a, b; // Интервал [a, b]

    cout << "Введите количество точек: ";
    cin >> m;

    double* x = new double[m];
    double* y = new double[m];

    cout << "Введите интервал [a, b]: ";
    cin >> a >> b;

    // Заполнение таблицы значений функции
    double step = (b - a) / (m - 1);
    for (int i = 0; i < m; i++) {
        x[i] = a + i * step;
        y[i] = f(x[i]);
    }

    // Вывод таблицы значений функции
    cout << "Таблица значений функции:\n";
    for (int i = 0; i < m; i++) {
        cout << "x[" << i << "] = " << x[i] << ", f(x[" << i << "]) = " << y[i] << endl;
    }

    double xi; // Точка, в которой вычисляется значение аппроксимации
    cout << "Введите точку xi для вычисления аппроксимации: ";
    cin >> xi;

    // Вычисление аппроксимации функции в заданной точке xi
    double approximation = lagrangeInterpolation(x, y, m, xi);

    cout << "Аппроксимация функции в точке xi = " << xi << ": " << approximation << endl;

    delete[] x;
    delete[] y;

    return 0;
}
