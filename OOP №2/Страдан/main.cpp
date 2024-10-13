#include "fraction.h"


int main() {
    setlocale(LC_ALL, "RU");
    fraction f1, f2;
    cout << "Введите первую дробь(через enter)\n";
    cin >> f1;
    cout << "Введите вторую дробь(через enter)\n";
    cin >> f2;

    
    
    int x=-1;
    while (x != 0) {
        cout << "1 - Сложение\n2 - Вычитание\n3 - Умножение\n4 - Деление\n5 - Проверка равенства\n6 - Проверка больше,меньше\n7 - Вывод дробей на экран\n8 - Замена первой дроби\n9 - Замена второй дроби\n0 - Выход\n";
        cin >> x;
        switch (x){
        case 1: {
            fraction f3 = f1.operator+(f2);
            cout << "Результат: " << f3 << endl;
            break;
        }
        case 2: {
            fraction f4 = f1.operator-(f2);
            cout << "Результат: " << f4 << endl;
            break;
        }
        case 3: {
            fraction f5 = f1.operator*(f2);
            cout << "Результат: " << f5 << endl;
            break;
        }
        case 4: {
            fraction f6 = f1.operator/(f2);
            cout << "Результат: " << f6 << endl;
            break;
        }
       
        case 5: {
            if (f1.operator==(f2)) {
                cout << f1<< " и " << f2 <<" равны " << endl;
            }
            else
            {
                cout << f1 << " и " << f2<< " не равны " << endl;
            }
            break;
        }
        case 6: {
            if (f1.operator==(f2)) {
                cout << f1 << " и " << f2 << " равны " << endl;
                break;
            }
            if (f1.operator>(f2)) {
                cout << f1 << " больше " << f2<< endl;
            }
            else {
                cout << f1 << " меньше " << f2<< endl;
            }
            break;
        }
        case 7: {
            cout << "Первая дробь" << f1 << endl;
            cout << "Вторая дробь" << f2 << endl;
            break;
        }
        case 8: {
            cout << "Введите новые значения\n";
            fraction F1;
            cin >> F1;
            f1.operator=(F1);
            break;
        }
        case 9: {
            cout << "Введите новые значения\n";
            
            fraction F2;
            cin >> F2;
            f2.operator=(F2);
            break;
        }
        default:
            break;
            
        }
    }

    
}

