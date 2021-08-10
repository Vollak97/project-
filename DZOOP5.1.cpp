#include <iostream>

using namespace std;
//----------------------------------------------------------------------№1 Задание---------------------------------------------------------------------------
template <class T>
class Pair1
{
private:
	T m_a;
	T m_b;

public:
	Pair1(const T& a, const T& b)
		: m_a(a), m_b(b)
	{}

	T& first() { return m_a; }
	const T& first() const { return m_a; }

	T& second() { return m_b; }
	const T& second() const { return m_b; }
};

int main()
{
	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
//----------------------------------------------------------------------№1 Задание---------------------------------------------------------------------------
//----------------------------------------------------------------------№2 Задание---------------------------------------------------------------------------
template <class T, class S>
class Pair
{
private:
	T m_a;
	S m_b;

public:
	Pair(const T& a, const S& b)
		: m_a(a), m_b(b)
	{}

	T& first() { return m_a; }
	const T& first() const { return m_a; }

	S& second() { return m_b; }
	const S& second() const{ return m_b; }
};

int main()
{
	Pair<int, double> p1(6, 7.8);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(3.4, 5);
	cout << "Pair: " << p2.first() << ' ' << p1.second() << '\n';

	return 0;
}
//----------------------------------------------------------------------№2 Задание---------------------------------------------------------------------------
//----------------------------------------------------------------------№3 Задание---------------------------------------------------------------------------
template <class T, class S>
class Pair
{
private:
	T m_a;
	S m_b;

public:
	Pair(const T& a, const S& b)
		: m_a(a), m_b(b)
	{}

	T& first() { return m_a; }
	const T& first() const { return m_a; }

	S& second() { return m_b; }
	const S& second const{ return m_b; }
};

template <class S>
class StringValuePair : public Pair<string, S>
{
public:
	StringValuePair(const string& key, const S& value)
		:Pair<string, S>(key, value)
	{}
};

int main()
{
	StringValuePair<int> svp("Amazing", 7);

	cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
//----------------------------------------------------------------------№3 Задание---------------------------------------------------------------------------
//----------------------------------------------------------------------№4 Задание---------------------------------------------------------------------------
//GenericPlayer
//Класс Hand присылал в домашнем задании к 4 Вебинару. 

class GenericPlayer : public Hand
{
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
public:
	GenericPlayer(const string& name = " ");

	virtual ~GenericPlayer();
	//Показывает хочет ли игрок взять еще карты
	virtual bool IsHitting() const = 0;
	//Если игрок имеет перебор возвращает значение сумму очков больше 21
	bool IsBusted() const;
	//Анонсирует что у игрока перебор
	void Bust() const;
protected:
	string m_Name;
};
GenericPlayer::GenericPlayer(const string& name) :
	m_Name(name)
{}
GenericPlayer::~GenericPlayer()
{}
bool GenericPlayer::IsBusted() const
{
	return (GetTotal() > 21);
}
void GenericPlayer::Bust() const
{
	cout << m_Name << "busts.\n";
}
//----------------------------------------------------------------------№4 Задание---------------------------------------------------------------------------