#include "Student.h"

Student::Student(string name, int ID, int age){
	this->name = name;
	this->ID = ID;
	this->age = age;
}

void Student::setName(string name){
	this->name = name;
}

string Student::getName(){
	return name;
}

void Student::setID(int ID){
	this->ID = ID;
}

int Student::getID(){
	return ID;
}

void Student::setAge(int age){
	this->age = age;
}

int Student::getAge(){
	return age;
}