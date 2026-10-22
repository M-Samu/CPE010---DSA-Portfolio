// ILO C2

#include <iostream>

float kelvinToFahrenheit(float kelvin);

int main(){
	
	float kelvin = 0;
	std::cout << "Enter the temperature in Kelvin: " << kelvin << std::endl;
	
	
	std::cout << "Kelvin converted to Fahrenheit is: " << kelvinToFahrenheit(kelvin);
	
	return 0;
}

float kelvinToFahrenheit(float kelvin){
	float fahrenheit = (kelvin - 273.15)*(9.0/5.0) + 32;
	
	return fahrenheit;
}
