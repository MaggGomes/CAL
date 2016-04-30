#include "School.h"

int School::lastID = 0;

School::School(string name, int nodeID){
	this->name = name;
	this->nodeID = nodeID;
	this->ID = lastID;
	lastID++;
};

void School::setName(int name){
	this->name = name;
}

string School::getName() const{
	return name;
}

void School::addStudent(Student *student){
	this->students.push_back(student);
}

vector <Student*> School::getStudents() const{
	return students;
}

int School::getNumStudents() const{
	return students.size();
}

void School::setNodeID(int nodeID){
	this->nodeID = nodeID;
}

int School::getNodeID() const{
	return nodeID;
}

void School::setID(int ID){
	this->ID = ID;
}

int School::getID() const{
	return ID;
}

bool School::operator==(School * school) const{
	if (this->name == school->getName())
		return true;
	else
		return false;
}

// TODO - MOSTRAR COORDENADAS GPS DA MORADA PARA CADA ESCOLA E RESPETIVO NODEID ASSOCIADO
ostream& operator<<(ostream& os, School * school){
	os << "> ID: ";
	os << school->getID();
	os << " | ";
	os << "Name: ";
	os << school->getName();
	os << " | ";
	os << "NODE ID: ";
	os << school->getNodeID();
	os << endl;

	return os;
}
