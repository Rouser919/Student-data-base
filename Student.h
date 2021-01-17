#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
class Student
{
	std::string name;
	std::string surname;
	typedef std::map < const std::string, std::vector<float> > x;
	double  average_of_school_subjects[8];
	enum classroom {I,II,III,IV};
	int class_;
	x marks{
	{ "English",{} },
	{"Mathematic",{}},
	{ "Biology",{} },
	{"History",{}},
	{ "Physics",{} },
	{"Chemistry",{}},
	{ "Ethic/Religion",{} },
	{"P.E",{}},
	};
	//static std::map<const std::string,double> average_of_school_subjects;
	double average;
	void set_ave_of_scho_sub();
	void set_ave_marks();
public:
	Student(std::string& _name, std::string& _surname, classroom _class);
	Student();
	Student(const Student& x);
	Student& operator=(const Student& x);
	void change_class(classroom n);
	void add_marks();
	void delete_marks();
	void modify_marks();
	void show_1(const int n) ;
	void edit(std::string& _name, std::string& _surname, int _class);
	~Student() {};
	friend std::ostream& operator<<(std::ostream& os, const Student& x);
};

class Base {
	std::vector<std::unique_ptr<Student>> x;// https://cpp-polska.pl/post/kompendium-wiedzy-o-smart-pointerach
	int count;
public:
	Base();
	Base(int _count);
	~Base() {};
	void add();
	void remove();
	friend std::ostream& operator>>(std::ostream& os, const Student& x);
	void read(FILE* fp);
	void write(FILE* fp);




};

