#include <iostream> 
#include <cstdlib>
#include <math.h>
#include <time.h>

using namespace std;

float cost(float prediction, float real){
	return pow((prediction - real), 2);
}

int main(){
	srand(time(0));
	int points[6][2] = {
		{2, 3},
		{3, 5},
		{6, 7},
		{8, 9},
		{9, 14},
		{10, 15}
	};
	
	float w = (float) rand() / RAND_MAX;
	float b = (float) rand() / RAND_MAX;
	float r = 0.0001f;
	int iterations = 10000000;

	cout << "Starting weight: " << w << " Starting bias: " << b << endl;

	for(int i=0; i<iterations; i++){
		float sum_dcdw = 0;
		float sum_dcdb = 0;	
		float total_cost = 0;
		
		for(int j=0; j<6; j++){
			float p = w*points[j][0] + b;
			float c = cost(p, points[j][1]);
			total_cost += c;
			float dcdw = 2.0f * points[j][0] * (p - points[j][1]);
			float dcdb = (p - points[j][1]);	
			sum_dcdw += dcdw;
			sum_dcdb += dcdb;
		}

		w = w - sum_dcdw*r/6;
		b = b - sum_dcdb*r/6;
	}
	
	cout << "After " << iterations << " backpropegation iterations" << endl;
	cout << "Final weight: " << w << " Final bias: " << b << endl;
	float total_cost = 0;
	for(int i = 0; i<6; i++){
		float p = w*points[i][0] + b;
		float c = cost(p, points[i][1]);
		cout << "Cost of x: " << points[i][0] << " = " << c << endl;
		total_cost += c;
	}
	cout << "Total cost: " << total_cost << endl;

	return 0;
}
