/*                                                                                                             
Aurin Chakravarty                                                                                                                                                                                                  
Last Modified: Nov 7 2016                                                                                      
*/
#ifndef a7a_h
#define a7a_h

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

int forwardOrder(map<string, int> &counters);
int reverseOrder(map<string, int> &counters);
int countOrder(map<string, int> &counters);
int readTextFile(istream &cin, map<string, int> &counters, string &combinedWord, string firstWord, string &temp);

#endif
