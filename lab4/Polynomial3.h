#ifndef POLYNOMIAL3_H
#define POLYNOMIAL3_H

#include <iostream> 

class Polynomial {
private:
    int n;          
    double* coef;   
    static int objectCount; 

public:
    // --- БЛОК 1: КЕРУВАННЯ ПАМ'ЯТТЮ ---
    Polynomial();                                
    Polynomial(int size);                        
    Polynomial(const Polynomial& other);         
    ~Polynomial();                               
    Polynomial& operator=(const Polynomial& other); 

    // --- БЛОК 2: СТАТИКА ТА ФУНКЦІЇ-ДРУЗІ ---
    static int getObjectCount(); 
    friend std::istream& operator>>(std::istream& is, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

    // --- БЛОК 3: НЕОПЕРАТОРНІ ФУНКЦІЇ ---
    Polynomial copyPolynomial() const;           
    double evaluate(double x) const;             
    Polynomial derivative() const;               
    Polynomial multiplyByXMinusB(double b) const; 
    Polynomial compose(const Polynomial& q) const;
    Polynomial shiftX(double b) const;            
    void divide(const Polynomial& divisor, Polynomial& quotient, Polynomial& remainder) const;

    // --- БЛОК 4: ПЕРЕВАНТАЖЕНІ ОПЕРАТОРИ (Етап 3) ---
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
};

#endif