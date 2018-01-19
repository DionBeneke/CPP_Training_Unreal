#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//all values initialized to 0
struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {

	//Public interface
public:
	FBullCowGame(); // constructor
	void Reset(int32 WorkLenth); //TODO make a more rich return value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString);
	
	BullCowCount SubmitGuess(FString);

	//private
private:
	int32 MyCurrentTry =1;
	int32 MyMaxTries = 5;
	bool IsIsogram(FString);
	FString MyHiddenWord;


};