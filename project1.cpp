// project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// cs 311 Project 1 : Reads a text file in char by char mode and then writes it to a new file and determines the time it takes. Then similarly reads the text file in line by line mode and then writes it displaying the time it takes.

#include "pch.h"
#include <iostream>
#include <fstream>
#include<string>
#include "time_functions.h"
using namespace std;

int charbychar() {										
	cout << "in char by char mode"<<endl;
	double wall_clock_diff;
	double cpu_time;
	int nanodiff;
	char ch;
	ifstream file;
	file.open("C:/temp/coursein/p1-in.txt", ios::in);
	if (!file) {
		cout << "error in opening file!!!" << endl;
		return -1;
	}
	ofstream filea;
	filea.open("C:/temp/courseout/p1-out.txt");

	start_nanotime();
	start_timing();
	while (!file.eof())
	{
		file >> noskipws >> ch;
		//cout << ch;
		filea << noskipws << ch;
	}
	stop_timing();
	wall_clock_diff = get_wall_clock_diff();
	cpu_time = get_CPU_time_diff();
	nanodiff = get_nanodiff();
	cout << "The cpu_time taken to read and write the whole file is: " << cpu_time << " seconds" << endl;
	cout << "The wall_clock time taken to read and write the whole file is: " << wall_clock_diff << " seconds" << endl;
	filea.close();
	file.close();
	return nanodiff;
}

int linebyline()
{
	cout << "in line by line mode"<<endl;
	string st;
	double wall_clock_diff;
	double cpu_time;
	int nanodiff;
	ifstream fileb;
	fileb.open("C:/temp/coursein/p1-in.txt", ios::in);
	if (!fileb) {
		cout << "error in opening file!!!" << endl;
		return -1;
	}
	ofstream filec;
	filec.open("C:/temp/courseout/p1-out.txt");
	start_nanotime();
	start_timing();
	while (getline(fileb, st)) {
		//cout << st << endl;
		filec << noskipws << st<< endl;

	}
	stop_timing();
	wall_clock_diff = get_wall_clock_diff();
	cpu_time = get_CPU_time_diff();
	nanodiff = get_nanodiff();
	cout << "The cpu_time taken to read and write the whole file is: " << cpu_time << " seconds" << endl;
	cout << "The wall_clock time taken to read and write the whole file is: " << wall_clock_diff << " seconds" << endl;
	
	filec.close();
	fileb.close();

	return nanodiff;


}


int main()
{
	int charns = 0;
	int linens = 0;

	
	int mode;
	std::cout << "enter the desired mode 0 for character by character mode and 1 for line by line mode\n";
		cin >> mode;
		if (mode == 0)
		{
			charns = charbychar();
			cout << "The time taken for char by char in nano seconds is: " << charns << " nanoseconds" << endl;

		}
		else
		{
			linens = linebyline();
			cout << "The time taken for line by line in nano seconds is: " << linens << " nanoseconds" << endl;
		}

		
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
