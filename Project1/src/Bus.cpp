#include "Bus.h"

Bus::Bus(int buildYear, string registration, int capacity){
	this->buildYear = buildYear;
	this->registration = registration;
	this->capacity = capacity;
}

void Bus::setBuildYear(int year){
	this->buildYear = year;
}

int Bus::getBuildYear(){
	return buildYear;
}

void Bus::setRegistration(string registration){
	this->registration = registration;
}

string Bus::getRegistration(){
	return registration;
}

void Bus::setCapacity(int capacity){
	this->capacity = capacity;
}

int Bus::getCapacity(){
	return capacity;
}
