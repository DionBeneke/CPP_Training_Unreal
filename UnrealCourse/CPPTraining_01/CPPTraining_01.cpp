/*
	This is the console executable, that makes use of the BullCow class
	This acts as the view in a MVC patter and is responsable for all 
	user inteaction. For game logic see the FBullCOwcame.cpp

*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "CCPTraining_01.h"
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FText Guess = "";
FBullCowGame BCGame; //instanciate a instance of a new game

int main()
{
	bool playAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		//TODO add a game summary

		playAgain = AskToPlayAgain();
	} while (playAgain);
	
	return 0;
}

void PlayGame()
{
	BCGame.Reset(5);

	int32 maxTries = BCGame.GetMaxTries();

	//loop for the number of turns
	//TODO change from for to while loop once we are validating tries
	for (int32 i = 1; i <= maxTries; i++) {
		GetGuess(); //TODO make loop checking valid

		//submit valid guess to the game
		BullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;


		ShowGuess();
		BCGame.CheckGuessValidity("placeholder");

		//provide a method for counting bulls and cows and incrementing turn number
	}

	//TODO Summarise game
}



void PrintIntro()
{
	//introduce the game
	constexpr int32 WORD_LENTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENTH;
	std::cout << " letter isogram I'm thinking off" << std::endl;
	std::cout << std::endl;
	return;
}

void GetGuess()
{
	//get the guess from the player
	std::cout << "Try " << BCGame.GetCurrentTry();
	std::cout << ": Enter your guess" << std::endl;
	std::getline(std::cin, Guess);
	return;
}

void ShowGuess() {
	//repeat the guess out to the player
	std::cout << "Your guess was: " << Guess;
	std::cout << std::endl;
	return;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play agian? (y/n) \n";
	FText Response = "";
	std::getline(std::cin, Response);

	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}

