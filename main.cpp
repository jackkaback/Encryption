#include <iostream>
#include <bitset>
#include <fstream>

//EVIL BIT LEVEL HACKING
using namespace std;

int main() {
	fstream target;

	target.open("test.txt", ios::out | ios::in | ios::binary);

	target << "Hello world";

	srand (time(NULL));

	//8 bit int
	int8_t a = 89;
	cout << a << endl;

	//convert to bit string
	bitset<8> x(a);
	cout << x << endl;

	//invert a bit
	x[0] = !x[0];
	cout << x << endl;

	//convert back to int
	a = (int)x.to_ulong();

	target.close();
	return 0;
}