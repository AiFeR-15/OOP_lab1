#ifndef POLYNOMIAL2_H
#define POLYNOMIAL2_H

#include <iostream> 

class Polynomial {
private:
    int n;          
    double* coef;   
    static int objectCount; 

public:
    Polynomial();                                
    Polynomial(int size);                        
    Polynomial(const Polynomial& other);         
    ~Polynomial();                               
    Polynomial& operator=(const Polynomial& other); 

    static int getObjectCount(); 
    friend std::istream& operator>>(std::istream& is, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

    Polynomial copyPolynomial() const;           
    double evaluate(double x) const;             
    Polynomial derivative() const;               
    Polynomial multiplyByXMinusB(double b) const; 
    Polynomial compose(const Polynomial& q) const;
    Polynomial shiftX(double b) const;            
    void divide(const Polynomial& divisor, Polynomial& quotient, Polynomial& remainder) const;
};

#endif