#include "Bus.h"

Bus::Bus(int buildYear, string registration, int capacity){
	this->buildYear = buildYear;
	this->registration = registration;
	this->capacity = capacity;
}

void Bus::setBuildYear(int year){
	this->buildYear = year;
}

int Bus::getBuildYear() const{
	return buildYear;
}

void Bus::setRegistration(string registration){
	this->registration = registration;
}

string Bus::getRegistration() const{
	return registration;
}

void Bus::setCapacity(int capacity){
	this->capacity = capacity;
}

int Bus::getCapacity() const{
	return capacity;
}

void Bus::setSchool(const School &school){
	this->school = school;
}

School Bus::getSchool() const{
	return school;
}

void Bus::addStudent(const Student &student){
	this->students.push_back(student);
}

vector<Student> Bus::getStudents() const{
	return students;
}

bool Bus::operator==(const Bus bus) const{
	if (this->registration == bus.getRegistration())
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const Bus& bus){
	os << "> Registration: ";
	/*os << bus.getRegistration();
	os << " :::: ";
	os << "Capacity: ";
	os << bus.getCapacity();
	os << " :::: ";
	os << "Current occupation: ";
	os << bus.getStudents().size();
	os << endl;*/

	return os;
}
