//Collin Kinchen
//CS 356
//PA1

#include "Cipher.h"

bool Cipher::Read(istream& istr){

	char c;
	while(istr.get(c)){
		plainTextVec.push_back(c);
		count++;
	}
	for(int i = 0; i < count; i++){
		int temp = (int)plainTextVec[i];
		
		plainDecVec.push_back(temp);
	}
	// cout << "PLAIN TEXT" << endl;
	// for(int i = 0; i < count; i++){
		// cout << plainTextVec[i] << ": " << plainDecVec[i] << endl;	
	// }
	// cout << count << endl;
	return true;
}

void Cipher::padding(){
	//cout << "PADDED" << endl;
	int numToAdd = 8 - (count % 8);
	//cout << numToAdd << endl;
	
	for(int i = 0; i < numToAdd; i++){
		plainDecVec.push_back(128);
		count++;
	}
	// for(int i = 0; i < count; i++){
		// cout << i << ": " << plainDecVec[i] << endl;	
	// }
}

bool Cipher::ReadKey(istream& istr){

	char c;
	while(istr.get(c)){
		charKey.push_back(c);
		keyCount++;
	}
	for(int i = 0; i < keyCount; i++){
		int temp = (int)charKey[i];
		
		decKey.push_back(temp);
	}
	// cout << "KEY" << endl;
	// for(int i = 0; i < keyCount; i++){
		// cout << charKey[i] << ": " << decKey[i] << endl;
	// }
	return true;
}

void Cipher::blockXOR(){
	int loop = (count / 8);
	//cout << loop << endl;
	int blockCount = 0;
	for (int i = 0; i < loop; i++){
		for (int j = 0; j < 8; j++){
		plainDecVec[blockCount] ^= decKey[j];
		blockCount++;
		}
	}
	// cout << "AFTER XOR" << endl;
	
	// for(int i = 0; i < count; i++){
		// cout << i << ": " << plainDecVec[i] << endl;
	// }
}

void Cipher::swap(){
	int start = 0;
	int end = count - 1;
	
	int loop = (count / 8);
	for (int i = 0; i < loop; i++){
		for (int j = 0; j < 8; j++){
		int temp = (decKey[j] % 2);
		// cout << temp << endl;
		if (temp == 0) start++;
		else if (temp == 1){
			int startTemp = plainDecVec[start];
			int endTemp = plainDecVec[end];
			plainDecVec[start] = endTemp;
			plainDecVec[end] = startTemp;
			start++;
			end--;
		}
		if (start >= end ) break;
		
		}
		if (start >= end ) break;
	}
	// cout << "AFTER SWAP" << endl;
	// for(int i = 0; i < count; i++){
		// cout << i << ": " << plainDecVec[i] << endl;
	// }
	
}

void Cipher::write(string outFile){
	// cout << outFile << endl;
	ofstream myfile;
	myfile.open (outFile);
	
	for(int i = 0; i < count; i++){
		char temp = (char)plainDecVec[i];
		
		cipherTextVec.push_back(temp);
	}

	for(int i = 0; i < count; i++){
		myfile << cipherTextVec[i];
	}
	myfile.close();	
}

void Cipher::removepadding(){
	
	// int numToDel = (count % 8);
	// cout << numToDel << endl;
		// count -= numToDel;
		
	// for(int i = 0; i < count; i++){
		// cout << plainDecVec[i] << endl;
	// }	
	//cout << "Before count:" << count << endl;
		int tempCount = count;
	for(int i = 0; i < tempCount; i++){
		if( plainDecVec[i] > 127 || plainDecVec[i] < 0) count--;
	}
	//cout << "after count:" << count << endl;

}

void Cipher::streamXOR(){
	//int loop = (count / keyCount);
	//cout << loop << endl;
	int blockCount = 0;
	while (blockCount < count){
		for (int j = 0; j < keyCount; j++){
		plainDecVec[blockCount] ^= decKey[j];
		blockCount++;
		
		}
		
	}
	
}