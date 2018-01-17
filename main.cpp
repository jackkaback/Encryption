#include <iostream>
#include <bitset>
#include <fstream>
#include <vector>

//EVIL BIT LEVEL HACKING
using namespace std;

void encrypt(vector<string> &lines){
	string currLine;

	for (auto &line : lines) {
		currLine = line;

		for (char &jj : currLine) {
			bitset<8> bitset(jj);

			for (int k = 0; k < 8; k++){
				bitset[k] = !bitset[k];
			}

			jj = char(bitset.to_ullong());
		}
		line = currLine;
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

	for (const auto &line : lines) {
		target << line << endl;
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