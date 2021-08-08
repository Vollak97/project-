#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class ArrayInt
{
private:
	int m_length;
	int* m_data;

public:
	ArrayInt() : m_length(), m_data(nullptr)
	{}

	ArrayInt(int length) : m_length(length)
			
	{
	   assert(length >= 0);

	   if (length > 0)
		  m_data = new int[length];
	   else
		  m_data = nullptr;
	}

		void erase()
	{
		delete[] m_data;

		m_data = nullptr;
		m_length = 0;
	}
	int getLength() { return m_length; }

	int& operator[](int index)
		
	{
	   assert(index >= 0 && index < m_length);
	   return m_data[index];
	}

		void resize(int newLength)
		
	{
	   if (newLength == m_length)
		  return;

	   if (newLength <= 0)
	   {
		  erase();
		  return;
	   }

	   int* data = new int[newLength];

	   if (m_length > 0)
	   {
		  int elementsToCopy = (newLength > m_length) ? m_length : newLength;

		  for (int index = 0; index < elementsToCopy; ++index)
			 data[index] = m_data[index];
	   }

	   delete[] m_data;

	   m_data = data;
	   m_length = newLength;
	}

		void insertBefore(int value, int index)
		
	{
	   assert(index >= 0 && index <= m_length);
	   int* data = new int[m_length + 1];
	   for (int i = 0; i < index; ++i)
		  data[i] = m_data[i];
	   data[index] = value;
	   for (int i = index; i < m_length; ++i)
		  data[i + 1] = m_data[i];
	   delete[] m_data;
	   m_data = data;
	   ++m_length;
	}

		void push_back(int value)
	{
		insertBefore(value, m_length);
	}

	void pop_back()
	{
		assert(m_length == 0);
		int* data = new int(m_length - 1);
		for (int i = 0; i < m_length - 1; ++i)
		{
			data[i] = m_data[i];
		}
		delete[] m_data;
		m_data = data;
		--m_length;
	}

	void pop_front()
	{
		int* data = new int[m_length - 1];
		for (int i = 0; i < m_length - 1; ++i)
		{
			data[i] = m_data[i + 1];
		}
		delete[] m_data;
		m_data = data;
		--m_length;
	}

	void print()
	{
		for (int i = 0; i < m_length; ++i)
		{
			cout << m_data[i] << " ";
		}
	}

	void BubbleSort()
	

	{
	   int temp;
	   for (int i = 0; i < m_length - 1; ++i)
	   {
		  for (int j = 0; j < m_length - 1; ++j)
		  {
			 if (m_data[j + 1] < m_data[j])
			 {
				temp = m_data[j + 1];
				m_data[j + 1] = m_data[j];
				m_data[j] = temp;
			 }
		  }
	   }
	}

		~ArrayInt()
	{
		delete[] m_data;
	}
};

//------------------------------------------------------------------------------------------№3 Задание----------------------------------------------------------------------
//Класс Карты
class Card
{
public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

	friend ostream& operator<<(ostream& os, const Card& aCard);

	Card(rank r = ACE, suit s = SPADES, bool ifu = true);

	int GetValue() const;
	//Переворачивает карту. Лежит лицом вверх

	void Flip();
	//Переворчивается лицом вниз и наоборот

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};
Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}
int Card::GetValue() const
{
	//Если карта перевернута вниз, ее значение равно 0
	int value = 0;

	if (m_IsFaceUp)
	{
		//Значение - это число, указанное на карте
		value = m_Rank;
		//Значение равно 10 для открытых карт
		if (value > 10)
		{
			value = 10;
		}
	}
	return value;
}
void Card::Flip()
{
	m_IsFaceUp = !(m_IsFaceUp);
}

//Класс Рука
class Hand
{
public:
	Hand();
	virtual ~Hand();

	void Add(Card* pCard);
	//Добавляет карту в руку 
	void Clear();
	//Очищает руку от карт
	int GetTotal()const;

protected:
	vector<Card*> m_Cards;
};
Hand::Hand()
{
	m_Cards.reserve(7);
}
Hand::~Hand()
{
	Clear();
}
void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}
void Hand::Clear()
{
	vector<Card*>::iterator iter = m_Cards.begin();

	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}
	m_Cards.clear();
	//Очистка вектора указателей
}
int Hand::GetTotal()const
{
	if (m_Cards.empty())
		//Если карт в руке нет, возрвращает 0
	{
		return 0;
	}
	if (m_Cards[0]->GetValue() == 0)
		//Если первая карта имеет значение 0, то она лежит рубашкой вверх и возвращает 0
	{
		return 0;
	}
	int total = 0;

	vector<Card*>::const_iterator iter;

	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		total += (*iter)->GetValue();
	}

	//Определяет есть ли в руке туз
	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		if ((*iter)->GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}
	//Если в руке есть туз и сумма очков маленькая, туз дает 11 очков
	if (containsAce && total <= 11)
	{
		total += 10;
	}
	return total;
}
//------------------------------------------------------------------------------------------№3 Задание----------------------------------------------------------------------