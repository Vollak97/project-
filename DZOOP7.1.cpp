#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

//----------------------------------------------------------------------№1-2 Задание---------------------------------------------------------------------------

class Date {
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int const& day, int const& month, int const& year) : m_day(day), m_month(month), m_year(year) {}

	~Date() {}

	int getDay() {
		return m_day;
	}
	int getMonth() {
		return m_month;
	}
	int getYear() {
		return m_year;
	}

	friend ostream& operator<< (ostream& out, const Date& date);
};

ostream& operator<< (ostream& out, const Date& date) {
	out << "Date : " << date.m_day << "." << date.m_month << "." << date.m_year;
	return out;
}

class today_ptr {
	Date* m_ptr;
public:
	today_ptr(Date* ptr = nullptr) : m_ptr(ptr) {}
	~today_ptr() {
		delete m_ptr;
	}

	Date& operator*() const { return *m_ptr; }
	Date* operator->() const { return m_ptr; }
	today_ptr& operator=(today_ptr& t_ptr) {
		if (this == &t_ptr) {
			return *this;
		}
		delete m_ptr;
		m_ptr = t_ptr.m_ptr;
		t_ptr.m_ptr = nullptr;
		return *this;
	}
	bool Null() const {
		return m_ptr == nullptr;
	}
};

today_ptr& Compare(today_ptr& ptr1, today_ptr& ptr2) {
	if (ptr1->getYear() > ptr2->getYear()) {
		return ptr1;
	}
	else if (ptr1->getYear() < ptr2->getYear()) {
		return ptr2;
	}
	else {
		if (ptr1->getMonth() > ptr2->getMonth()) {
			return ptr1;
		}
		else if (ptr1->getMonth() < ptr2->getMonth()) {
			return ptr2;
		}
		else {
			if (ptr1->getDay() > ptr2->getDay()) {
				return ptr1;
			}
			else if (ptr1->getDay() < ptr2->getDay()) {
				return ptr2;
			}
			else {
				std::cout << "dates are equal";
				return ptr1;
			}
		}
	}
}

void Obmen(today_ptr& today, today_ptr& date) {
	today_ptr ptr;
	ptr = today;
	today = date;
	date = ptr;
}

int main() {
	today_ptr today = new Date(17, 8, 2021);
	today_ptr date;
	cout << today->getDay() << "." << today->getMonth() << "." << today->getYear() << endl;
	cout << *today << endl;
	date = today;
	cout << "today null? -> " << today.Null() << endl;
	cout << "date null? -> " << today.Null() << endl;
	today_ptr date1 = new Date(4, 11, 2015);
	today_ptr date2 = new Date(15, 9, 2019);
	cout << *Compare(date1, date2) << endl;
	Obmen(date1, date2);
	cout << *date1 << endl;
	cout << *date2 << endl;

	return 0;
}
//----------------------------------------------------------------------№1-2 Задание---------------------------------------------------------------------------


//----------------------------------------------------------------------№3 Задание---------------------------------------------------------------------------
//Класс Deck/Колода
class Deck : public Hand
{
public:
	Deck();

	virtual ~Deck();
	//Создает стандартную колоду из 52 карт
	void Populate();
	//Тасует Карты
	void Shuffle();
	//Выдает одну карту в руку
	void Deal(Hand& aHand);
	//Выдает дополнительные карты игроку
	void AdditionalCards(GenericPlayer& aGenericPlayer);
};
Deck::Deck()
{
	m_Cards.reserve(52);
	Populate();
}
Deck::~Deck()
{}
void Deck::Populate()
{
	Clear();
	//Формирует стандартную колоду
	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
	{
		for (int r = Card::ACE; r <= Card::KING; ++r)
		{
			Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
		}
	}
}
void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}
void Deck::Deal(Hand& aHand)
{
	if (!m_Cards.empty())
	{
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
	else
	{
		cout << "Out of cards. Unable to deal.";
	}
}
void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	cout << endl;

	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
	{
		Deal(aGenericPlayer);
		cout << aGenericPlayer << endl;
		if (aGenericPlayer.IsBusted())
		{
			aGenericPlayer.Bust();
		}
	};
};
//----------------------------------------------------------------------№3 Задание---------------------------------------------------------------------------
//----------------------------------------------------------------------№4 Задание---------------------------------------------------------------------------
//Класс Игра
class Game
{
public:
	Game(const vector<string>& names);

	~Game();

	void Play();

private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
};
Game::Game(const vector<string>& names)
{
	vector<string>::const_iterator pName;

	for (pName = names.begin(); pName != names.end(); ++pName)
	{
		m_Players.push_back(Player(*pName));
	}

	srand(static_cast<unsigned int>(time(0)));
	m_Deck.Populate();
	m_Deck.Shuffle();
}
Game::~Game()
{}
void Game::Play()
{
	vector<Player>::iterator pPlayer;

	for (int i = 0; i < 2; ++i)
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_Deck.Deal(*pPlayer);
		}
		m_Deck.Deal(m_House);
	}
	m_House.FlipFirstCard();

	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		cout << *pPlayer << endl;
	}
	cout << m_House << endl;

	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		m_Deck.AdditionalCards(*pPlayer);
	}

	m_House.FlipFirstCard();

	cout << endl << m_House;

	m_Deck.AdditionalCards(m_House);

	if (m_House.IsBusted())
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->IsBusted()))
			{
				pPlayer->Win();
			}
		}
	}
	else
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->IsBusted()))
			{
				if (pPlayer->GetTotal() > m_House.GetTotal())
				{
					pPlayer->Win();
				}
				else if (pPlayer->GetTotal() > m_House.GetTotal())
				{
					pPlayer->Lose();
				}
				else
				{
					pPlayer->Push();
				}
			}
		}
	}
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		pPlayer->Clear();
	}
	m_House.Clear();
}
//----------------------------------------------------------------------№4 Задание---------------------------------------------------------------------------
//----------------------------------------------------------------------№5 Задание---------------------------------------------------------------------------
//Функция Main
int main()
{
	cout << "\t\tWelcome to BlackJack!\n\n";

	int numPlayers = 0;

	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "How many players? ( 1 - 7 ): ";

		cin >> numPlayers;
	}
	vector<string> names;
	string name;

	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Enter player name: ";

		cin >> name;
		names.push_back(name);
	}
	cout << endl;

	//Игровой цикл
	Game aGame(names);

	char again = 'y';

	while (again != 'n' && again != 'N')
	{
		aGame.Play();

		cout << "\nDo you want to play again? (Y/N): ";

		cin >> again;
	}
	return 0;
}
//----------------------------------------------------------------------№5 Задание---------------------------------------------------------------------------