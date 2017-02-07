//Collin Kinchen
//CS 356
//PA1

#include "Cipher.h"

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;

int errorMessage(int i)
{  
	switch(i){
	case 1: cerr << "Error: Wrong number of arguments" << endl; break;
	case 2: cerr << "Error: Argument 1 needs to be a B or an S" << endl; break;
	case 3: cerr << "Error: Input file could not be found" << endl; break;
	case 4: cerr << "Error: Could not find the Keyfile" << endl; break;
	case 5: cerr << "Error: Argument 5 needs to be a E or an D" << endl; break;
	}
  return -1;
}

int main(int argc, char* argv[]){
	
	
if (argc != 6) return errorMessage(1);

string arg1 = argv[1];
if (arg1 != "B"){
	if (arg1 != "S") return errorMessage(2);
}

ifstream istr(argv[2]);
 if (istr.fail()) return errorMessage(3);
 
ifstream istr2(argv[4]);
 if (istr2.fail()) return errorMessage(4);
 
 string arg5 = argv[5];
if (arg5 != "E"){
	if (arg5 != "D") return errorMessage(5);
}
	
	/*    

// argv[2] = K(number of clusters)
  if (argc != 3) return errorMessage(1);
 
 
  ifstream istr(argv[1]);
  if (istr.fail()) return errorMessage(2);
  
	
  Histogram h1;
  if (!h1.ReadFiles(istr)) return errorMessage(4);
  temp = h1.returnOBJ();
  tempCount = h1.returnCount();
  if (numClusters < 1 || numClusters > tempCount) return errorMessage(7);
  
  if (tempCount < 2) return errorMessage(6);
  
  
 
  for (int i = 0; i < tempCount; i++){
  a = temp[i].Name();

  ifstream istr2(a);
  if (istr2.fail()) return errorMessage(2);
  if (!h1.ReadHeader(istr2,i)) return errorMessage(3);
  if (!h1.Read(istr2,i)) return errorMessage(4);

  h1.Normalize(i);
  }//gets all the histograms and normalizes them 
  
  h1.copyObj();

  if (numClusters == tempCount){//if K=N print out the clusters and end
      h1.Print();
      return 0;
	}  
  while (numClusters != tempCount){
    
  for (int i = 0; i < tempCount; i++){
	  h1.Mult(i); 
  } 
  
  h1.findClosest();
  tempCount--;   

  }
  h1.Print();
 
*/
return 0;
}