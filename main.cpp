#include <iostream>
#include <bitset>
#include <fstream>
#include <vector>

//EVIL BIT LEVEL HACKING
using namespace std;

void encrypt(vector<string> &lines){
	string currLine;

	for(int ii = 0; ii < lines.size(); ii++) {
		currLine = lines[ii];

		for(int jj = 0; jj < currLine.size(); jj++) {
			bitset<8> bitset(currLine[jj]);

			for (int k = 0; k < 8; k++){
				bitset[k] = !bitset[k];
			}

			currLine[jj] = char(bitset.to_ullong());
		}
		lines[ii] = currLine;
	}
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

void write(vector<string> &lines, string source){
	fstream target;
	target.open(source);

	for(int ii = 0; ii < lines.size(); ii++){
		target << lines[ii] << endl;
	}

	target.close();
}

int main() {

	vector<string> lines;
	string source;

	cout << "Enter the target file" << endl;
	cin >> source;

	read(lines, source);

	encrypt(lines);

	write(lines, source);

	return 0;
}