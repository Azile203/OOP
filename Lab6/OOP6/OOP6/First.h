#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    std::string position;
    double salary;

public:
    // ����������� �� ���������
    Employee() : name(""), position(""), salary(0.0) {}

    // ����������� � �����������
    Employee(const std::string& n, const std::string& pos, double sal)
        : name(n), position(pos), salary(sal) {}

    // ����������
    ~Employee() {
        std::cout << "���������� Employee ������ ��� " << name << std::endl;
    }

    // ����� ��� ������� ���������� ����� �� ���
    double calculateAnnualSalary() const {
        return salary * 12;
    }

    // ����� ��� ������ ���������� � ��������� �� �������
    void displayInfo() const {
        std::cout << "���: " << name << ", ���������: " << position << ", ���������� �����: " << salary << std::endl;
    }
};

class Manager : public Employee {
private:
    double annual_bonus;
    std::string company_car;
    int stock_options;

public:
    // ����������� �� ���������
    Manager()
        : Employee(), annual_bonus(0.0), company_car(""), stock_options(0) {}

    // ����������� � �����������
    Manager(const std::string& n, const std::string& pos, double sal, double bonus, const std::string& car, int options)
        : Employee(n, pos, sal), annual_bonus(bonus), company_car(car), stock_options(options) {}

    // ����������
    ~Manager() {
        std::cout << "���������� Manager ������ ��� " << name << std::endl;
    }

    // ����� ��� ������ ���������� � ��������� �� �������
    void displayInfo() const {
        Employee::displayInfo();  // �������� ����� displayInfo �� ������-��������
        std::cout << "��������� �����: " << annual_bonus << ", ���������� ��������: " << company_car << ", ����� �� �����: " << stock_options << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // ���� ������ ��� ������ Employee � �������
    std::string empName, empPosition;
    double empSalary;

    std::cout << "������� ������ ��� ���������:" << std::endl;
    std::cout << "���: ";
    std::getline(std::cin, empName);

    std::cout << "���������: ";
    std::getline(std::cin, empPosition);

    std::cout << "���������� �����: ";
    std::cin >> empSalary;

    // ������ ������������� ������ Employee
    Employee emp1(empName, empPosition, empSalary);
    emp1.displayInfo();
    std::cout << "��������� ���������� �����: " << emp1.calculateAnnualSalary() << std::endl;

    // ���� ������ ��� ������ Manager � �������
    std::string mgrName, mgrPosition, mgrCar;
    double mgrSalary, mgrBonus;
    int mgrOptions;

    std::cout << "������� ������ ��� ���������:" << std::endl;
    std::cout << "���: ";
    std::getline(std::cin, mgrName);

    std::cout << "���������: ";
    std::getline(std::cin, mgrPosition);

    std::cout << "���������� �����: ";
    std::cin >> mgrSalary;

    std::cout << "��������� �����: ";
    std::cin >> mgrBonus;

    std::cin.ignore(); // ������� ������ ����� ����������� ������
    std::cout << "���������� ��������: ";
    std::getline(std::cin, mgrCar);

    std::cout << "����� �� �����: ";
    std::cin >> mgrOptions;

    // ������ ������������� ������ Manager
    Manager manager1(mgrName, mgrPosition, mgrSalary, mgrBonus, mgrCar, mgrOptions);
    manager1.displayInfo();
    std::cout << "��������� ���������� �����: " << manager1.calculateAnnualSalary() << std::endl;

    return 0;
}
