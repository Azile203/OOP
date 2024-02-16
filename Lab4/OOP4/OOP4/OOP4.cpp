#include <iostream>
#include <string>

using namespace std;

class Kamaz {
private:
    string name;
    int speed_plain;
    int speed_mountains;
    int speed_desert;
public:
    Kamaz(string n, int sp, int sm, int sd) : name(n), speed_plain(sp), speed_mountains(sm), speed_desert(sd) {}
    int getPlainSpeed() const { return speed_plain; }
    int getMountainsSpeed() const { return speed_mountains; }
    int getDesertSpeed() const { return speed_desert; }
    string getName() const { return name; }
};

class Tatra {
private:
    string name;
    int speed_plain;
    int speed_mountains;
    int speed_desert;
public:
    Tatra(string n, int sp, int sm, int sd) : name(n), speed_plain(sp), speed_mountains(sm), speed_desert(sd) {}
    int getPlainSpeed() const { return speed_plain; }
    int getMountainsSpeed() const { return speed_mountains; }
    int getDesertSpeed() const { return speed_desert; }
    string getName() const { return name; }
};

int main() {
    string kamazName, tatraName;
    int kamazPlain, kamazMountains, kamazDesert;
    int tatraPlain, tatraMountains, tatraDesert;

    cout << "Enter Kamaz name: ";
    cin >> kamazName;
    cout << "Enter Kamaz speed on Plain (km/h): ";
    cin >> kamazPlain;
    cout << "Enter Kamaz speed in Mountains (km/h): ";
    cin >> kamazMountains;
    cout << "Enter Kamaz speed in Desert (km/h): ";
    cin >> kamazDesert;

    cout << "Enter Tatra name: ";
    cin >> tatraName;
    cout << "Enter Tatra speed on Plain (km/h): ";
    cin >> tatraPlain;
    cout << "Enter Tatra speed in Mountains (km/h): ";
    cin >> tatraMountains;
    cout << "Enter Tatra speed in Desert (km/h): ";
    cin >> tatraDesert;
    cout << "=== Results ===" << endl;

    Kamaz kamaz(kamazName, kamazPlain, kamazMountains, kamazDesert);
    Tatra tatra(tatraName, tatraPlain, tatraMountains, tatraDesert);

    int kamazWins = 0, tatraWins = 0;

    if (kamaz.getPlainSpeed() > tatra.getPlainSpeed()) {
        cout << "Plain: " << kamaz.getName() << " wins" << endl;
        kamazWins++;
    }
    else if (kamaz.getPlainSpeed() < tatra.getPlainSpeed()) {
        cout << "Plain: " << tatra.getName() << " wins" << endl;
        tatraWins++;
    }
    else {
        cout << "Plain: It's a tie!" << endl;
    }

    if (kamaz.getMountainsSpeed() > tatra.getMountainsSpeed()) {
        cout << "Mountains: " << kamaz.getName() << " wins" << endl;
        kamazWins++;
    }
    else if (kamaz.getMountainsSpeed() < tatra.getMountainsSpeed()) {
        cout << "Mountains: " << tatra.getName() << " wins" << endl;
        tatraWins++;
    }
    else {
        cout << "Mountains: It's a tie!" << endl;
    }

    if (kamaz.getDesertSpeed() > tatra.getDesertSpeed()) {
        cout << "Desert: " << kamaz.getName() << " wins" << endl;
        kamazWins++;
    }
    else if (kamaz.getDesertSpeed() < tatra.getDesertSpeed()) {
        cout << "Desert: " << tatra.getName() << " wins" << endl;
        tatraWins++;
    }
    else {
        cout << "Desert: It's a tie!" << endl;
    }

    if (kamazWins > tatraWins) {
        cout << kamaz.getName() << " wins overall!" << endl;
    }
    else if (kamazWins < tatraWins) {
        cout << tatra.getName() << " wins overall!" << endl;
    }
    else {
        cout << "Overall: It's a tie!" << endl;
    }

    return 0;
}    







