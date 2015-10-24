#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findMin(vector<double> array, int size) {
		
	int min = 0;

	for (int i = 1; i < size; i++) {
		if (array[i] < min) {
			min = i;
		}
	}

	return min;
}


void algorithm(int number, vector<double> x, vector<double> y, int size) {
	
	int minindex = findMin(x, size);
	double x_start = x[minindex], y_start = y[minindex];
// ******
	vector<double> xdiffs;
	vector<double> ydiffs;
	vector<int> indices;
	vector<int> quadrants;
	bool q[5]; for(int i = 0; i < 5; q[i++] = 0);
	int quadchosen;

	for (int i = 0; i < size; i++)
	{
		if (i == minindex) {continue; }
		
		int tempx = x[i] - x[minindex];
		int tempy = y[i] - y[minindex];


		xdiffs.push_back(tempx);
		ydiffs.push_back(tempy);
		indices.push_back(i);
// Quadrants used	
		if ((tempx > 0) && (tempy >= 0)) {
			quadrants.push_back(1);
			q[1] = 1; 
		}
		else if ((tempx <= 0) && (tempy > 0)) { 
			quadrants.push_back(2);
			q[2] = 1;
		}
		else if ((tempx < 0) && (tempy <= 0)) {
			quadrant.push_back(3);
			q[3] = 1;
		}
		else if ((tempx >= 0) && (tempy < 0)) {
			quadrant.push_back(4);
			q[4] = 1;
		}
// 
		if (!q[4]) {
			if (q[3]) { quadchosen = 3;}
			else if (q[2]) { quadchosen = 2; } 
			else { quadchosen = 1; }
		}
		else if (!q[3]) {
			if (q[2]) { quadchosen = 2; } 
			else if (q[1]) {quadchosen = 1;}
			else { quadchosen = 4; }
		}
		else if (!q[2]) {
			if (q[1]) {quadchosen = 1; }
			else { quadchosen = 4; }
		}
		else if (!q[1]) {
			quadchosen = 4;
		}


	}
	

//*****
}



int main() {
	
	return 0;
}
