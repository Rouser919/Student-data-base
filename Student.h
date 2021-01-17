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
	static x marks;
	enum classroom {I,II,III,IV};
	double average;
	void set_ave();
public:
	Student(std::string& _name, std::string& _surname, int _class);
	Student();
	Student(const Student& x);
	Student& operator=(const Student& x);
	void add_marks();
	void delete_marks();
	void modify_marks();
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





};

