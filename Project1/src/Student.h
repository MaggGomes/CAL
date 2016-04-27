#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Class that represents a student
 */
class Student {
	string name;
	int ID;
	static int lastID;
	int schoolID;
	int busID;
	int nodeID;
public:
	/**
	 * @brief Student's constructor
	 *
	 * @param name of the student
	 * @param nodeID(localization) of the Student
	 */
	Student(string name, int nodeID);

	/**
	 * @brief Sets a new student's name
	 *
	 * @param name to be settled
	 */
	void setName(string name);

	/**
	 * @brief Returns the student's name
	 *
	 * @return name
	 */
	string getName() const;

	/**
	 * @brief Sets a new student's ID
	 *
	 * @param ID to be settled
	 */
	void setID(int ID);

	/**
	 * @brief Returns the student's ID
	 *
	 * @return ID
	 */
	int getID() const;

	/**
	 * @brief Sets a new student's nodeID
	 *
	 * @param nodeID to be settled
	 */
	void setNodeID(int nodeID);

	/**
	 * @brief Returns the student's ID
	 *
	 * @return nodeID
	 */
	int getNodeID() const;

	/**
	 * @brief Sets a new student's schoolID
	 *
	 * @param schoolID to be settled
	 */
	void setSchoolID(int schoolID);

	/**
	 * @brief Returns the student's schoolID
	 *
	 * @return schoolID
	 */
	int getSchoolID() const;

	/**
	 * @brief Sets a new student's busID
	 *
	 * @param schoolID to be settled
	 */
	void setBusID(int busID);

	/**
	 * @brief Returns the student's busID
	 *
	 * @return busID
	 */
	int getBusID() const;

	/**
	 * @brief Overload of the operator == for the class Student
	 *
	 * @returns true if the name and ID of the 2 student are equal
	 */
	bool operator==(Student * student) const;

	/**
	 * @brief Overload of the operator << for the class Student
	 */
	friend ostream& operator<<(ostream& os, Student * student);
};

#endif // STUDENT_H
