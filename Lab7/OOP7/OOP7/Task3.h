#pragma once

#include <iostream>
using namespace std;

class Currency {
public:
    virtual double convertToRubles(double amount) const = 0; 
    virtual void display() const = 0; 
};


class Dollar : public Currency {
public:
    double convertToRubles(double amount) const override {
      
        return amount * 70;
    }

    void display() const override {
        cout << "Amount in Dollars" << endl;
    }
};
class Euro : public Currency {
public:
    double convertToRubles(double amount) const override {
       
        return amount * 80;
    }

    void display() const override {
        cout << "Amount in Euros" << endl;
    }
};

class Task3 {
public:
    static void run() {
        
        Dollar dollar;
        Euro euro;

        double amountInDollars = 100;
        double amountInEuros = 150;

        cout << "Amount in Rubles (Dollars): " << dollar.convertToRubles(amountInDollars) << endl;
        dollar.display();

        cout << "Amount in Rubles (Euros): " << euro.convertToRubles(amountInEuros) << endl;
        euro.display();
    }
};
