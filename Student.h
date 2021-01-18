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
	typedef std::array<std::vector<double>, 8> x;
	x marks{};
	double average;
	void set_ave_of_scho_sub();
	void set_ave_marks() { average = std::accumulate(average_of_school_subjects, average_of_school_subjects + 8, 0) / 8; }
	bool good_mark(int n) { if (n > 48 && n < 55) return 1; else return 0; }
public:
	Student(std::string& _name, std::string& _surname, int _class);
	Student(std::string& _name, std::string& _surname, int _class, double ave[8], x &b, double aver);
	Student();
	Student(const Student& x);
	Student& operator=(const Student& x);
	void change_class(int n);
	void add_marks();
	void delete_marks();
	void modify_marks();
	void show_1(const int n) ;
	void show_student();
	void edit();
	std::string& copy();  // in feature delete, now for testing
	~Student() {};
	friend std::ostream& operator<<(std::ostream & os, const Student& x);
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
	void add_for_menu();
	void add_for_read_file(const Student &x);
	void modify();
	void remove();
	void show_by_name();
	void show_by_surname();
	void show_by_class();
	void sort_and_show_by_best_average_mark();

		/*7.Show all Students" << std::endl
		<< "8.Show all Students by name" << std::endl << "9.Show all Students by surname" << std::endl <<
		"10.Show all Students by class" << std::endl << "11.Show all Students by best average mark" << std::endl <<
		*/
	void show_students();
	friend std::ostream& operator<<(std::ostream& os, const Base& x);
	void read();
	void write();
};

