#include "SchoolBus.h"

SchoolBus::SchoolBus(){};

void SchoolBus::addBus(const Bus &bus){
	this->bus.push_back(bus);
}

vector <Bus> SchoolBus::getBus() const{
	return bus;
}
