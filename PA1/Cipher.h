//Collin Kinchen
//CS 356
//PA1

#ifndef HISTOGRAM_H_INCLUDE
#define CIPHER_H_INCLUDE

#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
#include <stdlib.h>


using std::istream;
using std::ofstream;
using std::ostream;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::string;
using std::min;
using std::max;
using std::hex;
//using std::pow;
using std::string;
using std::stringstream;
 
class Cipher{
public:
bool Read(istream& istr);
bool ReadKey(istream& istr);
vector<char> plainTextVec;
vector<char> cipherTextVec;
vector<int> plainDecVec;
vector<char> charKey;
vector<int> decKey;
int count = 0;
int keyCount = 0;
void padding();
void removepadding();
void blockXOR();
void swap();
void write(string outFile);
void streamXOR();

private:


};
#endif // CIPHER_H_INCLUDE