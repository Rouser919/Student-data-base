#include "Student.h"
#include <iostream>
#include <cctype>
#include <string>
static std::vector<std::string> subjects{
{ "English"},
{"Mathematic"},
{ "Biology"},
{"History"},
{ "Physics" },
{"Chemistry"},
{ "Ethic/Religion"},
{"P.E"}
};
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
	class_ = 0;
}
Student::Student(const Student& x) {
	name = x.name;
	surname = x.surname;
	class_ = x.class_;
	marks = x.marks;
	average = x.average;
	std::memcpy(average_of_school_subjects, x.average_of_school_subjects, 8);
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
void Student::edit() {
	std::cout << " Welcome to personal editor" << std::endl;
	char c;
	std::cout << "Press 1 to edit name, 2 for surname or 3 for edit class. Press x for exit " << std::endl;
	while (std::cin >> c && c != 'x') {
		switch (c - 48) {
		case(1):
			std::cout << "Type name " << std::endl;
			std::cin >> name;
			std::cout << "You write" << name << " Back to the menu" << std::endl;
			std::cin.clear();
			break;
		case(2):
			std::cout << "Type surname " << std::endl;
			std::cin >> surname;
			std::cout << "You write" << surname << " Back to the menu" << std::endl;
			std::cin.clear();
			break;
		case(3):
			std::cout << "Type name " << std::endl;
			std::cin >> class_;
			std::cout << "You write" << class_ << " Back to the menu" << std::endl;
			std::cin.clear();
			break;
		default:
			std::cin.clear();
			break;
		}
		std::cout << "Press 1 to edit name, 2 for surname or 3 for edit class. Press x for exit " << std::endl;
	}
}
std::ostream& operator<<(std::ostream& os, const Student& x) {
	os << x.name << " " << x.surname << " Class:" << x.class_ << " Average of marks:" << x.average << " ";
	int index = 0;
	for (auto i : x.marks) {
		os << subjects[index] << ": " << x.average_of_school_subjects[index] << " Marks:";
		for (auto b : x.marks[index]) {
			os << b << ",";
		}
		os << "X";
		index++;
	}
	return os;
}
/*
class Base {
	std::vector<std::unique_ptr<Student>> data;// https://cpp-polska.pl/post/kompendium-wiedzy-o-smart-pointerach
	int count;
	std::string file_name;
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
*/
Base::Base() {
	std::unique_ptr<Student> ptr2x( new Student());
	data.emplace_back(std::move(ptr2x)); 
	count = 1;
}
Base::Base(int _count) {
	count = 0;
	while (count < _count) {
		data.emplace_back(std::move(std::unique_ptr<Student>(new Student())));
		count++;
	}

}	
Base::~Base() {
	write();
};
void Base::menu() {
	std::cout << "Welcome to main menu of the program" << std::endl
		<< "---------------------------------------------------------------------------------------" << std::endl << std::endl
		<< "Select options that you want:" << std::endl << "1.Add Student" << std::endl <<
		"2.Modify Student" << std::endl << "3.Remove Student" << std::endl << "4.Show all Students" << std::endl
		<< "5.Show all Students by name" << std::endl << "6.Show all Students by surname" << std::endl <<
		"7.Show all Students by class" << std::endl << "8.Show all Students by best average mark" << std::endl <<
		"9.Read base data from file" << std::endl << "10.Write base data to file" << std::endl <<
		std::endl << "Notice: Autosave will automate save base data to file base.txt at the end of the program" << std::endl;
}
void Base::add() {
	data.emplace_back(std::move(std::unique_ptr<Student> (new Student())));
	count++;
}
void Base::remove() {
	std::cout << "Welcome in program to delete Student" << std::endl;
	show_students();
	std::cout << " Insert a student number that you want to delete:" << std::endl;
	char b;
	while (std::cin >> b && b != 'x') {
		if (isdigit(b)) {
			data.erase(data.begin() + b - 1);
		}
		else {
			std::cout << " Invalid value " << std::endl;
		}
		std::cout << "Press k to exit or insert new number" << std::endl;
	}
}





