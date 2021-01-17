#include "Student.h"
#include <numeric> 
#include <iostream>
#include <cctype>
/*
class Student
{
	std::string name;
	std::string surname;
	typedef std::map < const std::string, std::vector<float> > x;
	double average_of_school_subjects[8];
	static x marks;
	enum classroom {I,II,III,IV};
	//static std::map<const std::string,double> average_of_school_subjects;
	double average;
	void set_ave_of_scho_sub();
	void set_ave_marks();
public:
	Student(std::string& _name, std::string& _surname, int _class);
	Student();
	Student(const Student& x);
	Student& operator=(const Student& x);
	void next_class();
	void add_marks();
	void delete_marks();
	void modify_marks();
	void edit(std::string& _name, std::string& _surname, int _class);
	~Student() {};
	friend std::ostream& operator<<(std::ostream& os, const Student& x);
};0
	*/
void Student::set_ave_marks() {
	average=std::accumulate(average_of_school_subjects[0], average_of_school_subjects[8], 0 )/8;
}
void Student::set_ave_of_scho_sub() {
	double sum;
	int count, i = 0;
	for (auto &b : marks) {
		count = 0;
		sum = 0;
		for (auto &c : b.second) {
			sum += c;
			count++;
		}
		average_of_school_subjects[i]= sum / count;
		i++;
	}
	set_ave_marks();
}
Student::Student(std::string& _name, std::string& _surname,classroom _class) {
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
}
Student& Student::operator=(const Student& x) {
	name = x.name;
	surname = x.surname;
	class_ = x.class_;
	marks = x.marks;
}
void Student::change_class(classroom n) {
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
		"Click K to exit" << std::endl;;
	while (std::cin >> x && x != 'K') {
		if (isdigit(x)) {
			switch (x) {
			case(1):
				while (std::cin >> tmp && tmp != 'K') {
					if (isdigit(tmp)) {
						marks["English"].push_back(tmp);
						std::cout << "Succesfully added!" << std::endl
							<< "Click K to exit or add new mark" << std::endl;
					}
				}
				break;
			case(2):
				while (std::cin >> tmp && tmp != 'K') {
					if (isdigit(tmp)) {
						marks["Mathematic"].push_back(tmp);
						std::cout << "Succesfully added!" << std::endl
							<< "Click K to exit or add new mark" << std::endl;
					}
				}
				break;
			case(3):
				while (std::cin >> tmp && tmp != 'K') {
					if (isdigit(tmp)) {
						marks["Biology"].push_back(tmp);
						std::cout << "Succesfully added!" << std::endl
							<< "Click K to exit or add new mark" << std::endl;
					}
				}
				break;
			case(4):
				while (std::cin >> tmp && tmp != 'K') {
					if (isdigit(tmp)) {
						marks["History"].push_back(tmp);
						std::cout << "Succesfully added!" << std::endl
							<< "Click K to exit or add new mark" << std::endl;
					}
				}
				break;
			case(5):
				while (std::cin >> tmp && tmp != 'K') {
					if (isdigit(tmp)) {
						marks["Psyhics"].push_back(tmp);
						std::cout << "Succesfully added!" << std::endl
							<< "Click K to exit or add new mark" << std::endl;
					}
				}
				break;
			case(6):
				while (std::cin >> tmp && tmp != 'K') {
					if (isdigit(tmp)) {
						marks["Chemistry"].push_back(tmp);
						std::cout << "Succesfully added!" << std::endl
							<< "Click K to exit or add new mark" << std::endl;
					}
				}
				break;
			case(7):
				while (std::cin >> tmp && tmp != 'K') {
					if (isdigit(tmp)) {
						marks["Ethic/Religion"].push_back(tmp);
						std::cout << "Succesfully added!" << std::endl
							<< "Click K to exit or add new mark" << std::endl;
					}
				}
				break;
			case(8):
				while (std::cin >> tmp && tmp != 'K') {
					if (isdigit(tmp)) {
						marks["P.E"].push_back(tmp);
						std::cout << "Succesfully added!" << std::endl
							<< "Click K to exit or add new mark" << std::endl;
					}
				}
				break;
			default:
				std::cout << "Invalid value!" << std::endl;
				break;
			}
		}




	}
}
void Student::delete_marks(){

}



