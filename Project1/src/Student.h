#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
	string name;
	int ID;
	static int lastID;
	int schoolID;
	int busID;
	int nodeID;
public:
	Student(string name, int nodeID);
	void setName(string name);
	string getName() const;
	void setID(int ID);
	int getID() const;
	void setNodeID(int nodeID);
	int getNodeID() const;
	void setSchoolID(int schoolID);
	int getSchoolID() const;
	void setBusID(int busID);
	int getBusID() const;
	bool operator==(Student * student) const;
	friend ostream& operator<<(ostream& os, Student * student);
};

#endif // STUDENT_H
