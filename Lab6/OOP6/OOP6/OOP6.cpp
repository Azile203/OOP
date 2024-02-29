/*#include <iostream>
#include <string>
using namespace std;
class Employee {
protected:
    string name;
    string position;
    double salary;

public:
   
    Employee() : name(""), position(""), salary(0.0) {}
    Employee(const string& n, const string& pos, double sal)
        : name(n), position(pos), salary(sal) {}

   
    ~Employee() {
       cout << "Деструктор Employee вызван для " << name << endl;
    }
    double calculateAnnualSalary() const {
        return salary * 12;
    }
    void displayInfo() const {
       cout << "Имя: " << name << ", Должность: " << position << ", Заработная плата: " << salary << endl;
    }
};

class Manager : public Employee {
private:
    double annual_bonus;
    string company_car;
    int stock_options;

public:
    Manager()
        : Employee(), annual_bonus(0.0), company_car(""), stock_options(0) {}
    Manager(const string& n, const std::string& pos, double sal, double bonus, const string& car, int options)
        : Employee(n, pos, sal), annual_bonus(bonus), company_car(car), stock_options(options) {}

    
    ~Manager() {
       cout << "Деструктор Manager вызван для " << name << endl;
    }

    void displayInfo() const {
        Employee::displayInfo();  // Вызываем метод displayInfo из класса-родителя
        cout << "Ежегодный бонус: " << annual_bonus << ", Автомобиль компании: " << company_car << ", Опции на акции: " << stock_options << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

 
    string empName, empPosition;
    double empSalary;

    cout << "Введите данные для работника:" << endl;
    cout << "Имя: ";
    getline(cin, empName);

    cout << "Должность: ";
    getline(std::cin, empPosition);

    cout << "Заработная плата: ";
    cin >> empSalary;

    
    Employee emp1(empName, empPosition, empSalary);
    emp1.displayInfo();
    cout << "Ежегодная Заработная плата: " << emp1.calculateAnnualSalary() << endl;

    
    string mgrName, mgrPosition, mgrCar;
    double mgrSalary, mgrBonus;
    int mgrOptions;

    cin.ignore(); 

    cout << "Введите данные для менеджера:" << endl;
    cout << "Имя: ";
    getline(cin, mgrName);

    cout << "Должность: ";
    getline(cin, mgrPosition);

    cout << "Заработная плата: ";
    cin >> mgrSalary;

    cin.ignore(); 

    cout << "Ежегодный бонус: ";
    cin >> mgrBonus;

    cin.ignore(); 

    cout << "Автомобиль компании: ";
    getline(std::cin, mgrCar);

    cout << "Опции на акции: ";
    cin >> mgrOptions;

    Manager manager1(mgrName, mgrPosition, mgrSalary, mgrBonus, mgrCar, mgrOptions);
    manager1.displayInfo();
    cout << "Ежегодная Заработная плата: " << manager1.calculateAnnualSalary() << endl;

    return 0;
}*/








/*

#include <iostream>
#include <cstring>

using namespace std;

class Display {
protected:
    char type[32];
    long colors;
    int x_resolution;
    int y_resolution;

public:
   
    Display(const char* t, long c, int x_res, int y_res) : colors(c), x_resolution(x_res), y_resolution(y_res) {
        strncpy_s(type, t, sizeof(type) - 1);
        type[sizeof(type) - 1] = '\0';
    }

    void displayInfo() const {
        cout << "Тип монитора: " << type << ", Количество цветов: " << colors
            << ", Разрешение: " << x_resolution << "x" << y_resolution << endl;
    }
};

class MotherBoard {
protected:
    int processor;
    int speed;
    int RAM;

public:
   
    MotherBoard(int proc, int spd, int ram) : processor(proc), speed(spd), RAM(ram) {}

    
    void displayInfo() const {
        cout << "Тип процессора: " << processor << ", Скорость процессора: " << speed
            << ", Объем оперативной памяти: " << RAM << " GB" << endl;
    }
};

class Computer : public Display, public MotherBoard {
private:
    char name[64];
    int hard_disk;

public:
 
    Computer(const char* n, int hd, const char* t, long c, int x_res, int y_res, int proc, int spd, int ram)
        : Display(t, c, x_res, y_res), MotherBoard(proc, spd, ram), hard_disk(hd) {
        strncpy_s(name, n, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
    }

   
    void displayInfo() const {
        cout << "Марка компьютера: " << name << ", Объем жесткого диска: " << hard_disk << " GB" << endl;
        Display::displayInfo();  // Метод из родительского класса Display
        MotherBoard::displayInfo();  // Метод из родительского класса MotherBoard
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
   
    Computer myComputer("MyPC", 512, "LED", 16'777'216, 1920, 1080, 3, 3600, 32);
    myComputer.displayInfo();

    return 0;
}*/





#include <iostream>
#include <cstring>

using namespace std;

// Родительский класс Employee
class Employee {
private:
    string name;
    string position;
    double salary;

public:
    Employee() : name(""), position(""), salary(0.0) {}

    Employee(const string& n, const string& pos, double sal)
        : name(n), position(pos), salary(sal) {}

    ~Employee() {
        cout << "Деструктор Employee вызван для " << name << endl;
    }

    double calculateAnnualSalary() const {
        return salary * 12;
    }

    void displayInfo() const {
        cout << "Имя: " << name << ", Должность: " << position << ", Заработная плата: " << salary << endl;
    }

    // Объявление дружественного класса Manager
    friend class Manager;
};

// Производный класс Manager
class Manager : public Employee {
private:
    double annual_bonus;
    string company_car;
    int stock_options;

public:
    Manager() : Employee(), annual_bonus(0.0), company_car(""), stock_options(0) {}

    Manager(const string& n, const string& pos, double sal, double bonus, const string& car, int options)
        : Employee(n, pos, sal), annual_bonus(bonus), company_car(car), stock_options(options) {}

    ~Manager() {
        cout << "Деструктор Manager вызван для " << name << endl;
    }

    // Метод для доступа к членам базового класса
    void displayInfoManager() const {
        // Мы можем обращаться к private-членам базового класса, так как Manager объявлен как friend
        displayInfo();
        cout << "Ежегодный бонус: " << annual_bonus << ", Автомобиль компании: " << company_car << ", Опции на акции: " << stock_options << endl;
    }

    // Восстановление доступа к методу calculateAnnualSalary из базового класса
    double calculateAnnualSalary() const {
        // Мы можем вызвать метод базового класса из производного, так как Manager объявлен как friend
        return Employee::calculateAnnualSalary();
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Manager manager1("John Doe", "Manager", 5000, 1000, "Company Car", 500);

    manager1.displayInfoManager(); // Мы используем public-метод производного класса для доступа к private-членам базового класса
    cout << "Ежегодная Заработная плата: " << manager1.calculateAnnualSalary() << endl; // Восстанавливаем доступ и используем метод базового класса

    return 0;
}











