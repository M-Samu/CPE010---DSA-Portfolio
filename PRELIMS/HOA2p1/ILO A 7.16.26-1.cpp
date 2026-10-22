#include <iostream>
#include <string>

class Student{
	private:
		std::string studentName;
		int studentAge;
		
	public:
		// constructor
		Student(std::string newName="John Doe", int newAge=18){
			studentName = std::move(newName);
			studentAge = newAge;
			std::cout << "Constructor called." << std::endl;
		}
		
		// Deconstructor
		~Student(){
			std::cout << "Deconstrutor Called" << std::endl;
		}
		
		// Copy Constructor
		Student(const Student &copyStudent){
			std::cout << "Copy Constructor Called" << std::endl;
			studentName = copyStudent.studentName;
			studentAge = copyStudent.studentAge;
		}
		
		// Display Attributes
		void printDetails(){
			std::cout << this ->studentName << " " << this -> studentAge << std::endl;
		}
		
};

int main(){
    const size_t j = 5;

    Student studentList[j]= {};
    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    // Loop A
    for(int i=0; i<j; i++){
        Student *ptr = new Student(namesList[i], ageList[i]);
        studentList[i] = *ptr;
    }
    
    // Loop B
    for(int i=0; i<j; i++){
        studentList[i].printDetails();
    }

	return 0;
}

