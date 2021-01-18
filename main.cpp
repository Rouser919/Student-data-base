#include "Student.h"



int main(void) {
	std::string c{ "Mateusz" };
	std::string d{ "Stopa" };

	Student b(c,d,2);
	b.modify_marks();
}