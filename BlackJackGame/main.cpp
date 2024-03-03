#include<iostream>
#include<Windows.h>
#include "Blackjack.h"

void BeginGame() {
	system("cls");
	Blackjack game = Blackjack();
	game.StartNewGame();
	//game.PrintDeck();
	system("pause");
}

void TopUpBalance() {
	system("cls");
}

void Program() {
	system("cls");
	
	int choise;
	std::cout << "Blackjack\t\t\tВаш баланс: \n";
	std::cout << "1)Начать игру\n2)Пополнить баланс\n0)Выйти\n\nВведите ваш выбор: ";
	std::cin >> choise;
	switch (choise)
	{
	case 1:
		BeginGame();
		break;
	case 2:
		TopUpBalance();
		break;
	case 0:
		return;
	default:
		break;
	}
	return Program();
}

int main() {
	setlocale(LC_ALL, "RUS");
	Program();
	return 0;
}