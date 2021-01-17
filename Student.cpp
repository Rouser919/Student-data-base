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
};0
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
	return *this;
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
	set_ave_of_scho_sub();
}
void Student::delete_marks(){
	for (auto b : marks) {
		b.second.clear();
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
	while (std::cin >> x && x != 'K') {
		switch (x) {
		case(1):
			show_1(1);
			std::cout << "Modify or erase?" << std::endl
				<< "Click 1 for modify or 2 for erase element";
			std::cin >> tmp;
			if (tmp == 1) {
				std::cout << "What value u want to modify?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					if (marks["English"].size() > tmp && tmp >= 0) {
						std::cout << "Enter new Value" << std::endl;
						std::cin >> tmp_2;
						if (isdigit(tmp_2)) {
							marks["English"].insert(marks["English"].begin()+tmp,tmp_2);
						}
						else {
							std::cout << "Invalid value" << std::endl
								<< "Back to main console" << std::endl;
							break;
						}
					}
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			else if (tmp == 2) {
				std::cout << "What value u want to erase?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					marks["English"].erase(marks["English"].begin() + tmp);
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			break;
		case(2):
			show_1(2);
			std::cout << "Modify or erase?" << std::endl
				<< "Click 1 for modify or 2 for erase element";
			std::cin >> tmp;
			if (tmp == 1) {
				std::cout << "What value u want to modify?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					if (marks["Mathematic"].size() > tmp && tmp >= 0) {
						std::cout << "Enter new Value" << std::endl;
						std::cin >> tmp_2;
						if (isdigit(tmp_2)) {
							marks["Mathematic"].insert(marks["Mathematic"].begin() + tmp, tmp_2);
						}
						else {
							std::cout << "Invalid value" << std::endl
								<< "Back to main console" << std::endl;
							break;
						}
					}
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			else if (tmp == 2) {
				std::cout << "What value u want to erase?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					marks["Mathematic"].erase(marks["Mathematic"].begin() + tmp);
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			break;
		case(3):
			show_1(3);
			std::cout << "Modify or erase?" << std::endl
				<< "Click 1 for modify or 2 for erase element";
			std::cin >> tmp;
			if (tmp == 1) {
				std::cout << "What value u want to modify?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					if (marks["Biology"].size() > tmp && tmp >= 0) {
						std::cout << "Enter new Value" << std::endl;
						std::cin >> tmp_2;
						if (isdigit(tmp_2)) {
							marks["Biology"].insert(marks["Biology"].begin() + tmp, tmp_2);
						}
						else {
							std::cout << "Invalid value" << std::endl
								<< "Back to main console" << std::endl;
							break;
						}
					}
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			else if (tmp == 2) {
				std::cout << "What value u want to erase?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					marks["Biology"].erase(marks["Biology"].begin() + tmp);
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			break;
		case(4):
			show_1(4);
			std::cout << "Modify or erase?" << std::endl
				<< "Click 1 for modify or 2 for erase element";
			std::cin >> tmp;
			if (tmp == 1) {
				std::cout << "What value u want to modify?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					if (marks["History"].size() > tmp && tmp >= 0) {
						std::cout << "Enter new Value" << std::endl;
						std::cin >> tmp_2;
						if (isdigit(tmp_2)) {
							marks["History"].insert(marks["History"].begin() + tmp, tmp_2);
						}
						else {
							std::cout << "Invalid value" << std::endl
								<< "Back to main console" << std::endl;
							break;
						}
					}
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			else if (tmp == 2) {
				std::cout << "What value u want to erase?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					marks["History"].erase(marks["History"].begin() + tmp);
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			break;
		case(5):
			show_1(5);
			std::cout << "Modify or erase?" << std::endl
				<< "Click 1 for modify or 2 for erase element";
			std::cin >> tmp;
			if (tmp == 1) {
				std::cout << "What value u want to modify?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					if (marks["Psyhics"].size() > tmp && tmp >= 0) {
						std::cout << "Enter new Value" << std::endl;
						std::cin >> tmp_2;
						if (isdigit(tmp_2)) {
							marks["Psyhics"].insert(marks["Psyhics"].begin() + tmp, tmp_2);
						}
						else {
							std::cout << "Invalid value" << std::endl
								<< "Back to main console" << std::endl;
							break;
						}
					}
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			else if (tmp == 2) {
				std::cout << "What value u want to erase?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					marks["Psyhics"].erase(marks["Psyhics"].begin() + tmp);
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			break;
		case(6):
			show_1(6);
			std::cout << "Modify or erase?" << std::endl
				<< "Click 1 for modify or 2 for erase element";
			std::cin >> tmp;
			if (tmp == 1) {
				std::cout << "What value u want to modify?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					if (marks["Chemistry"].size() > tmp && tmp >= 0) {
						std::cout << "Enter new Value" << std::endl;
						std::cin >> tmp_2;
						if (isdigit(tmp_2)) {
							marks["Chemistry"].insert(marks["Chemistry"].begin() + tmp, tmp_2);
						}
						else {
							std::cout << "Invalid value" << std::endl
								<< "Back to main console" << std::endl;
							break;
						}
					}
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			else if (tmp == 2) {
				std::cout << "What value u want to erase?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					marks["Chemistry"].erase(marks["Chemistry"].begin() + tmp);
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			break;
		case(7):
			show_1(7);
			std::cout << "Modify or erase?" << std::endl
				<< "Click 1 for modify or 2 for erase element";
			std::cin >> tmp;
			if (tmp == 1) {
				std::cout << "What value u want to modify?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					if (marks["Ethic/Religion"].size() > tmp && tmp >= 0) {
						std::cout << "Enter new Value" << std::endl;
						std::cin >> tmp_2;
						if (isdigit(tmp_2)) {
							marks["Ethic/Religion"].insert(marks["Ethic/Religion"].begin() + tmp, tmp_2);
						}
						else {
							std::cout << "Invalid value" << std::endl
								<< "Back to main console" << std::endl;
							break;
						}
					}
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			else if (tmp == 2) {
				std::cout << "What value u want to erase?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					marks["Ethic/Religion"].erase(marks["Ethic/Religion"].begin() + tmp);
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			break;
		case(8):
			show_1(8);
			std::cout << "Modify or erase?" << std::endl
				<< "Click 1 for modify or 2 for erase element";
			std::cin >> tmp;
			if (tmp == 1) {
				std::cout << "What value u want to modify?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					if (marks["P.E"].size() > tmp && tmp >= 0) {
						std::cout << "Enter new Value" << std::endl;
						std::cin >> tmp_2;
						if (isdigit(tmp_2)) {
							marks["P.E"].insert(marks["P.E"].begin() + tmp, tmp_2);
						}
						else {
							std::cout << "Invalid value" << std::endl
								<< "Back to main console" << std::endl;
							break;
						}
					}
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			else if (tmp == 2) {
				std::cout << "What value u want to erase?" << std::endl;
				std::cin >> tmp;
				if (isdigit(tmp)) {
					marks["P.E"].erase(marks["P.E"].begin() + tmp);
				}
				else {
					std::cout << "Invalid value" << std::endl
						<< "Back to main console" << std::endl;
					break;
				}
			}
			break;
		default:
			break;

		}
	std::cout << "Please choose what do you want to modify or erase element:" << std::endl
		<< "1.English" << std::endl << "2.Mathematic" << std::endl
		<< "3.Biology" << std::endl << "4.History" << std::endl
		<< "5.Psyhics" << std::endl << "6.Chemistry" << std::endl
		<< "7.Ethic/Religion" << std::endl << "8.P.E" << std::endl <<
		"Click K to exit" << std::endl;
	}
	set_ave_of_scho_sub();

}
void Student::show_1(const int n) {
	switch (n) {
	case(1):
		std::cout << "English marks" << std::endl;
		for (int i = 0; i < marks["English"].size(); i++) {
			std::cout << i << ": " << marks["English"][i] << std::endl;
		}
		break;
	case(2):
		std::cout << "Mathematic marks" << std::endl;
		for (int i = 0; i < marks["Mathematic"].size(); i++) {
			std::cout << i << ": " << marks["Mathematic"][i] << std::endl;
		}
		break;
	case(3):
		std::cout << "Biology marks" << std::endl;
		for (int i = 0; i < marks["Biology"].size(); i++) {
			std::cout << i << ": " << marks["Biology"][i] << std::endl;
		}
		break;
	case(4):
		std::cout << "History marks" << std::endl;
		for (int i = 0; i < marks["History"].size(); i++) {
			std::cout << i << ": " << marks["History"][i] << std::endl;
		}
		break;
	case(5):
		std::cout << "Psyhics marks" << std::endl;
		for (int i = 0; i < marks["Psyhics"].size(); i++) {
			std::cout << i << ": " << marks["Psyhics"][i] << std::endl;
		}
		break;
	case(6):
		std::cout << "Chemistry marks" << std::endl;
		for (int i = 0; i < marks["Chemistry"].size(); i++) {
			std::cout << i << ": " << marks["Chemistry"][i] << std::endl;
		}
		break;
	case(7):
		std::cout << "Ethic/Religion marks" << std::endl;
		for (int i = 0; i < marks["Ethic/Religion"].size(); i++) {
			std::cout << i << ": " << marks["Ethic/Religion"][i] << std::endl;
		}
		break;
	case(8):
		std::cout << "P.E marks" << std::endl;
		for (int i = 0; i < marks["P.E"].size(); i++) {
			std::cout << i << ": " << marks["P.E"][i] << std::endl;
		}
		break;

	}
}
void Student::edit(std::string& _name, std::string& _surname, int _class) {
	name = _name;
	surname = _surname;
	class_ = _class;
}
std::ostream& operator<<(std::ostream& os, const Student& x) {

}





