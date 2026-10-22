// ILO B

#include <iostream>

// naming convention for class name: PascalCase (first letter is always capital)
class Triangle{
	private:
		double totalAngle,angleA,angleB,angleC;
	
	public:
		// constructor
		Triangle(double A, double B, double C);
		void setAngels(double A, double B, double C);
		const bool validateTriangle();
	
};



int main(){
	
	Triangle set1(40,30,110);
	
	if (set1.validateTriangle()){
		std::cout << "The shape is a valid triangle \n";
	}
	
	else{
		std::cout << "The shape is NOT a valid triangle \m";
	}
	
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

