#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    std::string position;
    double salary;

public:
    // Конструктор по умолчанию
    Employee() : name(""), position(""), salary(0.0) {}

    // Конструктор с аргументами
    Employee(const std::string& n, const std::string& pos, double sal)
        : name(n), position(pos), salary(sal) {}

    // Деструктор
    ~Employee() {
        std::cout << "Деструктор Employee вызван для " << name << std::endl;
    }

    // Метод для расчета заработной платы за год
    double calculateAnnualSalary() const {
        return salary * 12;
    }

    // Метод для вывода информации о работнике на консоль
    void displayInfo() const {
        std::cout << "Имя: " << name << ", Должность: " << position << ", Заработная плата: " << salary << std::endl;
    }
};

class Manager : public Employee {
private:
    double annual_bonus;
    std::string company_car;
    int stock_options;

public:
    // Конструктор по умолчанию
    Manager()
        : Employee(), annual_bonus(0.0), company_car(""), stock_options(0) {}

    // Конструктор с аргументами
    Manager(const std::string& n, const std::string& pos, double sal, double bonus, const std::string& car, int options)
        : Employee(n, pos, sal), annual_bonus(bonus), company_car(car), stock_options(options) {}

    // Деструктор
    ~Manager() {
        std::cout << "Деструктор Manager вызван для " << name << std::endl;
    }

    // Метод для вывода информации о менеджере на консоль
    void displayInfo() const {
        Employee::displayInfo();  // Вызываем метод displayInfo из класса-родителя
        std::cout << "Ежегодный бонус: " << annual_bonus << ", Автомобиль компании: " << company_car << ", Опции на акции: " << stock_options << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Ввод данных для класса Employee с консоли
    std::string empName, empPosition;
    double empSalary;

    std::cout << "Введите данные для работника:" << std::endl;
    std::cout << "Имя: ";
    std::getline(std::cin, empName);

    std::cout << "Должность: ";
    std::getline(std::cin, empPosition);

    std::cout << "Заработная плата: ";
    std::cin >> empSalary;

    // Пример использования класса Employee
    Employee emp1(empName, empPosition, empSalary);
    emp1.displayInfo();
    std::cout << "Ежегодная Заработная плата: " << emp1.calculateAnnualSalary() << std::endl;

    // Ввод данных для класса Manager с консоли
    std::string mgrName, mgrPosition, mgrCar;
    double mgrSalary, mgrBonus;
    int mgrOptions;

    std::cout << "Введите данные для менеджера:" << std::endl;
    std::cout << "Имя: ";
    std::getline(std::cin, mgrName);

    std::cout << "Должность: ";
    std::getline(std::cin, mgrPosition);

    std::cout << "Заработная плата: ";
    std::cin >> mgrSalary;

    std::cout << "Ежегодный бонус: ";
    std::cin >> mgrBonus;

    std::cin.ignore(); // Очистка буфера перед считыванием строки
    std::cout << "Автомобиль компании: ";
    std::getline(std::cin, mgrCar);

    std::cout << "Опции на акции: ";
    std::cin >> mgrOptions;

    // Пример использования класса Manager
    Manager manager1(mgrName, mgrPosition, mgrSalary, mgrBonus, mgrCar, mgrOptions);
    manager1.displayInfo();
    std::cout << "Ежегодная Заработная плата: " << manager1.calculateAnnualSalary() << std::endl;

    return 0;
}
