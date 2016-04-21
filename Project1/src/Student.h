#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
	string name;
	int ID;
	string localization;
	int nodeID;
public:
	Student(string name, int ID, const string &localization);
	void setName(string name);
	string getName() const;
	void setID(int ID);
	int getID() const;
	void setLocalization(const string &localization);
	string getLocalization() const;
	bool operator==(const Student s) const;
	friend ostream& operator<<(ostream& os, const Student& student);
};

#endif // STUDENT_H
