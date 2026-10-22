// ILO C#4
// modified ilo B
#include <iostream>
#include <cmath>


class Triangle{
	private:
		double totalAngle,angleA,angleB,angleC;
	
	public:
		// constructor
		Triangle(double A, double B, double C);
		void setAngels(double A, double B, double C);
		const bool validateTriangle();
	
};

float areaOfTriangle(float base, float height);
int perimeterOfTriangle(int a, int b, int c);
void angleOfTriangle(int a, int b, int c);


int main(){
	
	Triangle set1(40,30,110);
	
	if (set1.validateTriangle()){
		std::cout << "The shape is a valid triangle \n";
	}
	
	else{
		std::cout << "The shape is NOT a valid triangle \n";
	}
	
	std::cout << "The area of a triangle with base of 11 and height of 20 is: " << areaOfTriangle(11,20) << std::endl;
	
	std::cout << "The perimeter of a triangle with the sides 5, 8 ,7 is: " << perimeterOfTriangle(5,8,7) << std::endl;
	
	std::cout << "The angle of the triangle with the sides 5,8,7 is: ";
	angleOfTriangle(5,8,7);
	
	return 0;

}



Triangle::Triangle(double A, double B, double C){
	angleA = A;
	angleB = B;
	angleC = C;
	totalAngle = A+B+C;
}

void Triangle::setAngels(double A, double B, double C){
	angleA = A;
	angleB = B;
	angleC = C;
	totalAngle = A+B+C;
}

const bool Triangle::validateTriangle(){
	return(totalAngle<=180);
}

float areaOfTriangle(float base, float height){
	return 1.0/2.0*(base*height);
}

int perimeterOfTriangle(int a, int b, int c){
	return a+b+c;
}

void angleOfTriangle(int a, int b, int c){
	int temporary;
	int e = 2;
	
	if (a>b){
		temporary = a;
		a = b ;
		b = temporary;
	}
	
	if (b>c){
		temporary = b;
		b = c;
		c = temporary;
	}
	
	if (pow(a,e)+pow(b,e)==pow(c,e)){
	 	std::cout << "Right triangle" << std::endl;
	}
	 
	else if (pow(a,e)+pow(b,e)>pow(c,e)){
	 	std::cout << "Acute triangle" << std::endl;
	}
	 
	else{
	 	std::cout << "Obtuse triangle" << std::endl;
	}
}
