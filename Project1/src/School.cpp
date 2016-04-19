#include "School.h"

School::School(){};

School::School(string name, string localization){
	this->name = name;
	this->localization = localization;
};

void School::setName(int name){
	this->name = name;
}

string School::getName() const{
	return name;
}

void School::addStudent(const Student &student){
	this->students.push_back(student);
}

vector <Student> School::getStudents() const{
	return students;
}

int School::getNumStudents() const{
	return students.size();
}

void School::setLocalization(string localization){
	this->localization = localization;
}

string School::getLocalization() const{
	return localization;
}

bool School::operator==( const School s) const{
	if (this->name == s.getName())
		return true;
	else
		return false;
}
