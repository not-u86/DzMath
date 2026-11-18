#include <iostream>
#include <Windows.h>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return log(x) - cos(x);
}

double df(double x) {
    return 1.0 / x + sin(x);
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

        cout << fixed << setprecision(6);

       
        cout << "Локализация " << endl;

        double a = 0.5;
        double h = 0.1;
        double b;
        bool found = false;

        while (a < 3.0) {
            b = a + h;
            if (f(a) * f(b) < 0) {
                cout << "отрезок: [" << a << ", " << b << "]" << endl;
                found = true;
                break;
            }
            a = b;
        }

        if (!found) {
            cout << "отрезок не найден" << endl;
            system("pause");
            return 0;
        }

      
        cout << "\nметод половинного деления " << endl;

        for (int i = 1; i <= 3; i++) {
            double c = (a + b) / 2.0;
            cout << "итерация " << i
                << ": a = " << a
                << ", b = " << b
                << ", c = " << c
                << ", f(c) = " << f(c) << endl;

            if (f(a) * f(c) < 0)
                b = c;
            else
                a = c;
        }

        double x0 = (a + b) / 2.0;
        cout << "\nначальное приближение x0 = " << x0 << endl;

        
        cout << "\n метод Ньютона " << endl;

        double eps = 0.000001;
        double x = x0;
        int iteration = 0;

        while (true) {
            iteration++;
            double fx = f(x);
            double dfx = df(x);

            if (fabs(dfx) < 1e-10) {
                cout << "ошибка" << endl;
                break;
            }

            double x_new = x - fx / dfx;

            cout << "итерация " << iteration
                << ": x = " << setprecision(8) << x_new
                << ", f(x) = " << f(x_new) << endl;

            if (fabs(x_new - x) < eps) {
                x = x_new;
                break;
            }
            x = x_new;
        }

        cout << "\nкорень x = " << setprecision(8) << x
            << ", f(x) = " << f(x) << endl;

        cout << "\n";
        system("pause");   
        return 0;
    }

	


