/*                                                                                                             
Aurin Chakravarty                                                                                                                                                                                                  
Last Modified: Nov 7 2016                                                                                      
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
#include <functional>
#include "a7a.h"

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

//input of "a"
int forwardOrder(map<string, int> &counters) {
  int count = 0;
  //iterator for the map given, count through as iterating and cout the current first and second words
  for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
    cout << it -> first << " " << it->second << '\n';
    count++;
  }
  if (count == 0) {
    return 1;
  } else {
    return 0;
  }
  return 0;
}

// input of "r"
int reverseOrder(map<string, int> &counters) {
  int count = 0;
  // similar concept to forwardOrder, except use reverse_iterator class within std
  map<string, int>::reverse_iterator it;
  for(it = counters.rbegin(); it!=counters.rend(); ++it) {
    cout << it -> first << " " << it -> second << '\n';
    count++;
  }
  if (count == 0) {
    return 1;
  } else {
    return 0;
  }
  return 0;
}
// struct to help with comparing values between pairs so that it goes in ascending order
struct val_lessthan:binary_function <pair<string,int>, pair<string,int>, bool> {
  bool operator() (pair<string,int>&first, pair<string,int>&second) {
    return first.second < second.second;
  }
}sortFrequency;

// input of "c"
int countOrder(map<string, int> &counters) {
  //vector to help store the pairs and their respective frequencies
  vector <pair<string, int> > wordFrequency;
  copy(counters.begin(), counters.end(), back_inserter(wordFrequency));
  //Sort the collection in order to that it is in ascending order
  sort(wordFrequency.begin(), wordFrequency.end(), sortFrequency);

  int sizeVector = wordFrequency.size();
  int count = 0;
  //count the wordFrequencies found in the vector
  for (int i = 0; i < sizeVector; i++) {
    cout << wordFrequency[i].first << " " << wordFrequency[i].second << '\n';
    count++;
  }

  if (count == 0) {
    return 1;
  }
  return 0;
}
// Method to read the input file, used in the main method
int readTextFile(istream &cin, map<string, int> &counters, string &combinedWord, string firstWord, string &temp) {
  int counter = 0;
  while(cin >> firstWord) {
    combinedWord = temp + " " + firstWord;
    ++counters[combinedWord];
    temp = firstWord;
    counter++;
  }
  if (counter == 0) {
    return 1;
  }
  return 0;
}

int main(int argc, char **argv) {
  if (argc==1) {
    printf("Need command line argument");
    puts("");
    return 1;
  }
  //string that has both words
  string combinedWord;
  //first word
  string firstWord;
  //second word
  string secondWord;
  string temp;
  //count for pairs
  map<string, int> counters;

  cin >> firstWord;
  //add start to first word
  combinedWord = "<START> " +firstWord;
  ++counters[combinedWord];
  temp = firstWord;

  readTextFile(cin, counters, combinedWord, firstWord, temp);
  //add end to last word
  combinedWord = temp + " <END>";
  ++counters[combinedWord];
  //the options given for the program, outputs error if invalid
  if (argv[1][0] == 'a') {
    forwardOrder(counters);
  } else if (argv[1][0] == 'r') {
    reverseOrder(counters);
  } else if (argv[1][0] == 'c') {
    countOrder(counters);
  } else {
    cout << "Please enter a valid input from command line" << endl;
    return 1;
  }

  return 0;

}