/*#include <iostream>
#include <string>

using namespace std;

class Tatra;

class Kamaz {
private:
    string name;
    int speed_plain;
    int speed_mountains;
    int speed_desert;
public:
    Kamaz(string n, int sp, int sm, int sd) : name(n), speed_plain(sp), speed_mountains(sm), speed_desert(sd) {}
    int getPlainSpeed() const { return speed_plain; }
    int getMountainsSpeed() const { return speed_mountains; }
    int getDesertSpeed() const { return speed_desert; }
    string getName() const { return name; }
    friend void FrCreater(Kamaz& kamaz);
    friend void FrCreater(Kamaz& kamaz, Tatra& tatra);
    friend void compareSpeed(Kamaz& kamaz, Tatra& tatra);
};

class Tatra {
private:
    string name;
    int speed_plain;
    int speed_mountains;
    int speed_desert;
public:
    Tatra(string n, int sp, int sm, int sd) : name(n), speed_plain(sp), speed_mountains(sm), speed_desert(sd) {}
    int getPlainSpeed() const { return speed_plain; }
    int getMountainsSpeed() const { return speed_mountains; }
    int getDesertSpeed() const { return speed_desert; }
    string getName() const { return name; }
    friend void FrCreater(Kamaz& kamaz, Tatra& tatra);
    friend void compareSpeed(Kamaz& kamaz, Tatra& tatra);
};

void FrCreater(Kamaz& kamaz) {
    cout << "Name: " << kamaz.name << endl;
    cout << "Plain Speed: " << kamaz.speed_plain << endl;
    cout << "Mountains Speed: " << kamaz.speed_mountains << endl;
    cout << "Desert Speed: " << kamaz.speed_desert << endl;
}

void FrCreater(Kamaz& kamaz, Tatra& tatra) {
    cout << "Kamaz Name: " << kamaz.name << endl;
    cout << "Kamaz Plain Speed: " << kamaz.speed_plain << endl;
    cout << "Kamaz Mountains Speed: " << kamaz.speed_mountains << endl;
    cout << "Kamaz Desert Speed: " << kamaz.speed_desert << endl;
    cout << "Tatra Name: " << tatra.name << endl;
    cout << "Tatra Plain Speed: " << tatra.speed_plain << endl;
    cout << "Tatra Mountains Speed: " << tatra.speed_mountains << endl;
    cout << "Tatra Desert Speed: " << tatra.speed_desert << endl;
}

void compareSpeed(Kamaz& kamaz, Tatra& tatra) {
    int kamazWins = 0, tatraWins = 0;

    if (kamaz.getPlainSpeed() > tatra.getPlainSpeed()) {
        cout << "Plain: " << kamaz.getName() << " wins" << endl;
        kamazWins++;
    }
    else if (kamaz.getPlainSpeed() < tatra.getPlainSpeed()) {
        cout << "Plain: " << tatra.getName() << " wins" << endl;
        tatraWins++;
    }
    else {
        cout << "Plain: It's a tie!" << endl;
    }

    if (kamaz.getMountainsSpeed() > tatra.getMountainsSpeed()) {
        cout << "Mountains: " << kamaz.getName() << " wins" << endl;
        kamazWins++;
    }
    else if (kamaz.getMountainsSpeed() < tatra.getMountainsSpeed()) {
        cout << "Mountains: " << tatra.getName() << " wins" << endl;
        tatraWins++;
    }
    else {
        cout << "Mountains: It's a tie!" << endl;
    }

    if (kamaz.getDesertSpeed() > tatra.getDesertSpeed()) {
        cout << "Desert: " << kamaz.getName() << " wins" << endl;
        kamazWins++;
    }
    else if (kamaz.getDesertSpeed() < tatra.getDesertSpeed()) {
        cout << "Desert: " << tatra.getName() << " wins" << endl;
        tatraWins++;
    }
    else {
        cout << "Desert: It's a tie!" << endl;
    }

    if (kamazWins > tatraWins) {
        cout << kamaz.getName() << " wins overall!" << endl;
    }
    else if (kamazWins < tatraWins) {
        cout << tatra.getName() << " wins overall!" << endl;
    }
    else {
        cout << "Overall: It's a tie!" << endl;
    }
}

int main() {
    string kamazName, tatraName;
    int kamazPlain, kamazMountains, kamazDesert;
    int tatraPlain, tatraMountains, tatraDesert;

    cout << "Enter Kamaz name: ";
    cin >> kamazName;
    cout << "Enter Kamaz speed on Plain (km/h): ";
    cin >> kamazPlain;
    cout << "Enter Kamaz speed in Mountains (km/h): ";
    cin >> kamazMountains;
    cout << "Enter Kamaz speed in Desert (km/h): ";
    cin >> kamazDesert;

    cout << "Enter Tatra name: ";
    cin >> tatraName;
    cout << "Enter Tatra speed on Plain (km/h): ";
    cin >> tatraPlain;
    cout << "Enter Tatra speed in Mountains (km/h): ";
    cin >> tatraMountains;
    cout << "Enter Tatra speed in Desert (km/h): ";
    cin >> tatraDesert;

    Kamaz kamaz(kamazName, kamazPlain, kamazMountains, kamazDesert);
    Tatra tatra(tatraName, tatraPlain, tatraMountains, tatraDesert);

    FrCreater(kamaz);
    FrCreater(kamaz, tatra);
    compareSpeed(kamaz, tatra);

    return 0;
}*/







