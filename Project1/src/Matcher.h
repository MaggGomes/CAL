#ifndef MATCHER_H_
#define MATCHER_H_

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Student.h"
using namespace std;

/**
 * @brief Compares 2 students according to the name's edition distance
 *
 * @param student 1
 * @param student 2
 */
bool compStudentNED (Student * s1, Student* s2);

/**
 * @brief Compares 2 students according to the road's edition distance
 *
 * @param student 1
 * @param student 2
 */
bool compStudentRED (Student * s1, Student* s2);

void pre_kmp(string pattern, vector<int> & prefix);

int kmp(string text, string pattern);

int numStringMatching(string filename,string toSearch);

int editDistance(string pattern, string text);

float numApproximateStringMatching(string filename,string toSearch);

#endif // MATCHER_H_
