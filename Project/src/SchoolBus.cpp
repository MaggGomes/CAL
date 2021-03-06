#include "SchoolBus.h"

using namespace std;

SchoolBus::SchoolBus(){
	nodeID = 1;
	loadData();
	this->routesGraph.floydWarshallShortestPath();
};

SchoolBus::SchoolBus(const Graph<int> &graph){
	nodeID = 1;
	loadData();
	this->routesGraph = graph;
	this->routesGraph.floydWarshallShortestPath();
}

void SchoolBus::addBus(const Bus &bus){
	this->bus.push_back(bus);
}

vector <Bus> SchoolBus::getBus() const{
	return bus;
}

void SchoolBus::addSchool(School * school){
	this->schools.push_back(school);
}

vector <School *> SchoolBus::getSchools() const{
	return schools;
}

Graph <int> SchoolBus::getRoutesGraph() const{
	return routesGraph;
}

void SchoolBus::showMap(){
	gv = new GraphViewer(800, 600, true);
	gv->setBackground("res/mapa.jpg");
	gv->createWindow(800, 600);
	gv->rearrange();
}

void SchoolBus::showAllClientsAndSchools(){

	// Get network of all nodes of the graph
	vector<Vertex<int>*> routes = routesGraph.getVertexSet();

	gv = new GraphViewer(WIDTH_SIZE, HEIGHT_SIZE, false);
	gv->createWindow(WIDTH_SIZE, HEIGHT_SIZE);
	gv->defineVertexColor("CYAN");
	gv->defineEdgeCurved(false);

	// Creating the nodes
	for (size_t i = 0; i < routes.size(); i++){
		gv->addNode(routes[i]->getInfo(), routes[i]->getX(), routes[i]->getY());

		for (size_t j = 0; j < schools.size(); j++){
			if (routes[i]->getInfo() == schools[j]->getNodeID()){
				// Prints school's icon
				gv->setVertexIcon(routes[i]->getInfo(), "res/schoolIcon.png");
				break;
			}

			for (size_t k = 0; k < schools[j]->getStudents().size(); k++){
				if (schools[j]->getStudents()[k]->getNodeID() == routes[i]->getInfo()){
					// Prints student's icon
					gv->setVertexIcon(routes[i]->getInfo(), "res/studentIcon.png");
					break;
				}
			}
		}

		// Prints bus station's icon
		if (routes[i]->getInfo() == this->nodeID)
			gv->setVertexIcon(routes[i]->getInfo(), "res/busIcon.png");
		else
			gv->setVertexSize(routes[i]->getInfo(), 8);

		routes[i]->gvNodeID = routes[i]->getInfo();
	}

	// Creating the edges
	unsigned int counter = 0;
	for (size_t i = 0; i < routes.size(); i++){
		for (int unsigned j = 0; j < routes[i]->adj.size(); j++){
			gv->addEdge(counter++, routes[i]->gvNodeID,
					routes[i]->adj[j].getDest()->gvNodeID,
					EdgeType::UNDIRECTED);
			if (j > 0){
				if (routes[i]->adj[j].getName() != routes[i]->adj[j-1].getName())
					gv->setEdgeLabel(counter, routes[i]->adj[j].getName());
			}
			gv->setEdgeThickness(counter, 5);
			gv->setEdgeColor(counter, "LIGHT_GRAY");
			routes[i]->adj[j].setGvEdgeID(counter);
		}
	}

	gv->rearrange();

}

void SchoolBus::showRoads(){

	// Get network of all nodes of the graph
	vector<Vertex<int>*> routes = routesGraph.getVertexSet();

	gv = new GraphViewer(WIDTH_SIZE, HEIGHT_SIZE, false);
	gv->createWindow(WIDTH_SIZE, HEIGHT_SIZE);
	gv->defineVertexColor("CYAN");
	gv->defineEdgeCurved(false);

	// Creating the nodes
	for (size_t i = 0; i < routes.size(); i++){
		gv->addNode(routes[i]->getInfo(), routes[i]->getX(), routes[i]->getY());
		gv->setVertexSize(routes[i]->getInfo(), 8);
		routes[i]->gvNodeID = routes[i]->getInfo();
	}

	// Creating the edges
	unsigned int counter = 0;
	for (size_t i = 0; i < routes.size(); i++){
		for (int unsigned j = 0; j < routes[i]->adj.size(); j++){
			gv->addEdge(counter++, routes[i]->gvNodeID,
					routes[i]->adj[j].getDest()->gvNodeID,
					EdgeType::UNDIRECTED);
			gv->setEdgeThickness(counter, 5);
			gv->setEdgeColor(counter, "LIGHT_GRAY");
			routes[i]->adj[j].setGvEdgeID(counter);
		}
	}

	gv->rearrange();

}

void SchoolBus::showGraph(){

	gv = new GraphViewer(WIDTH_SIZE, HEIGHT_SIZE, false);
	gv->createWindow(WIDTH_SIZE, HEIGHT_SIZE);
	gv->defineVertexColor("CYAN");
	gv->defineEdgeColor("LIGHT_GRAY");
	gv->defineEdgeCurved(false);

	// Get network of all nodes of the graph
	vector<Vertex<int>*> routes = routesGraph.getVertexSet();

	// Creating the nodes
	for (size_t i = 0; i < routes.size(); i++){
		gv->addNode(routes[i]->getInfo(), routes[i]->getX(), routes[i]->getY());
		gv->setVertexSize(routes[i]->getInfo(), 8);
		routes[i]->gvNodeID = routes[i]->getInfo();
	}

	// Creating the edges
	unsigned int counter = 0;
	for (unsigned int i = 0; i < routes.size(); i++){
		for (int unsigned j = 0; j < routes[i]->adj.size(); j++){
			gv->addEdge(counter++, routes[i]->gvNodeID,
					routes[i]->adj[j].getDest()->gvNodeID,
					EdgeType::DIRECTED);
			gv->setEdgeThickness(counter, 5);
			routes[i]->adj[j].setGvEdgeID(counter);
		}
	}

	gv->rearrange();
}

void SchoolBus::showSchoolAndStudents(School* school){

	// Get network of all nodes of the graph
	vector<Vertex<int>*> routes = routesGraph.getVertexSet();

	gv = new GraphViewer(WIDTH_SIZE, HEIGHT_SIZE, false);
	gv->createWindow(WIDTH_SIZE, HEIGHT_SIZE);
	gv->defineVertexColor("CYAN");
	gv->defineEdgeCurved(false);

	// Creating the nodes
	for (size_t i = 0; i < routes.size(); i++){
		gv->addNode(routes[i]->getInfo(), routes[i]->getX(), routes[i]->getY());

		// Prints student's icon
		for (size_t j = 0; j < school->getStudents().size(); j++)
			if (school->getStudents()[j]->getNodeID() == routes[i]->getInfo())
				gv->setVertexIcon(routes[i]->getInfo(), "res/studentIcon.png");

		// Prints bus station's icon
		if (routes[i]->getInfo() == this->nodeID)
			gv->setVertexIcon(routes[i]->getInfo(), "res/busIcon.png");

		// Prints school's icon
		else if (routes[i]->getInfo() == school->getNodeID())
			gv->setVertexIcon(routes[i]->getInfo(), "res/schoolIcon.png");
		else
			gv->setVertexSize(routes[i]->getInfo(), 8);

		routes[i]->gvNodeID = routes[i]->getInfo();
	}

	// Creating the edges
	unsigned int counter = 0;
	for (size_t i = 0; i < routes.size(); i++){
		for (int unsigned j = 0; j < routes[i]->adj.size(); j++){
			gv->addEdge(counter++, routes[i]->gvNodeID,
					routes[i]->adj[j].getDest()->gvNodeID,
					EdgeType::UNDIRECTED);
			gv->setEdgeThickness(counter, 5);
			gv->setEdgeColor(counter, "LIGHT_GRAY");
			routes[i]->adj[j].setGvEdgeID(counter);
		}
	}

	gv->rearrange();

}

