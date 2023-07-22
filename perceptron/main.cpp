#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;

float cost(float predicted, float real){
	return pow((predicted - real), 2.0f);
}

int main(){
	
	float x = 2.0f;
	float y = 3.0f;

	float w = (float)rand() / RAND_MAX;
	float b = (float)rand() / RAND_MAX;

	float rate = 0.1f;

	float p = 0;
	float c = 0;
	cout << "starting weight: " << w << "starting bias: " << b << endl;
	cout << "cost: " << cost(w*x+b, y) << endl;
	for(int i = 0; i<20; i++){
		p = w*x + b;
		c = cost(p, y);
		float dcdp = 2*(p-y);
		float dpdw = x;
		float dcdw = dcdp*dpdw;
		
		float dcdb = dcdp;

		w = w - dcdw*rate;
		b = b - dcdp*rate;

	cout << "new weight: " << w << " new bias: " << b << endl;
	cout << "new cost: " << cost(w*x+b, y) << endl;
	cout << "===========================" << endl;
	}

	return 0;
}
