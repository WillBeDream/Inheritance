// department.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

#define human_take_parameters const std::string& last_name, const std::string& first_name, unsigned int age
#define human_give_parameters last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;

public:
	const std::string& get_last_name()const
	{
		return last_name;
	}

	const std::string& get_first_name()const
	{
		return first_name;
	}

	unsigned int get_age()const
	{
		return age;
	}

	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}

	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}

	void set_age(unsigned int age)
	{
		this->age = age;
	}

	Human(human_take_parameters)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "Destruction\t" << this << endl;
	}
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет" << endl;
	}

};

#define employee_take_parameters const std::string& position
#define employee_give_parameters position

class Employee :public Human
{
	std::string position;

public:
	const std::string& get_position()const
	{
		return position;
	}
	void set_position(const std::string& position)
	{
		this->position = position;
	}
	virtual double get_salary()const=0
	{

	}
	Employee(human_take_parameters, employee_take_parameters):Human(human_give_parameters)
	{
		set_position(position);
		cout << "EConstructor:\t" << this << endl;
	}
	~Employee()
	{
		cout << "EDestructor:\t" << this << endl;
	}

	void print()const
	{
		Human::print();
		cout << position << endl;
	}
};

#define permanent_employee_take_parameters double salary
#define permanent_employee_give_parameters salary

class PermanentEmployee: public Employee
{
	double salary;
public:
	double get_salary()const
	{
		return salary;
	}
	void set_salary(double salary)
	{
		this->salary = salary;
	}
	PermanentEmployee
	(	human_take_parameters,
		employee_take_parameters, 
		permanent_employee_take_parameters
	):Employee(human_give_parameters, employee_give_parameters)
	{
		set_salary(salary);
		cout << "PEConstructor:\t" << this << endl;
	}
	~PermanentEmployee()
	{
		cout << "PEDestructor:\t" << this << endl;
	}
	void print()const
	{
		Employee::print();
		cout << salary << endl;
	}
};

#define hourly_employee_take_parameters double rate, int hours
#define hourly_employee_give_parameters rate, hours

class HourlyEmployee :public Employee
{
	double rate;
	int hours;
public:
	double get_rate()const
	{
		return rate;
	}
	int get_hours()const
	{
		return hours;
	}
	double get_salary()const
	{
		return rate * hours;
	}
	void set_rate(double rate)
	{
		this->rate = rate;
	}
	void set_hours(int hours)
	{
		this->hours = hours;
	}
	HourlyEmployee
	(
		human_take_parameters,
		employee_take_parameters,
		hourly_employee_take_parameters
	):Employee(human_give_parameters, employee_give_parameters)
	{
		set_rate(rate);
		set_hours(hours);
		cout << "HEConstructor:\t" << this << endl;
	}
	~HourlyEmployee()
	{
		cout << "HEDestructor:\t" << this << endl;
	}
	void print()const
	{
		Employee::print();
		cout << "тариф: " << rate << "отработано: " << hours<<"итого:"<<get_salary() << endl;
	}
};

int main()
{
    setlocale(LC_ALL, "");
	Employee* department[] =
	{
		new PermanentEmployee("Rosenberg","Ken",30, "Lawyer", 2000),
		new PermanentEmployee("Diaz", "Ricardo", 50, "Boss", 50000),
		new HourlyEmployee("Vercetty", "Thomas", 30, "Security", 500, 8)
	};

	double total_salary = 0;
	for (size_t i = 0; i < sizeof(department)/sizeof(Employee*); i++)
	{
		department[i]->print();
		total_salary += department[i]->get_salary();
		cout << "\n--------------------------------------\n";
	}

	std::ofstream file("myfile1.txt");
	if (file.is_open())
	
	if (file.is_open())
	{
		for (size_t i = 0; i < sizeof(department) / sizeof(Employee*); i++)
		{
			file << department[i]->get_salary()<<endl;
		}
		
	}

	file.close();

	cout << total_salary << endl;
	for (size_t i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		delete department[i];
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