vector<Vertex<int>*> SchoolBus::getInttoVertex(vector <int> &vec){
	vector<Vertex<int>*> temp;
	vector<Vertex<int>*> routes = this->routesGraph.getVertexSet();

	for (unsigned int i = 0; i < vec.size(); i++){
		for (unsigned int j = 0; j < routes.size(); j++){
			if (routes[j]->getInfo() == vec[i]){
				if (temp.size()>0){
					if (temp[temp.size()-1]->getInfo()!=routes[j]->getInfo())
						temp.push_back(routes[j]);
				}
				else
					temp.push_back(routes[j]);
				break;
			}
		}
	}

	return temp;
}

void SchoolBus::generateRoute(int origin, int dest, vector<int> stops){

	vector <int> bestRoute = this->routesGraph.getShortestPathMultiPoints(origin, dest,stops);

	// Vector with the info of the nodes that the best route uses
	vector <int> finalRoute;

	for (size_t i = 0; i < bestRoute.size()-1; i++){
		vector <int> temp = this->routesGraph.getfloydWarshallPath(bestRoute[i], bestRoute[i+1]);
		finalRoute.insert(finalRoute.end(), temp.begin(), temp.end());
	}

	// Final vector with the nodes of the best route
	vector<Vertex<int>*> path = getInttoVertex(finalRoute);

	// Get network of all nodes of the graph
	vector<Vertex<int>*> routes = routesGraph.getVertexSet();

	gv = new GraphViewer(WIDTH_SIZE, HEIGHT_SIZE, false);
	gv->createWindow(WIDTH_SIZE, HEIGHT_SIZE);
	gv->defineVertexColor("CYAN");
	gv->defineEdgeCurved(false);

	// Creating the nodes
	for (size_t i = 0; i < routes.size(); i++){
		gv->addNode(routes[i]->getInfo(), routes[i]->getX(), routes[i]->getY());

		// Prints student's icon
		for (size_t j = 0; j < stops.size(); j++)
			if (stops[j] == routes[i]->getInfo())
				gv->setVertexIcon(routes[i]->getInfo(), "res/studentIcon.png");

		// Prints bus station's icon
		if (routes[i]->getInfo() == origin)
			gv->setVertexIcon(routes[i]->getInfo(), "res/busIcon.png");

		// Prints school's icon
		else if (routes[i]->getInfo() == dest)
			gv->setVertexIcon(routes[i]->getInfo(), "res/schoolIcon.png");
		else
			gv->setVertexSize(routes[i]->getInfo(), 8);

		routes[i]->gvNodeID = routes[i]->getInfo();
	}

	// Creating the edges
	unsigned int counter = 0;
	for (size_t i = 0; i < routes.size(); i++){
		for (int unsigned j = 0; j < routes[i]->adj.size(); j++){
			gv->addEdge(counter++, routes[i]->gvNodeID,
					routes[i]->adj[j].getDest()->gvNodeID,
					EdgeType::DIRECTED);
			gv->setEdgeThickness(counter, 5);
			gv->setEdgeColor(counter, "LIGHT_GRAY");
			routes[i]->adj[j].setGvEdgeID(counter);
		}
	}

	counter = 10000;
	for (size_t i = 0; i < path.size()-1; i++){
		for (size_t j = 0; j < path[i]->adj.size(); j++){
			if (path[i]->adj[j].getDest()->gvNodeID == path[i+1]->gvNodeID){
				gv->addEdge(counter++, path[i]->gvNodeID, path[i+1]->gvNodeID, EdgeType::DIRECTED);
				gv->setEdgeColor(counter, "GREEN");
				gv->setEdgeThickness(counter, 8);
				break;
			}
		}
	}

	gv->rearrange();
}

void SchoolBus::saveBus(){
	ofstream file;

	remove("res/bus.csv");
	file.open("res/bus.csv");

	for (size_t i = 0; i < bus.size(); i++){
		if (i < bus.size() - 1)
			file << bus[i].getID() << ";" << bus[i].getRegistration() << ";" << bus[i].getBuildYear()<<";"<< bus[i].getCapacity() << ";" << bus[i].getSchool()->getID() << "\n";
		else
			file << bus[i].getID() << ";" << bus[i].getRegistration() << ";" << bus[i].getBuildYear()<<";"<< bus[i].getCapacity() << ";" << bus[i].getSchool()->getID();
	}

	file.close();
}

void SchoolBus::saveSchools(){
	ofstream file;

	remove("res/schools.csv");
	file.open("res/schools.csv");

	for (size_t i = 0; i < schools.size(); i++){
		if (i < schools.size() - 1)
			file << schools[i]->getID() << ";" << schools[i]->getName() << ";" << schools[i]->getNodeID() << ";" << schools[i]->getRoad() << "\n";
		else
			file << schools[i]->getID() << ";" << schools[i]->getName() << ";" << schools[i]->getNodeID() << ";" << schools[i]->getRoad();
	}

	file.close();
}

void SchoolBus::saveStudents(){

	ofstream file;

	remove("res/students.csv");
	file.open("res/students.csv");

	for (size_t i = 0; i < schools.size(); i++){
		for (unsigned j = 0; j < schools[i]->getStudents().size(); j++){
			if ((i < schools.size() - 1) && (j < schools[i]->getStudents().size()-1))
				file << schools[i]->getStudents()[j]->getID() << ";" << schools[i]->getStudents()[j]->getName() << ";" << schools[i]->getStudents()[j]->getNodeID() << ";" << schools[i]->getStudents()[j]->getRoad()<< ";" << schools[i]->getStudents()[j]->getSchoolID()<< ";" << schools[i]->getStudents()[j]->getBusID() << "\n";
			else
				file << schools[i]->getStudents()[j]->getID() << ";" << schools[i]->getStudents()[j]->getName() << ";" << schools[i]->getStudents()[j]->getNodeID() << ";" << schools[i]->getStudents()[j]->getRoad()<< ";" << schools[i]->getStudents()[j]->getSchoolID()<< ";" << schools[i]->getStudents()[j]->getBusID() << "\n";
		}
	}

	file.close();
}

void SchoolBus::saveData(){
	saveSchools();
	saveBus();
	saveStudents();
};

void SchoolBus::loadBus(){
	ifstream file;
	string line;
	string buffer;
	string registration;
	int ID;
	int buildYear;
	int capacity;
	int schoolID;

	file.open("res/bus.csv");

	while(getline(file, line)){
		istringstream ss(line);

		while(ss.good()){
			getline(ss, buffer, ';');
			ID = atoi(buffer.c_str()); // ID
			getline(ss, registration, ';'); // Registration
			getline(ss, buffer, ';');
			buildYear = atoi(buffer.c_str()); // Build year
			getline(ss, buffer, ';');
			capacity = atoi(buffer.c_str()); // Build year
			getline(ss, buffer, ';');
			schoolID = atoi(buffer.c_str()); // School ID
		}

		Bus busTemp(buildYear, registration, capacity);
		busTemp.setID(ID);

		for (size_t i = 0; i < schools.size(); i++){
			if (schools[i]->getID() == schoolID){
				busTemp.setSchool(schools[i]);
				break;
			}
		}

		bus.push_back(busTemp);
	}

	file.close();
}

