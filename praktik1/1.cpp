#include <iostream>

class Engine {
public:
    void run() {
        std::cout << "Двигатель запущен!" << std::endl;
    }
};

class Car {
private:
    Engine engine;  

public:
    void start() {
        std::cout << "Запуск автомобиля..." << std::endl;
        engine.run();  
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Car myCar;
    myCar.start();

    return 0;
}
