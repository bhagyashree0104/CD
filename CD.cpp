#include <iostream>

class Temperaturesensor {
private:
    int currentTemperature;

public:
    Temperaturesensor() : currentTemperature(0) {}

    void setCurrentTemperature(int temperature) {
        currentTemperature = temperature;
    }

    int getCurrentTemperature() const {
        return currentTemperature;
    }
};

class Waterheater {
private:
    int heatingTemperature;

public:
    Waterheater() : heatingTemperature(0) {}

    void setHeatingTemperature(int temperature) {
        heatingTemperature = temperature;
    }

    int getHeatingTemperature() const {
        return heatingTemperature;
    }

    void heatWater(int requiredTemperature) const {
        std::cout << "Heating the water to " << requiredTemperature << " degrees Celsius." << std::endl;
    }
};

class SmartGeyser {
private:
    const Temperaturesensor& sensor;
    Waterheater& heater;

public:
    SmartGeyser(const Temperaturesensor& tempSensor, Waterheater& waterHeater)
        : sensor(tempSensor), heater(waterHeater) {}

    void activateGeyser() const {
        std::cout << "Geyser activated." << std::endl;
        int currentTemp = sensor.getCurrentTemperature();
        std::cout << "Current temperature detected: " << currentTemp << " degrees Celsius." << std::endl;
        int requiredTemp = calculateRequiredTemperature(currentTemp);
        heater.heatWater(requiredTemp);
    }

    int calculateRequiredTemperature(int currentTemperature) const {

        return currentTemperature - 10;
    }
};

class HomeOwner {
public:
    void getOutOfBed() const {
        std::cout << "Homeowner has gotten out of bed." << std::endl;
    }
};

int main() {
    Temperaturesensor sensor;
    Waterheater heater;
    SmartGeyser geyser(sensor, heater);
    HomeOwner owner;

    int currentTemp;

    std::cout << "Enter the current temperature in degrees Celsius: ";
    std::cin >> currentTemp;

    sensor.setCurrentTemperature(currentTemp);

    owner.getOutOfBed();
    geyser.activateGeyser();

    return 0;
}
