#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
const int N = 100;

class GaussElimination {
private:
	float AB[N][N];
	int n;
public:
	void loadData(string filename, float arr[N][N], int n);
	void loadData(string filename);
	void eliminate(string fileInputData, string fileMartixSize);
	void showMatrix(float arr[N][N]);
};

void GaussElimination::loadData(string filename) {
	ifstream file{ filename };
	if (file.is_open()) {
		file >> n;
	}
}
void GaussElimination::loadData(string filename, float arr[N][N], int n) {

	ifstream file{ filename };
	if (file.is_open()) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n + 1; j++)
				file >> AB[i][j];
	}
}

void GaussElimination::eliminate(string fileInputData, string fileMartixSize) {
	loadData(fileMartixSize);
	loadData(fileInputData, AB, n);
	

		
				

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			showMatrix(AB);
			float m = -AB[i + 1][j] / AB[i][j];
			for (int k = 0; k < n + 1; k++) {
				
				AB[i + 1][j] += (AB[i][j] * m);
			}
			
		}
		cout << endl;
	}
}

void GaussElimination::showMatrix(float arr[N][N])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	GaussElimination gauss;
	gauss.eliminate("input_data.txt", "n.txt");

}