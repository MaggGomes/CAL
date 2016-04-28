#ifndef LOADGRAPH_H
#define LOADGRAPH_H

#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Utilities.h"
#include "Graph.h"

#define WIDTH_SIZE 600
#define HEIGHT_SIZE 600

using namespace std;

struct Node{
	int node_id;
	double lat_deg;
	double  long_deg;
	double  long_rad;
	double lat_rad;
};

struct Road{
	int road_id;
	string road_name;
	bool is_two_way;
};

struct Connect{
	int road_id;
	int def_id;
	int node1;
	int node2;
};

/**
 * @brief Functional class to load .txt files and create a working graph
 */
class LoadGraph{
public:
	static Graph<int> createGraph(const string &nodes, const string &roads, const string &connections);
	static vector <Node> loadNodes(const string &nodes);
	static vector <Road> loadRoads(const string &roads);
	static vector <Connect> loadConnections(const string &connections);
	static double degToCartLat(double coord);
	static double degToCartLong(double coord);
	static double distance(double aLat,double aLong,double bLat,double bLong);
};

#endif // LOADGRAPH_H
