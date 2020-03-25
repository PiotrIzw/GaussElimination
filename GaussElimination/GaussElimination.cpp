#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class GaussElimination {
private:
	float** AB;
	int n[1];
	string line;
	fstream file;
public:
	void loadData(string filename, float** arr, int n);
	void loadData(string filename, int matrixSize[]);
	void eliminate(string fileInputData, string fileMartixSize);
};

void GaussElimination::loadData(string filename, int matrixSize[]) {
	int i = 0;
	file.open(filename, ios::in);
	if (file.good() == true)
	{
		while (!file.eof())
		{
			getline(file, line);
			matrixSize[i] = stoi(line); // stof - konwersja string do float
			i++;
		}
		file.close();
	}
}
void GaussElimination::loadData(string filename, float** arr, int n) {

	ifstream file{ filename };
	if (file.is_open()) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n + 1; j++)
				file >> arr[i][j];
	}
}

void GaussElimination::eliminate(string fileInputData, string fileMartixSize) {
	cout << n;
	loadData(fileMartixSize, n);
	cout << endl << n << endl;
	//loadData("input_data.txt", AB, k);
//	cout << k << "a";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n + 1; j++) {
			//cout << AB[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}


int main()
{
	GaussElimination gauss;
	gauss.eliminate("input_data.txt", "n.txt");


	/*
	int n;
	float arr[100][100];
	ifstream file{ "n.txt" };
	if (file.is_open()) {

		
				file >> n;
	}
	cout << n;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4 + 1; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
	std::cout << "Hello World!\n";
}