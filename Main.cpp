/*
Tom Petrangelo
CIS 554 2019-0703 - Object Oriented Programming
Homework #4 - Computer Assisted Instructed
Pages 281-2
*/
#include "ComputerAssist.h"
#include <iostream>
int main()
{
	int type{ 0 };
	int difficulty{ 0 };
	ComputerAssist student1;
	
	std::cout << "Hello, please enter a problem type:" << std::endl << "1: Addition 2: Subtraction" << std::endl;;
	std::cout << "3: Multiplication 4: Division" << std::endl << "5: All four types" << std::endl;
	std::cout << "Enter type: ";
	std::cin >> type;
	student1.setInstructionType(type);
	std::cout << "Please now enter a difficutly, input decides number of digits in problem: ";
	std::cin >> difficulty;
	student1.setDifficulty(difficulty);
	student1.askQuestion(difficulty, type);
	return 0;

}