#define NEURAL_IMPLEMENTATIONS
#include "neural.h"

using namespace std;
using namespace NMatrix;

int main(){
	srand(time(0));

	Matrix M = {.rows = 5, .cols = 5};

	MEMORY_ALLOC(&M);

	RANDOMIZE(&M);
	PRINT(&M);

	MEMORY_DEALLOC(&M);
}
