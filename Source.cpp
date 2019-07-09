//------------------------------------------------------------------------------
//
//
//
//
//
//
//------------------------------------------------------------------------------
#include <iostream>
#include <math.h>
using namespace std;

//To find the minimum out of the three distances
char Min(float a, float b, float c) {
	if (a < b && a < c)
		return 'R';
	else if (b < c && b < a)
		return 'G';
	else if (c < a && c < b)
		return 'B';
	else 
		return ' ';
}

int main() {

	float centr, centg, centb;//centroids
	int test, cluster = 3, i = 0;
	float arr[9];
	
	// Accept inputs for Number of test cases
	cout << "Test cases: ";
	cin >> test;
	cout << "\n";
	int* result = new int[test];
	cout << "-----------------------------------------------------------" << endl;
	for (int h = 0; h < test; h++) 
		result[h] = 0;

	// Accept inputs for centroids
	while (cluster > 0) {
		cout << "Centroid: ";
		cin >> centr>>centg>>centb;
		cout << "\n";
		arr[0 + i] = centr;
		arr[1 + i] = centg;
		arr[2 + i] = centb;
		i = i + 3;
		cluster--;
	}
	
	cout << "-----------------------------------------------------------" << endl;
	int temp = test,j=0,k=0,m = 0;
	float* check = new float[3];
	while (temp > 0) {
		float R,G,B;
		cout << "Red [R]: ";
		cin >> R;
		cout << "Green [G]: ";
		cin >> G;
		cout << "Blue [B]: ";
		cin >> B;
		cout << "\n";
		while (k < 3) {
			
			float diff1, diff2, diff3;
			diff1 = pow((arr[0 + j] - R), 2);
			diff2 = pow((arr[1 + j] - G), 2);
			diff3 = pow((arr[2 + j] - B), 2);

			float euclid = sqrt(diff1 + diff2 + diff3);
			check[k] = euclid;

			k++;
			if(k==3){

				if (Min(check[0], check[1], check[2]) == 'R') {
					arr[0] = (arr[0] + R) / 2;
					arr[1] = (arr[1] + G) / 2;
					arr[2] = (arr[2] + B) / 2;
					cout << "k1: " <<arr[0]<<" "<< arr[1]<<" "<< arr[2] << endl;
					cout << "\n";
					result[m] = 1;
				}
				else if (Min(check[0], check[1], check[2]) == 'G') {
					arr[3] = (arr[3] + R) / 2;
					arr[4] = (arr[4] + G) / 2;
					arr[5] = (arr[5] + B) / 2;
					cout <<"k2: "<< arr[3] << " " << arr[4] << " " << arr[5] << endl;
					cout << "\n";
					result[m] = 2;
				}
				else if (Min(check[0], check[1], check[2]) == 'B') {
					arr[6] = (arr[6] + R) / 2;
					arr[7] = (arr[7] + G) / 2;
					arr[8] = (arr[8] + B) / 2;
					cout << "k3: " << arr[6] << " " << arr[7] << " " << arr[8] << endl;
					cout << "\n";
					result[m] = 3;
				}				
				else
					break;
				cout << "Assignment to k = " << result[m] << endl;
				m++;					
			}	
			
			j = j + 3;
		}
		k = 0;
		for (int c = 0; c < 3; c++) 
			check[c] = 0.0;

		temp--;
		j = 0;
		cout <<"-----------------------------------------------------------"<<endl;
	}

	for (int y = 0; y < test; y++) 
		cout <<"k - "<< result[y]<<endl;

	cout << "-----------------------------------------------------------" << endl;

	cout << "k1: " << arr[0] << " " << arr[1] << " " << arr[2] << endl;
	cout << "k2: " << arr[3] << " " << arr[4] << " " << arr[5] << endl;
	cout << "k3: " << arr[6] << " " << arr[7] << " " << arr[8] << endl;

	cout << "-----------------------------------------------------------" << endl;
	return 0;
}