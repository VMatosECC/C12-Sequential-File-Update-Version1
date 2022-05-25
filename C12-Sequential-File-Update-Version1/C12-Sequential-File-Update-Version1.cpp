// C12-Sequential-File-Update-Version1.cpp 

// ConsoleApplication15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* SAMPLE DATA

yyy1.txt
111
222
444
666
777
888
999

yyy2.txt
333
666
777
---------------------------------------------------------------------- */

void readFile(fstream& fname, int& num);
// -------------------------------------------------------------------
int main()
{
	fstream infile1("c:/temp/yyy1.txt", ios::in);
	fstream infile2("c:/temp/yyy2.txt", ios::in);
	fstream outfile("c:/temp/yyy3.txt", ios::out);

	if (!infile1) { cout << "Error-1 \n";  exit(1); }
	if (!infile2) { cout << "Error-2 \n";  exit(2); }

	//read the first pair of records
	int num1, num2;
	readFile(infile1, num1);
	readFile(infile2, num2);


	while ((num1 != INT_MAX || num2 != INT_MAX))
	{
		//the old key should be copied to the output file
		if (num1 < num2)
		{
			cout << num1 << endl;
			outfile << num1 << endl;
			readFile(infile1, num1);
		}
		else if (num1 == num2)
		{
			//when both keys match ignore them and continue with the rest
			readFile(infile1, num1);
			readFile(infile2, num2);
		}
		//the new key should be added to the output file
		else if (num1 > num2)
		{
			cout << num2 << endl;
			outfile << num2 << endl;
			readFile(infile2, num2);
		}
	}

	outfile.close();

	std::cout << "\nAll done!\n";
}

// --------------------------------------------------------------
void readFile(fstream& fname, int& num)
{
	fname >> num;
	if (fname.fail()) num = INT_MAX;
}

