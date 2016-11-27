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
#include "a7a.h"

//run this file with input redirection, like: ./a.out < test.txt, or it will not work

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

  string combinedWord;
  string firstWord;
  string secondWord;
  string temp;
  map<string, int> counters;

  cin >> firstWord;
  combinedWord = "<START> " + firstWord;
  ++counters[combinedWord];
  temp = firstWord;

  assert(readTextFile(cin, counters, combinedWord, firstWord, temp)==0); //true because text file is not empty

  combinedWord = temp + " <END>";
  ++counters[combinedWord];

  assert(forwardOrder(counters)==0); //true because text file is not empty

  assert(reverseOrder(counters)==0); //true because text file is not empty

  assert(readTextFile(cin, counters, combinedWord, firstWord, temp)==1);

  assert(countOrder(counters)==0); //true because text file is not empty



  map<string, int> tester;

  assert(forwardOrder(tester)==1);

  assert(reverseOrder(tester)==1);

  assert(countOrder(tester)==1);


  return 0;
}
