//============================================================================
// Name        : dasda.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
	vector <int> vec;
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);


	unordered_map <string,vector<int>> tempMapVec;
	unordered_map <string,int> tempMap;

	tempMap.insert(make_pair("abc", 2));
	tempMap.insert(make_pair("a", 3));
	tempMapVec.insert(make_pair("abc", vec));

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	sort(vec.begin(), vec.end());

	for (size_t i = 0; i < tempMapVec["abc"].size(); i++){
		cout << tempMapVec["abc"][i] << endl;
	}

	for (size_t i = 0; i < vec.size(); i++){
		cout << vec[i] << endl;
	}


	return 0;
}
