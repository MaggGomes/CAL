#include <string>

using namespace std;

class School {
	vector <Student> students;

public:
	School();
	void addStudent(const Student &student);
	vector <Student> getStudents();
	int getNumStudents();
};
