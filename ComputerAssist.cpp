/*
Tom Petrangelo
CIS 554-70618 - Object Oriented Programming
Homework #4 - Computer Assisted Instructed
Pages 281-2
*/

#include "ComputerAssist.h"

//default constructor for ComputerAssist object
ComputerAssist::ComputerAssist()
{
}

//sets difficulty of question
void ComputerAssist::setDifficulty(int difficultySet)
{
	difficulty = difficultySet;
}

//sets instruction type of question
void ComputerAssist::setInstructionType(int typeSet)
{
	type = typeSet;
}

//returns question difficulty
int ComputerAssist::getDifficulty()
{
	return difficulty;
}

//returns question type
int ComputerAssist::getInstructionType()
{
	return type;
}

/*
Asks the user a set of 10 math questions, "type" will determine operator for math question
if "5" is input, question operator will be asked at random. askQuestion uses srand() and 
rand, along with pow to create random numbers contained in a range set by the user input
variable "difficulty". Once the 10 questions are completed, getBenchmark is called that
checks to see if the user got greater than 75% correct (8 or more). An output will be sent
to the user based on this result
*/
int ComputerAssist::askQuestion(int type, int difficulty)
{
	for (int i = 0; i < 10; i++) {
		srand(time(NULL));

		//creates two random numbers bounded by difficutly ex: difficulty of 2 bounds possible numbers from 10 to 99
		int randomNumber1{ rand() % ((int)pow(10,difficulty) - 1 + 1 - (int)pow(10,difficulty - 1)) + (int)pow(10,difficulty - 1) };
		int randomNumber2{ rand() % ((int)pow(10,difficulty) - 1 + 1 - (int)pow(10,difficulty - 1)) + (int)pow(10,difficulty - 1) }; 
		
		//{ rand() % (int)pow(10,difficulty) - 1 + (int)pow(10,difficulty - 1) };
		//creates a random operator in the case that the user inputs 5 for type "combination of all four operators"
		int randOperator = (rand() % 4 + 1);
		
		//validation of integer inputs for type, bounds valid inputs from 1 to 5
		if (type < 1 || type > 5) {
			std::cout << "Invalid choice, please re-enter a type: ";
			std::cin >> type;
			askQuestion(type, difficulty);
		}

		//if type equals five, randOperator will take place of type to vary the operator that will be asked in next question, otherwise user-input type will be used
		if (type == 5) {
			questionInput(randomNumber1, randomNumber2, randOperator);
		}
		else
		{
			questionInput(randomNumber1, randomNumber2, type);
		}
	}
		//passes numCorrect to getBenchmark to check if user got eight or more questions correctly.
		getBenchmark(numCorrect);
		
		return 0;
}

//getResponse outputs various repsponses to user based on if their answer was correct or not
void ComputerAssist::getResponse(bool isCorrectParam)
{
	//randomized integer that will output a random response to user
	srand(time(NULL));
	responseNum = { 1 + rand() % 4 };
	
	//outputs for correct answers based on responseNum, a random integer between one and four
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

	//outputs for incorrect answers based on responseNum, a random integer between one and four
	else {

		switch (responseNum)
		{
		case 1:
			std::cout << "No. Please try again" << std::endl << std::endl;
			break;
		case 2:
			std::cout << "Wrong. Try once more." << std::endl << std::endl;
			break;
		case 3:
			std::cout << "Don't give up!" << std::endl << std::endl;
			break;
		case 4:
			std::cout << "No. Keep trying" << std::endl << std::endl;
			break;
		default:
			std::cout << "Invalid response" << std::endl << std::endl;
			break;
		}
	}
}
	

//checks to see if user got eight or more questions correctly. Outputs correct response to user if they passed or not
void ComputerAssist::getBenchmark(int correctParam)
{
	if (correctParam > 7) {
		std::cout << "Congratulations, you are ready to go to the next level!" << std::endl;
	}
	else {
		std::cout << "Please ask your teacher for extra help" << std::endl;
	}
}

