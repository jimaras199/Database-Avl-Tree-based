#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream> 
#include <stdio.h>
#include <typeinfo>
#include <functional>
#include <cstdio>
#include <sstream>
#include <forward_list>
#include <iostream>
#include <ctime>
#include <time.h>
#include "AVLHashTable.h"

using namespace std;

void itf_not_found_message();

int main()
{
	//line 33885
	ifstream File;
	
	File.open("TYPESOPSDB.DBA", fstream::in);
	if (!File.is_open())
	{
		itf_not_found_message();
	}
	else
	{
		cout << " HDL maker started, please wait..." << endl;
		HT.assertz("consecutive_106(\"false\")");
	}
	return 0;
}

void itf_not_found_message()
{
	fstream File("hdlmaker.log", ios::app);
	stringstream line;
	string str;
	
	//cout << " hdlmaker CCC compiler run on: " << __DATE__ << endl;
	//cout << "        ...with errors    at: " << __TIME__ << endl << endl;
	//cout << " hdlmaker CCC compiler runtime error : " << endl;
	//cout << "    there is no TYPESOPSDB.DBA file....; run first the front-end CCC compiler SUBADA.EXE" << endl;
	line << " hdlmaker CCC compiler run on: " << __DATE__ << endl;
	line << "        ...with errors    at: " << __TIME__ << endl << endl;
	line << " hdlmaker CCC compiler runtime error : " << endl;
	line << "    there is no TYPESOPSDB.DBA file....; run first the front-end CCC compiler SUBADA.EXE" << endl;
	str = line.str();
	File << str;
	File.close();
}