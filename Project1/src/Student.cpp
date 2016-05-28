#include "Student.h"

int Student::lastID = 0;

Student::Student(string name, int nodeID){
	this->name = name;
	this->ID = lastID;
	this->nodeID = nodeID;
	this->nameEditDist = 0;
	this->roadEditDist = 0;
	lastID++;
}

void Student::setName(string name){
	this->name = name;
}

string Student::getName() const{
	return name;
}

void Student::setID(int ID){
	this->ID = ID;
}

int Student::getID() const{
	return ID;
}

void Student::setNodeID(int nodeID){
	this->nodeID = nodeID;
}

int Student::getNodeID() const {
	return nodeID;
}

void Student::setRoad(string road){
	this->road = road;
}


string Student::getRoad() const{
	return road;
}

void Student::setSchoolID(int schoolID){
	this->schoolID = schoolID;
}

int Student::getSchoolID() const{
	return schoolID;
}

void Student::setBusID(int busID){
	this->busID = busID;
}

int Student::getBusID() const{
	return busID;
}

void Student::setNameEditDist(int dist){
	this->nameEditDist = dist;
}

void Student::incNameEditDist(){
	this->nameEditDist++;
}

int Student::getNameEditDist() const{
	return nameEditDist;
}

void Student::setRoadEditDist(int dist){
	this->roadEditDist = dist;
}

void Student::incRoadEditDist(){
	this->roadEditDist++;
}

int Student::getRoadEditDist() const{
	return roadEditDist;
}

bool Student::operator==(Student * student) const{
	if (this->name == student->getName() && this->ID == student->getID())
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, Student * student){
	os << "> ID: ";
	os << student->getID();
	os << " | ";
	os << "Name: ";
	os << student->getName();
	os << " | ";
	os << "Address: ";
	os << student->getRoad();
	os << endl;
	os << "  NODE ID: ";
	os << student->getNodeID();
	os << " | ";
	os << "SCHOOL ID: ";
	os << student->getSchoolID();
	os << " | ";
	os << "BUS ID: ";
	os << student->getBusID();
	os << endl;

	return os;
}
