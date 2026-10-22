// ILO C1

#include <iostream>


int main(){
	
	int num1 = 5;
	int num2 = 6;
	int temporaryNum;
	
	std::cout << "First number: " << num1 <<  std::endl;
	std::cout << "Second number: " << num2 << std::endl;
	
	temporaryNum = num2;
	num2 = num1;
	num1 = temporaryNum;
	
	std::cout << "First number: " << num1 <<  std::endl;
	std::cout << "Second number: " << num2 << std::endl;
	
	return 0;
}


