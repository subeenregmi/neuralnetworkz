#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>

using namespace std;

float cost(float p, float r){
	return pow(p-r, 2);
}

float rand_float(){
	return (float) rand() / RAND_MAX;
}

int main(){
	srand(time(0));
	int points[6][2] = {
		{2, 4},
		{3, 9},
		{4, 16},
		{5, 25}, 
		{6, 36},
		{7, 49}
	};

	float w00 = rand_float();
	float w01 = rand_float(); 

	float b10 = rand_float();
	float b11 = rand_float();

	float sum_dcdw00 = 0;
	float sum_dcdw01 = 0;

	float sum_dcdb10 = 0;
	float sum_dcdb11 = 0;

	float r = 0.0000000000000001f;
	long int iterations = 10000000000;
	float total_cost = 0;

	cout << w00 << ", " << w01 << ", " << b10 << ", " << b11 << endl;
	
	for(int i=0; i<iterations; i++){
		total_cost = 0;
		for(int j=0; j<6; j++){
			float p = (w00 * points[j][0] + b10) + (w01 * pow(points[j][0], 2) + b11);
			float c = cost(p, points[j][0]);
			total_cost += c;

			// calculating weight changes
			
			float dcdw00 = 2 * points[j][0] * (p - points[j][1]);
			float dcdw01 = 2 * pow(points[j][0], 2) * (p - points[j][1]); 
			
			// calculating bias changes

			float dcdb10 = 2 * (p - points[j][1]);
			float dcdb11 = 2 * (p - points[j][1]);

			sum_dcdw00 += dcdw00;
			sum_dcdw01 += dcdw01;

			sum_dcdb10 += dcdb10;
			sum_dcdb11 += dcdb11;

		}
		cout << "Total Cost: " << total_cost << endl;

		w00 = w00 - sum_dcdw00*r/6;
		w01 = w01 - sum_dcdw01*r/6;
		b10 = b10 - sum_dcdb10*r/6;
		b11 = b11 - sum_dcdb11*r/6;
	//	cout << w00 << ", " << w01 << ", " << b10 << ", " << b11 << endl;
	}
	cout << w00 << ", " << w01 << ", " << b10 << ", " << b11 << endl;

	return 0;
}
