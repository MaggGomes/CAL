#ifndef BUS_STOP_H
#define BUS_STOP_H

#include <string>

using namespace std;

class BusStop {
	int ID;
	string name;
	Localization localization;
 public:
	BusStop(int ID, string name, Localization localization);
	void setID(int ID);
	int getID();
	void setName(string name);
	string getName();
	void setLocalization(Localization localization);
	Localization getLocalization();
};

#endif // BUS_STOP_H
