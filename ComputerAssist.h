/*
Tom Petrangelo
CIS 554 2019-0703 - Object Oriented Programming
Homework #4 - Computer Assisted Instructed
Pages 281-2
*/

#pragma once
#include <iostream>
#include <ctime>


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
	//combines all five possible inputs using a switch statement to output a question
	void questionInput(int randomInt1, int randomInt2, int type);
	//validates user input
	void validateData(int input);


private:
	//default difficutly (one digit)
	int difficulty{ 1 };
	//default question type (addition)
	int type{ 1 };
	//default user-input answer
	int answer{ 0 };
	//default correct answer
	int correctAnswer{ 0 };
	//default status of user input correct answer
	bool isCorrect{ true };
	//default counter for correct answers, decrements if answer is wrong
	int numCorrect{ 10 };
	//default response to an answer, used in a switch statement
	int responseNum{ 1 };
};