void SchoolBus::loadSchools(){
	ifstream file;
	string line;
	string buffer;
	string name;
	string roadTemp;
	int ID;
	int nodeID;

	file.open("res/schools.csv");

	while(getline(file, line)){
		istringstream ss(line);

		while(ss.good()){
			getline(ss, buffer, ';');
			ID = atoi(buffer.c_str()); // ID
			getline(ss, name, ';'); // Name
			getline(ss, buffer, ';');
			nodeID = atoi(buffer.c_str()); // Node ID
			getline(ss, roadTemp, ';');
		}

		School * school = new School(name, nodeID);
		school->setID(ID);
		school->setRoad(roadTemp);
		schools.push_back(school);
	}

	file.close();
}

void SchoolBus::loadStudents(){
	ifstream file;
	string line;
	string buffer;
	string name;
	string roadTemp;
	int ID;
	int nodeID;
	int schoolID;
	int busID;

	file.open("res/students.csv");

	while(getline(file, line)){
		istringstream ss(line);

		while(ss.good()){
			getline(ss, buffer, ';');
			ID = atoi(buffer.c_str()); // ID
			getline(ss, name, ';'); // Name
			getline(ss, buffer, ';');
			nodeID = atoi(buffer.c_str()); // Node ID
			getline(ss, roadTemp, ';'); // Road
			getline(ss, buffer, ';');
			schoolID = atoi(buffer.c_str()); // schoolID
			getline(ss, buffer, ';');
			busID = atoi(buffer.c_str()); // Build year
		}

		Student * student = new Student(name, nodeID);
		student->setID(ID);
		student->setNodeID(nodeID);
		student->setRoad(roadTemp);
		student->setSchoolID(schoolID);
		student->setBusID(busID);

		for (size_t i = 0; i < schools.size(); i++){
			if (schools[i]->getID() == schoolID){
				schools[i]->addStudent(student);
				break;
			}
		}

		for (size_t i = 0; i < bus.size(); i++){
			if (bus[i].getID() == busID){
				bus[i].addStudent(student);
				break;
			}
		}

		students.push_back(student);
	}

	file.close();
}

void SchoolBus::loadData(){
	routesGraph = LoadGraph::createGraph("res/nos.txt", "res/arestas.txt", "res/ligacoes.txt");
	loadSchools();
	loadBus();
	loadStudents();
};

void SchoolBus::menuShowBus(){
	clrscr();
	printAppName();
	int k = 0;
	cout << endl << endl;

	for (size_t i = 0; i < bus.size(); i++){
		if (k%2 == 0)
			setColor(7, 0);
		else
			setColor(3, 0);
		k++;
		cout << bus[i];
	}

	cout << endl;
}

void SchoolBus::menuShowSchools(){
	clrscr();
	printAppName();
	int k = 0;
	cout << endl;

	for (size_t i = 0; i < schools.size(); i++){
		if (k%2 == 0)
			setColor(7, 0);
		else
			setColor(3, 0);
		k++;
		cout << schools[i];
	}

	cout << endl;
}

void SchoolBus::menuShowStudents(){
	clrscr();
	printAppName();
	int k = 0;
	cout << endl << endl;

	for (size_t i = 0; i < schools.size(); i++){
		for (size_t j = 0; j < schools[i]->getStudents().size(); j++){
			if (k%2 == 0)
				setColor(7, 0);
			else
				setColor(3, 0);
			cout << schools[i]->getStudents()[j];

			k++;
		};
	}

	setColor(7, 0);

	cout << endl;
}

void SchoolBus::menuStarting(){
	string Menu[6] = { "<<  SCHOOL MANAGEMENT >>", "<<  CLIENT MANAGEMENT >>", "<<  BUS MANAGEMENT    >>", "<<  SEE MAPS          >>", "<<  REMOVE CONNECTION >>" , "<<  EXIT              >>" };
	bool validity = true;
	int pointer = 0;

	while (validity)
	{
		clrscr();
		printAppName();
		setColor(11, 0);
		cout << setw(51) << "<<<<<   WELCOME    >>>>>" << endl << endl;

		for (int i = 0; i < 6; ++i)
		{
			if (i == pointer)
			{
				cout << "                           ";
				setColor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setColor(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		setColor(7, 0);

		while (validity)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 6)
				{
					pointer = 0;
				}
				break;
			}

			if (ch == ARROW_UP){
				Beep(250, 160);
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 5;
				}
				break;
			}

			if (ch == '\r')
			{
				setColor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validity = false;
					menuSchoolManagement();
					break;
				case 1:
					validity = false;
					menuClientManagement();
					break;
				case 2:
					validity = false;
					menuBusManagement();
					break;
				case 3:
					menuShowMaps();
					break;
				case 4:
					menuRemoveConnection();
					break;
				case 5:
					saveData();
					exiting();
				}
			}
		}
	}
}

void SchoolBus::searchSchoolID(int schoolID){
	bool found = false;
	int schoolFound = 0;

	for (size_t i = 0; i < schools.size(); i++){
		if (schools[i]->getID()==schoolID){
			found = true;
			schoolFound = i;
			break;
		}
	}

	if (found){
		clrscr();
		printAppName();
		cleanBuffer();
		char input = ' ';
		cout << "> Do you want to see the location of the School and its students?";
		cin >> input;
		if (input == 'y' || input == 'Y'){
			cout << "\n> Please wait a moment while the map loads.\n";
			showSchoolAndStudents(schools[schoolFound]);
		}

		pressKeyToContinue();
		menuSearchSchool();
	}

	else {
		setColor(4, 0);
		cout << ":: ERROR: There is no School with the ID " << schoolID << " registered in the database! Please try again."<< endl << endl;
		setColor(7, 0);
		Sleep(2000);
		menuSearchSchool();
	}
}

void SchoolBus::searchSchoolName(string schoolName){
	bool found = false;
	int schoolFound = 0;

	for (size_t i = 0; i < schools.size(); i++){
		if (schools[i]->getName()==schoolName){
			found = true;
			schoolFound = i;
			break;
		}
	}

	if (found){
		clrscr();
		printAppName();
		cleanBuffer();
		char input = ' ';
		cout << "> Do you want to see the location of the School and its students?";
		cin >> input;
		if (input == 'y' || input == 'Y'){
			cout << "\n> Please wait a moment while the map loads.\n";
			showSchoolAndStudents(schools[schoolFound]);
		}

		pressKeyToContinue();
		menuSearchSchool();
	}

	else {
		setColor(4, 0);
		cout << ":: ERROR: There is no School with the name " << schoolName << " registered in the database! Please try again."<< endl << endl;
		setColor(7, 0);
		Sleep(2000);
		menuSearchSchool();
	}
}

