#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
class Blackjack
{
private:
	std::vector<std::pair<char, char>> _deck;
	std::vector<std::pair<char, char>> _playerHand;
	std::vector<std::pair<char, char>> _dealerHand;

	void NewDeck(int x = 2);
	void RandomizeDeck();
	void ShowTable();
	void PrintHand(std::vector<std::pair<char, char>> hand);
	std::pair<char, char> GetCard();
	short GetSum(std::vector<std::pair<char, char>> hand);
	short isWin();
public:
	Blackjack();
	void StartNewGame();
};

