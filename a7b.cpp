/*                                                                                                             
Aurin Chakravarty                                                                                              
600.120                                                                                                        
Assignment 7                                                                                                   
achakr16                                                                                                       
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
//method to read the file, used in main method
int readFile(map<string, map<string, int>> &dataMap, istream &cin) {
  string firstWord;
  string secondWord;
  int frequency;
  int count=0;
  while (!cin.eof()) {
    cin >> firstWord;
    cin >> secondWord;
    cin >> frequency;
    //store the words w/ their respective frequency
    dataMap[firstWord][secondWord] = frequency;
    count++;
  }
  if (count==0) {
    return 1;
  }
  return 0;
}
// locate where first word is to indicate it with <START>
int findStart(map<string, map<string, int>> &dataMap, string &temp) {
  int count=0;
  for(map<string, map<string, int> >::iterator it=dataMap.begin(); it!=dataMap.end(); ++it){
    for (map<string, int>:: iterator j=it->second.begin(); j!=it->second.end();++j) {
      if (it->first == "<START>") {
	cout << it->first << ' ';
	count++;
      }
      temp = j->first;
    }
  }
  if (count==0) {
    return 1;
  }
  return 0;
}

//method to keep track of various pair frequencies
int countFrequency(map<string, map<string, int>> &dataMap, string temp, int &count) {
  int counter=0;
  for(map<string, map<string, int> >::iterator it=dataMap.begin(); it!=dataMap.end(); ++it){
    for (map<string, int>:: iterator j=it->second.begin(); j!=it->second.end();++j) {
      if (it->first == temp) {
	count = count+(j->second);
	counter++;
      }

    }
  }
  if (counter==0) {
    return 1;
  }
  return 0;

}

int main(int argc, char **argv) {
  if (argc==1) {
    cout << "Forgot to add command line argument" << endl;
    return 1;
  }
  map<string, map<string, int>> dataMap;
  readFile(dataMap, cin);
  string temp;

  int doneProgram=0;
  int count=0;
  int sentenceGenerated=0;
  int end=0;
  int total=0;
  //make input a number
  int iterations = atoi(argv[1]);
  //seeded random number
  srand(8922);
  while (doneProgram < iterations) {
    findStart(dataMap, temp);

    while (sentenceGenerated==0) {
      countFrequency(dataMap, temp, count);
      while (end==0) {
	int randomNum = rand()%count;
	//iterates through map of string 
	for(map<string, map<string, int> >::iterator it=dataMap.begin(); it!=dataMap.end(); ++it){
	  for (map<string, int>:: iterator j=it->second.begin(); j!=it->second.end();++j) {
	    if (it->first == temp) {
	      total = total+(j->second);
	      //checks if number of words has exceeded the random number
	      if (total >= randomNum) {
		cout << ' ' << j->first << ' ';
		temp = j->first;
		if (j->first == "<END>") {
		  sentenceGenerated=1;
		}
		count=0;
		total=0;
		end=1;
	      }

	    }

	  }
	}
      }
      end--;
    }
    sentenceGenerated--;
    cout << ' ' <<endl;
    doneProgram++;
  }
  return 0;
}
