#define NEURAL_IMPLEMENTATIONS
#include "neural.h"

using namespace std;
using namespace NMatrix;

int main(){
	srand(time(0));

	Matrix M = {.rows = 2, .cols = 4};
	Matrix D = {.rows = 2, .cols = 4};
	Matrix C = {.rows = 2, .cols = 4};

	MEMORY_ALLOC(&M);
	MEMORY_ALLOC(&D);
	MEMORY_ALLOC(&C);

	RANDOMIZE(&M);
	RANDOMIZE(&D);
	RANDOMIZE(&C);

	SCALE(&M, 10.0f);
	SCALE(&D, 10.0f);

	PRINT(&M);
	PRINT(&D);

	cout << "----------------------" << endl;
	SUBTRACT(&C, &M, &D);
	PRINT(&C);

	MEMORY_DEALLOC(&M);
}
