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
	std::cout << "Blackjack\t\t\t��� ������: \n";
	std::cout << "1)������ ����\n2)��������� ������\n0)�����\n\n������� ��� �����: ";
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