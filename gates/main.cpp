#include <iostream> 
#include <cstdlib>
#include <math.h>
#include <time.h>

using namespace std;

float cost(float p, float r){
	return pow((p-r), 2);
}

float sigmoidf(float x){
	return 1/(1 + exp(-x));
}

float dsigmoidf(float x){
	return exp(x)/ pow(exp(x) + 1, 2);
}

float rand_float(){
	return (float) rand() / RAND_MAX;
}

int main(){
	
	int AND[4][3] = {
		{0, 0, 0},
		{0, 1, 0},
		{1, 0, 0},
		{1, 1, 1}
	};

	int OR[4][3] = {
		{0, 0, 0},
		{0, 1, 1},
		{1, 0, 1},
		{1, 1, 1}
	};

	int NAND[4][3] = {
		{0, 0, 1},
		{0, 1, 1},
		{1, 0, 1},
		{1, 1, 0}
	};

	float w0 = rand_float();
	float w1 = rand_float();
	float b = rand_float(); 
	float r = 0.1f;
	float total_cost = 0;

	int iterations = 100000;

	for(int i=0; i<iterations; i++){
		total_cost = 0;
		for(int j=0; j<4; j++){
			float z = w0 * AND[j][0] + w1*AND[j][1] + b;
			float a = sigmoidf(z);
			float c = cost(a, AND[j][2]);
			total_cost += c;

			float dcdw0 = 2 * (a - AND[j][2]) * dsigmoidf(z) * AND[j][0];
			float dcdw1 = 2 * (a - AND[j][2]) * dsigmoidf(z) * AND[j][1];
			float dcdb = 2 * (a - AND[j][2]) * dsigmoidf(z);

			w0 = w0 - dcdw0*r/4;
			w1 = w1 - dcdw1*r/4;
			b = b - dcdb*r/4;
		}
	}

	for(int i=0; i<4; i++){
		float z = w0 * AND[i][0] + w1*AND[i][1] + b;
		float a = sigmoidf(z);
		printf("Inputs: %i, %i, Expecting: %i, Probability: %f\n", AND[i][0], AND[i][1], AND[i][2], a);
	}

	cout << "-------------OR------------------" << endl;
	for(int i=0; i<iterations; i++){
		total_cost = 0;
		for(int j=0; j<4; j++){
			float z = w0 * OR[j][0] + w1*OR[j][1] + b;
			float a = sigmoidf(z);
			float c = cost(a, OR[j][2]);
			total_cost += c;

			float dcdw0 = 2 * (a - OR[j][2]) * dsigmoidf(z) * OR[j][0];
			float dcdw1 = 2 * (a - OR[j][2]) * dsigmoidf(z) * OR[j][1];
			float dcdb = 2 * (a - OR[j][2]) * dsigmoidf(z);

			w0 = w0 - dcdw0*r/4;
			w1 = w1 - dcdw1*r/4;
			b = b - dcdb*r/4;
		}
	}

	for(int i=0; i<4; i++){
		float z = w0 * OR[i][0] + w1*OR[i][1] + b;
		float a = sigmoidf(z);
		printf("Inputs: %i, %i, Expecting: %i, Probability: %f\n", OR[i][0], OR[i][1], OR[i][2], a);
	}

	w0 = rand_float();
	w1 = rand_float();
	b = rand_float();

	cout << "-------------NAND------------------" << endl;
	for(int i=0; i<iterations; i++){
		total_cost = 0;
		for(int j=0; j<4; j++){
			float z = w0 * NAND[j][0] + w1*NAND[j][1] + b;
			float a = sigmoidf(z);
			float c = cost(a, NAND[j][2]);
			total_cost += c;

			float dcdw0 = 2 * (a - NAND[j][2]) * dsigmoidf(z) * NAND[j][0];
			float dcdw1 = 2 * (a - NAND[j][2]) * dsigmoidf(z) * NAND[j][1];
			float dcdb = 2 * (a - NAND[j][2]) * dsigmoidf(z);

			w0 = w0 - dcdw0*r/4;
			w1 = w1 - dcdw1*r/4;
			b = b - dcdb*r/4;
		}
	}

	for(int i=0; i<4; i++){
		float z = w0 * NAND[i][0] + w1*NAND[i][1] + b;
		float a = sigmoidf(z);
		float c = cost(a, NAND[i][2]);
		printf("Inputs: %i, %i, Expecting: %i, Probability: %f\n", NAND[i][0], NAND[i][1], NAND[i][2], a);
	}
	
	return 0;
}

