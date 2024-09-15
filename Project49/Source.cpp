#include <iostream>  
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

   
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    
    int abs(int x) {
        return (x < 0) ? -x : x;
    }

    
    void simplify() {
        int d = gcd(abs(numerator), abs(denominator));
        numerator /= d;
        denominator /= d;
      
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    
    Fraction(int numerator = 0, int denominator = 1) {
        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero. Default value set to 1." << endl;
            this->numerator = numerator;
            this->denominator = 1;
        }
        else {
            this->numerator = numerator;
            this->denominator = denominator;
        }
        simplify();
    }

    
    void input() {
       cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero. Default value set to 1." << endl;
            denominator = 1;
        }
        simplify();
    }

 
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator,
            denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
           cout << "Error: Division by zero." <<endl;
            return Fraction();
        }
        return Fraction(numerator * other.denominator,
            denominator * other.numerator);
    }

    
    void print() const {
        cout << numerator << "/" << denominator <<endl;
    }
};

int main() {
    Fraction fraction1, fraction2;

   cout << "Enter the first fraction:" << endl;
    fraction1.input();

    cout << "Enter the second fraction:" << endl;
    fraction2.input();

    Fraction result;

    result = fraction1 + fraction2;
   cout << "Result of addition: ";
    result.print();

    result = fraction1 - fraction2;
    cout << "Result of subtraction: ";
    result.print();

    result = fraction1 * fraction2;
    cout << "Result of multiplication: ";
    result.print();

    result = fraction1 / fraction2;
    cout << "Result of division: ";
    result.print();

    return 0;
}