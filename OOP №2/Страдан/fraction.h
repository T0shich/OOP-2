#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept> 

using namespace std;

class fraction {
    int* a; 
    int* b; 

    int gcd(int x, int y);

    void reduce();

public:
    fraction(int num = 0, int den = 1);

    ~fraction();

    fraction(const fraction& other);

    fraction& operator=(const fraction& other);

    fraction operator+(const fraction& other);

    fraction operator-(const fraction& other);

    fraction operator*(const fraction& other);

    fraction operator/(const fraction& other);

    bool operator==(const fraction& other);

    bool operator!=(const fraction& other);

    bool operator>(const fraction& other);

    bool operator<(const fraction& other);

    bool operator>=(const fraction& other);

    bool operator<=(const fraction& other);

    friend ostream& operator<<(ostream& out, const fraction& f);

    friend istream& operator>>(istream& in, fraction& f);
    
    
};

