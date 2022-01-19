// Academy.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
		cout << last_name<<" " <<first_name << " " << age << " лет" << endl;
	}

	virtual std::ostream& print(std::ostream& os)const
	{
		/*return os << last_name << " " << first_name << " " << age << " лет";*/
		os << std::left;
		os.width(10);
		os << last_name;
		os.width(10);
		os << first_name;
		os.width(3);
		os << age << " лет";
		return os;
	}

	virtual std::ofstream& print(std::ofstream& os)const 
	{
		os << std::left;
		os.width(10);
		os << last_name;
		os.width(10);
		os << first_name;
		os.width(5);
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

#define students_take_parameters const std::string& speciality, const std::string& group, double rating,double attendance
#define students_give_parameters speciality, group, rating, attendance

class Student:public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	Student
	(human_take_parameters, students_take_parameters):Human(human_give_parameters)

	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}

	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
	
	std::ofstream& print(std::ofstream& os)const
	{
		Human::print(os);
		os << std::left;
		os.width(15);
		os<< speciality;
		os.width(10);
		os<<group;
		os.width(3);
		os<<rating;
		os.width(3);
		os<< attendance;
		return os;
	}

	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);
		Human::print(os);
		os << std::left;
		os.width(15);
		os << speciality;
		os.width(10);
		os << group;
		os.width(3);
		os << rating;
		os.width(3);
		os << attendance;
		return os;
	}

	std::ifstream& scan(std::ifstream& is)
	{
		Human::scan(is);
		is>> speciality;
		is>> group;
		is>>rating;
		is>>attendance;
		return is;
	}
};

#define teacher_take_parameters const std::string& subject, int expirience
#define teacher_give_parameters subject, expirience

class Teacher:public Human
{
	int expirience;
	std::string subject;
public:
	const int get_expirience()const
	{
		return expirience;
	}
	const std::string get_subject()const
	{
		return subject;
	}
	void set_expirience(int expirience)
	{
		this->expirience = expirience;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	
	Teacher
	(
		human_take_parameters,
		teacher_take_parameters
	):Human(human_give_parameters)
	{
		set_expirience(expirience);
		set_subject(subject);
		cout << "TeachConstructor\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TeachDestructor\t" << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << expirience << endl;
		cout << subject << endl;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Human::print(os);
		os << std::left;
		os.width(10);
		os << subject;
		os.width(10);
		os << expirience;
		return os;
	}
	std::ifstream& scan(std::ifstream& is)
	{
		Human::scan(is);
		is >> subject;
		is >> expirience;
		return is;
	}
	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);
		os << std::left;
		os.width(10);
		os << subject;
		os.width(10);
		os << expirience;
		return os;
	}
};


class Graduate :public Student
{
	std::string topic;
	int result;
public:
	const std::string& get_topic()const
	{
		return topic;
	}

	const int get_result()const
	{
		return result;
	}

	void set_topic(const std::string& topic)
	{
		this->topic = topic;
	}
	void set_result(int result)
	{
		this->result = result;
	}

	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, const double rating,
		int attendance, const std::string& topic, int result
	) : Student
		(
			last_name, first_name, age, 
			speciality, group, rating, attendance
		)
	{
		set_topic(topic);
		set_result(result);
		cout << "GrConstructor\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GrDestructor" << this << endl;
	}
	void print()const
	{
		Student::print();
		cout << topic << endl;
		cout << result << endl;
	}
	std::ofstream& print(std::ofstream& os)const
	{
		Student::print(os);
		os << std::left;
		os.width(10);
		os<< topic;
		os<< result;
		return os;
	}

	std::ifstream& scan(std::ifstream& is)
	{
		Student::scan(is);
		is >> topic;
		is >> result;
		return is;
	}
	std::ostream& print(std::ostream& os)const
	{
		Student::print(os);
		os << std::left;
		os.width(10);
		os << topic;
		os << result;
		return os;
	}
};

Human* HumanFactory(std::string& type)
{
	if (type.find("Student") != std::string::npos)return new Student("", "", 0, "","", 0, 0);
	if (type.find("Teacher") != std::string::npos)return new Teacher("", "", 0, "", 0);
	if (type.find("Graduate") != std::string::npos)return new Graduate("", "", 0, "","", 0, 0,"", 0);
}

//#define INHERITANCE

int main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human h("Montana", "Antonio", 35);
	h.print();

	Student s("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95);
	s.print();

	Graduate P("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95, "OVR", 10);
	P.print();
//
//Graduate T("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93, "OBR", 10);
//T.print();
//
Teacher T("Pinkman", "Jessie", 22, "math", 5);
T.print();
#endif // INHERITANCE
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_01", 93,10),
		new Student("Versetti", "Thomas", 30, "Criminal", "Vice", 90, 9),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Student("Diaz", "Ricardo", 55, "Weapons", "Vice", 80, 5),
		new Graduate("Schrader", "Hank", 42,
		"Cryminalistic", "OBN", 95 ,5," some topic", 5 ),
		new Teacher("Eistein", "Albert", 143, "Astronomy", 120)
	};

	//for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	//{
	//	cout << "\n----------------------------------------\n";
	//	//group[i]->print();
	//	cout << typeid(*group[i]).name() << endl;
	//	group[i]->print();
	//}
	//cout << "\n----------------------------------------\n";

	/*std::ofstream fout("file1.txt");
	for (size_t i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		fout << std::string(typeid(*group[i]).name()) + ":";
		fout << *group[i]<<endl;
	}
	system("start notepad file1.txt");
	fout.close();*/

	Human** groups = nullptr;
	int n = 0;
	std::ifstream fin("file1.txt");
	if (fin.is_open())
	{
		std::string employee_type;

		for (; !fin.eof(); n++)
		{
			std::getline(fin, employee_type);
		}
		n--;
		cout << n << endl;
		groups = new Human * [n] {};

		for (size_t i = 0; i < n; i++)
		{
			std::getline(fin, employee_type, ':');
			groups[i] = HumanFactory(employee_type);
			fin >> *groups[i];
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << *groups[i] << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete[] group[i];
	}
	delete[]group;
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
