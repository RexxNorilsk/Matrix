#include <iostream>
#include <fstream>

using namespace std;

int randomRange(int max, int min = 1) {
	return min + rand() % (max - min);
}


int main() {
	char filenameA[256];
	char filenameB[256];
	int matrixSize[] = { 100, 250, 500 };
	for (int N : matrixSize) {
		sprintf_s(filenameA, "matrixA % d.txt", N);
		sprintf_s(filenameB, "vectorB % d.txt", N);
		ofstream matrixA(filenameA);
		ofstream matrixB(filenameB);
		if (!matrixA.is_open() || !matrixB.is_open()) {
			cout << "Error write to file" << endl;
			return 1;
		}
		int* matrA = new int[N];
		int* matrB = new int[N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				matrA[j] = randomRange(100, 0);
			}
			for (int j = 0; j < N; j++) {
				matrixA << matrA[j] << "\t";
			}
			matrixA << endl;
			matrB[i] = randomRange(100, 0);
			matrixB << matrB[i];
		}
		matrixA.close();
		matrixB.close();
		delete[] matrA;
		delete[] matrB;
	}
	return 0;
}
