// Academy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

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

	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
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

};

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
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, double rating,
		double attendance
	) :Human(last_name, first_name, age)
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
	
};

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
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& subject, int expirience
	):Human(last_name,first_name,age)
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
};

#define INHERITANCE

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
#endif // INHERITANCE
	
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
