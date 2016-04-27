#include <string>
#include <vector>
#include "Student.h"

using namespace std;

/**
 * @brief Class that represents a school
 */
class School {
	string name;
	vector <Student *> students;
	int ID;
	static int lastID;
	int nodeID;
public:
	/**
	 * @brief School's constructor
	 *
	 * @param name of the school
	 * @param nodeId localization of the school
	 */
	School(string name, int nodeID);

	/**
	 * @brief Sets a new name to the school
	 *
	 * @param name to be settled
	 */
	void setName(int name);

	/**
	 * @brief Returns school's name
	 *
	 * @return name
	 */
	string getName() const;

	/**
	 * @brief Adds a new student to the school
	 *
	 * @param student to be added to the school
	 */
	void addStudent(Student * student);

	/**
	 * @brief Returns the school's students
	 *
	 * @return the students
	 */
	vector <Student*> getStudents() const;

	/**
	 * @brief Returns the number of students of the school
	 *
	 * @return the number of students
	 */
	int getNumStudents() const;

	/**
	 * @brief Sets a new school's nodeID (localization)
	 *
	 * @param nodeID to be settled
	 */
	void setNodeID(int nodeID);

	/**
	 * @brief Returns the nodeID of the school
	 *
	 * @return the nodeID
	 */
	int getNodeID() const;

	/**
	 * @brief Sets a new school's ID (localization)
	 *
	 * @param ID to be settled
	 */
	void setID(int ID);

	/**
	 * @brief Returns the ID of the school
	 *
	 * @return the ID
	 */
	int getID() const;

	/**
	 * @brief Overload of the operator == for the class School
	 *
	 * @returns true if the name, ID and nodeID of the 2 schools are equal
	 */
	bool operator==(School * school) const;

	/**
	 * @brief Overload of the operator << for the class School
	 */
	friend ostream& operator<<(ostream& os, School * school);
};
