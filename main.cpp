#include <iostream>
#include <bitset>
#include <fstream>
#include <vector>

//EVIL BIT LEVEL HACKING
using namespace std;

void write(vector<string> &lines, string source){
	fstream target;

	target.open(source);
	for(int ii = 0; ii < lines.size(); ii++){
		target << lines[ii] << endl;
	}

	target << "Testing" << endl;
	target.close();
}

void read(vector<string> &lines, string source){
	string l;
	fstream target;
	target.open(source);

	while(getline(target,l)){
		cout << l << endl;
		lines.push_back(l);
	}

	target.close();
}

int main() {

	vector<string> lines;
	string source = "test.txt";

	read(lines, source);
	write(lines, source);
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

	return 0;
}