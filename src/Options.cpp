#include "Options.h"
#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

Options::Options()
{

    argC = 0;
    argV = NULL;
    optstring = "";
    count = 1;
}

Options::~Options()
{

}


void Options::setOptstring(string validopt)
{
	count = 0;
	optstring = validopt;
}

int Options::numopt(void)
{
	count = 0;
	int number = 0;
	while (getopt() != "INVALID") {
        number++;
    }
		count = 0;
		return number;
	}
