#define NEURAL_IMPLEMENTATIONS
#include "neural.h"

using namespace std;

int main(){
	Matrix M = {.rows = 2, .cols = 2};
	MATRIX_MEMORY_ALLOCATE(&M);

	MATRIX_SET_ITEM_AT(&M, 1.0f, 0, 0);
	MATRIX_SET_ITEM_AT(&M, 2.0f, 0, 1);
	MATRIX_SET_ITEM_AT(&M, 3.0f, 1, 0);
	MATRIX_SET_ITEM_AT(&M, 4.0f, 1, 1);
	
	Matrix D; 
	D.rows = 2;
	D.cols = 2;
	MATRIX_MEMORY_ALLOCATE(&D);

	MATRIX_SET_ITEM_AT(&D, 5.0f, 0, 0);
	MATRIX_SET_ITEM_AT(&D, 3.5f, 0, 1);
	MATRIX_SET_ITEM_AT(&D, 6.9f, 1, 0);
	MATRIX_SET_ITEM_AT(&D, 0.03f, 1, 1);

	Matrix C;
	C.rows = 2;
	C.cols = 2;
	MATRIX_MEMORY_ALLOCATE(&C);
		
	MATRIX_DOT(&C, &M, &D);	

	MATRIX_PRINT(&C);

	MATRIX_DESTROY(&M);
	MATRIX_DESTROY(&D);
	MATRIX_DESTROY(&C);
}
