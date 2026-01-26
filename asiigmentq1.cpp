#include <iostream>
using namespace std;


float celsiusToFahrenheit(float c) {
    return (1.8 * c + 32);
}


float fahrenheitToCelsius(float f) {
    return ((f - 32) / 1.8);
}

int main() {
    float t;
    char u;

    cout << "Enter the temperature and unit (C or F): ";
    cin >> t >> u;

    if (u == 'C' || u == 'c') {
        cout << "Temperature in Fahrenheit = "
             << celsiusToFahrenheit(t);
    }
    else if (u == 'F' || u == 'f') {
        cout << "Temperature in Celsius = "
             << fahrenheitToCelsius(t);
    }
    else {
        cout << "Invalid unit! Please enter C or F";
    }

    return 0;
}
