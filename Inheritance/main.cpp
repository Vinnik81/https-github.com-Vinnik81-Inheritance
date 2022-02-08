#include<iostream>
using namespace std;

class Human
{
protected:
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string get_last_name()const
	{
		return last_name;
	}
	const std::string get_first_name()const
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
	Human(const std::string& last_name,const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	virtual std::ostream& print(std::ostream& os)const
	{
		os << "\n----------------------------------------------------------------------------------------------------------\n";
		os << std::left;
		os.width(15);
		os << last_name;
		os.width(15);
		os << first_name;
		os.width(3);
		os << age << "years";
		 return os;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}

class Student :public Human
{
	std::string speciality;
	std::string group;
	float rating;
	float attendance;

public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& group_speciality()const
	{
		return group;
	}
	float get_rating()const
	{
		return rating;
	}
	float get_attendance()const
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
	void set_rating(float rating)
	{
		this->rating = rating;
	}
	void set_attendance(float attendance)
	{
		this->attendance = attendance;
	}

	Student
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, float rating, float attendance
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
	std::ostream& print(std::ostream& os)const
	{
		/*return Human::print(os) << " "
			<< speciality << " " 
			<< group << " " 
			<< rating << " " 
			<< attendance;*/
		Human::print(os) << " | ";
		os << std::left;
		os.width(22);
		os << speciality;
		os.width(8);
		os << group;
		os.width(4);
		os << rating;
		os.width(4);
		os << attendance;
		return os;
	}
};

class Teacher : public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, unsigned int experience
	): Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDeconstructor:\t" << this << endl;
	}
	std::ostream& print(std::ostream& os)const
	{
		/*return Human::print(os) << " " << speciality << " " << experience;*/
		Human::print(os) << " | ";
		os << std::left;
		os.width(22);
		os << speciality;
		os.width(4);
		os << experience;
		return os;
	}
};

class Graduate : public Student
{
	std::string subject;

public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, float rating, float attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDeconstructor:\t" << this << endl;
	}
	std::ostream& print(std::ostream& os)const
	{
		return Student::print(os) << " | " << subject;
	}
};

//#define INHERITANCE_CHEK

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHEK
	Human human("Misha", "Specialist", 18);
	human.print();
	Student student("Jessi", "Pinkman", 20, "Chim", "WW121", 90, 85);
	student.print();
	Teacher teacher("White", "Walter", 50, "Chim", 20);
	teacher.print();
	Graduate graduate("Shrader", "Hank", 40, "Criminalistic", "WW121", 95, 55, "How to catch Heisenberg");
	graduate.print();
#endif // INHERITANCE_CHEK

	//Generalisation:
	Human* group[] =
	{
		new Student("Jessi", "Pinkman", 20, "Chim", "WW121", 90, 85),
		new Teacher("White", "Walter", 50, "Chim", 20),
		new Graduate("Shrader", "Hank", 40, "Criminalistic", "WW121", 95, 55, "How to catch Heisenberg"),
		new Student("Vercetty", "Tomas", 30, "Criminalistic", "Vice", 98, 95),
		new Teacher("Dias", "Ricardo", 50, "Weapons distribution", 30)
	};
	//cout << "\n----------------------------------------\n";
	//Specialisation:
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->print();
		cout << *group[i] << endl;
		//cout << "\n----------------------------------------\n";
	}
	//������� ������:
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
		cout << "\n----------------------------------------\n";
	}

}