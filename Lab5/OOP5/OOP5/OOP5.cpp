/*#include <iostream>
#include <limits>
using namespace std;
class Int {
private:
    long double value;

public:
    // Конструктор класса
    Int(int initial) : value(initial) {}

    // Перегрузка оператора +
    Int operator+(const Int& other) const {
        return checkOverflow(value + other.value, "Addition");
    }

    // Перегрузка оператора -
    Int operator-(const Int& other) const {
        return checkOverflow(value - other.value, "Subtraction");
    }

    // Перегрузка оператора *
    Int operator*(const Int& other) const {
        return checkOverflow(value * other.value, "Multiplication");
    }

    // Перегрузка оператора /
    Int operator/(const Int& other) const {
        if (other.value == 0) {
            throw std::runtime_error("Division by zero");
        }
        return checkOverflow(value / other.value, "Division");
    }

    // Перегрузка оператора префиксного инкремента
    Int& operator++() {
        value = checkOverflow(value + 1, "Increment").value;
        return *this;
    }

    // Перегрузка оператора постфиксного инкремента
    Int operator++(int) {
        Int temp = *this;
        ++(*this);
        return temp;
    }

    // Метод для вывода значения
    void display() const {
        std::cout << value << endl;
    }

private:
    // Метод для проверки переполнения и выброса исключения при необходимости
    Int checkOverflow(long double result, const std::string& operation) const {
        if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Arithmetic overflow in " + operation + " operation");
        }
        return Int(static_cast<int>(result));
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        int initialValue;
        cout << "Введите начальное значение: ";
        cin >> initialValue;

        Int myInt(initialValue);

        Int result = myInt + 5;
        cout << "Результат сложения: ";
        result.display();

        result = myInt - 3;
        cout << "Результат вычитания: ";
        result.display();

        result = myInt * 2;
        cout << "Результат умножения: ";
        result.display();

        result = myInt / 2;
        cout << "Результат деления: ";
        result.display();

        cout << "Постфиксный инкремент: ";
        (myInt++).display();

        cout << "После постфиксного инкремента: ";
        myInt.display();

        
        cout << "Префиксный инкремент: ";
        (++myInt).display();
    }
    catch (const std::exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}*/











/*#include <iostream>
using namespace std;
class Fraction {
private:
    double chislo;

public:
    // Конструкторы
    Fraction() : chislo(0.0) {}
    Fraction(double numerator) : chislo(numerator) {}

    // Методы для доступа к chislo
    double getChislo() const {
        return chislo;
    }

    void setChislo(double value) {
        chislo = value;
    }

    // Перегрузка операторов сложения, вычитания, умножения и деления для объектов класса
    Fraction operator+(const Fraction& other) const {
        return Fraction(chislo + other.chislo);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(chislo - other.chislo);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(chislo * other.chislo);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.chislo != 0.0) {
            return Fraction(chislo / other.chislo);
        }
        else {
            std::cerr << "Error: Division by zero\n";
            return Fraction();
        }
    }

    // Перегрузка операторов сложения, вычитания, умножения и деления для работы с числами
    Fraction operator+(double number) const {
        return Fraction(chislo + number);
    }

    Fraction operator-(double number) const {
        return Fraction(chislo - number);
    }

    Fraction operator*(double number) const {
        return Fraction(chislo * number);
    }

    Fraction operator/(double number) const {
        if (number != 0.0) {
            return Fraction(chislo / number);
        }
        else {
            cerr << "Error: Division by zero\n";
            return Fraction();
        }
    }

    // Перегрузка унарной операции инкремента (префиксная форма)
    Fraction operator++() {
        chislo += 1.0;
        return *this;
    }

    // Перегрузка унарной операции инкремента (постфиксная форма)
    Fraction operator++(int) {
        Fraction temp = *this;
        chislo += 1.0;
        return temp;
    }

    // Метод для вывода значения дроби
    void display() const {
        cout << chislo << endl;
    }

    // Метод для ввода значения дроби с консоли
    void input() {
        cout << "Enter a fraction: ";
        cin >> chislo;
    }
};

// Перегрузка операторов сложения, вычитания, умножения и деления для работы с числами (внешние функции)
Fraction operator+(double number, const Fraction& fraction) {
    return Fraction(number + fraction.getChislo());
}

Fraction operator-(double number, const Fraction& fraction) {
    return Fraction(number - fraction.getChislo());
}

Fraction operator*(double number, const Fraction& fraction) {
    return Fraction(number * fraction.getChislo());
}

Fraction operator/(double number, const Fraction& fraction) {
    if (fraction.getChislo() != 0.0) {
        return Fraction(number / fraction.getChislo());
    }
    else {
        std::cerr << "Error: Division by zero\n";
        return Fraction();
    }
}

int main() {
    // Пример использования класса
    Fraction a;
    Fraction b;

    a.input();
    b.input();

    Fraction result1 = a + b;
    std::cout << "Sum: ";
    result1.display();

    Fraction result2 = a - b;
    std::cout << "Difference: ";
    result2.display();

    Fraction result3 = a * b;
    std::cout << "Product: ";
    result3.display();

    Fraction result4 = a / b;
    std::cout << "Quotient: ";
    result4.display();

    return 0;
}*/







#include <iostream>
using namespace std;
class Rectangle {
public:
    // Перегрузка метода rect_area() для прямоугольника (длина и ширина)
    double rect_area(double length, double width) {
        return length * width;
    }

    // Перегрузка метода rect_area() для квадрата (одна сторона)
    double rect_area(double side) {
        return side * side;
    }
};

int main() {
    Rectangle figure;

    int choice;
    double result;

    cout << "Choose the figure type:\n";
    cout << "1. Rectangle\n";
    cout << "2. Square\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        double length, width;
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the width of the rectangle: ";
        cin >> width;

        result = figure.rect_area(length, width);
        cout << "Area of the rectangle: " << result << endl;
    }
    else if (choice == 2) {
        double side;
        cout << "Enter the side of the square: ";
        cin >> side;

        result = figure.rect_area(side);
        cout << "Area of the square: " << result << endl;
    }
    else {
        cout << "Invalid choice. Please choose 1 or 2.\n";
    }

    return 0;
}

