#ifndef SCHOOLBUS_H
#define SCHOOLBUS_H

#include "Graph.h"
#include "Graphviewer.h"
#include "Bus.h"
#include "Utilities.h"
#include <vector>
#include <string>

using namespace std;

class SchoolBus {
	GraphViewer *gv;
	Graph <string> graph;
	vector <Bus> bus;
	vector <School> schools;
public:
	SchoolBus();
	void addBus(const Bus &bus);
	vector <Bus> getBus() const;
	void addSchool(const School &school);
	vector <School> getSchool() const;
	void addStudent(string name, int ID, const string &localization, School &school);
	void loadData();
	void saveData();
	void menuStarting();
	void menuSchoolManagement();
	void menuClientManagement();
	void menuBusManagement();
};

#endif // SCHOOLBUS_H
