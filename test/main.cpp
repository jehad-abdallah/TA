#include "pch.h"
#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <algorithm> 

using namespace std;

std::string str;
std::fstream infile;
std::string strr;

const string var = "var";

set<string> varTypes = { "int", "float", "char" };

bool isTypes(string type){
	return (varTypes.find(type) != varTypes.end());
}

bool point(char symbol) {
	return (symbol = ':');
}

bool IsLetters(string input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (!(isalpha(input[i]) || isdigit(input[i]))) {
			return false;
		}
	}
	return true;
}

int main()
{
	infile.open("input.txt");

	getline(infile, str, ' ');
	if (str == var) {

		getline(infile, str, ' ');
		if (!isdigit(str[0])) {

			if (IsLetters(str)) {
				getline(infile, str, ' ');
				if (str == ":") {

					getline(infile, str, ';');
					if (isTypes(str)) {

						cout << "true";
					}
					else
						cout << "this is not right type" << endl;
				}
				else
					cout << "you need : " << endl;
			}
			else
				cout << "you need just numbers and letters" << endl;
		}
		else
			cout << "first symbol can't be a number" << endl;		
	}
	else
		cout << "not right var" << endl;

}
