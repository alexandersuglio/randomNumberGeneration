//Alexander Suglio
//FSUID AJS17M
//Assignment 4

#include <iostream>
#include <cstdlib>
#include <iomanip>

#include <ctime>


using namespace std;

void seedRNG(int seed);
int getRand(int min, int max);
void testGetRand();

int getMin(int a, int b, int c);
void testGetMin();

void getMin(int a, int b, int c, int & min);
void testGetMinRef();

int getMax(int a, int b, int c);
void testGetMax();

void getMax(int a, int b, int c, int & max);
void testGetMaxRef();

void getMinMax(int a, int b, int c, int & min, int & max);
void testGetMinMax();

void formatDouble(double d, int numDecimals);
void testFormatDouble();

bool isEven(int x);
void testIsEven();

void printChar(char c, int numTimes);
void testPrintChar();

double fToC(double f);
void testfToC();

double cToF(double c);
void testcToF();

//@include(main)
//@addRule(commentAll)
int main() {
	
	int selection;
	cout << "Choose a test:" << endl;
	cout << "1) testGetRand()" << endl;
	cout << "2) testGetMin()" << endl;
	cout << "3) testGetMinRef()" << endl;
	cout << "4) testGetMax()" << endl;
	cout << "5) testGetMaxRef()" << endl;
	cout << "6) testGetMinMax()" << endl;
	cout << "7) testFormatDouble()" << endl;
	cout << "8) testIsEven()" << endl;
	cout << "9) testPrintChar()" << endl;
	cout << "10) testfToC()" << endl;
	cout << "11) testcToF()" << endl;

	cout << "Selection:";
		cin >> selection;

	switch (selection) {
	case 1:
		testGetRand();
		cout << "Press ENTER to exit";
		break;
	case 2:
		testGetMin();
		cout << "Press ENTER to exit";
		break;
	case 3:
		testGetMinRef();
		cout << "Press ENTER to exit";
		break;
	case 4:
		testGetMax();
		cout << "Press ENTER to exit";
		break;
	case 5:
		testGetMaxRef();
		cout << "Press ENTER to exit";
		break;
	case 6:
		testGetMinMax();
		cout << "Press ENTER to exit";
		break;
	case 7:
		testFormatDouble();
		cout << "Press ENTER to exit";
		break;
	case 8:
		testIsEven();
		cout << "Press ENTER to exit";
		break;
	case 9:
		testPrintChar();
		cout << "Press ENTER to exit";
		break;
	case 10:
		testfToC();
		cout << "Press ENTER to exit";
		break;
	case 11:
		testcToF();
		cout << "Press ENTER to exit";
		break;

	default:
		cout << "Invalid test number\nPress ENTER to exit";
	}

	cin.ignore(80, '\n');
	cin.get();
}
//@removeRule(commentAll)

void seedRNG(int seed) {
srand(seed);
}  

int getRand(int min, int max){

	int random = rand() % (max + 1);
	return random;
}

void testGetRand() {
	seedRNG(0);
	for (int i = 0; i < 10; ++i) {
		cout << "random[" << i << "]=" << getRand(0, 100) << endl;	
	}
}


int getMin(int a, int b, int c) {

int minimum = a;
if (b < minimum) {
	minimum= b;
}
if (c < minimum) {
	minimum = c;
}
return minimum;
}


void testGetMin() {
	seedRNG(0);

	int minRand = 0;
	int maxRand = 100;
	int a = 0;
	int b = 0;
	int c = 0;
	 
	for (int i = 0; i < 10; ++i) {

		a = getRand(minRand, maxRand);
		b = getRand(minRand, maxRand);
		c = getRand(minRand, maxRand);
		cout << "MIN[" << i << "](" << a << "," << b << "," << c << ")=" << getMin(a, b, c) << "\n";
	}
}

void getMin(int a, int b, int c, int & min) {
	min = a;

	if (b < min) {
		min = b;
	}
	if (c < min) {
		min = c;
	}
}


void testGetMinRef() {
	seedRNG(0);

	int minRand = 0;
	int maxRand = 100;
	int a = 0;
	int b = 0;
	int c = 0;
	int myMin = 0;

	for (int i = 0; i < 10; ++i) {

		a = getRand(minRand, maxRand);
		b = getRand(minRand, maxRand);
		c = getRand(minRand, maxRand);
		getMin(a, b, c, myMin);
		cout << "MINREF[" << i << "](" << a << "," << b << "," << c << ")=" << myMin << "\n";
	}
}


