#include "Work.h"

string** ReadFromFile()
{
	string** catalog = new string * [1000];
	for (int i = 0; i < 1000; i++)
		catalog[i] = new string[1000];
	try
	{
		ifstream file("note.txt");
		string temp = "", tempPastWord = "", tempPastDigit = "";
		int i = 0, j = 0;
		bool flag = false, f = true;
		while (file >> temp)
		{
			if (f) {
				tempPastWord = "", tempPastDigit = "";
				f = false;
			}
			for (int g = 0; g < temp.size() && flag == false; g++)
			{
				if (temp[g] == '.' && flag == false) 
				{
					flag = true;
					catalog[i][j++] = tempPastWord;
					catalog[i][j++] = tempPastDigit;
					continue;
				}
			}
			if (!flag)
			{
				tempPastWord = catalog[i][j];
				catalog[i][j] += temp + " ";
				tempPastDigit = temp;
			}
			else
			{
				catalog[i][j++] = temp;
			}
			if (j == 11)
			{
				i++;
				j = 0;
				flag = false;
				f = true;
			}
		}
		return catalog;
	}
	catch (exception e)
	{

	}
	return NULL;
}

void StartProg()
{
	int amount = 16;
	NOTEBOOK* notebooks = new NOTEBOOK[amount];

	fstream file("note.txt");


	for (int i = 0; i < amount; i++)
	{
		int j = 0;
		char notebook[80];
		file.getline(notebook, 80);
		//cout << notebook << endl;
		for (; j < 20; j++)
			notebooks[i].name[j] = notebook[j];

		notebooks[i].name[19] = '\0';

		char price[4];
		for (int k = 0; k < 4; k++)
			price[k] = notebook[j++];

		notebooks[i].price = atoi(price);

		j++;

		char weight[3];
		for (int k = 0; k < 3; k++)
			weight[k] = notebook[j++];

		notebooks[i].weight = stof(weight);

		j++;

		char gab[4];
		for (int k = 0; k < 4; k++)
			gab[k] = notebook[j++];
		j++; //x
		notebooks[i].dimension.height = stof(gab);

		for (int k = 0; k < 4; k++)
			gab[k] = notebook[j++];
		j++; //x
		notebooks[i].dimension.lenght = stof(gab);

		for (int k = 0; k < 4; k++)
			gab[k] = notebook[j++];

		notebooks[i].dimension.width = stof(gab);

		j++;

		char CPU[3];
		for (int k = 0; k < 3; k++)
			CPU[k] = notebook[j++];

		notebooks[i].CPU_max_freq = atoi(CPU);

		j++;

		char RAM[2];
		for (int k = 0; k < 2; k++)
			RAM[k] = notebook[j++];
		notebooks[i].RAM_max = atoi(RAM);

		j++;

		char diag[4];
		for (int k = 0; k < 4; k++)
			diag[k] = notebook[j++];
		notebooks[i].diag = stof(diag);

		j++;

		char vRAM[1];
		vRAM[0] = notebook[j++];
		notebooks[i].video_RAM = atoi(vRAM);

		j++;

		char num[4];
		for (int i = 0; i < 4; i++)
		{
			num[i] = notebook[j++];
		}
		notebooks[i].resolution.height = atoi(num);

		j++;

		for (int i = 0; i < 4; i++)
		{
			num[i] = notebook[j++];
		}
		notebooks[i].resolution.width = atoi(num);

		j++;

		char freq[2];
		for (int i = 0; i < 2; i++)
		{
			freq[i] = notebook[j++];
		}
		notebooks[i].disp_reg = atoi(freq);


		j++;

		char HDD[5];
		for (int i = 0; i < 5; i++)
		{
			HDD[i] = notebook[j++];
		}
		notebooks[i].HDD = atof(HDD);
	}

	for (int i = 0; i < amount - 1; i++)
	{
		for (int j = 0; j < amount - i - 1; j++)
		{
			if (notebooks[j].price > notebooks[j + 1].price)
			{
				NOTEBOOK temp = notebooks[j];
				notebooks[j] = notebooks[j + 1];
				notebooks[j + 1] = temp;
			}
			if (notebooks[j].price == notebooks[j + 1].price && notebooks[j].weight > notebooks[j + 1].weight)
			{
				NOTEBOOK temp = notebooks[j];
				notebooks[j] = notebooks[j + 1];
				notebooks[j + 1] = temp;
			}
		}

	}


	cout << "NAME" << setw(20) << '\t'
		<< "PRICE" << '\t'
		<< "WEIGHT" << '\t'
		<< "HEIGHT" << 'x'
		<< "LENGHT" << 'x'
		<< "WIDTH" << '\t'
		<< "CPU" << setw(5) << '\t'
		<< "RAM" << setw(5) << '\t'
		<< "DAIGONAL" << '\t'
		<< "VRAM" << '\t'
		<< "HEIGHT" << 'x'
		<< "WIDHT" << ' '
		<< "DISP FREQ" << '\t'
		<< "HDD" << '\t'

		<< endl << endl;

	for (int i = 0; i < amount; i++)
	{
		cout << notebooks[i].name << '\t'
			<< notebooks[i].price << '\t'
			<< notebooks[i].weight << '\t'
			<< notebooks[i].dimension.height << 'x'
			<< notebooks[i].dimension.lenght << 'x'
			<< notebooks[i].dimension.width << setw(10) << '\t'
			<< notebooks[i].CPU_max_freq << setw(5) << '\t'
			<< notebooks[i].RAM_max << setw(5) << '\t'
			<< notebooks[i].diag << setw(5) << '\t'
			<< notebooks[i].video_RAM << setw(7) << '\t'
			<< notebooks[i].resolution.height << 'x'
			<< notebooks[i].resolution.width << setw(5) << '\t'
			<< notebooks[i].disp_reg << setw(5) << '\t'
			<< notebooks[i].HDD << setw(5) << '\t'

			<< endl;

	}
}
