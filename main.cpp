#include <iostream>
#include <bitset>
#include <fstream>
#include <vector>

//EVIL BIT LEVEL HACKING
using namespace std;

int main() {
	fstream target;
	vector<string> lines;
	string string1;
	target.open("test.txt", ios::out | ios::in | ios::binary);

	while(getline(target,string1)){
		cout << string1 << endl;
		lines.push_back(string1);
	}

//	for(int ii = 0; ii < lines.size(); ii++){
//		target << lines[ii];
//	}

	target << "Hello world";

//	srand (time(NULL));
//
//	//8 bit int
//	int8_t a = 89;
//	cout << a << endl;
//
//	//convert to bit string
//	bitset<8> x(a);
//	cout << x << endl;
//
//	//invert a bit
//	x[0] = !x[0];
//	cout << x << endl;
//
//	//convert back to int
//	a = (int)x.to_ulong();

	target.close();
	return 0;
}