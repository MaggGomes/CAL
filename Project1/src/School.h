#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class School {
	string name;
	vector <Student> students;
	string localization;

public:
	School();
	School(string name, string localization);
	void setName(int name);
	string getName() const;
	void addStudent(const Student &student);
	vector <Student> getStudents() const;
	int getNumStudents() const;
	void setLocalization(string localization);
	string getLocalization() const;
	bool operator==(const School s) const;
};
