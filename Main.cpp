/*
Tom Petrangelo
CIS 554-70618 - Object Oriented Programming
Homework #4 - Computer Assisted Instructed
Pages 281-2
*/

#include "ComputerAssist.h"
#include <iostream>
int main()
{
	//initialize type and difficulty
	int type{ 0 };
	int difficulty{ 0 };

	//initialization of ComputerAssist object
	ComputerAssist student1;
	
	//ask user for type of question
	std::cout << "Hello, please enter a problem type" << std::endl << "1: Addition 2: Subtraction" << std::endl;;
	std::cout << "3: Multiplication 4: Division" << std::endl << "5: All four types" << std::endl;
	std::cout << "Enter type: ";
	std::cin >> type;
	
	//Integer validation for type
	while (!std::cin) {
		std::cout << "Invalid data type, please enter an integer: ";
		//repair the instream
		std::cin.clear();
		//clear the buffer
		std::cin.ignore();
		std::cin >> type;
	}
	//sets instruction type for student1 based on user input
	student1.setInstructionType(type);

	//asks user for difficulty of question, input determines number of digits in question
	std::cout << "Please now enter a difficutly, input decides number of digits in problem: ";

	//sets the difficulty for student1 based on user input
	std::cin >> difficulty;
	
	//Integer validation for difficutly
	while (!std::cin) {
		std::cout << "Invalid data type, please enter an integer: ";
		
		//repair the instream
		std::cin.clear();
		
		//clear the buffer
		std::cin.ignore();
		std::cin >> type;
	}

	//sets the difficulty for student1 based on user input
	student1.setDifficulty(difficulty);
	
	//combines type and difficulty and passes these two arguments to askQuestion, which initiates the math questions
	student1.askQuestion(type, difficulty);
	return 0;

}