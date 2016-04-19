#ifndef SCHOOLBUS_H
#define SCHOOLBUS_H

#include "Bus.h"
#include "Utilities.h"
#include "School.h"
#include <vector>
#include <string>

using namespace std;

class SchoolBus {
	vector <Bus> bus;
	vector <School> schools;
public:
	SchoolBus();
	void addBus(const Bus &bus);
	vector <Bus> getBus() const;
	void addSchool(const School &school);
	vector <School> getSchool() const;
	void addStudent(string name, int ID, const BusStop &busStop, School &school);
	void loadData();
	void saveData();
	void menuStarting();
	void menuSchoolManagement();
	void menuClientManagement();
	void menuBusManagement();
};

#endif // SCHOOLBUS_H
