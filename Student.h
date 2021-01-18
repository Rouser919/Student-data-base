#pragma once
#include <string>
#include <vector>
#include <map>
#include <numeric> 
#include <memory>
#include<array>
class Student
{
	std::string name;
	std::string surname;
	double  average_of_school_subjects[8];
	int class_;
	std::array<std::vector<double>, 8> marks{};
	double average;
	void set_ave_of_scho_sub();
	void set_ave_marks() { average = std::accumulate(average_of_school_subjects, average_of_school_subjects + 8, 0) / 8; }
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
	void edit();
	~Student() {};
	friend std::ostream& operator<<(std::ostream& os, const Student& x);
};

class Base {
	std::vector<std::unique_ptr<Student>> data;// https://cpp-polska.pl/post/kompendium-wiedzy-o-smart-pointerach
	static int count;
	std::string file_name;
	bool validate_for_menu(int c) { if (isdigit(c) && c <= data.size() && c > 0) return 1; else return 0; }
public:
	Base();
	Base(int _count);
	~Base();
	void menu();
	void add();
	void modify();
	void remove();
	void show_students();
	friend std::ostream& operator>>(std::ostream& os, const Student& x);
	void read();
	void write();
};

