#include <cstdio>
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
	long long int road_id;
	int node1;
	int node2;
};

vector<typeA> txtAReader();
vector<typeB> txtBReader();
vector<typeC> txtCReader();

vector<typeA> txtAReader(){
	vector<typeA> ret;
	ifstream input( "nos.txt" );
	for( string line; getline( input, line ); ){
		int in = 0,comp = 0,var = 0;
		typeA temp;

		for(int i = 0;i<line.size();i++){
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
					temp. long_deg = atof((line.substr(in,comp)).c_str());
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
				temp.lat_deg = atof((line.substr(in,line.size()-1)).c_str());
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

	ifstream input( "arestas.txt" );
	for( string line; getline( input, line ); ){
		int in = 0,comp = 0,var = 0;

		typeB temp;

		for(int i = 0;i<line.size();i++){
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
		ret.push_back(temp);
	}
	return ret;
}

vector<typeC> txtCReader(){
	vector<typeC> ret;
	ifstream input( "ligacoes.txt" );
	long long int nodeCmp = 0;
	int subNode = 1;


	for( string line; getline( input, line ); ){
		int in = 0,comp = 0,var = 0;

		string ID = "",x = "",y = "";

		typeC temp;

		for(unsigned int i = 0;i < line.size();i++){
			if(line[i]==';'){
				if(var == 0){
					if(atoll((line.substr(in,comp)).c_str()) == nodeCmp){
						subNode++;
					}else{
						subNode = 1;
						nodeCmp = atoll((line.substr(in,comp)).c_str());
					}
					temp.road_id = (atoll((line.substr(in,comp)).c_str()) * 1000) + subNode;
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
		cout << temp.road_id << endl;
		ret.push_back(temp);
	}
	return ret;
}
