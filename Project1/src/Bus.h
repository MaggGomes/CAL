#ifndef BUS_H
#define BUS_H

#include <string>

using namespace std;

class Bus {
	int buildYear;
	string registration;
	int capacity;
public:
	Bus(int buildYear, string registration, int capacity);
	void setBuildYear(int year);
	int getBuildYear();
	void setRegistration(string registration);
	string getRegistration();
	void setCapacity(int capacity);
	int getCapacity();
};

#endif // BUS_H