void SchoolBus::menuSearchSchool(){
	string Menu[4] = { "<<  SEARCH BY ID      >>", "<<  SEARCH BY NAME    >>", "<<  BACK              >>", "<<  EXIT              >>" };
	bool validity = true;
	int pointer = 0;
	int id;
	string name;

	while (validity)
	{
		clrscr();
		printAppName();
		setColor(11, 0);
		cout << setw(51) << "<<<<< SEARCH SCHOOL>>>>>" << endl << endl;

		for (int i = 0; i < 4; ++i)
		{
			if (i == pointer)
			{
				cout << "                           ";
				setColor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setColor(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		setColor(7, 0);

		while (validity)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 4)
				{
					pointer = 0;
				}
				break;
			}

			if (ch == ARROW_UP){
				Beep(250, 160);
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 3;
				}
				break;
			}

			if (ch == '\r')
			{
				setColor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validity = false;
					clrscr();
					printAppName();
					cleanBuffer();
					cout << ">> SCHOOL ID: ";
					cin >> id;
					if (cin.fail()){
						setColor(4, 0);
						cout << ":: ERROR: Invalid input! Please try again." << endl << endl;
						setColor(7, 0);
						Sleep(2000);
					}
					else
						searchSchoolID(id);
					pressKeyToContinue();
					cleanBuffer();
					menuSearchSchool();
				case 1:
					validity = false;
					clrscr();
					printAppName();
					cleanBuffer();
					cout << ">> SCHOOL NAME: ";
					getline(cin, name);
					searchSchoolName(name);
					pressKeyToContinue();
					cleanBuffer();
					menuSearchSchool();
					break;
				case 2:
					validity = false;
					menuSchoolManagement();
					break;
				case 3:
					saveData();
					exiting();
				}
			}
		}
	}
}

bool SchoolBus::validSchoolName(const string &name){

	for (size_t i = 0; i < schools.size(); i++){
		if (schools[i]->getName() == name)
			return false;
	}

	return true;
}

string SchoolBus::registerSchoolName(){
	string name;
	clrscr();
	printAppName();

	cout << ">> SCHOOL NAME: ";
	getline(cin, name);

	while(cin.fail() || !validSchoolName(name)){
		cleanBuffer();
		setColor(4, 0);
		cout << ":: ERROR: Invalid school name! Please try again." << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		clrscr();
		printAppName();
		cout << ">> SCHOOL NAME: ";
		getline(cin, name);
	}

	cleanBuffer();

	return name;
}

bool SchoolBus::validSchoolNodeID(int nodeID){

	// Can't there is repeated node ID

	if (this->nodeID == nodeID)
		return false;

	for (size_t i = 0; i < schools.size(); i++){
		if (schools[i]->getNodeID()==nodeID)
			return false;
	}

	for (size_t i = 0; i < bus.size(); i++){
		for (unsigned j = 0; j < bus[i].getStudents().size(); j++){
			if (bus[i].getStudents()[j]->getNodeID() == nodeID)
				return false;
		}
	}

	// Verifies if the nodeID exists
	for (size_t i = 0; i < routesGraph.getVertexSet().size(); i++){
		if (routesGraph.getVertexSet()[i]->getInfo() == nodeID){
			// Verifies if the paths from school to the bus station and vice-versa are possible
			if (routesGraph.getW()[this->nodeID][nodeID] < INT_INFINITY && routesGraph.getW()[nodeID][this->nodeID] < INT_INFINITY)
				return true;
			else
				return false;
		}

	}

	return false;
}

int SchoolBus::registerSchoolNodeID(){

	int nodeID;

	clrscr();
	printAppName();

	cout << ">> SCHOOL NODE ID (localization in the graph): ";
	cin >> nodeID;

	while(cin.fail() || !validSchoolNodeID(nodeID)){
		cleanBuffer();
		setColor(4, 0);
		cout << ":: ERROR: Invalid school localization! Please try again." << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		clrscr();
		printAppName();
		cout << ">> SCHOOL NODE ID (localization in the graph): ";
		cin >> nodeID;
	}

	cleanBuffer();

	return nodeID;
}

void SchoolBus::registerNewSchool(){

	string name = registerSchoolName();
	int schoolNodeID = registerSchoolNodeID();

	School * schoolTemp = new School(name, schoolNodeID);
	schoolTemp->setRoad(getRoadByID(schoolNodeID));
	this->schools.push_back(schoolTemp);

	setColor(10, 0);
	cout << ":: INFO: A new school was registered with success!" << endl << endl;
	setColor(7, 0);

	Sleep(2000);

	menuSchoolManagement();
}

void SchoolBus::menuSchoolManagement(){
	string Menu[5] = { "<<  SEE SCHOOLS       >>", "<<  SEARCH SCHOOL     >>", "<<  CREATE SCHOOL     >>","<<  BACK              >>", "<<  EXIT              >>" };
	bool validity = true;
	int pointer = 0;

	while (validity)
	{
		clrscr();
		printAppName();
		setColor(11, 0);
		cout << setw(51) << "<<<<<    SCHOOLS   >>>>>" << endl << endl;

		for (int i = 0; i < 5; ++i)
		{
			if (i == pointer)
			{
				cout << "                           ";
				setColor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setColor(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		setColor(7, 0);

		while (validity)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 5)
				{
					pointer = 0;
				}
				break;
			}

			if (ch == ARROW_UP){
				Beep(250, 160);
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 4;
				}
				break;
			}

			if (ch == '\r')
			{
				setColor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validity = false;
					menuShowSchools();
					pressKeyToContinue();
					menuSchoolManagement();
					break;
				case 1:
					validity = false;
					menuSearchSchool();
					break;
				case 2:
					validity = false;
					registerNewSchool();
					break;
				case 3:
					validity = false;
					menuStarting();
					break;
				case 4:
					saveData();
					exiting();
				}
			}
		}
	}
}

void SchoolBus::menuClientManagement(){
	string Menu[5] = { "<<  SEE CLIENTS       >>", "<<  SEARCH CLIENT     >>","<<  CREATE CLIENT     >>", "<<  BACK              >>", "<<  EXIT              >>" };
	bool validity = true;
	int pointer = 0;

	while (validity)
	{
		clrscr();
		printAppName();
		setColor(11, 0);
		cout << setw(51) << "<<<<<    CLIENT    >>>>>" << endl << endl;

		for (int i = 0; i < 5; ++i)
		{
			if (i == pointer)
			{
				cout << "                           ";
				setColor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setColor(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		setColor(7, 0);

		while (validity)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 5)
				{
					pointer = 0;
				}
				break;
			}

			if (ch == ARROW_UP){
				Beep(250, 160);
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 4;
				}
				break;
			}

			if (ch == '\r')
			{
				setColor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validity = false;
					menuShowStudents();
					pressKeyToContinue();
					menuClientManagement();
					break;
				case 1:
					validity = false;
					menuSearchStudent();
					break;
				case 2:
					registerNewClient();
					break;
				case 3:
					validity = false;
					menuStarting();
					break;
				case 4:
					saveData();
					exiting();
				}
			}
		}
	}
}

void SchoolBus::searchStudentInBus(Bus &bus){

	clrscr();
	printAppName();
	cleanBuffer();
	string input;
	bool found = false;

	cout << "> STUDENT NAME: ";
	getline(cin, input);
	input = toLowerString(input);

	for (size_t i = 0; i < bus.getStudents().size(); i++){
		if (kmp(toLowerString(bus.getStudents()[i]->getName()), input) > 0){
			found = true;
			clrscr();
			printAppName();
			setColor(10, 0);
			cout << ">> Student found!" << endl;
			setColor(7, 0);
			cout << bus.getStudents()[i];
			break;
		}
	}

	if (!found){
		setColor(4, 0);
		cout << ">> Not exact match found!" << endl << endl;
		setColor(7, 0);
		Sleep(1000);

		char answer = ' ';
		cout << "> Do you want to see the most similar results for your input (press Y/y to see)?";
		cin >> answer;
		if (tolower(answer) == 'y'){
			clrscr();
			printAppName();
			searchStudentName(input);
		}
	}

	cout << endl;
}

