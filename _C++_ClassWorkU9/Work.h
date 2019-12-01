#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct NOTEBOOK 
{
	char name[20];
	int price, disp_reg, CPU_max_freq, RAM_max, video_RAM, diag;
	double weight, HDD;

	struct dimensions
	{
		float height, lenght, width;
	}dimension;

	struct resolution 
	{
		int height, width;
	}resolution;

};

string **ReadFromFile();
void StartProg();