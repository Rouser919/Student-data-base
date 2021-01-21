#include "Student.h"
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <iomanip>
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
	double count;
	int i = 0;
	for (auto &b : marks) {
		count = 0;
		sum = 0;
		for (auto &c : b) {
			sum += c;
			count++;
		}
		if (b.size() == 0) {
			sum = 1;
			count = 1;
		}
		average_of_school_subjects[i]= sum / count;
		i++;
	}
	set_ave_marks();
}
std::string& Student::parse(std::string &x) { 
	int c = 0; 
	for (auto& b : x){ 
		if (!isalpha(b)) { x.erase(x.begin() + c); c--; };
		c++; 
	}
	return x;
}
Student::Student(std::string& _name, std::string& _surname,int _class) {
	name = _name;
	parse(name);
	surname = _surname;
	parse(surname);
	class_ = _class;
	add_marks();
}
Student::Student(std::string& _name, std::string& _surname, int _class, double ave[8], x& b, double aver) {
	name = _name;
	parse(name);
	surname = _surname;
	parse(surname);
	class_ = _class;
	marks = b;
	average = aver;
	std::memcpy(average_of_school_subjects, ave,sizeof(double )*8);

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
	std::memcpy(average_of_school_subjects, x.average_of_school_subjects, sizeof(double)*8);
	set_ave_of_scho_sub();
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
	std::cout << "Please choose subject if you want to new marks" << std::endl
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
					if(marks[x-49].size()==1){
						marks[x - 49][0] = std::stoi(&tmp);
					}
					else {
						marks[x - 49].push_back(std::stoi(&tmp));
					}
					std::cout << "Succesfully added!" << std::endl
						<< "Click x to exit or add new mark" << std::endl;
				}
				else {
					std::cout << "Invalid value! Please write correct mark" << std::endl;
				}
				std::cin >> tmp;
			}
		}
		std::cout << "Please choose subject if you want to new marks" << std::endl
			<< "1.English" << std::endl << "2.Mathematic" << std::endl
			<< "3.Biology" << std::endl << "4.History" << std::endl
			<< "5.Psyhics" << std::endl << "6.Chemistry" << std::endl
			<< "7.Ethic/Religion" << std::endl << "8.P.E" << std::endl <<
			"Click k to exit" << std::endl;
	}
	set_ave_of_scho_sub();
}
void Student::delete_marks(){
	for (auto &b : marks) {
		b.clear();
	}
	set_ave_of_scho_sub();
}
void Student::modify_marks() {
	char x;
	char tmp;
	char tmp_2;
	std::cout << "Please choose subject that you want to modify or erase marks:" << std::endl
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
				if (marks[x-49].size() >= tmp-48 && tmp-48 >= 0) {
					std::cout << "Enter new Value" << std::endl;
					std::cin >> tmp_2;
					if (good_mark(tmp_2)) {
						if (marks[x - 49].size() == 1) {
							marks[x - 49][0] = std::stoi(&tmp);
						}
						else {
							marks[x - 49][tmp - 49] = std::stoi(&tmp_2);
						}
						std::cout << "After change: " << std::endl;
						show_1((x - 49));
					}
					else {
						std::cout << "Invalid value" << std::endl
							<< "Back to main console" << std::endl;
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

		std::cout << "Please choose subject that you want to modify or erase marks:" << std::endl
			<< "1.English" << std::endl << "2.Mathematic" << std::endl
			<< "3.Biology" << std::endl << "4.History" << std::endl
			<< "5.Psyhics" << std::endl << "6.Chemistry" << std::endl
			<< "7.Ethic/Religion" << std::endl << "8.P.E" << std::endl <<
			"Click K to exit" << std::endl;
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
// lambda
void Student::show_student(int n) { 
	auto b = [&n]()->int {
		int c = 0;
		while (n > 0) {
			n /= 10;
			c++;
		}
		return c; 
	};

	int i = b()+1; // because dot
	while (i < 8) {
		std::cout << " ";
		i++;
	}
	std::cout << name;
	i +=name.size();
	while (i < 23) {
		std::cout << " ";
		i++;
	}
	std::cout << surname;
	i += surname.size();
	while (i < 38) {
		std::cout << " ";
		i++;

	}
	std::cout << class_ << "        " <<std::fixed<<std::setprecision(2) << (double)average << std::endl;
} 
void Student::show_for_menu_person() {
	std::cout << name << " " << surname << " Class:" << class_ << " Average of marks:" << average << " "<<std::endl;
	int index = 0;
	for (auto i : marks) {
		std::cout<< subjects[index] << ": " << average_of_school_subjects[index] << " Marks:";
		for (auto b : marks[index]) {
			std::cout << b << ",";
		}
		index++;
		std::cout << std::endl;
	}

}
void Student::edit() {
	std::cout << "Welcome to personal editor" << std::endl;
	char c;
	int tmp;
	std::cout << "Press 1 to edit name, 2 for surname or 3 for edit class. Press x for exit " << std::endl;
	while (std::cin >> c && c != 'x') {
		switch (c - 48) {
		case(1):
			std::cout << "Type name " << std::endl;
			std::cin >> name;
			name[0] = toupper(name[0]);
			parse(name);
			std::cout << "You write " << name <<  std::endl;
			std::cin.clear();
			break;
		case(2):
			std::cout << "Type surname " << std::endl;
			std::cin >> surname;
			surname[0] = toupper(surname[0]);
			parse(surname);
			std::cout << "You write " << surname << std::endl;
			std::cin.clear();
			break;
		case(3):
			std::cout << "Type class " << std::endl;
			std::cin >> tmp;
			if (good_class(tmp)) {
				class_ = tmp;
				std::cout << "You write " << class_ << std::endl;
			}
			else {
				std::cout << "Invalid value" << std::endl;
			}

			std::cin.clear();
			break;
		default:
			std::cin.clear();
			break;
		}
		std::cout << "Press 1 to edit name, 2 for surname or 3 for edit class. Press x for exit " << std::endl;
	}
}
void Student::add_personal() {
	int tmp;
	std::cout << "Type name of Student" << std::endl;
	std::cin >> name;
	parse(name);
	std::cin.clear();
	std::cout << "Type surname of Student" << std::endl;
	std::cin >> surname;
	parse(surname);
	std::cin.clear();
	std::cout << "Type class of Student" << std::endl;
	while (std::cin >> tmp && !good_class(tmp)) {
		std::cout << "Invalid value" << std::endl << "Type again:" << std::endl;
	}
	class_ = tmp;
	std::cin.clear();
}
void Student::write_file_s(std::fstream& x) {
	x << name << " " << surname << " Class:" << class_ << " Average of marks:" << average << " ";
	int index = 0;
	for (auto &i : marks) {
		x << subjects[index] << ": " << average_of_school_subjects[index] << " Marks:";
		for (auto &b : marks[index]) {
			x << b << ",";
		}
		x << 'X';// me control word to find for example in file.txt
		index++;
	}
	x << std::endl << std::endl;

}
std::ostream& operator<<(std::ostream& os, const Student& x) {
	os << x.name << " " << x.surname << " Class:" << x.class_ << " Average of marks:" << x.average << " ";
	int index = 0;
	for (auto i : x.marks) {
		os << subjects[index] << ": " << x.average_of_school_subjects[index] << " Marks:";
		for (auto b : x.marks[index]) {
			os << b << ",";
		}
		index++;
		os << std::endl;
	}
	return os;
}
void Base::change_name_student() {
	std::cout << "Type new name file to write" << std::endl;
	std::cin >> file_name_write;
	std::cin.clear();
	std::cout << "You typed " << file_name_write << " . Succesfully change!" << std::endl;
}
Base::Base() {
	file_name_write = "file.txt";

}
Base::Base(int _count) {
	while (count < _count) {
		data.emplace_back(std::move(std::unique_ptr<Student>(new Student())));
		count++;
	}
	file_name_write = "file.txt";

}	
Base::~Base() {
	sort_by_var(0, 1);
	write_file_b();
};
void Base::menu() {
	show_menu();
	int c;
	while (std::cin >> c && c != 'k') {
		switch (c) {
		case(1):
			add_for_menu();
			data.back()->add_personal();
			data.back()->add_marks();
			break;
		case(2):
			show_students();
			std::cout << "Please type number of Student that you want to modify" << std::endl;
			Sleep(1000);
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
			std::cout << "Please type number of Student that you want to delete"<< std::endl;
			Sleep(1000);
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
			std::cout << "Please type number of Student that you want to add marks" << std ::endl;
			Sleep(1000);
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
			std::cout << "Please type number of Student that you want to modify/delete marks" << std::endl;
			Sleep(1000);
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
			std::cout << "Please type number of Student that you want to delete all marks" << std::endl;
			Sleep(1000);
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
			std::cout << "Please type number of Student that you want to show" << std::endl;
			Sleep(1000);
			show_students();
			std::cin >> c;
			if (validate_for_menu(c)) {
				data[c - 1]->show_for_menu_person();
				Sleep(3000);
			}
			else {
				std::cout << "Invalid value, back to main program" << std::endl;

			}
			break;

		case(8):
			show_students();
			Sleep(1000);
			break;
		case(9):
			show_by_name();
			break;
		case(10):
			show_by_surname();
			break;
		case(11):
			show_by_class();
			break;
		case(12):
			show_by_mark();
			break;
		case(13):
			menu_for_sort();
			break;
		case(14):
			read();
			break;
		case(15):
			write_file_b();
			break;
		case(16):
			change_name_student();
			break;
		default:
			std::cout << "Invalid value, type again" << std::endl;
			break;
		}
		Sleep(1000);
		std::cin.clear();
		show_menu();
	}
}
void Base::menu_for_sort() {
	char i;
	std::cout << "Welcome to sort menu" << std::endl <<
		"1. Sort by name raising" << std::endl << "2. Sort by name falling" << std::endl <<
		"3. Sort by surname raising" << std::endl << "4. Sort by surname falling" << std::endl <<
		"5. Sort by average raising" << std::endl << "6. Sort by average falling" << std::endl <<
		"7. Sort by class raising" << std::endl << "8. Sort by class falling" << std::endl <<
		"Press x to exit" << std::endl << "---------------------------------------------------------------------------------------"
		<< std::endl;
	while (std::cin >> i && i != 'x') {
		switch (i-48) {
		case(1):
			sort_by_str(0, 0);
			break;
		case(2):
			sort_by_str( 1, 0);
			break;
		case(3):
			sort_by_str(0, 1);
			break;
		case(4):
			sort_by_str(1, 1);
			break;
		case(5):
			sort_by_var(0, 0);
			break;
		case(6):
			sort_by_var( 1, 0);
			break;
		case(7):
			sort_by_var( 0, 1);
			break;
		case(8):
			sort_by_var(1, 1);
			break;
		default:
			std::cout << "Invalid value" << std::endl;
			break;
		Sleep(1000);
		std::cin.clear();
		}
		std::cout << "Welcome to sort menu" << std::endl <<
			"1. Sort by name raising" << std::endl << "2. Sort by name falling" << std::endl <<
			"3. Sort by surname raising" << std::endl << "4. Sort by surname falling" << std::endl <<
			"5. Sort by average raising" << std::endl << "6. Sort by average falling" << std::endl <<
			"7. Sort by class raising" << std::endl << "8. Sort by class falling" << std::endl <<
			"Press x to exit" << std::endl << "---------------------------------------------------------------------------------------"
			<< std::endl;
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
	std::cout << " Insert a Student number that you want to delete:" << std::endl;
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
// Lambda power
void Base::sort_by_str(bool slope, bool mode) { // slop 0 fallig slop 1 rise   , mode 0 sort by name mode 1 sort by surname
	/*std::string tmp, tmp_var;
	int index_tmp = 0,index_h=0;
	int i = 0;
	int size = data.size();
	*/
	if (mode == 0 && slope == 0) { //by name falling
		std::sort(data.begin(), data.end(), [](const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) {return a->get_name() < b->get_name(); });
		/*for (auto& c : data) {
			tmp_var = c->get_name();
			index_tmp = i;
			while (index_tmp < size) {
				tmp = data[index_tmp]->get_name();
				if (tmp < tmp_var) {
					std::swap(c, data[index_tmp]);
					tmp_var = tmp;
				}
				index_tmp++;
			}
			i++;
		}*/

	}
	else if (mode == 0 && slope == 1) { // by name raising
		std::sort(data.begin(), data.end(), [](const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) {return a->get_name() > b->get_name(); });
		/*for (auto& c : data) {
			tmp_var = c->get_name();
			index_tmp = i;
			while (index_tmp < size) {
				tmp = data[index_tmp]->get_name();
				if (tmp > tmp_var) {
					std::swap(c, data[index_tmp]);
					tmp_var = tmp;
				}
				index_tmp++;
			}
			i++;
		}
		*/

	}
	else {
		if (mode == 1 && slope == 0) {// by surname falling
			std::sort(data.begin(), data.end(), [](const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) {return a->get_surname() < b->get_surname(); });
			/*
			for (auto& c : data) {
				tmp_var = c->get_surname();
				index_tmp = i;
				while (index_tmp < size) {
					tmp = data[index_tmp]->get_surname();
					if (tmp < tmp_var) {
						std::swap(c, data[index_tmp]);
						tmp_var = tmp;
					}
					index_tmp++;
				}
				i++;
			}
			*/

		}
		else if (mode == 1 && slope == 1 ){ // by surname raising
			std::sort(data.begin(), data.end(), [](const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) {return a->get_surname() > b->get_surname(); });
			/*
			for (auto& c : data) {
				tmp_var = c->get_surname();
				index_tmp = i;
				while (index_tmp < size) {
					tmp = data[index_tmp]->get_surname();
					if (tmp > tmp_var) {
						std::swap(c, data[index_tmp]);
						tmp_var = tmp;
					}
					index_tmp++;
				}
				i++;
			}
		}
		*/
		}

	}
}
void Base::sort_by_var( bool slope, bool mode) { // slop 0 fallig slop 1 rise   , mode 0 sort by average mode 1 sort by class
	/*
	double tmp, tmp_var;
	int index_tmp = 0, index_h = 0;
	int i = 0;
	int size = data.size();
	*/
	
	
	if (mode == 0 && slope == 0) { //by average falling
		std::sort(data.begin(), data.end(), [](const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) {return a->get_average() < b->get_average(); });
		/*
		for (auto& c : data) {
			tmp_var = c->get_average();
			index_tmp = i;
			while (index_tmp < size) {
				tmp = data[index_tmp]->get_average();
				if (tmp < tmp_var) {
					std::swap(c, data[index_tmp]);
					tmp_var = tmp;
				}
				index_tmp++;
			}
			i++;
		}
		*/

	}
	else if (mode == 0 && slope == 1) { // by average raising
		std::sort(data.begin(), data.end(), [](const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) {return a->get_average() > b->get_average(); });
		/*
		for (auto& c : data) {
			tmp_var = c->get_average();
			index_tmp = i;
			while (index_tmp < size) {
				tmp = data[index_tmp]->get_average();
				if (tmp > tmp_var) {
					std::swap(c, data[index_tmp]);
					tmp_var = tmp;
				}
				index_tmp++;
			}
			i++;
		}
		*/
	}
	else {
		if (mode == 1 && slope == 0) {// by class falling
			std::sort(data.begin(), data.end(), [](const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) {return a->get_class() < b->get_class(); });
			/*
			for (auto& c : data) {
				tmp_var = c->get_class();
				index_tmp = i;
				while (index_tmp < size) {
					tmp = data[index_tmp]->get_class();
					if (tmp < tmp_var) {
						std::swap(c, data[index_tmp]);
						tmp_var = tmp;
					}
					index_tmp++;
				}
				i++;
			}
			*/

		}
		else if(mode==1 && slope==1){ // by class raising
			std::sort(data.begin(), data.end(), [](const std::unique_ptr<Student>& a, const std::unique_ptr<Student>& b) {return a->get_class() > b->get_class(); });
			/*
			for (auto& c : data) {
				tmp_var = c->get_class();
				index_tmp = i;
				while (index_tmp < size) {
					tmp = data[index_tmp]->get_class();
					if (tmp > tmp_var) {
						std::swap(c, data[index_tmp]);
						tmp_var = tmp;
					}
					index_tmp++;
				}
				i++;
			}
			*/
		}


	}
}
void Base::show_menu() {
	std::cout << "			Welcome to main menu of the program" << std::endl
		<< "---------------------------------------------------------------------------------------" << std::endl << std::endl
		<< "				Made by Mateusz Stopa" << std::endl << "---------------------------------------------------------------------------------------" << std::endl << std::endl
		<< "Select options that you want:" << std::endl << "1.Add Student" << std::endl <<
		"2.Modify Student" << std::endl << "3.Remove Student" << std::endl << "4.Add Marks" << std::endl << "5.Modify marks/Delete marks" << std::endl << "6.Delete all marks of Student" << std::endl
		<< "7.Show Student" << std::endl << "8.Show all Students" << std::endl
		<< "9.Show all Students by name" << std::endl << "10.Show all Students by surname" << std::endl <<
		"11.Show all Students by class" << std::endl << "12.Show all Students by above input average" << std::endl <<
		"13.Menu sort" << std::endl <<
		"14.Read base data from file" << std::endl << "15.Write base data to file" << std::endl << "16.Specify name of file to write" << std::endl <<
		"Press k to exit" << std::endl << std::endl << "---------------------------------------------------------------------------------------"<<std::endl
		<< "At the end of the program, program will sort Students by class raising and autosave." << std::endl <<
		"Notice: Autosave will automate save base data to file: " << file_name_write << " at the end of the program" << std::endl;

}
void Base::show_tab() {
	std::cout << "Students list:" << std::endl << "--------------------------------------------------------------------------------------"
		<< std::endl << "--------------------------------------------------------------------------------------" << std::endl <<
		"Nr.	 Name	        Surname        Class	Average" << std::endl << "--------------------------------------------------------------------------------------" << std::endl;
}
void Base::show_by_name() {
	std::cout << "Type name of Student:" << std::endl;
	std::string tmp;
	std::cin >> tmp;
	short i = 1;
	show_tab();
	for (auto& c : data) {
		if (c->comp_name(tmp)) {
			std::cout << i << ". ";
			c->show_student(i);
			i++;
		}
	}
	std::cout << std::endl;
}
void Base::show_by_surname() {
	std::cout << "Type surname of Student:" << std::endl;
	std::string tmp;
	std::cin >> tmp;
	short i = 1;
	show_tab();
	for (auto& c : data) {
		if (c->comp_surname(tmp)) {
			std::cout << i << ". ";
			c->show_student(i);
			i++;
		}
	}
	std::cout << std::endl;
}
void Base::show_by_class() {
	std::cout << "Type class" << std::endl;
	short tmp;
	std::cin >> tmp;
	short i = 1;
	if (tmp>0 && tmp<5 ) {
		show_tab();
		for (auto& c : data) {
			if (c->comp_class(tmp)) {
				std::cout << i << ". ";
				c->show_student(i);
				i++;
			}
		}
	}
	else {
		std::cout << "Invalid value" << std::endl;
	}
	std::cout << std::endl;

}
void Base::show_by_mark() {
	std::cout << "Write the average from which shows" << std::endl;
	double tmp;
	std::cin >> tmp;
	short i = 1;
	if ( tmp > 0 && tmp < 6) {
		show_tab();
		for (auto& c : data) {
			if (c->comp_mark(tmp)) {
				std::cout << i << ". ";
				c->show_student(i);
				i++;
			}
		}
	}
	else {
		std::cout << "Invalid value" << std::endl;
	}
	std::cout << std::endl;

}
void Base::show_students() {
	int i = 1;
	show_tab();
	for(auto &b:data) {
		std::cout << i << ". ";
		b->show_student(i);
		i++;
	}
	std::cout << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Base& x){
	os << (Student&)x;
	return os;
}
void Base::read() {
	std::cout << "Write there name of your data base" << std::endl;
	std::cin >> file_name_read;
	std::ifstream file;
	file.open(file_name_read, std::ios::in);
	std::string tmp;
	std::string tmp_name, tmp_surname;
	int tmp_class;
	double tmp_average;
	double tmp_averages_subjects[8];
	std::array<std::vector<double>,8> c;
	int  index_o;
	int max_mark, tmp_mark;
	int count_x = 0;
	int tmp_of_good_mark;
	double tmp_of_good_average;
	while (std::getline(file, tmp)) {
		if (tmp.size() > 4) {
			for (auto& x : c) {
				x.clear();
			}
			count_x = 0;
			index_o = tmp.find(' ');
			tmp_name = tmp.substr(0, index_o);
			tmp.erase(0, index_o+1 ); //// remeber of one space; if needed +1 all index_o
			index_o = tmp.find(' ');
			tmp_surname = tmp.substr(0, index_o );
			tmp.erase(0, index_o + 6+1); // because one space+ "class:" =7 pieces
			index_o = tmp.find(' ');
			tmp_class = std::stoi(tmp);
			tmp.erase(0, index_o + 17+1);// because " Average of marks:" 18 pieces
			index_o = tmp.find(' ');
			tmp_average = std::stod(tmp);
			tmp.erase(0, index_o+1);
			while (count_x < 8) {
				index_o = tmp.find(' ');
				tmp.erase(0, index_o+1);
				tmp_of_good_average = std::stod(tmp);
				if(tmp_of_good_average > 0 && tmp_of_good_average < 7) tmp_averages_subjects[count_x] =tmp_of_good_average;
				index_o = tmp.find(':');
				tmp.erase(0, index_o + 1);
				tmp_mark = 0;
				max_mark = tmp.find('X');
				while (tmp_mark < max_mark) { // i use it for good validate marks
					tmp_of_good_mark=std::stoi(tmp);
					if (tmp_of_good_mark > 0 && tmp_of_good_mark <7)c[count_x].push_back(std::stoi(tmp));
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
void Base::write_file_b() {
	int i = 0;
	std::fstream file;
	file.open(file_name_write, std::ios::out);
	for (auto& b : data) {
		b->write_file_s(file);
	}
	std::cout << "Succesfully writed!" << std::endl;
	file.close();
}





