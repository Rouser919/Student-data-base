#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>
#include<array>
class Student
{
	std::string name;
	std::string surname;
	double  average_of_school_subjects[8];
	int class_;
	std::array<std::vector<double>, 8> marks{};
	std::vector<std::string> subjects{
	{ "English"},
	{"Mathematic"},
	{ "Biology"},
	{"History"},
	{ "Physics" },
	{"Chemistry"},
	{ "Ethic/Religion"},
	{"P.E"}
	};
	double average;
	void set_ave_of_scho_sub();
	void set_ave_marks();
	bool good_mark(int n) { if (n > 48 && n < 55) return 1; else return 0; }
public:
	Student(std::string& _name, std::string& _surname, int _class);
	Student();
	Student(const Student& x);
	Student& operator=(const Student& x);
	void change_class(int n);
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