void SchoolBus::searchBusID(int busID){
	bool found = false;
	Bus tempBus;

	for (size_t i = 0; i < bus.size(); i++){
		if (bus[i].getID()==busID){
			tempBus = bus[i];
			found = true;
			break;
		}
	}

	if (found){
		clrscr();
		printAppName();
		cleanBuffer();
		char input = ' ';
		cout << "> Do you want to see the BUS Route?";
		cin >> input;
		if (input == 'y' || input == 'Y'){
			cout << "\n> Please wait a moment while the map loads.\n";
			generateRoute(this->nodeID, tempBus.getSchool()->getNodeID(),tempBus.getStops());
		}

		clrscr();
		printAppName();
		cleanBuffer();
		input = ' ';

		cout << "> Do you want to see if a student is using this Bus Service (Press Y/y to continue)?";
		cin >> input;
		if (input == 'y' || input == 'Y'){
			searchStudentInBus(tempBus);
			cleanBuffer();
		}

		pressKeyToContinue();
		menuSearchBus();
	}

	else {
		setColor(4, 0);
		cout << ":: ERROR: There is no BUS with the ID " << busID << " registered in the database! Please try again."<< endl << endl;
		setColor(7, 0);
		Sleep(2000);
		menuSearchBus();
	}
}

void SchoolBus::searchBusReg(string busReg){
	bool found = false;
	Bus tempBus;

	for (size_t i = 0; i < bus.size(); i++){
		if (bus[i].getRegistration()==busReg){
			tempBus = bus[i];
			found = true;
			break;
		}
	}

	if (found){
		clrscr();
		printAppName();
		cleanBuffer();
		char input = ' ';
		cout << "> Do you want to see the BUS Route?";
		cin >> input;
		if (input == 'y' || input == 'Y'){
			cout << "\n> Please wait a moment while the map loads.\n";
			generateRoute(this->nodeID, tempBus.getSchool()->getNodeID(),tempBus.getStops());
		}

		clrscr();
		printAppName();
		cleanBuffer();
		input = ' ';

		cout << "> Do you want to see if a student is using this Bus Service (Press Y/y to continue)?";
		cin >> input;
		if (input == 'y' || input == 'Y'){
			searchStudentInBus(tempBus);
			cleanBuffer();
		}

		pressKeyToContinue();
		menuSearchSchool();
	}

	else {
		setColor(4, 0);
		cout << ":: ERROR: There is no BUS with the Registration " << busReg << " registered in the database! Please try again."<< endl << endl;
		setColor(7, 0);
		Sleep(2000);
		menuSearchSchool();
	}
}

void SchoolBus::menuSearchBus(){
	string Menu[4] = { "<<  SEARCH BY ID      >>", "<<  SEARCH BY REGIST  >>", "<<  BACK              >>", "<<  EXIT              >>" };
	bool validity = true;
	int pointer = 0;
	int id;
	string reg;

	while (validity)
	{
		clrscr();
		printAppName();
		setColor(11, 0);
		cout << setw(51) << "<<<<<  SEARCH BUS  >>>>>" << endl << endl;

		for (int i = 0; i < 4; ++i)
		{
			if (i == pointer)
			{
				cout << "                           ";
				setColor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setColor(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		setColor(7, 0);

		while (validity)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 4)
				{
					pointer = 0;
				}
				break;
			}

			if (ch == ARROW_UP){
				Beep(250, 160);
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 3;
				}
				break;
			}

			if (ch == '\r')
			{
				setColor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validity = false;
					clrscr();
					printAppName();
					cleanBuffer();
					cout << ">> BUS ID: ";
					cin >> id;
					if (cin.fail()){
						setColor(4, 0);
						cout << ":: ERROR: Invalid input! Please try again." << endl << endl;
						setColor(7, 0);
						Sleep(2000);
					}
					else
						searchBusID(id);
					pressKeyToContinue();
					cleanBuffer();
					menuSearchBus();
				case 1:
					validity = false;
					clrscr();
					printAppName();
					cleanBuffer();
					cout << ">> BUS REGISTRATION: ";
					getline(cin, reg);
					searchBusReg(reg);
					pressKeyToContinue();
					cleanBuffer();
					menuSearchBus();
					break;
				case 2:
					validity = false;
					menuBusManagement();
					break;
				case 3:
					saveData();
					exiting();
				}
			}
		}
	}
}

int SchoolBus::registerBusYear(){
	int busYear;
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	int currentYear = now->tm_year + 1900;

	clrscr();
	printAppName();

	cout << ">> CONSTRUCTION BUS YEAR: ";
	cin >> busYear;

	while(cin.fail() || busYear < 1900 || busYear > currentYear){
		cleanBuffer();
		setColor(4, 0);
		cout << ":: ERROR: Invalid construction year! Please try again." << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		clrscr();
		printAppName();
		cout << ">> CONSTRUCTION BUS YEAR: ";
		cin >> busYear;
	}

	cleanBuffer();

	return busYear;
}

bool SchoolBus::validRegistration(const string &reg){

	if (reg.size() != 6)
		return false;

	for (size_t i = 0; i < bus.size(); i++)
		if (bus[i].getRegistration() == reg)
			return false;


	if (reg[0] >= '0' && reg[1] >= '0' && reg[4] >= '0' && reg[5] >= '0'){
		if (reg[0] <= '9' && reg[1] <= '9' && reg[4] <= '9' && reg[5] <= '9')
			if (reg[2] >= 'A' && reg[3] >= 'A')
				if (reg[2] <= 'Z' && reg[3] <= 'Z')
					return true;
	}

	return false;
}

string SchoolBus::registerBusRegistration(){
	string busReg;
	clrscr();
	printAppName();

	cout << ">> BUS REGISTRATION (09AZ09): ";
	getline(cin, busReg);

	while(cin.fail() || !validRegistration(busReg)){
		cleanBuffer();
		setColor(4, 0);
		cout << ":: ERROR: Invalid registration! Please try again." << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		clrscr();
		printAppName();
		cout << ">> BUS REGISTRATION (09AZ09): ";
		getline(cin, busReg);
	}

	cleanBuffer();

	return busReg;
}

int SchoolBus::registerBusCapacity(){
	int capacity;

	clrscr();
	printAppName();

	cout << ">> BUS CAPACITY (min: 10 | max: 20): ";
	cin >> capacity;

	while(cin.fail() || capacity < 10 || capacity > 20){
		cleanBuffer();
		setColor(4, 0);
		cout << ":: ERROR: Invalid bus capacity! Please try again." << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		clrscr();
		printAppName();
		cout << ">> BUS CAPACITY (min: 10 | max: 20): ";
		cin >> capacity;
	}

	cleanBuffer();

	return capacity;
}

bool SchoolBus::validBusSchoolID(int id){
	for (size_t i = 0; i < schools.size(); i++){
		if (schools[i]->getID() == id){
			return true;
		}
	}

	return false;
}

int SchoolBus::registerBusSchool(){
	int ID;

	clrscr();
	printAppName();

	cout << ">> SCHOOL ID: ";
	cin >> ID;

	while(cin.fail() || !validBusSchoolID(ID)){
		cleanBuffer();
		setColor(4, 0);
		cout << ":: ERROR: Invalid school ID! Please try again." << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		clrscr();
		printAppName();
		cout << ">> SCHOOL ID: ";
		cin >> ID;
	}

	cleanBuffer();

	return ID;
}

void SchoolBus::registerNewBus(){

	if (schools.size() == 0){
		clrscr();
		printAppName();
		setColor(4, 0);
		cout << ":: ERROR: Cant create bus because currently there is no any school in database." << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		menuBusManagement();
	}

	else {
		int year = registerBusYear();
		string registration = registerBusRegistration();
		int capacity = registerBusCapacity();
		int schoolID = registerBusSchool();

		Bus busTemp(year, registration, capacity);

		for (size_t i = 0; i < schools.size(); i++){
			if (schools[i]->getID() == schoolID){
				busTemp.setSchool(schools[i]);
				break;
			}
		}

		bus.push_back(busTemp);

		setColor(10, 0);
		cout << ":: INFO: A new bus was registered with success!" << endl << endl;
		setColor(7, 0);

		Sleep(2000);

		menuBusManagement();
	}

}

