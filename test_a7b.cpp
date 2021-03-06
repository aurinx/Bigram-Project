/*
 Aurin Chakravarty
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "a7b.h"

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
int main()
{
  map<string, map<string, int>> dataMap;

  assert(readFile(dataMap, cin)==0); //since text file is not empty

  string temp;
  int count=0;

  assert(findStart(dataMap, temp)==0); //since there is a "<START>" in the text file

  assert(readFile(dataMap, cin)==1);

  assert(countFrequency(dataMap, temp, count)==0); //since each word has a nonzero frequency

  assert(readFile(dataMap, cin)==1);

  assert(countFrequency(dataMap, temp, count)==0);

  map<string, map<string, int>> tester;  //empty map

  assert(findStart(tester, temp)==1);

  assert(countFrequency(tester, temp, count)==1);

  return 0;
}
