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
	string road;
	int nameEditDist;
	int roadEditDist;
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
	 * @brief Sets student's road
	 *
	 * @param road
	 */
	void setRoad(string road);

	/**
	 * @brief Returns student's road
	 *
	 * @return road
	 */
	string getRoad() const;

	/**
	 * @brief Sets a new name's edition distance
	 */
	void setNameEditDist(int dist);

	/**
	 * @brief Increments by 1 the name's edition distance
	 */
	void incNameEditDist();

	/**
	 * @Return name's edition distance
	 *
	 * @return name's edition distance
	 */
	int getNameEditDist() const;

	/**
	 * @brief Sets a new road's edition distance
	 */
	void setRoadEditDist(int dist);

	/**
	 * @brief Increments by 1 the road's edition distance
	 */
	void incRoadEditDist();

	/**
	 * @brief Returns the road's edition distance
	 *
	 * @return the road's edition distance
	 */
	int getRoadEditDist() const;

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
