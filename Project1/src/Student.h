#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
	string name;
	int ID;
	int age;

public:
	Student(string name, int ID, int age);
	void setName(string name);
	string getName();
	void setID(int ID);
	int getID();
	void setAge(int age);
	int getAge();
};

#endif // STUDENT_H
