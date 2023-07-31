#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class: Car

// class: Manual
// class: Automatic

// Manaul ve Automatic-den de mashinlar yaransin.
// Misal class Bmw: Automatic

// funksiya yazirisiniz, Parametr olaraq Base qebul edir.
// Funksiya icersinde mashinlarin melumatlarni chap edirsiz.

// Her mashina aid field-ler ve mehodlar olsun.

// Base class adi altinda butun mashinlari vector-da saxlamaq
// Dersde kecdiylermizden istifade etmek...

class Car {
protected:
    string brand;

public:
    Car(const string& brand) : brand(brand) {}

    virtual void info() = 0;
};

class Manual : public Car {
private:
    int horsePower;

public:
    Manual(const string& brand, int horsePower) : Car(brand), horsePower(horsePower) {}

    void info() override {
        cout << "Car Brand: " << brand << endl;
        cout << "Transmission: Manual" << endl;
        cout << "Horsepower: " << horsePower << " HP" << endl;
        cout << endl;
    }
};

class Automatic : public Car {
private:
    string engineCapacity;

public:
    Automatic(const string& brand, string engineCapacity) : Car(brand), engineCapacity(engineCapacity) {}

    void info() override {
        cout << "Car Brand: " << brand << endl;
        cout << "Transmission: Automatic" << endl;
        cout << "Engine Capacity: " << engineCapacity << endl;
        cout << endl;
    }
};

// Base function
void base(const vector<Car*>& cars) {
    for (Car* car : cars) {
        car->info();
    }
}

int main() {
    Automatic* bmw = new Automatic("BMW M5", "4.4");
    Manual* hyundai = new Manual("Hyundai i30", 150);
    Automatic* mercedes = new Automatic("Mercedes G63", "4.0");

    vector<Car*> carList = { bmw, hyundai, mercedes };

    base(carList);

    for (Car* car : carList) {
        delete car;
    }

    return 0;
}