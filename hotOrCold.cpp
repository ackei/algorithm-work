#include <iostream>
#include <iomanip>
using namespace std;

void integrate(double* poly, int power, double* antideriv);

double evaluatePolynomial(double* poly, int power, double time); 

int main() {

	bool first = true;
	int power = 0;
	double start = 0, end = 0; 
	while ((cin >> power) && (power != 0))
	{
		if (first) { first = false; }
		else { cout << endl; }
				

		double poly[100], antideriv[101];
		for (int i = power; i >= 0; i--)
		{
			cin >> poly[i];
		}
		
		cin >> start;
		cin >> end;
		
		integrate(poly, power, antideriv);
		
		double answer = (evaluatePolynomial(antideriv, power+1, end) -  evaluatePolynomial(antideriv, power+1, start)) / (end - start);
		cout << setprecision(3) << answer;
	}
	



	return 0;
}


void integrate(double* poly, int power, double* antideriv) {
	
	for (int i = 0; i < power + 1; i++)
	{
		antideriv[i + 1] = poly[i] / (i + 1);
	} 
}


double evaluatePolynomial(double* poly, int power, double time) {
	
	double answer = poly[power];
	for (int i = power - 1; i >= 0; i--)
	{
		answer *= time;
		answer += poly[i];
	}
	return answer;	
	
} 

