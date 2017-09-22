#include "OptWord.h"
#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

OptWord::OptWord(int argc, const char **argv) {
	argC = argc;
	argV = (char**) argv;
	optstring = "";
	count = 1;
}


OptWord::OptWord(const OptWord &rhs) {

	argC = rhs.argC;
	argV = rhs.argV;
	optstring = rhs.optstring;
	count = rhs.count;
}



OptWord::OptWord() {
}

OptWord::~OptWord() {

}


string OptWord::getopt(void) {

	for (; count < argC; count++) {

		if (argV[count][0] == '-' && argV[count][1] == '-'
				&& strlen(argV[count]) > 3) {
			string str(argV[count] + 2);

			if (str == optstring) {
				count++;
				return optstring;
			}
		}
	}
	return "INVALID";
}
