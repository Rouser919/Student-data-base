#include "Student.h"
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <windows.h>
int Base::count = 0;
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
Student::Student(std::string& _name, std::string& _surname, int _class, double ave[8], x& b, double aver) {
	name = _name;
	surname = _surname;
	class_ = _class;
	marks = b;
	average = aver;
	std::memcpy(average_of_school_subjects, ave, 8);

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
	average = x.average;
	std::memcpy(average_of_school_subjects, x.average_of_school_subjects, 8);
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
void Student::show_student(){
	std::cout << name << " " << surname << " " << average << std::endl;
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
std::string &Student::copy() { // in feature delete, now for testing
	std::string data;
	data+= name + " " +surname + " Class:"+ std::to_string(class_) + " Average of marks:" + std::to_string(average) + " ";
	int index = 0;
	for (auto i : marks) {
		data += subjects[index] + ": " + std::to_string(average_of_school_subjects[index]) + " Marks:";
		for (auto b : marks[index]) {
			data += std::to_string( b) + ",";
		}
		data += 'X';
		data += '\n' + '\n';
		index++;
	}
	return data;

}
std::ostream& operator<<(std::ostream& os, const Student& x) {
	os << x.name << " " << x.surname << " Class:" << x.class_ << " Average of marks:" << x.average << " ";
	int index = 0;
	for (auto i : x.marks) {
		os << subjects[index] << ": " << x.average_of_school_subjects[index] << " Marks:";
		for (auto b : x.marks[index]) {
			os << b << ",";
		}
		os << 'X';// me control word to find for example in file.txt
		os << std::endl << std::endl;
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
	void read();
	void write();
*/
Base::Base() {
	std::unique_ptr<Student> ptr2x( new Student());
	data.emplace_back(std::move(ptr2x)); 
	count++;
}
Base::Base(int _count) {
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
		"2.Modify Student" << std::endl << "3.Remove Student" <<"4.Add Marks"<<std::endl<<"5.Modify marks/Delete marks"<<std::endl << "6.Delete all marks of student"<<std::endl<< "7.Show all Students" << std::endl
		<< "8.Show all Students by name" << std::endl << "9.Show all Students by surname" << std::endl <<
		"10.Show all Students by class" << std::endl << "11.Show all Students by best average mark" << std::endl <<
		"12.Read base data from file" << std::endl << "13.Write base data to file" << std::endl <<
		std::endl << "Notice: Autosave will automate save base data to file base.txt at the end of the program" << std::endl;
	int c;
	while (std::cin >> c && c != 'k') {
		switch (c) {
		case(1):
			add_for_menu();
			data.back()->edit();
			data.back()->add_marks();
			break;
		case(2):
			std::cout << "Please type number of student that you want to modify";
			show_students();
			std::cin >> c;
			if (validate_for_menu(c)) {
				data[c - 1]->edit();
				std::cout << "Succesfully modify!" << std::endl;
			}
			else {
				std::cout << "Invalid value, back to main program" << std::endl;
			}
			break;
		case(3):
			std::cout << "Please type number of student that you want to delete";
			show_students();
			std::cin >> c;
			if (validate_for_menu(c)) {
				data.erase(data.begin() + c - 1);
				std::cout << "Succesfully deleted!" << std::endl;
			}
			else {
				std::cout << "Invalid value, back to main program" << std::endl;
			}
			break;
		case(4):
			std::cout << "Please type number of student that you want to add marks";
			show_students();
			std::cin >> c;
			if (validate_for_menu(c)) {
				data[c - 1]->add_marks();
			}
			else {
				std::cout << "Invalid value, back to main program" << std::endl;
			}
			break;
		case(5):
			std::cout << "Please type number of student that you want to modify/delete marks";
			show_students();
			std::cin >> c;
			if (validate_for_menu(c)) {
				data[c - 1]->modify_marks();
			}
			else {
				std::cout << "Invalid value, back to main program" << std::endl;
			}
			break;
		case(6):
			std::cout << "Please type number of student that you want to delete all marks";
			show_students();
			std::cin >> c;
			if (validate_for_menu(c)) {
				data[c - 1]->delete_marks();
			}
			else {
				std::cout << "Invalid value, back to main program" << std::endl;
			}
			break;
		case(7):
			break;
		case(8):
			break;
		case(9):
			break;
		case(10):
			break;
		default:
			std::cout << "Invalid value, type again" << std::endl;
			Sleep(3);
			break;
		}
		std::cin.clear();
		std::cout << "Welcome to main menu of the program" << std::endl
			<< "---------------------------------------------------------------------------------------" << std::endl << std::endl
			<< "Select options that you want:" << std::endl << "1.Add Student" << std::endl <<
			"2.Modify Student" << std::endl << "3.Remove Student" << "4.Add Marks" << std::endl << "5.Modify marks/Delete marks" << std::endl << "6.Delete all marks of student" << std::endl << "7.Show all Students" << std::endl
			<< "8.Show all Students by name" << std::endl << "9.Show all Students by surname" << std::endl <<
			"10.Show all Students by class" << std::endl << "11.Show all Students by best average mark" << std::endl <<
			"12.Read base data from file" << std::endl << "13.Write base data to file" << std::endl <<
			std::endl << "Notice: Autosave will automate save base data to file base.txt at the end of the program" << std::endl;
	}
}
void Base::add_for_menu() {
	data.emplace_back(std::move(std::unique_ptr<Student>(new Student())));
	count++;

}
void Base::add_for_read_file(const Student &x) {
	data.emplace_back(std::move(std::unique_ptr<Student> (new Student(x))));
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
void Base::show_students() {
	int i = 1;
	std::cout << "Students list:" << std::endl << "-------------------------------------------" 
		<< std::endl<<"-------------------------------------------"<< std::endl;
	for (auto& b : data) {
		std::cout << i << ". ";
		b->show_student();
	}
}
std::ostream& operator<<(std::ostream& os, const Base& x){
	os << (Student&)x;
	return os;
}

void Base::read() {
	std::cout << "Write there name of your data base" << std::endl;
	std::cin >> file_name;
	std::ifstream file;
	file.open(file_name, 'r');
	std::string tmp;
	std::string tmp_name, tmp_surname;
	int tmp_class;
	double tmp_average;
	double tmp_averages_subjects[8];
	std::array<std::vector<double>, 8> c{};
	int  index_o;
	int max_mark, tmp_mark;
	int count_x = 0;
	while (std::getline(file, tmp)) {
		if (tmp.size() > 4) {
			index_o = tmp.find(' ');
			tmp_name = tmp.substr(0, index_o);
			tmp.erase(0, index_o ); //// remeber of one space; if needed +1 all index_o
			index_o = tmp.find(' ');
			tmp_surname = tmp.substr(0, index_o );
			tmp.erase(0, index_o + 6); // because one space+ "class:" =7 pieces
			index_o = tmp.find(' ');
			/*
				os << x.name << " " << x.surname << " Class:" << x.class_ << " Average of marks:" << x.average << " ";
	int index = 0;
	for (auto i : x.marks) {
		os << subjects[index] << ": " << x.average_of_school_subjects[index] << " Marks:";
		for (auto b : x.marks[index]) {
			os << b << ",";
		}
		os << std::endl << std::endl;
		index++;
	}
	return os;*/
			tmp_class = std::stoi(tmp);
			tmp.erase(0, index_o + 17);// because " Average of marks:" 18 pieces
			index_o = tmp.find(' ');
			tmp_average = std::stod(tmp);
			tmp.erase(0, index_o);
			while (count_x < 8) {
				index_o = tmp.find(' ');
				tmp_averages_subjects[count_x] = std::stod(tmp);
				tmp.erase(0, index_o);
				index_o = tmp.find(':');
				tmp_mark = 0;
				max_mark = tmp.find('X');
				while (tmp_mark < max_mark) { // i use it for good validate marks
					c[count_x].push_back(std::stoi(tmp));
					tmp.erase(0, 2);
					tmp_mark += 2;
				}
				count_x++;	
			}
			add_for_read_file(Student(tmp_name,tmp_surname,tmp_class,tmp_averages_subjects,c,tmp_average));
			count++;
		}
	}
	file.close();
}
void Base::write() {
	int i = 0;
	std::fstream file;
	file.open(file_name, 'w+');
	while (i < count) {
		file<< data[count];
		//std::cout << data[count]->copy();
		count++;
	}
	file.close();
}