/*#include <iostream>
#include <string>

using namespace std;

class Tatra;

class Kamaz {
private:
    string name;
    int speed_plain;
    int speed_mountains;
    int speed_desert;
public:
    Kamaz(string n, int sp, int sm, int sd) : name(n), speed_plain(sp), speed_mountains(sm), speed_desert(sd) {}
    int getPlainSpeed() const { return speed_plain; }
    int getMountainsSpeed() const { return speed_mountains; }
    int getDesertSpeed() const { return speed_desert; }
    string getName() const { return name; }
    friend void FrCreater(Kamaz& kamaz);
    friend void FrCreater(Kamaz& kamaz, Tatra& tatra);
    friend void compareSpeed(Kamaz& kamaz, Tatra& tatra);
    friend class Tatra; // Добавляем дружественный класс Tatra
};

class Tatra {
private:
    string name;
    int speed_plain;
    int speed_mountains;
    int speed_desert;
public:
    Tatra(string n, int sp, int sm, int sd) : name(n), speed_plain(sp), speed_mountains(sm), speed_desert(sd) {}
    int getPlainSpeed() const { return speed_plain; }
    int getMountainsSpeed() const { return speed_mountains; }
    int getDesertSpeed() const { return speed_desert; }
    string getName() const { return name; }
    friend void FrCreater(Kamaz& kamaz, Tatra& tatra);
    friend void compareSpeed(Kamaz& kamaz, Tatra& tatra);
};

void FrCreater(Kamaz& kamaz) {
    cout << "Friend function accessing Kamaz private members." << endl;
   
}

void FrCreater(Kamaz& kamaz, Tatra& tatra) {
    cout << "Friend function accessing Kamaz and Tatra private members." << endl;
    
}

void compareSpeed(Kamaz& kamaz, Tatra& tatra) {
    int kamazWins = 0, tatraWins = 0;

    if (kamaz.getPlainSpeed() > tatra.getPlainSpeed()) {
        cout << "Plain: " << kamaz.getName() << " wins" << endl;
        kamazWins++;
    }
    else if (kamaz.getPlainSpeed() < tatra.getPlainSpeed()) {
        cout << "Plain: " << tatra.getName() << " wins" << endl;
        tatraWins++;
    }
    else {
        cout << "Plain: It's a tie!" << endl;
    }

    if (kamaz.getMountainsSpeed() > tatra.getMountainsSpeed()) {
        cout << "Mountains: " << kamaz.getName() << " wins" << endl;
        kamazWins++;
    }
    else if (kamaz.getMountainsSpeed() < tatra.getMountainsSpeed()) {
        cout << "Mountains: " << tatra.getName() << " wins" << endl;
        tatraWins++;
    }
    else {
        cout << "Mountains: It's a tie!" << endl;
    }

    if (kamaz.getDesertSpeed() > tatra.getDesertSpeed()) {
        cout << "Desert: " << kamaz.getName() << " wins" << endl;
        kamazWins++;
    }
    else if (kamaz.getDesertSpeed() < tatra.getDesertSpeed()) {
        cout << "Desert: " << tatra.getName() << " wins" << endl;
        tatraWins++;
    }
    else {
        cout << "Desert: It's a tie!" << endl;
    }

    if (kamazWins > tatraWins) {
        cout << kamaz.getName() << " wins overall!" << endl;
    }
    else if (kamazWins < tatraWins) {
        cout << tatra.getName() << " wins overall!" << endl;
    }
    else {
        cout << "Overall: It's a tie!" << endl;
    }
}

int main() {
    string kamazName, tatraName;
    int kamazPlain, kamazMountains, kamazDesert;
    int tatraPlain, tatraMountains, tatraDesert;

    cout << "Enter Kamaz name: ";
    cin >> kamazName;
    cout << "Enter Kamaz speed on Plain (km/h): ";
    cin >> kamazPlain;
    cout << "Enter Kamaz speed in Mountains (km/h): ";
    cin >> kamazMountains;
    cout << "Enter Kamaz speed in Desert (km/h): ";
    cin >> kamazDesert;

    cout << "Enter Tatra name: ";
    cin >> tatraName;
    cout << "Enter Tatra speed on Plain (km/h): ";
    cin >> tatraPlain;
    cout << "Enter Tatra speed in Mountains (km/h): ";
    cin >> tatraMountains;
    cout << "Enter Tatra speed in Desert (km/h): ";
    cin >> tatraDesert;

    Kamaz kamaz(kamazName, kamazPlain, kamazMountains, kamazDesert);
    Tatra tatra(tatraName, tatraPlain, tatraMountains, tatraDesert);

    compareSpeed(kamaz, tatra);

    return 0;
}*/
