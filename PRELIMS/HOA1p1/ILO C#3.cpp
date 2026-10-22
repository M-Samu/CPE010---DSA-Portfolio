// ILO C #3
#include <iostream>


int distance(int x, int y);

int main(){
	
	std::cout << "The distance between the points 135 and 200 is: " << distance(135,200) << std::endl;
	
	return 0;
}

int distance(int x, int y){
	int d;
	d = y - x;
	
	return d;
}