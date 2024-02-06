/*#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class Timer {
private:
    int seconds;

public:
    // Конструктор для времени в секундах
    Timer(int sec) : seconds(sec) {}

    // Конструктор для времени в минутах и секундах
    Timer(int min, int sec) : seconds(min * 60 + sec) {}

    // Конструктор для времени в виде строки "мм:сс"
    Timer(const string& timeStr) {
        size_t found = timeStr.find(":");
        if (found != string::npos) {
            int min = stoi(timeStr.substr(0, found));
            int sec = stoi(timeStr.substr(found + 1));
            seconds = min * 60 + sec;
        }
        else {
            cerr << "Invalid time format. Please use MM:SS." << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Функция запуска таймера
    void run() {
        clock_t start = clock();
        while (seconds > 0) {
            if ((clock() - start) / CLOCKS_PER_SEC == 1) {
                seconds--;
                start = clock();
            }
        }
        cout << "\aTimer has finished!" << endl;
    }
};

int main() {
    // Примеры использования конструкторов
    Timer timer1(5);         // Время в секундах
    Timer timer2(0, 10);       // Время в минутах и секундах
    Timer timer3("00:05");     // Время в виде строки "мм:сс"

    // Запуск таймеров
    cout << "Timer 1:" << endl;
    timer1.run();

    cout << "\nTimer 2:" << endl;
    timer2.run();

    cout << "\nTimer 3:" << endl;
    timer3.run();

    return 0;
}*/







#include <iostream>
#include <string>

using namespace std;

class Nomenclature {
private:
    string itemName;     
    double wholesalePrice; 
    double retailMarkup;   
    int quantityInStock;  

public:
    // Конструктор с параметрами
    Nomenclature(const string& name, double wholesale, double markup, int quantity)
        : itemName(name), wholesalePrice(wholesale), retailMarkup(markup), quantityInStock(quantity) {}

    // Деструктор
    ~Nomenclature() {
        // Возможные дополнительные операции при удалении объекта
        cout << "Объект " << itemName << " удален." << endl;
    }

    // Функция подсчета возможного чистого дохода при продаже товара
    double calculateNetIncome(int soldQuantity) {
        double retailPrice = wholesalePrice * (1 + retailMarkup);
        double grossIncome = retailPrice * soldQuantity;
        double netIncome = grossIncome - (wholesalePrice * soldQuantity);
        return netIncome;
    }

    // Функция вывода данных о товаре на экран
    void displayItemInfo() {
        cout << "Наименование товара: " << itemName << endl;
        cout << "Оптовая цена: $" << wholesalePrice << endl;
        cout << "Наценка на розницу: " << (retailMarkup * 100) << "%" << endl;
        cout << "Количество на складе: " << quantityInStock << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
  
    Nomenclature item1("Юбка", 10.0, 0.2, 50);

    cout << "Информация о товаре:" << endl;
    item1.displayItemInfo();

    int soldQuantity = 10;
    double netIncome = item1.calculateNetIncome(soldQuantity);

    cout << "Чистый доход от продажи " << soldQuantity << " единиц товара: $" << netIncome << endl;

    return 0;
}







/*#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Soft {
private:
    string programName;     
    string developer;        
    double occupiedSpace;    
    time_t licenseExpiration; 

public:
    // Конструктор с параметрами
    Soft(const string& name, const string& dev, double space, time_t expiration)
        : programName(name), developer(dev), occupiedSpace(space), licenseExpiration(expiration) {}

    // Деструктор
    ~Soft() {
        cout << "Программа " << programName << " удалена." << endl;
    }

    // Функция подсчета количества дней до завершения лицензии
    int daysUntilLicenseExpiration() const {
        time_t currentTime;
        time(&currentTime);

        int secondsRemaining;
        if (difftime(licenseExpiration, currentTime) > 0) {
            secondsRemaining = static_cast<int>(difftime(licenseExpiration, currentTime));
        }
        else {
            secondsRemaining = 0;
        }

        int daysRemaining = secondsRemaining / (60 * 60 * 24);

        return daysRemaining;
    }

    void displaySoftwareInfo() const {
        cout << "Название программы: " << programName << endl;
        cout << "Разработчик: " << developer << endl;
        cout << "Занимаемый объем: " << occupiedSpace << " MB" << endl;

        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &licenseExpiration);
        cout << "Дата завершения лицензии: " << buffer;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
   
    time_t expirationTime;
    time(&expirationTime);
    expirationTime += 30 * 24 * 60 * 60;  // Лицензия на 30 дней от текущего момента

    Soft software1("Microsoft Visual Studio", "Эмилбекова", 150.5, expirationTime);

   
    cout << "Информация о программном обеспечении:" << endl;
    software1.displaySoftwareInfo();

    int daysRemaining = software1.daysUntilLicenseExpiration();
    cout << "Дней до завершения лицензии: " << daysRemaining << endl;

    return 0;
}*/
