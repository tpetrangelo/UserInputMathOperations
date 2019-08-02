/*
Tom Petrangelo
CIS 554 2019-0703 - Object Oriented Programming
Homework #4 - Computer Assisted Instructed
Pages 281-2
*/
#include "ComputerAssist.h"
#include <random>
#include <cmath>

ComputerAssist::ComputerAssist()
{
}

void ComputerAssist::setDifficulty(int difficultySet)
{
	difficulty = difficultySet;
}

void ComputerAssist::setInstructionType(int typeSet)
{
	type = typeSet;
}

int ComputerAssist::getDifficulty()
{
	return difficulty;
}

int ComputerAssist::getInstructionType()
{
	return type;
}

int ComputerAssist::askQuestion(int type, int difficulty)
{
	for (int i = 0; i < 10; i++) {
		int randomNumber1{ (int)pow(10,difficulty - 1) + rand() % (int)pow(10,difficulty) };
		int randomNumber2{ (int)pow(10,difficulty - 1) + rand() % (int)pow(10,difficulty) };
		switch (type) {
			//Addition
		case 1:
			std::cout << "How much is " << randomNumber1 << " + " << randomNumber2 << "?" << std::endl;
			correctAnswer = randomNumber1 + randomNumber2;
			std::cout << "Answer: ";
			std::cin >> answer;
			if (answer != correctAnswer) {
				getResponse(isCorrect);
				while (answer != correctAnswer) {
					isCorrect = false;
					
					std::cout << "How much is " << randomNumber1 << " + " << randomNumber2 << "?" << std::endl << "New answer : ";
					correctAnswer = randomNumber1 + randomNumber2;
					std::cout << correctAnswer << std::endl;
					std::cin >> answer;
					if (answer == correctAnswer) {
						isCorrect = true;
					}
					getResponse(isCorrect);
					correctAnswer = 0;
				}
				correctAnswer--;
			}
			else
			{
				getResponse(isCorrect);
				std::cout<< std::endl;
			}
			correctAnswer = 0;
			break;
			//Subtraction
		case 2:
			break;
			//Multiplication
		case 3:
			break;
			//Division
		case 4:
			break;
			//All four
		case 5:
			break;
		default:
			std::cout << "Invalid choice" << std::endl;
			std::cin >> type;
			askQuestion(type, difficulty);
		}
	}
	getBenchmark(correctAnswer);
	return 0;
}

void ComputerAssist::getResponse(bool isCorrectParam)
{
	responseNum = { 1 + rand() % 4 };
	if (isCorrectParam == true) {

		switch (responseNum)
		{
		case 1:
			std::cout << "Very good!" << std::endl;
			break;
		case 2:
			std::cout << "Excellent!" << std::endl;
			break;
		case 3:
			std::cout << "Nice work!" << std::endl;
			break;
		case 4:
			std::cout << "Keep up the good work!" << std::endl;
			break;
		default:
			std::cout << "Invalid response" << std::endl;
			break;
		}
	}
	else {

		switch (responseNum)
		{
		case 1:
			std::cout << "No. Please try again" << std::endl;
			break;
		case 2:
			std::cout << "Wrong. Try once more." << std::endl;
			break;
		case 3:
			std::cout << "Don't give up!" << std::endl;
			break;
		case 4:
			std::cout << "No. Keep trying" << std::endl;
			break;
		default:
			std::cout << "Invalid response" << std::endl;
			break;
		}
	}
}
	


void ComputerAssist::getBenchmark(int correctParam)
{
	if (correctParam > 7) {
		std::cout << "Congratulations, you are ready to go to the next level!" << std::endl;
	}
	else {
		std::cout << "Please ask your teacher for extra help" << std::endl;
	}
}
