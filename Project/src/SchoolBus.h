#ifndef SCHOOLBUS_H
#define SCHOOLBUS_H

#include <ctime>
#include <fstream>
#include <algorithm>
#include "Bus.h"
#include "Graphviewer.h"
#include "LoadGraph.h"
#include "Matcher.h"

/**
 * @brief Class that represents the Bus Company
 */
class SchoolBus {
	GraphViewer *gv;
	Graph <int> routesGraph;
	vector <Bus> bus;
	vector <School *> schools;
	vector <Student *> students;
	unordered_map<string, vector<Student *>> studentMap;
	unordered_map<string, vector<RoadT *>> roadMap;
	int nodeID;
public:
	/**
	 * @brief SchooBus's default constructor
	 */
	SchoolBus();

	/**
	 * @brief SchoolBus's constructor
	 *
	 * @param graph of the map to be used
	 */
	SchoolBus(const Graph<int> &graph);

	/**
	 * @brief adds a new bus the company
	 *
	 * @param bus to be added
	 */
	void addBus(const Bus &bus);

	/**
	 * @brief returns the company's bus
	 *
	 * @return bus
	 */
	vector <Bus> getBus() const;

	/**
	 * @brief adds a new school the company
	 *
	 * @param school to be added
	 */
	void addSchool(School * school);

	/**
	 * @brief returns the schools which are operated by the company
	 *
	 * @return schools
	 */
	vector <School *> getSchools() const;

	/**
	 * @brief returns the zone's graph where the company operates
	 *
	 * @return graph
	 */
	Graph <int> getRoutesGraph() const;

	/**
	 * @brief Convertes a vector of integers (vextex->info()) to a vector of the corresponding Vertex
	 *
	 * @param vector with the Vertex info
	 * @return vector with the Vertex
	 */
	vector<Vertex<int>*> getInttoVertex(vector <int> &vec);

	/**
	 * @brief Shows the map
	 */
	void showMap();

	/**
	 * @brief Shows the roads of the map
	 */
	void showRoads();

	/**
	 * @brief Shows the graph with the location of all clients and schools served by the Company
	 */
	void showAllClientsAndSchools();

	/**
	 * @brief Shows the graph
	 */
	void showGraph();

	/**
	 * @brief Shows the location of the School and its students in the graph
	 *
	 * @param school
	 */
	void showSchoolAndStudents(School* school);

	/**
	 * @brief Generate the best route between 2 nodes and passing in some mandatory nodes
	 *
	 * @param srcNode
	 * @param destNode
	 * @param stops
	 */
	void generateRoute(int origin, int dest, vector<int> stops);

	/**
	 * @brief Saves bus to a .csv file
	 */
	void saveBus();

	/**
	 * @brief Saves schools to a .csv file
	 */
	void saveSchools();

	/**
	 * @brief Saves students to a .csv file
	 */
	void saveStudents();

	/**
	 * @brief Saves the info of the bus, schools and students
	 */
	void saveData();

	/**
	 * @brief Loads bus from a .csv file
	 */
	void loadBus();

	/**
	 * @brief Loads schools from a .csv file
	 */
	void loadSchools();

	/**
	 * @brief Loads students from a .csv file
	 */
	void loadStudents();

	/**
	 * @brief Loads all data
	 */
	void loadData();

	/**
	 * @brief Returns the road associted with a nodeID
	 *
	 * @return road
	 */
	string getRoadByID(int roadID) const;

	/**
	 * @brief Menu showing all bus
	 */
	void menuShowBus();

	/**
	 * @brief Menu showing all schools
	 */
	void menuShowSchools();

	/**
	 * @brief Menu showing all students
	 */
	void menuShowStudents();

	/**
	 * @brief Starting menu
	 */
	void menuStarting();

	/**
	 * @brief Searches a school by schoolID
	 *
	 * @param schoolID
	 */
	void searchSchoolID(int schoolID);

	/**
	 * @brief Searches a school by name
	 *
	 * @param name
	 */
	void searchSchoolName(string schoolName);

	/**
	 * @brief Menu to search schools
	 */
	void menuSearchSchool();

	/**
	 * @brief Verifies if a school name is valid
	 *
	 * @param name
	 * @return true if the name is valid
	 */
	bool validSchoolName(const string &name);

	/**
	 * @brief Registers a school's name
	 *
	 * @returns new school name
	 */
	string registerSchoolName();

	/**
	 * @brief Verifies if a nodeID is valid
	 *
	 * @param nodeID
	 * @return true if the nodeID is valid
	 */
	bool validSchoolNodeID(int nodeID);

