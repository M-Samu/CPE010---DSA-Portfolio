// ILO A

#include <iostream>

int sumOfTwoNum(int fNum, int sNum);
int isGreater(int fNum, int sNum);
bool logicalOperators(bool a, bool b);

int main(){


	std::cout << "The sum of two numbers is: " << sumOfTwoNum(6,5) << std::endl;
	isGreater(6,5);
	
	if (logicalOperators(true, false)){
		std::cout << "Success!" << std::endl;
	}


return 0;

}

int sumOfTwoNum(int fNum, int sNum){
	
	int sum = fNum + sNum;
	
	return sum;
}

int isGreater(int fNum, int sNum){
	
	if (fNum > sNum){
		std::cout << "The first number is greater than the second number." << std::endl;
	}
	else{
		std::cout << "The first number is less than the second number." << std::endl;
	}
}

bool logicalOperators(bool a, bool b){
	
	std::cout << "A&&B = " << (a&&b) << std::endl;
	std::cout << "A||B = " << (a||b) << std::endl;
	std::cout << "!A = " << (!a) << std::endl;
	std::cout << "!B = " << (!b) << std::endl;
	
	return true;
}
