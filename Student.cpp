#include "Student.h"
#include <numeric> 
#include <iostream>
#include <cctype>
#include <string>
/*
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
	bool good_mark(int n) { if (n >= 0 && n < 7) return 1; else return 0; }
public:

	friend std::ostream& operator<<(std::ostream& os, const Student& x);
};
	*/
void Student::set_ave_marks() {
	average=std::accumulate(average_of_school_subjects, average_of_school_subjects+8, 0 )/8;
}
void Student::set_ave_of_scho_sub() {
	double sum;
	int count, i = 0;
	for (auto &b : marks) {
		count = 0;
		sum = 0;
		for (auto &c : b) {
			sum += c;
			count++;
		}
		average_of_school_subjects[i]= sum / count;
		i++;
	}
	set_ave_marks();
}
Student::Student(std::string& _name, std::string& _surname,int _class) {
	name = _name;
	surname = _surname;
	class_ = _class;
	add_marks();
}
Student::Student() {
	name="Empty";
	surname = "Empty";
	class_ = 1;
	add_marks();
}
Student::Student(const Student& x) {
	name = x.name;
	surname = x.surname;
	class_ = x.class_;
	marks = x.marks;
	add_marks();
}
Student& Student::operator=(const Student& x) {
	name = x.name;
	surname = x.surname;
	class_ = x.class_;
	marks = x.marks;
	return *this;
}
void Student::change_class(int n) {
	if (n < 1 || n>4) {
		std::cout << "Invalid class, please try again" << std::endl;
	}
	else {
		class_ = n;
		delete_marks();
	}
}
void Student::add_marks() {
	char x;
	char tmp;
	std::cout << "Please choose what do you want:" << std::endl
		<< "1.English" << std::endl << "2.Mathematic" << std::endl
		<< "3.Biology" << std::endl << "4.History" << std::endl
		<< "5.Psyhics" << std::endl << "6.Chemistry" << std::endl
		<< "7.Ethic/Religion" << std::endl << "8.P.E" << std::endl <<
		"Click k to exit" << std::endl;
	while (std::cin>>x && x != 'k') {
		if (isdigit(x)) {
			std::cout << "Write new mark" << std::endl;
			std::cin >> tmp;
			while  (tmp != 'x') {
				if (good_mark(tmp)) {
					marks[x-49].push_back(std::stoi(&tmp));
					std::cout << "Succesfully added!" << std::endl
						<< "Click x to exit or add new mark" << std::endl;
				}
				else {
					std::cout << "Invalid value! Please write correct mark" << std::endl;
				}
				std::cin >> tmp;
			}
		}
		std::cout << "Please choose what do you want:" << std::endl
			<< "1.English" << std::endl << "2.Mathematic" << std::endl
			<< "3.Biology" << std::endl << "4.History" << std::endl
			<< "5.Psyhics" << std::endl << "6.Chemistry" << std::endl
			<< "7.Ethic/Religion" << std::endl << "8.P.E" << std::endl <<
			"Click k to exit" << std::endl;
	}
	set_ave_of_scho_sub();
}
void Student::delete_marks(){
	for (auto b : marks) {
		b.clear();
	}
	set_ave_of_scho_sub();
}
void Student::modify_marks() {
	char x;
	char tmp;
	char tmp_2;
	std::cout << "Please choose what do you want to modify or erase element:" << std::endl
		<< "1.English" << std::endl << "2.Mathematic" << std::endl
		<< "3.Biology" << std::endl << "4.History" << std::endl
		<< "5.Psyhics" << std::endl << "6.Chemistry" << std::endl
		<< "7.Ethic/Religion" << std::endl << "8.P.E" << std::endl <<
		"Click K to exit" << std::endl;
	while (std::cin >> x && x != 'k') {
		show_1((x-49));
		std::cout << "Modify or erase?" << std::endl
			<< "Click 1 for modify or 2 for erase element"<<std::endl;
		std::cin >> tmp;
		if (tmp == '1') {
			std::cout << "What value u want to modify?" << std::endl;
			std::cin >> tmp;
			if (isdigit(tmp)) {
				if (marks[x-49].size() > tmp-48 && tmp-48 >= 0) {
					std::cout << "Enter new Value" << std::endl;
					std::cin >> tmp_2;
					if (good_mark(tmp_2)) {
						marks[x - 49][tmp - 49] = std::stoi(&tmp_2);
						std::cout << "After change: " << std::endl;
						show_1((x - 49));
					}
					else {
						std::cout << "Invalid value" << std::endl
							<< "Back to main console" << std::endl;
					}
				}
			}
			else {
				std::cout << "Invalid value" << std::endl
					<< "Back to main console" << std::endl;
			}
		}
		else if (tmp == '2') {
			std::cout << "What value u want to erase?" << std::endl;
			std::cin >> tmp;
			if (isdigit(tmp)&&marks[x - 49].size() > tmp - 48 && tmp - 48 >= 0) {
				marks[x-49].erase(marks[x-49].begin() +std::stoi(&tmp)-1);
				std::cout << "After change: " << std::endl;
				show_1((std::stoi(&x)));
			}
			else {
				std::cout << "Invalid value" << std::endl
					<< "Back to main console" << std::endl;
			}
		}

		std::cout << "Please choose what do you want to modify or erase element:" << std::endl
			<< "1.English" << std::endl << "2.Mathematic" << std::endl
			<< "3.Biology" << std::endl << "4.History" << std::endl
			<< "5.Psyhics" << std::endl << "6.Chemistry" << std::endl
			<< "7.Ethic/Religion" << std::endl << "8.P.E" << std::endl <<
			"Click k to exit" << std::endl;
	}
	std::cin.clear();

	set_ave_of_scho_sub();
}

void Student::show_1(const int n) {
		std::cout<<(std::string)subjects[n] << " "<<"marks" << std::endl;
		for (int i = 1; i <= marks[n].size(); i++) {
			std::cout << i << ": " << marks[n][i-1] << std::endl;
		}
}

void Student::edit(std::string& _name, std::string& _surname, int _class) {
	name = _name;
	surname = _surname;
	class_ = _class;
}






