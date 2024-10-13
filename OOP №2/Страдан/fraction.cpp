#include "fraction.h"


int fraction::gcd(int x, int y)
{
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

void fraction::reduce()
{
    int divisor = gcd(*a, *b);
    *a /= divisor;
    *b /= divisor;
}

fraction::fraction(int num, int den)
{
    if (den == 0) {
        cerr << "Ошибка: знаменатель равен нулю. Устанавливаем знаменатель в 1." << endl;
        den = 1;
    }
    a = new int(num);
    b = new int(den);
    reduce();
}

fraction::~fraction()
{
    delete a;
    delete b;
}

fraction::fraction(const fraction& other)
{
    a = new int(*other.a);
    b = new int(*other.b);
}

fraction& fraction::operator=(const fraction& other) {
    if (this != &other) {
        delete a;
        delete b;

        a = new int(*other.a);
        b = new int(*other.b);
    }
    return *this;
}

fraction fraction::operator+(const fraction& other)
{
    return fraction((*a * *other.b) + (*b * *other.a), *b * *other.b);   
}

fraction fraction::operator-(const fraction& other)
{
    return fraction((*a * *other.b) - (*b * *other.a), *b * *other.b);
}

fraction fraction::operator*(const fraction& other) {
    return fraction((*a * *other.a), (*b * *other.b));
}

fraction fraction::operator/(const fraction& other) {
    if (*other.a == 0) {
        cerr << "Ошибка: деление на дробь с нулевым числителем." << endl;
        exit(EXIT_FAILURE);
    }
    return fraction((*a * *other.b), (*b * *other.a));
}

bool fraction::operator==(const fraction& other) {
    return (*a == *other.a && *b == *other.b);
}

bool fraction::operator!=(const fraction& other) {
    return !(*this == other);
}

bool fraction::operator>(const fraction& other) {
    return (*a * *other.b > *b * *other.a);
}

bool fraction::operator<(const fraction& other) {
    return (*a * *other.b < *b * *other.a);
}

bool fraction::operator>=(const fraction& other)
{
    return (*a * *other.b >= *b * *other.a);
}

bool fraction::operator<=(const fraction& other)
{
    return (*a * *other.b <= *b * *other.a);
}

ostream& operator<<(ostream& out, const fraction& f)
{
    out << *f.a << "/" << *f.b;
    return out;
}

istream& operator>>(istream& in, fraction& f)
{

    in >> *f.a;
    in >> *f.b;

    if (*f.b == 0) {
        cerr << "Ошибка: знаменатель равен нулю. Устанавливаем знаменатель в 1." << endl;
        *f.b = 1;
    }
    f.reduce();
    return in;
}
