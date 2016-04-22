#include "SchoolBus.h"

using namespace std;

SchoolBus::SchoolBus(){};

SchoolBus::SchoolBus(const Graph<int> &graph){
	this->routesGraph = graph;
}

void SchoolBus::addBus(const Bus &bus){
	this->bus.push_back(bus);
}

vector <Bus> SchoolBus::getBus() const{
	return bus;
}

void SchoolBus::addSchool(const School &school){
	this->schools.push_back(school);
}

vector <School> SchoolBus::getSchool() const{
	return schools;
}

void SchoolBus::addStudent(string name, int ID, const string &localization, School &school){

	for (unsigned int i = 0; i < schools.size(); i++){
		if (schools[i] == school){
			schools[i].addStudent(Student (name, ID, localization));
			break;
		}
	}
}

Graph <int> SchoolBus::getRoutesGraph() const{
	return routesGraph;
}

// TODO - ADAPTAR CODIGO PARA O QUE FOR NECESS�RIO - M�TODO MOSTRA TODO O GRAFO E A ROTA ENTRE 2 PONTOS COM
// COR A VERDE
void SchoolBus::showGraph(unsigned int srcNode, unsigned int destNode){
	unsigned int width = 800;
	unsigned int height = 600;

	routesGraph.dijkstraShortestPath(srcNode);
	gv = new GraphViewer(width, height, true);
	gv->createWindow(width, height);
	gv->defineVertexColor("blue");
	gv->defineEdgeCurved(false);

	// Get network of nodes
	vector<Vertex<int>*> routes = routesGraph.getVertexSet();

	// Create the nodes
	for (unsigned int i = 0; i < routes.size(); i++){
		gv->addNode(i);
		gv->setVertexSize(i, 5);
		routes[i]->gvNodeID = i;
	}

	// Create the edges
	unsigned int counter = 0;
	for (unsigned int i = 0; i < routes.size(); i++){
		for (int unsigned j = 0; j < routes[i]->adj.size(); j++){
			gv->addEdge(counter++, routes[i]->gvNodeID,
					routes[i]->adj[j].getDest()->gvNodeID,
					EdgeType::UNDIRECTED);

			routes[i]->adj[j].setGvEdgeID(counter);
			gv->setEdgeWeight(counter-1, routes[i]->adj[j].getWeigth());
		}
	}

	unsigned int i  = destNode;
	while (routes[i]->path != NULL){
		for (int unsigned j = 0; j < routes[i]->path->adj.size(); j++){
			if (routes[i]->path->adj[j].getDest()->getInfo() == routes[i]->getInfo()){
				gv->removeEdge(routes[i]->path->adj[j].getGvEdgeID());
				gv->addEdge(routes[i]->path->adj[j].getGvEdgeID(), routes[i]->path->gvNodeID,
						routes[i]->path->adj[j].getDest()->gvNodeID,
						EdgeType::DIRECTED);
				gv->setEdgeColor(routes[i]->path->adj[j].getGvEdgeID(), "GREEN");
				gv->setEdgeThickness(routes[i]->path->adj[j].getGvEdgeID(), 3);
				i = routes[i]->path->getInfo();
				break;
			}
		}
	}

	gv->rearrange();
}

// TODO - falta implementar save e load data
void SchoolBus::loadData(){};
void SchoolBus::saveData(){};

void SchoolBus::menuShowBus(){
	clrscr();
	printAppName();
	cout << endl << endl;

	for (unsigned int i = 0; i < bus.size(); i++){
		cout << bus[i];
	}

	cout << endl;
}

void SchoolBus::menuStarting(){
	string Menu[5] = { "<<  SCHOOL MANAGEMENT >>", "<<  CLIENT MANAGEMENT >>", "<<  BUS MANAGEMENT    >>", "<<  VIEW OF CITY MAP  >>", "<<  EXIT              >>" };
	bool validity = true;
	int pointer = 0;

	while (validity)
	{
		clrscr();
		printAppName();
		setColor(11, 0);
		cout << setw(51) << "<<<<<   WELCOME    >>>>>" << endl << endl;

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
					// TODO - APAGAR/MODIFICAR
					showGraph(0, 6);
					break;
				case 4:
					saveData();
					exiting();
				}
			}
		}
	}
}

