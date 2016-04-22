#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct typeA{
	int node_id;
	double lat_deg;
	double  long_deg;
	double  long_rad;
	double lat_rad;
};

struct typeB{
	int road_id;
	string road_name;
	bool is_two_way;
};

struct typeC{
	int road_id;
	int def_id;
	int node1;
	int node2;
};

vector<typeA> txtAReader(){
	vector<typeA> ret;
	ifstream input( "res/nos.txt" );
	for( string line; getline( input, line ); ){
		int in = 0,comp = 0,var = 0;
		typeA temp;

		for(unsigned int i = 0; i<line.size(); i++){
			if(line[i]==';'){
				if(var == 0){
					temp.node_id = atoi((line.substr(in,comp)).c_str());
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

vector<typeB> txtBReader(){
	vector<typeB> ret;

	ifstream input( "res/arestas.txt" );
	for( string line; getline( input, line ); ){
		int in = 0,comp = 0,var = 0;

		typeB temp;

		for(unsigned int i = 0;i<line.size();i++){
			if(line[i]==';'){
				if(var == 0){
					temp.road_id = atoi((line.substr(in,comp)).c_str());
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

		cout << temp.road_id << endl;
	}
	return ret;
}

vector<typeC> txtCReader(int &tempID){
	vector<typeC> ret;
	ifstream input( "res/ligacoes.txt" );

	for( string line; getline( input, line ); ){
		int in = 0,comp = 0,var = 0;

		string ID = "",x = "",y = "";

		typeC temp;

		for(unsigned int i = 0;i < line.size();i++){
			if(line[i]==';'){
				if(var == 0){
					temp.def_id = atoi((line.substr(in,comp)).c_str());
					in = i+1;
					comp = 0;
					var++;
				}else if(var == 1){
					temp.node1 = atoi((line.substr(in,comp)).c_str());
					in = i+1;
					comp = 0;
					var++;
				}
			}else if(var == 2){
				temp.node2 = atoi((line.substr(in,line.size()-1)).c_str());
				break;
			}else
				comp++;
		}
		temp.road_id = tempID;
		tempID++;
		ret.push_back(temp);

		cout << temp.road_id << " - " << temp.def_id << endl;
	}
	return ret;
}

int deg_to_cartLat(double coord){
	int ret = 0, maxWin=600;

	double lat_min = 41.1890;
	double lat_max = 41.1686;

	double dLat = lat_max - lat_min;

	ret = ((coord - lat_min) * maxWin)/dLat;

	return ret;
}

int deg_to_cartLong(double coord){
	int ret = 0, maxWin=600;

	double long_min = -8.6225;
	double long_max = -8.5843;

	double dLong = long_max - long_min;


	ret = ((coord - long_min) * maxWin)/dLong;
	return ret;
}

GraphViewer * graphCreator(vector<typeA> vecA, vector<typeB> vecB, vector<typeC> vecC){
	GraphViewer *gv = new GraphViewer(600,600,false);
	gv->createWindow(600,600);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	gv->defineEdgeCurved(false);

	for(unsigned int i = 0;i<vecA.size();i++){
		gv->addNode(vecA[i].node_id,deg_to_cartLat(vecA[i].lat_deg),deg_to_cartLong(vecA[i].long_deg));
		gv->setVertexSize(vecA[i].node_id, 5);
	}

	for(unsigned int i = 0;i<vecC.size();i++){
		typeB temp;

		for (unsigned int j = 0; j < vecB.size(); j++) {
			if (vecC[i].def_id == vecB[j].road_id) {
				temp = vecB[j];
				break;
			}
		}

		if(temp.is_two_way)
			gv->addEdge(vecC[i].road_id,vecC[i].node1,vecC[i].node2,EdgeType::UNDIRECTED);
		else
			gv->addEdge(vecC[i].road_id,vecC[i].node1,vecC[i].node2,EdgeType::DIRECTED);
	}

	return gv;
}
