#include "LoadGraph.h"

Graph<int> LoadGraph::createGraph(const string &nodes, const string &roads, const string &connections){

	Graph <int>  graph;
	vector<Node> vecNodes = loadNodes(nodes);
	vector<Road> vecRoads = loadRoads(roads);
	vector<Connect> vecConnections = loadConnections(connections);


	for (unsigned int i = 0; i < vecNodes.size(); ++i) {
		graph.addVertex(vecNodes[i].node_id, degToCartLat(vecNodes[i].lat_deg),degToCartLong(vecNodes[i].long_deg));
	}

	for(unsigned int i = 0;i<vecConnections.size();i++){
		Road temp;
		Node nd1;
		Node nd2;
		for (unsigned int j = 0; j < vecRoads.size(); j++) {
			if (vecConnections[i].def_id == vecRoads[j].road_id) {
				temp = vecRoads[j];
				break;
			}
		}

		for (unsigned int j = 0; j < vecNodes.size(); j++) {
			if (vecConnections[i].node1 == vecNodes[j].node_id) {
				nd1 = vecNodes[j];
				break;
			}
		}

		for (unsigned int j = 0; j < vecNodes.size(); j++) {
			if (vecConnections[i].node2 == vecNodes[j].node_id) {
				nd2 = vecNodes[j];
				break;
			}
		}

		if(temp.is_two_way){
			graph.addEdge(vecConnections[i].node1,vecConnections[i].node2,distance(nd1.lat_deg,nd1.long_deg,nd2.lat_deg,nd2.long_deg));
			graph.addEdge(vecConnections[i].node2,vecConnections[i].node1,distance(nd1.lat_deg,nd1.long_deg,nd2.lat_deg,nd2.long_deg));
		}else
			graph.addEdge(vecConnections[i].node1,vecConnections[i].node2,distance(nd1.lat_deg,nd1.long_deg,nd2.lat_deg,nd2.long_deg));
	}

	return graph;
}

vector <Node> LoadGraph::loadNodes(const string &nodes){
	vector<Node> ret;
	ifstream input(nodes.c_str());

	for( string line; getline( input, line ); ){
		int in = 0,comp = 0,var = 0;
		Node temp;

		for(unsigned int i = 0; i<line.size(); i++){
			if(line[i]==';'){
				if(var == 0){
					temp.node_id = abs(atoi((line.substr(in,comp)).c_str()));
					in = i+1;
					comp = 0;
					var++;
				}else if(var == 1){
					temp.lat_deg = atof((line.substr(in,comp)).c_str());
					in = i+1;
					comp = 0;
					var++;
				}else if(var == 2){
					temp.long_deg = atof((line.substr(in,comp)).c_str());
					in = i+1;
					comp = 0;
					var++;
				}else if(var == 3){
					temp.long_rad = atof((line.substr(in,comp)).c_str());
					in = i+1;
					comp = 0;
					var++;
				}
			}else if(var == 4){
				temp.lat_rad = atof((line.substr(in,line.size()-1)).c_str());
				break;
			}else
				comp++;
		}

		ret.push_back(temp);
	}

	return ret;
}

vector <Road> LoadGraph::loadRoads(const string &roads){
	vector<Road> ret;

	ifstream input(roads.c_str());

	for( string line; getline( input, line ); ){
		int in = 0,comp = 0,var = 0;

		Road temp;

		for(unsigned int i = 0;i<line.size();i++){
			if(line[i]==';'){
				if(var == 0){
					temp.road_id = abs(atoi((line.substr(in,comp)).c_str()));
					in = i+1;
					comp = 0;
					var++;
				}else if(var == 1){
					temp.road_name = line.substr(in,comp);
					in = i+1;
					comp = 0;
					var++;
				}
			}else if(var == 2){
				if(line.substr(in,line.size()-1) == "True")
					temp.is_two_way = true;
				else
					temp.is_two_way = false;
				break;
			}else
				comp++;
		}

		ret.push_back(temp);
	}

	return ret;
}

vector <Connect> LoadGraph::loadConnections(const string &connections){
	vector<Connect> ret;
	int tempID = 1;

	ifstream input(connections.c_str());

	for( string line; getline( input, line ); ){
		int in = 0,comp = 0,var = 0;

		string ID = "",x = "",y = "";

		Connect temp;

		for(unsigned int i = 0;i < line.size();i++){
			if(line[i]==';'){
				if(var == 0){
					temp.def_id = abs(atoi((line.substr(in,comp)).c_str()));
					in = i+1;
					comp = 0;
					var++;
				}else if(var == 1){
					temp.node1 = abs(atoi((line.substr(in,comp)).c_str()));
					in = i+1;
					comp = 0;
					var++;
				}
			}else if(var == 2){
				temp.node2 = abs(atoi((line.substr(in,line.size()-1)).c_str()));
				break;
			}else
				comp++;
		}
		temp.road_id = tempID;
		tempID++;
		ret.push_back(temp);
	}
	return ret;
}

double LoadGraph::degToCartLat(double coord){
	double ret = 0, maxWin=WIDTH_SIZE;

	double lat_min = 41.40894;
	double lat_max = 41.24228;

	double dLat = lat_max - lat_min;

	ret = ((coord - lat_min) * maxWin)/dLat;

	return ret;
}

double LoadGraph::degToCartLong(double coord){
	double ret = 0, maxWin=HEIGHT_SIZE;

	double long_min = -8.780089;
	double long_max = -8.605257;

	double dLong = long_max - long_min;


	ret = ((coord - long_min) * maxWin)/dLong;
	return ret;
}

double LoadGraph::distance(double aLat,double aLong,double bLat,double bLong){
	double ax = degToCartLong(aLong);
	double ay = degToCartLat(aLat);
	double bx = degToCartLong(bLong);
	double by = degToCartLong(bLat);

	return sqrt( pow((bx-ax),2) + pow((by-ay),2));
}