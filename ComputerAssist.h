/*
Tom Petrangelo
CIS 554 2019-0703 - Object Oriented Programming
Homework #4 - Computer Assisted Instructed
Pages 281-2
*/

#pragma once
#include <iostream>
class ComputerAssist
{
public:
	ComputerAssist();
	//sets difficulty from user input, also validates correct input
	void setDifficulty(int difficultySet);
	//sets instruction type from user input (Add,Subtract,Multiply,Divide,All 4)
	void setInstructionType(int typeSet);
	//returns current difficulty
	int getDifficulty();
	//returns current instruction type
	int getInstructionType();
	//uses type and difficulty to ask a question to the user
	int askQuestion(int type, int difficulty);
	//returns variation of output to user
	void getResponse(bool answerParam);
	//sets benchmark to check if user answered 75% or more questions correctly
	void getBenchmark(int correctParam);


private:
	int difficulty{ 1 };
	int type{ 1 };
	int answer{ 0 };
	int correctAnswer{ 10 };
	bool isCorrect{ true };
	int numCorrect{ 0 };
	int responseNum{ 1 };
};

