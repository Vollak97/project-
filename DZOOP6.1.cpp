#include <iostream>
#include <string>


using namespace std;
//----------------------------------------------------------------------№1 Задание---------------------------------------------------------------------------
int main()
{
	int i;
	cout << "Enter number : ";
	while (!(cin >> i))
	{
		cout << "IDIOT !! Try again !\n";
		cin.clear(); 
		cin.ignore(9999, '\n');
		cin.sync();//Удаляем данные из буффера
		cout << "Enter number : ";
	}
	return 0;
}
//----------------------------------------------------------------------№1 Задание---------------------------------------------------------------------------
//----------------------------------------------------------------------№2 Задание---------------------------------------------------------------------------
int main(void)
{
	cout << "Hello Jonhy";
	sleep(2);
	cout << endl;

	return 0;
}
//----------------------------------------------------------------------№2 Задание---------------------------------------------------------------------------
//----------------------------------------------------------------------№3 Задание---------------------------------------------------------------------------
//Класс GenericPlayer присылал в домашнем задании к 5 Вебинару. 
//Класс Игрок/Player наследует от Класс GenericPlayer
class Player : public GenericPlayer
{
public:
	Player(const string& name = " ");

	virtual ~Player();

	virtual bool IsHitting() const;

	void Win() const;

	void Lose() const;

	void Push() const;
};
Player::Player(const string& name) :
	GenericPlayer(name)
{}
Player::~Player()
{}
bool Player::IsHitting()const
{
	cout << m_Name << ". Do you want a hit? (Y/N): ";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}
void Player::Win() const
{
	cout << m_Name << "Wins.\n";
}
void Player::Lose() const
{
	cout << m_Name << "Loses. \n";
}
void Player::Push() const
{
	cout << m_Name << "Pushes. \n";
}
//----------------------------------------------------------------------№3 Задание---------------------------------------------------------------------------
//----------------------------------------------------------------------№4 Задание---------------------------------------------------------------------------
//Класс House/Дилер
class House : public GenericPlayer
{
public:
	House(const string& name = "House");

	virtual ~House();

	virtual bool IsHitting() const;

	void FlipFirstCard();
};
House::House(const string& name) :
	GenericPlayer(name)
{}
House::~House()
{}
bool House::IsHitting()const
{
	return (GetTotal() <= 16);
}
void House::FlipFirstCard()
{
	if (!(m_Cards.empty()))
	{
		m_Cards[0]->Flip();
	}
	else
	{
		cout << "No card to flip!\n";
	}
}
//----------------------------------------------------------------------№4 Задание---------------------------------------------------------------------------
//----------------------------------------------------------------------№5 Задание---------------------------------------------------------------------------
//Перегрузка операторов 
ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

ostream& operator<<(ostream& os, const Card& aCard)
{
	const string RANKS[] = { "0", "A", "2","3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	const string SUITS[] = { "c", "d", "h", "s" };

	if (aCard.m_IsFaceUp)
	{
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
	}
	else
	{
		os << "XX";
	}
	return os;
}
//----------------------------------------------------------------------№5 Задание---------------------------------------------------------------------------