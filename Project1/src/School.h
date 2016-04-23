#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class School {
	string name;
	vector <Student *> students;
	int ID;
	static int lastID;
	int nodeID;
public:
	School(string name, int nodeID);
	void setName(int name);
	string getName() const;
	void addStudent(Student * student);
	vector <Student*> getStudents() const;
	int getNumStudents() const;
	void setNodeID(int nodeID);
	int getNodeID() const;
	void setID(int id);
	int getID() const;
	bool operator==(School * school) const;
	friend ostream& operator<<(ostream& os, School * school);
};
