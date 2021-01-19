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
	void set_ave_marks() { average = (double)std::accumulate(average_of_school_subjects, average_of_school_subjects + 8, 0.0) / 8.0; }
	bool good_mark(int n) { if (n > 48 && n < 55) return 1; else return 0; }
	bool good_class(int n) { if (n > 0 && n < 5) return 1; else return 0; }
public:
	Student(std::string& _name, std::string& _surname, int _class);
	Student(std::string& _name, std::string& _surname, int _class, double ave[8], x &b, double aver);
	Student();
	Student(const Student& x);
	Student& operator=(const Student& x);
	bool comp_name(const std::string& c) { return name.compare(c) == 0; }
	bool comp_surname(const std::string& c) { return surname.compare(c) == 0; }
	bool comp_class(int i) { return class_ == i; }
	bool comp_mark(double m) { return m < average; }
	std::string get_name() { return name; }
	std::string get_surname() { return surname; }
	double get_average() { return average; }
	int get_class() { return class_; }
	void change_class(int n);
	void add_marks();
	void delete_marks();
	void modify_marks();
	void show_1(const int n) ;
	void show_student();
	// ADD FUNTION TO INITITE PERSON
	void edit();
	void write_file_s(std::fstream& x);
	~Student() {};
	friend std::ostream& operator<<(std::ostream & os, const Student& x);
};

class Base {
	std::vector<std::unique_ptr<Student>> data;// https://cpp-polska.pl/post/kompendium-wiedzy-o-smart-pointerach
	static int count;
	std::string file_name_read;
	std::string file_name_write;
	bool validate_for_menu(int c) { if ( c <= data.size() && c > 0) return 1; else return 0; }
	void change_name_student();
	void add_for_read_file(const Student& x);
	void add_for_menu();
public:
	Base();
	Base(int _count);
	~Base();
	bool comp_name_for_sort(const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) { return a->get_name() < b->get_name(); }
	bool comp_surname_for_sort(const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) { return a->get_surname() < b->get_surname(); }
	bool comp_average_for_sort(const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) { return a->get_average() < b->get_average(); }
	bool comp_class_for_sort(const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) { return a->get_class() < b->get_class();}
	void menu();
	void menu_for_sort();
	void modify();
	void remove();
	void sort_by(const std::string &x,bool slope,bool mode );
	void sort_by(double x, bool slope, bool mode);
	void show_tab();
	void show_by_name();
	void show_by_surname();
	void show_by_class();
	void show_by_mark();
	void show_students();
	friend std::ostream& operator<<(std::ostream& os, const Base& x);
	void read();
	void write_file_b();
};

