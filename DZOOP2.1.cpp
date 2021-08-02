#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Person 
{
private:
	string m_name;
	int m_age;
	string m_gender;
	int m_weight;

public:
	Person() : m_name(""), m_age(0), m_gender(""), m_weight(0) 
	{

	}

	Person(string name, int age, string gender, int weight) 
	{
		this->m_name = name;
		this->m_age = age;
		this->m_gender = gender;
		this->m_weight = weight;
	}
	friend class Student;
};

class Student : public Person 
{
private:
	int m_year;
	int m_id;
	static int s_idGenerator;

public:
	Student() : m_year(0), m_id(0)
	{

	}

	Student(string name, int age, string gender, int weight, int year)


		: Person(name, age, gender, weight ,year)
	{
		s_idGenerator++;
		m_id = s_idGenerator;
	}
	static int getID() 
	{
		return s_idGenerator;
	}

	string getStudentInfo() 
	{
		ostringstream m_id;
		m_id << m_name << " " << m_age << " "
			<< m_gender << " " << m_weight << " " << m_year;
		return m_id.str();
	}
};

int Student::s_idGenerator = 0;

class Fruit 
{
public:
	string m_name;
	string m_color;

	Fruit() : m_name(""), m_color() 
	{

	}

	Fruit(string name, string color) 
	{
		m_name = name;
		m_color = color;
	}
};

class Apple : public Fruit 
{
public:
	Apple() 
	{

	}

	string getName() 
	{
		return "apple";
	}

	Apple(string color) 
	{
		m_color = color;
	}

	string getColor() {
		return m_color;
	}
};

class Banana : public Fruit 
{
public:
	string getName()
	{
		return "banana";
	}

	string getColor() 
	{
		return "yellow";
	}
};

class GrannySmith : public Apple {
public:
	GrannySmith() 
	{

	}

	string getName() 
	{
		return "Granny Smith apple";
	}

	string getColor()
	{
		return "green";
	}
};

int main() 
{
//====================================================№1 Задание==========================================
	int id;
	const int size = 4;
	Student stud;
	Student stud_list[size]
	{
			Student(" Arsen ",  24, " Male ", 78, 2021),
			Student(" Marat ", 28, " Male ", 88, 2020),
			Student(" Anna ", 24, " Female ", 60, 2021),
			Student(" Roman ", 35, "Male ", 80, 2021),
	};

	cout << "Number of students : " << stud.getID() << endl;
	cout << "Enter student ID(0-4) : ";
	cin >> id;
	cout << stud_list[id].getStudentInfo();

	cout << endl << endl;
//====================================================№2 Задание==========================================
	Apple a("red");
	Banana b;
	GrannySmith c;

	cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}


