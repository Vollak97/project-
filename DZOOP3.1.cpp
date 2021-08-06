#include <iostream>
#include <string>

using namespace std;

class Figure
{
public:

	Figure()
	{}
    virtual void area() = 0;

	virtual ~Figure()
	{}
};

class Parallelogram : public Figure
{
protected:
    int base; //основание
    int height; //высота
public:

    Parallelogram(int value_base, int value_height) :base(value_base), height(value_height) {}
    void area() override
    {
        cout << "The parallelogram area is " << base * height << endl;
    }
};

class Circle : public Figure
{
    double radius;
    double P;
public:
    Circle(double value_radius) : radius(value_radius) {}
    void area() override
    {
        cout << "The area of the circle is " << 3.1415 * (radius * radius) << endl;
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(int value_base, int value_height) : Parallelogram(value_base, value_height) {}
    void area() override
    {
        cout << "The area of the triangle is " << base * height << endl;
    }
};

class Square : public Parallelogram
{
public:

    Square(int value_base, int value_height) : Parallelogram(value_base, value_height) {}

    void area() override
    {
        cout << "The square area is " << base * height << endl;
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(int value_base, int value_height) : Parallelogram(value_base, value_height) {}
    void area() override
    {
        cout << "The area of the rhombus is " << base * height << endl;
    }
};


class Car 
{
protected:
	string m_company;
	string m_model;

public:
	Car() {}

	Car(string company, string model) : m_company(company), m_model(model) 
	{}
};

class PassengerCar : virtual public Car 
{
public:
	PassengerCar() {}

	PassengerCar(string company, string model) : Car(company, model) 
	{}

	void print() 
	{
		cout << "Passenger car info: \n Company: " << m_company << "\n Model: " << m_model << std::endl;
	}
};

class Bus : public virtual Car
{
public:
	Bus() {}

	Bus(string company, string model) : Car(company, model) 
	{}

	void print() 
	{
		cout << "Bus info: \n Company: " << m_company << "\n Model: " << m_model << std::endl;
	}
};

class Minivan : public PassengerCar, public Bus 
{
public:
	Minivan(string company, string model) : PassengerCar::Car(company, model)
	{}

	void print() 
	{
		cout << "Minivan info: \n Company: " << m_company << "\n Model: " << m_model << std::endl;
	}
};

class Fraction 
{
	int m_num;
	int m_denom;

public:
	Fraction(int num, int denom) 
	{
		if (m_denom == 0)
		{
			throw std::runtime_error("The denominator cannot be 0");
			this->m_num = num;
			this->m_denom = denom;
		};
	}

	int getNum(int num) const 
	{
		return m_num;
	}

	int getDenom(int denom) const
	{
		return m_denom;
	}

	bool operator==(const Fraction& other)
	{
		return this->m_num == other.m_num && this->m_denom == other.m_denom;
	}

	bool operator !=(const Fraction& other)
	{
		return this->m_num != other.m_num && this->m_denom != other.m_denom;
	}

	bool operator <(const Fraction& other) 
	{
		if (this->m_num >= other.m_num && this->m_denom >= other.m_denom) 
		{
			return false;
		}
		else 
		{
			return true;
		}
	}

	bool operator >(const Fraction& other)
	{
		if (this->m_num <= other.m_num && this->m_denom <= other.m_denom)
		{
			return false;
		}
		else 
		{
			return true;
		}
	}

	friend Fraction operator + (const Fraction& f1, const Fraction& f2)
	{
		return Fraction(f1.m_num * f2.m_denom + f2.m_num * f1.m_denom, f1.m_num * f2.m_num);
	}

	friend Fraction operator - (const Fraction& f1, const Fraction& f2)
	{
		return Fraction(f1.m_num * f2.m_denom - f2.m_num * f1.m_denom, f1.m_num * f2.m_num);
	}

	friend Fraction operator * (const Fraction& f1, const Fraction& f2)
	{
		return Fraction(f1.m_num * f2.m_num, f1.m_denom * f2.m_denom);
	}

	friend Fraction operator / (const Fraction& f1, const Fraction& f2) 
	{
		return Fraction(f1.m_num / f2.m_num, f1.m_denom * f2.m_denom);
	}
};

class Card 
{
protected:
	enum CardsValue 
	{
		two = 2,
		three = 3,
		four = 4,
		five = 5,
		six = 6,
		seven = 7,
		eight = 8,
		nine = 9,
		ten = 10,
		Jack = 11,
		Queen = 12,
		King = 13,
		Ace = 1
	};

	enum Suits 
	{
		Heart,
		Diamond,
		Club,
		Spade
	};

	bool cardPosition = true;

public:
	Card()
	{
	}

	bool Flip()
	{
		if (cardPosition)
		{
			return false;
		}
		else 
		{
			return true;
		}
	}

	int GetValue() 
	{
		return CardsValue();
	}

};

int main() 
{

	Parallelogram p(3, 5);
	p.area();

	Circle c(4);
	c.area();

	Rectangle r(5, 8);
	r.area();

	Square s(4, 4);
	s.area();

	Rhombus rom(4, 6);
	rom.area();

	cout << endl << endl;

	PassengerCar pas("Toyota", "Camry");

	Bus bus("Mersedes ", "Sprinter");

	Minivan mini("Toyota", "Hiace");

	pas.print();

	bus.print();

	mini.print();

	cout << endl << endl;

	Fraction g1(3, 7);

	Fraction g2(5, 12);

	bool result_1 = g1 == g2;

	bool result_2 = g1 != g2;

	bool result_3 = g1 < g2;

	bool result_4 = g1 > g2;

	Fraction f_sum = g1 + g2;

	Fraction f_sub = g1 - g2;

	Fraction f_pro = g1 * g2;

	Fraction f_res = g1 / g2;

	return 0;
}