#include "stdafx.h"
#include "FBullCowGame.h"

using int32 = int;

//constructor
FBullCowGame::FBullCowGame()
{
	constexpr int32 MAX_WORD_LENTH = 5;
	Reset(MAX_WORD_LENTH);
}

void FBullCowGame::Reset(int32 WorkLenth)
{
	//throw away MAX_WORD_LENTH for now.
	constexpr int32 CURRENT_TRY = 1;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = CURRENT_TRY;

	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	return;
}

int32 FBullCowGame::GetMaxTries () const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString) 
{
	MyCurrentTry++;
	return false;
}

//count Bulls and Cows and increate the try number: #assuming valid guess
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//increment the turn number
	MyCurrentTry++;

	//setup te return variable
	BullCowCount BullCowCount;


	//loop through all letters in the guess
	int32 HiddenWordLenth = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLenth; i++)
	{
		//compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLenth; j++)
		{
			//if they match
				//if they're in the same place
					//increment bulls 
				//else
					//increment cows 
		}
	}

	


	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString)
{
	return false;
}
