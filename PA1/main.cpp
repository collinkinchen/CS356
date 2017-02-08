//Collin Kinchen
//CS 356
//PA1

#include "Cipher.h"

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;

int errorMessage(int i)
{  
	switch(i){
	case 1: cerr << "Error: Wrong number of arguments" << endl; break;
	case 2: cerr << "Error: Argument 1 needs to be a B or an S" << endl; break;
	case 3: cerr << "Error: Input file could not be found" << endl; break;
	case 4: cerr << "Error: Could not find the Keyfile" << endl; break;
	case 5: cerr << "Error: Argument 5 needs to be a E or an D" << endl; break;
	case 6: cerr << "Error: Could not read file properly" << endl; break;
	}
  return -1;
}

int main(int argc, char* argv[]){
	
Cipher c1;	
if (argc != 6) return errorMessage(1);

string arg1 = argv[1];
if (arg1 != "B"){
	if (arg1 != "S") return errorMessage(2);
}
bool block = false;
if (arg1 == "B") {block = true;}

ifstream istr(argv[2]);
 if (istr.fail()) return errorMessage(3);
 
ifstream istr2(argv[4]);
 if (istr2.fail()) return errorMessage(4);
 if (!c1.ReadKey(istr2)) return errorMessage(6);
 
 string arg5 = argv[5];
if (arg5 != "E"){
	if (arg5 != "D") return errorMessage(5);
}
bool Encrypt = false;
if (arg5 == "E") {Encrypt = true;}


if (!c1.Read(istr)) return errorMessage(6);

if (block == true){
	
	if (Encrypt == true){
		c1.padding();
		c1.blockXOR();
		c1.swap();
		c1.write(argv[3]);	
	}
	else if (Encrypt == false){
		c1.swap();
		c1.blockXOR();    //somewhere this shit fucks up
		c1.removepadding();
		c1.write(argv[3]);
	}
}
else if (block == false){
	c1.streamXOR();
	c1.write(argv[3]);
}


// c1.blockXOR();
// c1.swap();
// c1.write(argv[3]);

return 0;
}