string SchoolBus::registerStudentName(){
	string stuName;
	clrscr();
	printAppName();

	cout << ">> STUDENT NAME: ";
	getline(cin, stuName);

	while(cin.fail() || stuName.size()<2 || stuName.size()>20){
		cleanBuffer();
		setColor(4, 0);
		cout << ":: ERROR: Invalid name! Please try again." << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		clrscr();
		printAppName();
		cout << ">> STUDENT NAME: ";
		getline(cin, stuName);
	}

	cleanBuffer();

	return stuName;
}

int SchoolBus::registerStudentSchool(){
	int stuSchool = 0;
	clrscr();
	printAppName();

	cout << ">> SCHOOL ID: ";
	cin >> stuSchool;

	while(cin.fail() || !validBusSchoolID(stuSchool)){
		cleanBuffer();
		setColor(4, 0);
		cout << ":: ERROR: Invalid school ID! Please try again." << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		clrscr();
		printAppName();
		cout << ">> SCHOOL ID: ";
		cin >> stuSchool;
	}

	cleanBuffer();

	return stuSchool;
}

int SchoolBus::registerStudentBus(int schoolID){
	int stuBus = 0;

	for(size_t i = 0;i < bus.size();i++){
		if((bus[i].getSchool()->getID() == schoolID) && ((bus[i].getCapacity() - 1) > bus[i].getStudents().size())){
			stuBus = bus[i].getID();
			break;

		}
	}

	return stuBus;
}

bool SchoolBus::validStudentNodeID(int studentNodeID, int schoolNodeID){

	// Can't there is repeated node ID

	if (this->nodeID == studentNodeID)
		return false;

	for (size_t i = 0; i < schools.size(); i++){
		if (schools[i]->getNodeID()==studentNodeID)
			return false;
	}

	for (size_t i = 0; i < bus.size(); i++){
		for (unsigned j = 0; j < bus[i].getStudents().size(); j++){
			if (bus[i].getStudents()[j]->getNodeID() == studentNodeID)
				return false;
		}
	}

	// Verifies if the nodeID exists
	for (size_t i = 0; i < routesGraph.getVertexSet().size(); i++){
		if (routesGraph.getVertexSet()[i]->getInfo() == studentNodeID){
			// Verifies if the paths from student to the bus station and vice-versa are possible
			if (routesGraph.getW()[this->nodeID][studentNodeID] < INT_INFINITY && routesGraph.getW()[studentNodeID][this->nodeID] < INT_INFINITY
					&& routesGraph.getW()[schoolNodeID][studentNodeID] < INT_INFINITY && routesGraph.getW()[studentNodeID][schoolNodeID] < INT_INFINITY)
				return true;
			else
				return false;
		}

	}

	return false;
}

int SchoolBus::registerStudentNode(int schoolNodeID){
	int nodeID;

	clrscr();
	printAppName();

	cout << ">> STUDENT NODE ID (localization in the graph): ";
	cin >> nodeID;

	while(cin.fail() || !validStudentNodeID(nodeID, schoolNodeID)){
		cleanBuffer();
		setColor(4, 0);
		cout << ":: ERROR: Invalid student localization! Please try again." << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		clrscr();
		printAppName();
		cout << ">> STUDENT NODE ID (localization in the graph): ";
		cin >> nodeID;
	}

	cleanBuffer();

	return nodeID;
}

string SchoolBus::getRoadByID(int roadID) const {

	// Get network of all nodes of the graph
	vector<Vertex<int>*> routes = routesGraph.getVertexSet();

	for (size_t i = 0; i < routes.size(); i++)
		if (routes[i]->getInfo() == roadID)
			return routes[i]->getRoad();

	return NULL;
}

void SchoolBus::registerNewClient(){

	if (bus.size() == 0){
		setColor(4, 0);
		cout << ":: ERROR: Can�t register any client because currently there isn't any bus in the database. Please register first a bus" << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		menuClientManagement();
	}

	else {
		string name = registerStudentName();
		int schoolID = registerStudentSchool();

		int schoolNodeID;

		for (size_t i = 0; i < schools.size(); i++){
			if (schools[i]->getID() == schoolID){
				schoolNodeID = schools[i]->getNodeID();
				break;
			}
		}

		int nodeID = registerStudentNode(schoolNodeID);

		Student tempStudent(name, nodeID);
		tempStudent.setRoad(getRoadByID(nodeID));
		tempStudent.setSchoolID(schoolID);

		Student* ptTempStudent = &tempStudent;

		for (size_t i = 0; i < schools.size(); i++){
			if (schools[i]->getID() == schoolID){
				schools[i]->addStudent(ptTempStudent);
				break;
			}
		}

		int busInd = placeStudent(nodeID,schoolID,1);
		if(busInd != -1){
			ptTempStudent->setBusID(bus[busInd].getID());
			bus[busInd].addStudent(ptTempStudent);
			setColor(10, 0);
			cout << ":: INFO: A new client was registered with success!" << bus[busInd].getRegistration() << endl << endl;
			setColor(7, 0);
		}else{
			setColor(4, 0);
			cout << ":: ERROR: Cant register the client because currently there isnt any bus available. Please register another bus to the school " << schoolID << endl << endl;
			setColor(7, 0);
		}

		Sleep(2000);

		menuClientManagement();
	}

}

void SchoolBus::showRoadStudents(const string &road){
	int counter = 0;
	int k = 0;

	clrscr();
	printAppName();

	// Shows the first 10 most similar results
	for (size_t i = 0; i < students.size(); i++){
		if (kmp(students[i]->getRoad(), road) > 0 && students[i]->getRoad().size() == road.size()){
			counter++;
			if (k%2 == 0)
				setColor(7, 0);
			else
				setColor(3, 0);
			cout <<i+1 <<" - " << students[i]->getName() << endl;
			k++;
		}
	}

	setColor(7, 0);

	cout << endl << "> " << counter << " student(s) found. " << endl << endl;
}

void SchoolBus::searchStudentRoad(string studentRoad){
	// All the comparisons are made in lowercase mode to prevent inaccurate results

	// Converts the string to lowercase
	studentRoad = toLowerString(studentRoad);

	// Struct with the comparing function to be used
	compareED<RoadT> cmpED;
	vector <RoadT *> vec = routesGraph.getRoads();
	int k = 0;
	char input;

	// Order the results by edition distance
	updateResults(studentRoad, vec, cmpED, roadMap);

	setColor(11, 0);
	cout << endl << ">> RESULTS:" << endl << endl;

	// Shows the first 10 most similar results
	for (size_t i = 0; i < 10; i++){
		if (k%2 == 0)
			setColor(7, 0);
		else
			setColor(3, 0);
		cout <<i+1 <<" - " << vec[i]->getName() << endl;
		k++;
	}

	if (vec.size() > 0){
		setColor(7, 0);
		cleanBuffer();
		cout << endl << ">> Do you want to select any of the results? (y/n): ";
		cin >> input;

		while (cin.fail() || ( tolower(input) != 'y' && tolower(input) != 'n')){
			cleanBuffer();
			setColor(4, 0);
			cout << endl << input << endl;
			cout << ":: ERROR: Invalid input! Please try again." << endl << endl;
			setColor(7, 0);
			Sleep(1000);
			cout << ">> Do you want to select any of the results? (y/n): ";
			cin >> input;
		}

		if (tolower(input) == 'y'){
			int option;
			int sizeV = vec.size();
			if (sizeV > 10)
				sizeV = 10;

			cleanBuffer();
			cout << endl << ">> Select the road you want to see (1 - " << sizeV << "): ";
			cin >> option;

			while (cin.fail() || option < 1 || option > sizeV){
				cleanBuffer();
				setColor(4, 0);
				cout << endl << option << endl;
				cout << ":: ERROR: Invalid input! Please try again." << endl << endl;
				setColor(7, 0);
				Sleep(1000);
				cout << endl << ">> Select the road you want to see (1 - " << sizeV << "): ";
				cin >> option;
			}

			cleanBuffer();
			showRoadStudents(vec[option-1]->getName());
		}
	}
}