//uses switch statement to ask user question and recieve input, either + - * / or all four. Gets passed in two random integers and question operator type
void ComputerAssist::questionInput(int randomInt1, int randomInt2, int op)
{
	//switch statment based on op (operator)
	switch (op)
	{

	//case 1: addition
	case 1:

		//asks user an addition question
		std::cout << "How much is " << randomInt1 << " + " << randomInt2 << "?" << std::endl;
		
		//correct answer is calculated for user comparison
		correctAnswer = randomInt1 + randomInt2;

		//looks for user input
		std::cout << "Answer: ";
		std::cin >> answer;

		//data type validation
		while (!std::cin) {
			std::cout << std::endl;
			std::cout << "Invalid data type, please enter an integer answer: ";
			
			//repair the instream
			std::cin.clear();
			
			//clear the buffer
			std::cin.ignore();
			std::cin >> answer;

		}

		//conditional if statement to check if user input is the correct answer
		if (answer != correctAnswer) {
			
			//while the user continues to input wrong answer, loop through
			while (answer != correctAnswer) {
				
				//set isCorrect to false in order to get an incorrect response from getResponse
				isCorrect = false;
				std::cout << std::endl;
				getResponse(isCorrect);
				
				//re-asks user same question they got wrong orignally
				std::cout << "How much is " << randomInt1 << " + " << randomInt2 << "?" << std::endl << "New answer : ";
				std::cin >> answer;

				
				//data type validation
				while (!std::cin) {
					std::cout << "Invalid data type, please enter an integer answer: ";
					
					//repair the instream
					std::cin.clear();
					
					//clear the buffer
					std::cin.ignore();
					std::cin >> answer;
					std::cout << std::endl;

				}
				
				//if user inputs correct answer, set isCorrect to true and get new output response reflecting a correct answer
				if (answer == correctAnswer) {
					isCorrect = true;
					std::cout << std::endl;
					getResponse(isCorrect);
					std::cout << std::endl;

				}

			}
			
			//set correctAnswer to 0 in order to allow a new question without correctAnswer holding a previous value
			correctAnswer = 0;
			
			//since user got the answer wrong at one point in current question, decrement numCorrect (defaulted at 10) in order to keep track of user passing or not 
			numCorrect--;
		}
		
		//if user gets answer right on first try, output a correct response and out an end line
		else
		{
			std::cout << std::endl;
			getResponse(isCorrect);
			std::cout << std::endl;
		}
		
		//set correct answer back to 0
		correctAnswer = 0;
		break;

		//case 2: subtraction
	case 2:


		//correct answer is calculated for user comparison
		correctAnswer = randomInt1 - randomInt2;

		//if correctAnswer is negative, change randomInt1 & randomInt2 until the answer is positive or 0
		while (correctAnswer < 0) {
			randomInt1 = { rand() % ((int)pow(10,difficulty) - 1 + 1 - (int)pow(10,difficulty - 1)) + (int)pow(10,difficulty - 1) };
			randomInt2 = { rand() % ((int)pow(10,difficulty) - 1 + 1 - (int)pow(10,difficulty - 1)) + (int)pow(10,difficulty - 1) };
			correctAnswer = randomInt1 - randomInt2;
		}

		//asks user an subtraction question
		std::cout << "How much is " << randomInt1 << " - " << randomInt2 << "?" << std::endl;

	
		//looks for user input
		std::cout << "Answer: ";
		std::cin >> answer;

		//data type validation
		while (!std::cin) {
			std::cout << std::endl;
			std::cout << "Invalid data type, please enter an integer answer: ";
			
			//repair the instream
			std::cin.clear();
		
			//clear the buffer
			std::cin.ignore();
			std::cin >> answer;

		}

		//conditional if statement to check if user input is the correct answer
		if (answer != correctAnswer) {
			
			//while the user continues to input wrong answer, loop through
			while (answer != correctAnswer) {
			
				//set isCorrect to false in order to get an incorrect response from getResponse
				isCorrect = false;
				std::cout << std::endl;
				getResponse(isCorrect);
			
				//re-asks user same question they got wrong orignally
				std::cout << "How much is " << randomInt1 << " - " << randomInt2 << "?" << std::endl << "New answer : ";
				std::cin >> answer;


				//data type validation
				while (!std::cin) {
					std::cout << "Invalid data type, please enter an integer answer: ";
					
					//repair the instream
					std::cin.clear();
				
					//clear the buffer
					std::cin.ignore();
					std::cin >> answer;
					std::cout << std::endl;

				}
				
				//if user inputs correct answer, set isCorrect to true and get new output response reflecting a correct answer
				if (answer == correctAnswer) {
					isCorrect = true;
					std::cout << std::endl;
					getResponse(isCorrect);
					std::cout << std::endl;

				}

			}
			//set correctAnswer to 0 in order to allow a new question without correctAnswer holding a previous value
			correctAnswer = 0;
			
			//since user got the answer wrong at one point in current question, decrement numCorrect (defaulted at 10) in order to keep track of user passing or not 
			numCorrect--;
		}
		//if user gets answer right on first try, output a correct response and out an end line
		else
		{
			std::cout << std::endl;
			getResponse(isCorrect);
			std::cout << std::endl;
		}
		
		//set correct answer back to 0
		correctAnswer = 0;
		break;

		//case 3: multiplication
	case 3:

		//asks user an multiplication question
		std::cout << "How much is " << randomInt1 << " * " << randomInt2 << "?" << std::endl;

		//correct answer is calculated for user comparison
		correctAnswer = randomInt1 * randomInt2;

		//looks for user input
		std::cout << "Answer: ";
		std::cin >> answer;

		//data type validation
		while (!std::cin) {
			std::cout << std::endl;
			std::cout << "Invalid data type, please enter an integer answer: ";
			
			//repair the instream
			std::cin.clear();
			
			//clear the buffer
			std::cin.ignore();
			std::cin >> answer;

		}

		//conditional if statement to check if user input is the correct answer
		if (answer != correctAnswer) {
			
			//while the user continues to input wrong answer, loop through
			while (answer != correctAnswer) {
				
				//set isCorrect to false in order to get an incorrect response from getResponse
				isCorrect = false;
				std::cout << std::endl;
				getResponse(isCorrect);
				
				//re-asks user same question they got wrong orignally
				std::cout << "How much is " << randomInt1 << " * " << randomInt2 << "?" << std::endl << "New answer : ";
				std::cin >> answer;


				//data type validation
				while (!std::cin) {
					std::cout << "Invalid data type, please enter an integer answer: ";
				
					//repair the instream
					std::cin.clear();
				
					//clear the buffer
					std::cin.ignore();
					std::cin >> answer;
					std::cout << std::endl;

				}
				
				//if user inputs correct answer, set isCorrect to true and get new output response reflecting a correct answer
				if (answer == correctAnswer) {
					isCorrect = true;
					std::cout << std::endl;
					getResponse(isCorrect);
					std::cout << std::endl;

				}

			}
			//set correctAnswer to 0 in order to allow a new question without correctAnswer holding a previous value
			correctAnswer = 0;
		
			//since user got the answer wrong at one point in current question, decrement numCorrect (defaulted at 10) in order to keep track of user passing or not 
			numCorrect--;
		}
		//if user gets answer right on first try, output a correct response and out an end line
		else
		{
			std::cout << std::endl;
			getResponse(isCorrect);
			std::cout << std::endl;
		}
		
		//set correct answer back to 0
		correctAnswer = 0;
		break;



		//case 4: division
	case 4:

		//to avoid dividing by 0, randomInt2 will be re-initialized as a non-zero number
		while (randomInt2 == 0) {
			randomInt2 = { rand() % ((int)pow(10,difficulty) - 1 + 1 - (int)pow(10,difficulty - 1)) + (int)pow(10,difficulty - 1) };
		}

		//used to ensure division will be even without any remainders
		while (randomInt1 % randomInt2 != 0) {
			randomInt1 = { rand() % ((int)pow(10,difficulty) - 1 + 1 - (int)pow(10,difficulty - 1)) + (int)pow(10,difficulty - 1) };
			randomInt2 = { rand() % ((int)pow(10,difficulty) - 1 + 1 - (int)pow(10,difficulty - 1)) + (int)pow(10,difficulty - 1) };
			correctAnswer = randomInt1 / randomInt2;
		}

		//correct answer is calculated for user comparison
		correctAnswer = randomInt1 / randomInt2;

		//asks user an division question
		std::cout << "How much is " << randomInt1 << " / " << randomInt2 << "?" << std::endl;

		//looks for user input
		std::cout << "Answer: ";
		std::cin >> answer;

		//data type validation
		while (!std::cin) {
			std::cout << std::endl;
			std::cout << "Invalid data type, please enter an integer answer: ";
		
			//repair the instream
			std::cin.clear();
		
			//clear the buffer
			std::cin.ignore();
			std::cin >> answer;

		}

		//conditional if statement to check if user input is the correct answer
		if (answer != correctAnswer) {
		
			//while the user continues to input wrong answer, loop through
			while (answer != correctAnswer) {
			
				//set isCorrect to false in order to get an incorrect response from getResponse
				isCorrect = false;
				std::cout << std::endl;
				getResponse(isCorrect);
			
				//re-asks user same question they got wrong orignally
				std::cout << "How much is " << randomInt1 << " / " << randomInt2 << "?" << std::endl << "New answer : ";
				std::cin >> answer;


				//data type validation
				while (!std::cin) {
					std::cout << "Invalid data type, please enter an integer answer: ";
				
					//repair the instream
					std::cin.clear();
				
					//clear the buffer
					std::cin.ignore();
					std::cin >> answer;
					std::cout << std::endl;

				}
			
				//if user inputs correct answer, set isCorrect to true and get new output response reflecting a correct answer
				if (answer == correctAnswer) {
					isCorrect = true;
					std::cout << std::endl;
					getResponse(isCorrect);
					std::cout << std::endl;

				}

			}
			//set correctAnswer to 0 in order to allow a new question without correctAnswer holding a previous value
			correctAnswer = 0;
			
			//since user got the answer wrong at one point in current question, decrement numCorrect (defaulted at 10) in order to keep track of user passing or not 
			numCorrect--;
		}
		//if user gets answer right on first try, output a correct response and out an end line
		else
		{
			std::cout << std::endl;
			getResponse(isCorrect);
			std::cout << std::endl;
		}
		
		//set correct answer back to 0
		correctAnswer = 0;
		break;


	}
}
