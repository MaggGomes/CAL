#ifndef SCHOOLBUS_H
#define SCHOOLBUS_H

#include "Graph.h"
#include "Graphviewer.h"
#include "Bus.h"
#include "Utilities.h"
#include <vector>
#include <string>
#include <sstream>

class SchoolBus {
	GraphViewer *gv;
	Graph <int> routesGraph;
	vector <Bus> bus;
	vector <School> schools;
	int nodeID = 1;
public:
	SchoolBus();
	SchoolBus(const Graph<int> &graph);
	void addBus(const Bus &bus);
	vector <Bus> getBus() const;
	void addSchool(const School &school);
	vector <School> getSchool() const;
	void addStudent(string name, int ID, const string &localization, School &school);
	Graph <int> getRoutesGraph() const;
	void showGraph(unsigned int srcNode, unsigned int destNod);
	void loadData();
	void saveData();
	void menuStarting();
	void menuSchoolManagement();
	void menuClientManagement();
	void menuBusManagement();
};

#endif // SCHOOLBUS_H