void SchoolBus::searchStudentName(string studentName){
	// All the comparisons are made in lowercase mode to prevent inaccurate results

	// Converts the string to lowercase
	studentName = toLowerString(studentName);

	// Struct with the comparing function to be used
	compareED<Student> cmpED;
	int k = 0;
	vector <Student *> vec = students;

	// Order the results by edition distance
	updateResults(studentName, vec, cmpED, studentMap);

	setColor(11, 0);
	cout << endl << ">> RESULTS:" << endl << endl;

	// Shows the first 10 most similar results
	for (size_t i = 0; i < 10; i++){
		if (k%2 == 0)
			setColor(7, 0);
		else
			setColor(3, 0);
		cout <<i+1 <<" - " << vec[i]->getName() << endl;
		k++;
	}

	if (students.size() > 0){
		setColor(7, 0);
		cleanBuffer();
		char input = ' ';
		cout << endl << ">> Do you want to select any of the results? (y/n): ";
		cin >> input;

		while (cin.fail() || ( tolower(input) != 'y' && tolower(input) != 'n')){
			cleanBuffer();
			setColor(4, 0);
			cout << endl << input << endl;
			cout << ":: ERROR: Invalid input! Please try again." << endl << endl;
			setColor(7, 0);
			Sleep(1000);
			cout << ">> Do you want to select any of the results? (y/n): ";
			cin >> input;
		}

		if (tolower(input) == 'y'){
			int option;
			int sizeV = vec.size();
			if (sizeV > 10)
				sizeV = 10;

			cleanBuffer();
			cout << endl << ">> Select the student you want to see (1 - " << sizeV << "): ";
			cin >> option;

			while (cin.fail() || option < 1 || option > sizeV){
				cleanBuffer();
				setColor(4, 0);
				cout << endl << option << endl;
				cout << ":: ERROR: Invalid input! Please try again." << endl << endl;
				setColor(7, 0);
				Sleep(1000);
				cout << endl << ">> Select the student you want to see (1 - " << sizeV << "): ";
				cin >> option;
			}

			cleanBuffer();

			// Prints the student selected
			cout << vec[option-1] << endl;
		}
	}
}

void SchoolBus::searchStudentID(int studentID){
	bool found = false;
	int schoolFound = 0;
	int studentFound = 0;
	Bus tempBus;

	for (size_t i = 0; i < schools.size(); i++){
		for (size_t j = 0; j < schools[i]->getStudents().size(); j++){
			if (schools[i]->getStudents()[j]->getID()==studentID){
				found = true;
				schoolFound = i;
				studentFound = j;
				break;
			}
		}
	}

	if (found){
		for (size_t k = 0; k < bus.size(); k++){
			if (bus[k].getID() == schools[schoolFound]->getStudents()[studentFound]->getBusID()){
				tempBus = bus[k];
			}
		}
	}

	if (found){
		clrscr();
		printAppName();
		cleanBuffer();
		char input = ' ';
		cout << "> Do you want to see the route of the student to the school?";
		cin >> input;
		if (input == 'y' || input == 'Y'){
			cout << "\n> Please wait a moment while the map loads.\n";
			generateRoute(this->nodeID, tempBus.getSchool()->getNodeID(), tempBus.getStops());
		}

		pressKeyToContinue();
		menuSearchSchool();
	}

	else {
		setColor(4, 0);
		cout << ":: ERROR: There is no student with the ID " << studentID << " registered in the database! Please try again."<< endl << endl;
		setColor(7, 0);
		Sleep(2000);
		menuSearchStudent();
	}
}

void SchoolBus::menuSearchStudent(){
	string Menu[5] = { "<<  SEARCH BY ID      >>", "<<  SEARCH BY NAME    >>","<<  SEARCH BY ROAD    >>", "<<  BACK              >>", "<<  EXIT              >>" };
	bool validity = true;
	int pointer = 0;
	int id;
	string studentName;
	string studentRoad;

	while (validity)
	{
		clrscr();
		printAppName();
		setColor(11, 0);
		cout << setw(51) << "<<<<< SEARCH CLIENT>>>>>" << endl << endl;

		for (int i = 0; i < 5; ++i)
		{
			if (i == pointer)
			{
				cout << "                           ";
				setColor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setColor(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		setColor(7, 0);

		while (validity)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 5)
				{
					pointer = 0;
				}
				break;
			}

			if (ch == ARROW_UP){
				Beep(250, 160);
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 4;
				}
				break;
			}

			if (ch == '\r')
			{
				setColor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validity = false;
					clrscr();
					printAppName();
					cleanBuffer();
					cout << ">> CLIENT ID: ";
					cin >> id;
					if (cin.fail()){
						setColor(4, 0);
						cout << ":: ERROR: Invalid input! Please try again." << endl << endl;
						setColor(7, 0);
						Sleep(2000);
					}
					else
						searchStudentID(id);
					pressKeyToContinue();
					cleanBuffer();
					menuSearchStudent();
				case 1:
					validity = false;
					clrscr();
					printAppName();
					cleanBuffer();
					cout << ">> STUDENT NAME: ";
					getline(cin, studentName);
					if (cin.fail()){
						setColor(4, 0);
						cout << ":: ERROR: Invalid input! Please try again." << endl << endl;
						setColor(7, 0);
						Sleep(2000);
					}
					else
						searchStudentName(studentName);
					pressKeyToContinue();
					cleanBuffer();
					menuSearchStudent();
				case 2:
					validity = false;
					clrscr();
					printAppName();
					cleanBuffer();
					cout << ">> ROAD NAME: ";
					getline(cin, studentRoad);
					if (cin.fail()){
						setColor(4, 0);
						cout << ":: ERROR: Invalid input! Please try again." << endl << endl;
						setColor(7, 0);
						Sleep(2000);
					}
					else
						searchStudentRoad(studentRoad);
					pressKeyToContinue();
					cleanBuffer();
					menuSearchStudent();
				case 3:
					validity = false;
					menuClientManagement();
					break;
				case 4:
					saveData();
					exiting();
				}
			}
		}
	}
}

