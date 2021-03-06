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
	Human()
	{
		set_last_name("Ivan");
		set_first_name("Ivanov");
		set_age(18);
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
	virtual std::ostream& print(std::ostream& os)const
	{
		/*return os << last_name << " " << first_name << " " << age << " ???";*/
		os << std::left;
		os.width(10);
		os << last_name;
		os.width(10);
		os << first_name;
		os.width(3);
		os << age << " ???";
		return os;
	}
	virtual std::istream& input(std::istream& is)
	{
		std::string last_name;
		std::string first_name;
		unsigned int age;
		is >> last_name >> first_name >> age;
		set_first_name(first_name);
		set_last_name(last_name);
		set_age(age);
		return is;
	}
	virtual std::ofstream& print(std::ofstream& os)const
	{
		/*return os << last_name << " " << first_name << " " << age << " ???";*/
		os << std::left;
		os.width(10);
		os << last_name;
		os.width(10);
		os << first_name;
		os.width(3);
		os << age;
		return os;
	}
	virtual std::ifstream& scan(std::ifstream& is)
	{
		is >> last_name >> first_name >> age;
		return is;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}

std::ofstream& operator<<(std::ofstream& os, const Human& obj)
{
	return obj.print(os);
}

std::ifstream& operator>>(std::ifstream& is, Human& obj)
{
	return obj.scan(is);
}

std::istream& operator>>(std::istream& is, Human& obj)
{
	return obj.input(is);
}

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
	Employee():Human()
	{
		set_position("student");
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

	std::ostream& print(std::ostream& os)const
	{
		Human::print(os)<<" ";
		os.width(10);
		return os << position;
	}

	std::istream& input(std::istream& is)
	{
		Human::input(is);
		return is >> position;
	}

	std::ofstream& print(std::ofstream& os)const
	{
		Human::print(os) << " ";
		os.width(10);
		os << position;
		return os;
	}
	std::ifstream& scan(std::ifstream& is)
	{
		Human::scan(is);
		is >> position;
		return is;
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
	PermanentEmployee() :Employee()
	{
		set_salary(1000);
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
	std::ostream& print(std::ostream& os)const
	{
		Employee::print(os) << " ";
		return os << salary;
	}

	std::istream& input(std::istream& is)
	{
		Employee::input(is);
		return is >> salary;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Employee::print(os) << " ";
		os << salary;
		return os;
	}
	std::ifstream& scan(std::ifstream& is)
	{
		Employee::scan(is);
		is >> salary;
		return is;
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
	std::ostream& print(std::ostream& os)const
	{
		Employee::print(os)<<" ";

		os << "?????: ";
		os.width(5);
		os << std::right;
		os << rate;
		os << " ??????????: ";
		os.width(3);
		os << hours << " ?????:" << get_salary();
		return os;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Employee::print(os) << " ";
		os.width(10);
		os << std::right;
		os << rate;
		os.width(3);
		os << hours;
		return os;
	}
	std::ifstream& scan(std::ifstream& is)
	{
		Employee::scan(is);
		is >> rate >> hours;
		return is;
	}
};

Employee* EmployeeFactory(std::string& type)
{
	if (type.find("PermanentEmployee") != std::string::npos)return new PermanentEmployee("", "", 0, "", 0);
	if (type.find("HourlyEmployee") != std::string::npos)return new HourlyEmployee("", "", 0, "", 0, 0);
}

//#define SAVE_TO_FILE

int main()
{
	setlocale(LC_ALL, "");
#ifdef SAVE_TO_FILE
	Employee* department[] =
	{
		new PermanentEmployee("Rosenberg","Ken",30, "Lawyer", 2000),
		new PermanentEmployee("Diaz", "Ricardo", 50, "Boss", 50000),
		new HourlyEmployee("Vercetty", "Thomas", 30, "Security", 500, 8)
	};

	double total_salary = 0;
	for (size_t i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		cout << *department[i];

		cout << "\n--------------------------------------\n";
	}

	std::ofstream fout("myfile3.txt");
	for (size_t i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		fout.width(25);
		fout << std::left;
		fout << std::string(typeid(*department[i]).name()) + ":";
		fout << *department[i] << endl;
	}
	fout.close();
	system("start notepad myfile3.txt");

	cout << total_salary << endl;
	for (size_t i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		delete department[i];
	}

	/*PermanentEmployee pe;
	cout << "??????? ?????????? ? ??????????: "<< endl;
	cin >> pe;
	cout << pe << endl;*/
#endif // DEBUG

	Employee** department = nullptr;
	int n = 0;
	std::ifstream fin("myfile3.txt");

	if (fin.is_open())
	{
		/*cout << fin.tellg() << endl;*/
		std::string employee_type;
		
		for (; !fin.eof(); n++)
		{
			std::getline(fin, employee_type);
		}
		n--;
		cout << n << endl;
		department = new Employee*[n] {};

		cout << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << fin.tellg() << endl;

		for (size_t i = 0; i < n; i++)
		{
			std::getline(fin, employee_type, ':');
			department[i] = EmployeeFactory(employee_type);
			fin >> *department[i];
		}
	}
	else
	{
		std::cerr << "Error: file not found"<<endl;
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << *department[i]<<endl;
	}
	for (size_t i = 0; i < n; i++)
	{
		delete department[i];
	}

	delete[]department;
	fin.close();

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
