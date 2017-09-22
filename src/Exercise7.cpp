#include "OptChars.h"
#include "OptWord.h"
#include <iostream>
#include "Options.h"
using namespace std;
OptChars opt;
OptWord opt2;

int main(int argc, char** argv) {
	string validOpt = "abo";
	//number of valid options.
	int WordArgs;
	int i = 2;
	string validWords[i];
	validWords[0] = "log";
	validWords[1] = "help";

	//Create first object
	OptChars *obj;
	obj = new OptChars(argc, (const char**) argv);
	opt = *obj;
	delete obj;
	obj = NULL;

	//create second object
	OptWord *obj2;
	obj2 = new OptWord(argc, (const char**) argv);
	opt2 = *obj2;
	delete obj2;
	obj2 = NULL;

	opt.setOptstring(validOpt);
	int args = opt.numopt();
	if (args != 0) {
		cout << "Valid chars on cmdline: " << args << endl;
		for (int i = 1; i <= args; i++) {
			string str = opt.getopt();
			if (str != "INVALID")
			{
			cout << "Found match: -" << str << endl;
			}
		}

	}

	for (int j = 0; j < i; j++) {
		opt2.setOptstring(validWords[j]);
		args = opt2.numopt();
		WordArgs += args;
	}

	if (WordArgs != 0) {
		cout << "valid words on cmdline: " << WordArgs << endl;
		for (int j = 0; j < i; j++) {
			opt2.setOptstring(validWords[j]);
				for (int i = 1; i <= WordArgs; i++) {
					string str = opt2.getopt();
					if (str != "INVALID")
					{
					cout << "Found match: -" << str << endl;
					}
			}
		}
	}

	return 0;
}
