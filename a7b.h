/*
Aurin Chakravarty
Last Modified: Nov 7 2016
 */
#ifndef a7b_h
#define a7b_h

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <functional>

/*using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::istream;
using std::binary_function;
using std::pair;
*/
using namespace std;
int readFile(map<string, map<string, int>> &dataMap, istream &cin);

int findStart(map<string, map<string, int>> &dataMap, string &temp);

int countFrequency(map<string, map<string, int>> &dataMap, string temp, int &count);

#endif
