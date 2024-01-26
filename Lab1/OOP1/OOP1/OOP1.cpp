/*#include <iostream>
#include <cmath> 
using namespace std;

// Прототип функции power
double power(double n, int p = 2);

int main() {
   
    setlocale(LC_ALL, "Russian");
    double base;
    int exponent;

    // Запрос ввода числа и степени у пользователя
    cout << "Введите число: ";
    cin >> base;

    // Проверка на необходимость ввода степени
    char inputChoice;
    cout << "Хотите ввести степень числа? (y/n): ";
    cin >> inputChoice;

    if (inputChoice == 'y' || inputChoice == 'Y') {
        cout << "Введите степень: ";
        cin >> exponent;
    }
    else {
        exponent = 2; // Установка значения по умолчанию, если степень не введена
    }

    // Вызов функции power и вывод результата
    double result = power(base, exponent);
    cout << "Результат: " << result << endl;

    return 0;
}

// Определение функции power
double power(double n, int p) {
    return pow(n, p);
}
*/





#include <iostream>
#include <cmath>
using namespace std;

// Перегрузка функции power для различных типов данных
double power(double n, int p = 2) {
    return pow(n, p);
}

char power(char n, int p = 2) {
    // Преобразование символа в целочисленное значение и использование целого числа вместо символа
    int num = static_cast<int>(n);
    return static_cast<char>(pow(num, p));
}

short int power(short int n, int p = 2) {
    return static_cast<short int>(pow(n, p));
}

long int power(long int n, int p = 2) {
    return static_cast<long int>(pow(n, p));
}

float power(float n, int p = 2) {
    return pow(n, p);
}

int main() {
    // Вызов функции power со всеми возможными типами аргументов
    cout << "double: " << power(3.5) << endl;
    cout << "char: " << power('A') << endl;
    cout << "short int: " << power(static_cast<short int>(2)) << endl;
    cout << "long int: " << power(static_cast<long int>(10)) << endl;
    cout << "float: " << power(4.7f) << endl;

    return 0;
}








/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

struct Worker {
    string surname;
    int age;
    string specialization;
    double averageSalary;
};


    string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {
    const int numFactories = 3; 
    vector<Worker> workers[numFactories]; 

    for (int i = 0; i < numFactories; ++i) {
        int numWorkers;
        cout << "Enter the number of workers at factory " << i + 1 << ": ";
        cin >> numWorkers;

        // information about each worker
        for (int j = 0; j < numWorkers; ++j) {
            Worker worker;
            cout << "Enter the surname of the worker: ";
            cin >> worker.surname;
            cout << "Enter the age of the worker: ";
            cin >> worker.age;
            cout << "Enter the specialization of the worker: ";
            cin >> worker.specialization;
            cout << "Enter the average salary of the worker: ";
            cin >> worker.averageSalary;

            workers[i].push_back(worker); 
        }
    }

    // Count the number of locksmiths and turners
    int countLocksmiths = 0;
    int countTurners = 0;

    for (int i = 0; i < numFactories; ++i) {
        for (const Worker& worker : workers[i]) {
            // Convert specialization to lowercase before comparison
            string lowercaseSpecialization = toLowerCase(worker.specialization);

            if (lowercaseSpecialization == "locksmith") {
                countLocksmiths++;
            }
            else if (lowercaseSpecialization == "turner") {
                countTurners++;
            }
        }
    }

    cout << "Number of locksmiths: " << countLocksmiths << endl;
    cout << "Number of turners: " << countTurners << endl;

    return 0;
}*/
