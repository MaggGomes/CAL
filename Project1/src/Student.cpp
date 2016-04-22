#include "Student.h"

int Student::lastID = 0;

Student::Student(string name, int nodeID, const string &localization){
	this->name = name;
	this->ID = lastID;
	this->nodeID = nodeID;
	this->localization = localization;
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

void Student::setLocalization(const string &localization){
	this->localization = localization;
}

string Student::getLocalization() const{
	return localization;
}

bool Student::operator==(const Student s) const{
	if (this->name == s.getName() && this->ID == s.getID())
		return true;
	else
		return false;
}

// TODO - MOSTRAR COORDENADAS GPS DA MORADA PARA CADA ALUNO E RESPETIVO NODEID ASSOCIADO
ostream& operator<<(ostream& os, const Student& student){
	os << "> ID: ";
	os << student.getID();
	os << " // ";
	os << "Name: ";
	os << student.getName();
	os << endl;

	return os;
}