int getMax(int a, int b, int c) {

	int maximum = a;
	if (b > maximum) {
		maximum = b;
	}
	if (c > maximum) {
		maximum = c;
	}
	return maximum;
}

void testGetMax() {
	seedRNG(0);

	int minRand = 0;
	int maxRand = 100;
	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 0; i < 10; ++i) {

		a = getRand(minRand, maxRand);
		b = getRand(minRand, maxRand);
		c = getRand(minRand, maxRand);
		cout << "MAX[" << i << "](" << a << "," << b << "," << c << ")=" << getMax(a, b, c) << "\n";
	}
}

void getMax(int a, int b, int c, int & max) {
	max = a;

	if (b > max) {
		max = b;
	}
	if (c > max) {
		max = c;
	}
}


void testGetMaxRef() {
	seedRNG(0);

	int minRand = 0;
	int maxRand = 100;
	int a = 0;
	int b = 0;
	int c = 0;
	int myMax = 0;

	for (int i = 0; i < 10; ++i) {

		a = getRand(minRand, maxRand);
		b = getRand(minRand, maxRand);
		c = getRand(minRand, maxRand);
		getMax(a, b, c, myMax);
		cout << "MAXREF[" << i << "](" << a << "," << b << "," << c << ")=" << myMax << "\n";
	}
}

void getMinMax(int a, int b, int c, int & min, int & max) {

	min = a;
	max = b;

	if (max < min) {
		min = b;
		max = a;
	}
	if (c < min) {
		min = c;
	}
	if (c > max) {
		max = c;
	}
}


void testGetMinMax() {
	seedRNG(0);

	int minRand = 0;
	int maxRand = 100;
	int a = 0;
	int b = 0;
	int c = 0;
	int myMin = 0;
	int myMax = 0;

	for (int i = 0; i < 10; ++i) {

		a = getRand(minRand, maxRand);
		b = getRand(minRand, maxRand);
		c = getRand(minRand, maxRand);
		getMinMax(a, b, c, myMin, myMax);

		cout << "MINMAX[" << i << "](" << a << "," << b << "," << c << ")=" << myMin << "/" << myMax << "\n";
	}
}

void formatDouble(double d, int numDecimals) {
	 double placeholder = d;

cout << fixed << setprecision(numDecimals);
cout << placeholder;

}


void testFormatDouble() {

	double d = 1.123456789;
	for (int i = 0; i < 10; i++) {
		
		cout << "PRINTDOUBLE[" << i << "]=";
		formatDouble(d, i);
		cout << endl;
	}

}

bool isEven(int x) {
	int number = x;

	if (number % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}

void testIsEven() {
	seedRNG(0);
	for (int i = 0; i < 10; i++) {
		int r = getRand(0, 100);
		cout << "ISEVEN(" << r << ")=" << boolalpha << isEven(r) << endl;
	}

}


void printChar(char c, int numTimes) {

	char letter = c;
	int times = numTimes;

	for (int j = 0; j < times; j++) {
		cout << letter;
	}


}




void testPrintChar() {
	seedRNG(0);
	for (int i = 0; i < 10; i++) {
		char c = getRand(33, 93);
		int numTimes = getRand(1, 10);
		
		cout << "PRINTCHAR(" << c << ", " << numTimes << ")=";
		
		printChar(c, numTimes);
		
		cout << "\n";
	}
}



double fToC(double f) {
	double fahrenheit = f;
	double celsius = (f - 32) * 5/9;
	return celsius;
}

void testfToC() {
	seedRNG(0);
	for (int i = 0; i < 10; i++) {
		int f = getRand(0, 100);
		cout << "FTOC(" << f << ")=" << fToC(f) << "\n";
	}
}


double cToF(double c) {
	double celsius = c;
	double fahrenheit = c * 9/5 + 32;
	return fahrenheit;
}

void testcToF() {
	seedRNG(0);
	for (int i = 0; i < 10; i++) {
		int c = getRand(0, 100);
		cout << "CTOF(" << c << ")=" << cToF(c) << "\n";
	}
}