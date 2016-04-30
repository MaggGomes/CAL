#include "Bus.h"

int Bus::lastID = 0;

Bus::Bus(){}

Bus::Bus(int buildYear, string registration, int capacity){
	this->ID = lastID;
	this->buildYear = buildYear;
	this->registration = registration;
	this->capacity = capacity;
	this->lastID++;
	this->school = NULL;
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

void Bus::addStudent(Student* student){
	this->students.push_back(student);
}

vector<Student*> Bus::getStudents() const{
	return students;
}

void Bus::setSchool(School * school){
	this->school = school;
}

School *  Bus::getSchool() const{
	return school;
}

void Bus::setID(int ID){
	this->ID = ID;
}

int Bus::getID() const {
	return ID;
}

vector<int> Bus::getStops() const{
	vector <int> stops;

	for (size_t i = 0; i < students.size(); i++)
		stops.push_back(students[i]->getNodeID());

	return stops;
}

bool Bus::operator==(const Bus bus) const{
	if (this->registration == bus.getRegistration())
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const Bus& bus){
	os << "> ID: ";
	os << bus.getID();
	os << " | ";
	os << "Registration: ";
	os << bus.getRegistration();
	os << " | ";
	os << "Capacity: ";
	os << bus.getCapacity();
	os << " | ";
	os << "Occupation: ";
	os << bus.getStudents().size();
	os << " | ";
	os << "School ID: ";
	os << bus.getSchool()->getID();
	os << endl;

	return os;
}
