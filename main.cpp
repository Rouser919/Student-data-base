#include "Student.h"



int main(void) {
	std::string c{ "John" };
	std::string d{ "Smith" };

	Student b(c,d,2);
	b.modify_marks();
}