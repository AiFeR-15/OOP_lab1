#ifndef POLYNOMIAL3_H
#define POLYNOMIAL3_H

#include <iostream>

class Polynomial {
private:
    int n;
    double* coef;
    static int objectCount;

public:
    Polynomial();
    Polynomial(int size);
    Polynomial(int size, const double* arr);
    Polynomial(const Polynomial& other);
    ~Polynomial();
    Polynomial& operator=(const Polynomial& other);

    void input();
    void output() const;

    static int getObjectCount();

    friend std::istream& operator>>(std::istream& is, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

    Polynomial copyPolynomial() const;
    double evaluate(double x) const;
    Polynomial derivative() const;
    Polynomial multiplyByXMinusB(double b) const;
    Polynomial shiftX(double b) const;
    Polynomial compose(const Polynomial& q) const;
    void divide(const Polynomial& divisor, Polynomial& quotient, Polynomial& remainder) const;

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
};

#endif