void SchoolBus::menuBusManagement(){
	string Menu[5] = { "<<  SEE ALL BUS       >>", "<<  SEARCH BUS        >>", "<<  REGISTER NEW BUS  >>", "<<  BACK              >>", "<<  EXIT              >>" };
	bool validity = true;
	int pointer = 0;

	while (validity)
	{
		clrscr();
		printAppName();
		setColor(11, 0);
		cout << setw(51) << "<<<<<     BUS      >>>>>" << endl << endl;

		for (int i = 0; i < 5; ++i)
		{
			if (i == pointer)
			{
				cout << "                           ";
				setColor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setColor(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		setColor(7, 0);

		while (validity)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 5)
				{
					pointer = 0;
				}
				break;
			}

			if (ch == ARROW_UP){
				Beep(250, 160);
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 4;
				}
				break;
			}

			if (ch == '\r')
			{
				setColor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					validity = false;
					menuShowBus();
					pressKeyToContinue();
					menuBusManagement();
					break;
				case 1:
					validity = false;
					menuSearchBus();
					break;
				case 2:
					saveData();
					registerNewBus();
					break;
				case 3:
					validity = false;
					menuStarting();
					break;
				case 4:
					saveData();
					exiting();
				}
			}
		}
	}
}

int SchoolBus::placeStudent(int nodeID,int schoolID,int start){
	vector<int> vecBus;
	int end;
	for (size_t i = 0; i < bus.size(); ++i) {
		if(bus[i].getSchool()->getID() == schoolID)
			vecBus.push_back(i);
	}

	for (size_t i = 0; i < schools.size(); ++i) {
		if(schools[i]->getID() == schoolID){
			end = schools[i]->getNodeID();
			break;
		}
	}


	if (vecBus.size() == 1)
		return vecBus[0];

	int tBus = -1;
	int dist = INT_INFINITY;
	for (size_t i = 0; i < vecBus.size(); i++) {
		vector<int> stuNodes;

		stuNodes.push_back(start);
		vector<Student*> tempStu = bus[vecBus[i]].getStudents();
		for(size_t j = 0; j < tempStu.size() ;j++)
			stuNodes.push_back(tempStu[j]->getID());
		stuNodes.push_back(nodeID);
		stuNodes.push_back(end);

		int tDist = this->getRoutesGraph().calculateDist(stuNodes);

		if (tDist < dist) {
			dist = tDist;
			tBus = vecBus[i];
		}
	}

	return tBus;
}

int SchoolBus::validNodes(int node1ID, int node2ID){

	int edgeWeight = INT_INFINITY;

	for (size_t i = 0; i < routesGraph.getVertexSet().size(); i++)
	{
		if (routesGraph.getVertexSet()[i]->getInfo() == node1ID)
		{
			for (size_t j = 0; j < routesGraph.getVertexSet()[i]->adj.size(); j++){
				if (routesGraph.getVertexSet()[i]->adj[j].getDest()->getInfo() == node2ID)
				{
					edgeWeight = routesGraph.getVertexSet()[i]->adj[j].getWeigth();
					routesGraph.getVertexSet()[i]->adj[j].setWeight(INT_INFINITY);
				}
			}
		}
	}

	for (size_t i = 0; i < routesGraph.getVertexSet().size(); i++)
	{
		if (routesGraph.getVertexSet()[i]->getInfo() == node2ID)
		{
			for (size_t j = 0; j < routesGraph.getVertexSet()[i]->adj.size(); j++){
				if (routesGraph.getVertexSet()[i]->adj[j].getDest()->getInfo() == node1ID)
				{
					edgeWeight = routesGraph.getVertexSet()[i]->adj[j].getWeigth();
					routesGraph.getVertexSet()[i]->adj[j].setWeight(INT_INFINITY);
				}
			}
		}
	}

	return edgeWeight;
}

void SchoolBus::showRemovedConnectionGraph(int node1ID, int node2ID){

	//show the graph
	gv = new GraphViewer(WIDTH_SIZE, HEIGHT_SIZE, false);
	gv->createWindow(WIDTH_SIZE, HEIGHT_SIZE);
	gv->defineVertexColor("CYAN");
	gv->defineEdgeCurved(false);

	// Get network of all nodes of the graph
	vector<Vertex<int>*> routes = routesGraph.getVertexSet();

	// Creating the nodes
	for (size_t i = 0; i < routes.size(); i++){
		gv->addNode(routes[i]->getInfo(), routes[i]->getX(), routes[i]->getY());
		gv->setVertexSize(routes[i]->getInfo(), 8);
		routes[i]->gvNodeID = routes[i]->getInfo();
	}

	// Creating the edges
	unsigned int counter = 0;
	for (unsigned int i = 0; i < routes.size(); i++){
		for (int unsigned j = 0; j < routes[i]->adj.size(); j++){
			if (routes[i]->getInfo() == node1ID && routes[i]->adj[j].getDest()->getInfo() == node2ID){
				gv->addEdge(counter++, routes[i]->gvNodeID, routes[i]->adj[j].getDest()->gvNodeID,EdgeType::DIRECTED);
				gv->setEdgeColor(counter, "GREEN");
			}

			else {

			}

			routes[i]->adj[j].setGvEdgeID(counter);
		}
	}
	gv->rearrange();
}

void SchoolBus::menuRemoveConnection(){

	showGraph();

	int node1ID, node2ID;
	string startNodeID, endNodeID;
	int valid;

	clrscr();
	printAppName();

	cout << ">> Start Node ID: ";
	cin >> node1ID;

	clrscr();
	printAppName();
	cout << ">> End Node ID: ";
	cin >> node2ID;

	valid = validNodes(node1ID, node2ID);

	while(cin.fail() || valid == INT_INFINITY){
		cleanBuffer();
		setColor(4, 0);
		cout << ":: ERROR: Invalid Nodes! Please try again." << endl << endl;
		Sleep(2000);
		setColor(7, 0);
		clrscr();
		printAppName();
		cout << ">> Start Node ID: ";
		cin >> node1ID;
		clrscr();
		printAppName();
		cout << ">> End Node ID : ";
		cin >> node2ID;
		valid = validNodes(node1ID, node2ID);
	}

	cleanBuffer();

	this->routesGraph.floydWarshallShortestPath();

	showRemovedConnectionGraph(node1ID, node2ID);

	menuStarting();
}

void SchoolBus::menuShowMaps(){
	string Menu[5] = { "<<  VIEW OF CITY MAP  >>", "<<  VIEW OF ROADS MAP >>", "<<  VIEW OF CLIENT MAP>>", "<<  BACK              >>", "<<  EXIT              >>" };
	bool validity = true;
	int pointer = 0;

	while (validity)
	{
		clrscr();
		printAppName();
		setColor(11, 0);
		cout << setw(51) << "<<<<<     MAPS     >>>>>" << endl << endl;

		for (int i = 0; i < 5; ++i)
		{
			if (i == pointer)
			{
				cout << "                           ";
				setColor(3, 1);
				cout << Menu[i] << endl << endl;
			}
			else
			{
				setColor(3, 0);
				cout << setw(51) << Menu[i] << endl << endl;
			}
		}
		setColor(7, 0);

		while (validity)
		{
			int ch = _getch();

			if (ch == 0 || ch == 224)
				ch = 256 + _getch();

			if (ch == ARROW_DOWN) {
				Beep(250, 160);
				pointer += 1;
				if (pointer == 5)
				{
					pointer = 0;
				}
				break;
			}

			if (ch == ARROW_UP){
				Beep(250, 160);
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 4;
				}
				break;
			}

			if (ch == '\r')
			{
				setColor(7, 0);
				Beep(200, 160);

				switch (pointer)
				{
				case 0:
					showMap();
					break;
				case 1:
					showRoads();
					break;
				case 2:
					showAllClientsAndSchools();
					break;
				case 3:
					validity = false;
					menuStarting();
					break;
				case 4:
					saveData();
					exiting();
				}
			}
		}
	}
}

unordered_map<string, vector<Student *>>& SchoolBus::getStudentMap(){
	return studentMap;
}

unordered_map<string, vector<RoadT *>>& SchoolBus::getRoadMap(){
	return roadMap;
}
