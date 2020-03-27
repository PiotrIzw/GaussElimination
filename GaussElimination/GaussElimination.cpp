#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
const int N = 100;

class GaussElimination {
private:
	float AB[N][N], x[N];
	int n;
	void loadData(string filename, float arr[N][N], int n);
	void loadData(string filename);
public:
	void eliminate(string fileInputData, string fileMartixSize);
	void calculateMatrixValues();
	void showMatrix(float arr[N][N]);
	void showValues(float arr[N]);
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

	showMatrix(AB);

	for (int i = 0; i < n - 1; i++) {

		for (int j = i + 1; j < n; j++) {

			float divider = AB[j][i] / AB[i][i];

			for (int k = 0; k < n + 1; k++)
				AB[j][k] -= divider * AB[i][k];
		}
		showMatrix(AB);
	}

}

void GaussElimination::calculateMatrixValues() {

	for (int i = n - 1; i >= 0; i--) {
		x[i] = AB[i][n];

		for (int j = i + 1; j < n; j++)
			if (i != j)
				x[i] = x[i] - AB[i][j] * x[j];

		x[i] = x[i] / AB[i][i];
	}
	showValues(x);

}

void GaussElimination::showMatrix(float arr[N][N]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void GaussElimination::showValues(float arr[N])
{
	for (int i = 0; i < n; i++)
		cout << "x" << i + 1 << " = " << x[i] << endl;
}


int main()
{
	GaussElimination gauss;
	cout << "Eliminacja Gaussa:" << endl << endl;
	gauss.eliminate("input_data.txt", "n.txt");

	cout << "Niewiadome macierzy sa rowne:" << endl;
	gauss.calculateMatrixValues();
}