void SchoolBus::menuSchoolManagement(){
	string Menu[4] = { "<<  SEE SCHOOLS       >>", "<<  SEARCH SCHOOL     >>", "<<  BACK              >>", "<<  EXIT              >>" };
	bool validity = true;
	int pointer = 0;

	while (validity)
	{
		clrscr();
		printAppName();
		setColor(11, 0);
		cout << setw(51) << "<<<<<    SCHOOLS   >>>>>" << endl << endl;

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
					exit(0);
					break;
				case 1:
					validity = false;
					exit(0);
					break;
				case 2:
					validity = false;
					menuStarting();
					break;
				case 3:
					saveData();
					exiting();
				}
			}
		}
	}
}

void SchoolBus::menuClientManagement(){
	string Menu[4] = { "<<  SEE CLIENTS       >>", "<<  SEARCH CLIENT     >>", "<<  BACK              >>", "<<  EXIT              >>" };
	bool validity = true;
	int pointer = 0;

	while (validity)
	{
		clrscr();
		printAppName();
		setColor(11, 0);
		cout << setw(51) << "<<<<<    CLIENT    >>>>>" << endl << endl;

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
					exit(0);
					break;
				case 1:
					validity = false;
					exit(0);
					break;
				case 2:
					validity = false;
					menuStarting();
					break;
				case 3:
					saveData();
					exiting();
				}
			}
		}
	}
}

void SchoolBus::searchBusID(int busID){
	bool found = false;

	for (unsigned int i = 0; i < bus.size(); i++){
		if (bus[i].getID()==busID){
			found = true;
			break;
		}
	}

	if (found){
		clrscr();
		printAppName();
		cleanBuffer();
		char input = ' ';
		cout << "> Do you want see the BUS Route?";
		cin >> input;
		if (input == 'y' || input == 'Y'){
			cout << "\n> Please wait a moment while the map loads.\n";
			showGraph(this->nodeID, 6); // TODO - IMPRIMIR ROTA - alterar para valores corretos (valor 6 aqui colocado � random - deve ser mudado apra o nodeID da escola)
		}

		pressKeyToContinue();
		menuSearchBus();
	}

	else {
		setColor(4, 0);
		cout << ":: ERROR: There is no BUS with the ID " << busID << " registered on the database! Please try again."<< endl << endl;
		setColor(7, 0);
		Sleep(1000);
		menuSearchBus();
	}
}

void SchoolBus::searchBusReg(string busReg){
	bool found = false;

	for (unsigned int i = 0; i < bus.size(); i++){
		if (bus[i].getRegistration()==busReg){
			found = true;
			break;
		}
	}

	if (found){
		clrscr();
		printAppName();
		cleanBuffer();
		char input = ' ';
		cout << "> Do you want see the BUS Route?";
		cin >> input;
		if (input == 'y' || input == 'Y'){
			cout << "\n> Please wait a moment while the map loads.\n";
			showGraph(this->nodeID, 6); // TODO - IMPRIMIR ROTA - alterar para valores corretos (valor 6 aqui colocado � random - deve ser mudado apra o nodeID da escola)
		}

		pressKeyToContinue();
		menuSearchBus();
	}

	else {
		setColor(4, 0);
		cout << ":: ERROR: There is no BUS with the Registration " << busReg << " registered on the database! Please try again."<< endl << endl;
		setColor(7, 0);
		Sleep(1000);
		menuSearchBus();
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
						cout << ":: ERRO: Invalid input! Please try again." << endl << endl;
						setColor(7, 0);
						Sleep(1000);
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
		Sleep(1000);
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

	for (unsigned int i = 0; i < bus.size(); i++)
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
		Sleep(1000);
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
		Sleep(1000);
		setColor(7, 0);
		clrscr();
		printAppName();
		cout << ">> BUS CAPACITY (min: 10 | max: 20): ";
		cin >> capacity;
	}

	cleanBuffer();

	return capacity;
}

void SchoolBus::registerNewBus(){

	int year = registerBusYear();
	string registration = registerBusRegistration();
	int capacity = registerBusCapacity();

	bus.push_back(Bus(year, registration, capacity));

	setColor(10, 0);
	cout << ":: INFO: A new bus was registered with success!" << endl << endl;
	setColor(7, 0);

	Sleep(2000);

	menuBusManagement();
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
