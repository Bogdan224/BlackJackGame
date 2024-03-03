#include "Blackjack.h"
Blackjack::Blackjack() {

}

void Blackjack::NewDeck(int x){
	_deck.clear();
	char c1[4] = { 'H','D','S','C'};
	char numbers[13] = { '2','3','4','5','6','7','8','9','0','J','Q','K','A'};
	for (size_t i = 0; i < x; i++)
	{
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 13; j++)
			{
				_deck.push_back(std::pair<char, char>(numbers[j], c1[i]));
			}
		}
	}
}

void Blackjack::RandomizeDeck() {
	srand(time(NULL));
	for (size_t i = 0; i < 200 * (_deck.size()/52); i++)
	{
		int x = rand() % _deck.size();
		int y = rand() % _deck.size();
		std::pair<char, char> tmp = _deck[x];
		_deck[x] = _deck[y];
		_deck[y] = tmp;
	}
}

std::pair<char, char> Blackjack::GetCard() {
	std::pair<char, char> res = this->_deck[0];
	_deck.erase(_deck.begin());
	return res;
}

void Blackjack::PrintHand(std::vector<std::pair<char, char>> hand) {
	for (size_t i = 0; i < hand.size(); i++)
	{
		if(hand[i].first != '0')
			std::cout << hand[i].first;
		else
			std::cout << 10;
		std::cout << hand[i].second << " ";
	}
}

short Blackjack::GetSum(std::vector<std::pair<char, char>> hand) {
	short sum = 0;
	std::vector<char> ace;
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i].first > 48 && hand[i].first <= 57) {
			sum += hand[i].first - '0';
		}
		else if (hand[i].first == 48 || hand[i].first != 'A') {
			sum += 10;
		}
		else {
			ace.push_back(hand[i].first);
		}
	}
	for (size_t i = 0; i < ace.size(); i++)
	{
		if (sum + 11 <= 21) {
			sum += 11;
		}
		else {
			sum++;
		}
	}
	return sum;
}

short Blackjack::isWin() {
	if (GetSum(_dealerHand) > 21 && GetSum(_playerHand) > 21)
		return 0;
	if (GetSum(_dealerHand) > 21 && GetSum(_playerHand) <= 21)
		return 1;
	if (GetSum(_dealerHand) <= 21 && GetSum(_playerHand) > 21)
		return -1;
	if (GetSum(_dealerHand) > GetSum(_playerHand))
		return -1;
	if (GetSum(_dealerHand) == GetSum(_playerHand))
		return 0;
	else
		return 1;
}

void Blackjack::StartNewGame()
{
	NewDeck();
	RandomizeDeck();
	this->_dealerHand.push_back(GetCard());
	this->_playerHand.push_back(GetCard());
	this->_dealerHand.push_back(GetCard());
	this->_playerHand.push_back(GetCard());
	int choise;
	while (GetSum(_playerHand) <= 21)
	{
		ShowTable();
		std::cout << "1)Взять карту\n2)Вскрыть руку\nВаш выбор: ";
		std::cin >> choise;

		if (choise == 1) {
			_playerHand.push_back(GetCard());
		}
		else if (choise == 2) {
			break;
		}
		else {
			continue;
		}
	} 

	while (GetSum(_dealerHand) < 18 && GetSum(_playerHand) <= 21) {
		this->_dealerHand.push_back(GetCard());
		ShowTable();
	}
	ShowTable();

	if (isWin() == 1) {
		std::cout << "\nВы победили!";
	}
	else if (isWin() == 0) {
		std::cout << "\nНичья!";
	}
	else if (isWin() == -1) {
		std::cout << "\nВы проиграли!";
	}
	return;
}

void Blackjack::ShowTable() {
	system("cls");
	std::cout << "Рука дилера: ";
	PrintHand(_dealerHand);
	std::cout << " " << GetSum(_dealerHand) << "\n";
	std::cout << "Ваша рука: ";
	PrintHand(_playerHand);
	std::cout << " " << GetSum(_playerHand) << "\n\n";
}