	/**
	 * @brief Registers school's nodeID
	 *
	 * @returns school nodeID
	 */
	int registerSchoolNodeID();

	/**
	 * @brief Registers a new school
	 */
	void registerNewSchool();

	/**
	 * @brief Menu for school management
	 */
	void menuSchoolManagement();

	/**
	 * @brief Menu for client management
	 */
	void menuClientManagement();

	/**
	 * @brief Menu for searching bus by busID
	 */
	void searchBusID(int busID);

	/**
	 * @brief Menu for searching bus by registration
	 */
	void searchBusReg(string busReg);

	/**
	 * @brief Menu for searching bus
	 */
	void menuSearchBus();

	/**
	 * @brief Registers bus's year
	 *
	 * @returns year of the bus
	 */
	int registerBusYear();

	/**
	 * @brief Registers bus's registration
	 *
	 * @param reg registration of the bus
	 * @returns true if the registration is valid
	 */
	bool validRegistration(const string &reg);

	/**
	 * @brief Registers the bus's registration
	 *
	 * @returns registration of the bus
	 */
	string registerBusRegistration();

	/**
	 * @brief Registers the bus's capacity
	 *
	 * @returns capacity of the bus
	 */
	int registerBusCapacity();

	/**
	 * @brief Verifies if the schoolID associated to the bus is valid
	 *
	 * @param id of the school
	 * @returns true if the id is valid
	 */
	bool validBusSchoolID(int id);

	/**
	 * @brief Associates a school to a bus
	 *
	 * @returns schoolID
	 */
	int registerBusSchool();

	/**
	 * @brief Registers a new bus
	 */
	void registerNewBus();

	/**
	 * @brief Registers student's name
	 *
	 * @returns student's name
	 */
	string registerStudentName();

	/**
	 * @brief Asscoaites a student to a school
	 *
	 * @returns schoolID
	 */
	int registerStudentSchool();

	/**
	 * @brief Verifies if a bus is valid
	 *
	 * @returns true if a bus is valid
	 */
	bool validBus(int stuBus, int schoolID);

	/**
	 * @brief Associates a student to a bus
	 *
	 * @param schoolID of the student's school
	 * @returns busID
	 */
	int registerStudentBus(int schoolID);

	/**
	 * @brief Associates a node to a student
	 *
	 * @param studentNodeID
	 * @param schoolNodeID
	 * @returns true if nodeID is valid
	 */
	bool validStudentNodeID(int studentNodeID, int schoolNodeID);

	/**
	 * @brief Registers student's nodeID
	 *
	 * @param schoolNodeID
	 * @returns student nodeID
	 */
	int registerStudentNode(int schoolNodeID);

	/**
	 * @brief Registers a new client
	 */
	void registerNewClient();

	/**
	 * @brief Searchs a student by his address (road)
	 *
	 * @param road
	 */
	void searchStudentRoad(string studentRoad);

	/**
	 * @brief Searches for a student by name
	 *
	 * @param name
	 */
	void searchStudentName(string studentName);

	/**
	 * @brief Searches for a student by ID
	 *
	 * @param studentID
	 */
	void searchStudentID(int studentID);

	/**
	 * @brief Searchs for a student
	 */
	void menuSearchStudent();

	/**
	 * @brief Menu for bus management
	 */
	void menuBusManagement();

	/**
	 * @brief Chooses the best bus for the student
	 *
	 * @param The node where the student is, and the school where the student belongs
	 */
	int placeStudent(int nodeID,int schoolID,int start);

	/**
	 * @brief Menu to remove connection
	 */
	void menuRemoveConnection();

	/**
	 * @brief Checks if the nodes are connected
	 *
	 * @param The nodes to be checked
	 */
	int validNodes(int node1ID, int node2ID);

	/**
	 * @brief Show graph highlighting the removed connection
	 *
	 * @param Nodes of the connection
	 */
	void showRemovedConnectionGraph(int node1ID, int node2ID);

	/**
	 * @brief Show the students living in a road
	 */
	void showRoadStudents(const string &road);

	/**
	 * @brief Verifies if a student is using a particular Bus to go to the school
	 *
	 * @param bus
	 */
	void searchStudentInBus(Bus &bus);

	/**
	 * @brief Show maps
	 */
	void menuShowMaps();

	/**
	 * @brief Returns student's unordered map
	 *
	 * @return student's unordered map
	 */
	unordered_map<string, vector<Student *>>& getStudentMap();

	/**
	 * @brief Returns road's unordered map
	 *
	 * @return student's unordered map
	 */
	unordered_map<string, vector<RoadT *>>& getRoadMap();
};

#endif // SCHOOLBUS_H
