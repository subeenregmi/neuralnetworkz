#define NEURAL_IMPLEMENTATIONS
#include "neural.h"

using namespace std;

int main(){
	Matrix M;
	M.rows = 10;
	M.cols = 10;
	MATRIX_MEMORY_ALLOCATE(&M);
	MATRIX_SET_ITEM_AT(&M, 1.0f, 0, 0);
	MATRIX_SET_ITEM_AT(&M, 1.0f, 1, 1);
	MATRIX_PRINT(&M);

	MATRIX_DESTROY(&M);
}
