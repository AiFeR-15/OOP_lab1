#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial {
private:
    int n;          
    double* coef;   
    static int objectCount; 

public:
    // --- Велика трійка ---
    Polynomial();                                
    Polynomial(int size);                        
    Polynomial(const Polynomial& other);         
    ~Polynomial();                               
    Polynomial& operator=(const Polynomial& other); 

    // --- Неоператорні функції ---
    Polynomial copyPolynomial() const;           
    double evaluate(double x) const;             
    Polynomial derivative() const;               
    Polynomial multiplyByXMinusB(double b) const; 
    Polynomial shiftX(double b) const;            
    Polynomial compose(const Polynomial& q) const;
    
    static int getObjectCount();                 

    // --- Введення/Виведення ---
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
    friend std::istream& operator>>(std::istream& is, Polynomial& p);

    // --- Перевантажені оператори ---
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
};

#endif