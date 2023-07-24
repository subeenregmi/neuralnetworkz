#ifndef NEURAL_H
#define NEURAL_H

#include <iostream>
#include <cassert>

typedef float dataT;

struct Matrix{
	int rows = 0;
	int cols = 0;
	dataT* start = nullptr;
};

// Init functions
void MATRIX_MEMORY_ALLOCATE(Matrix* M);
void MATRIX_DESTROY(Matrix* M);
void MATRIX_IDENTITY(Matrix* M);

// Mathematical functions
void MATRIX_DOT(Matrix D, Matrix A, Matrix B);
void MATRIX_ADD(Matrix D, Matrix A, Matrix B);

// Miscellaneous functions
void MATRIX_PRINT(Matrix* M);
dataT MATRIX_GET_ITEM_AT(Matrix* M, int rows, int cols);
void MATRIX_SET_ITEM_AT(Matrix* M, dataT item, int rows, int cols);

#endif // NEURAL_H

#ifdef NEURAL_IMPLEMENTATIONS
#define NEURAL_IMPLEMENTATIONS

// Init functions
void MATRIX_MEMORY_ALLOCATE(Matrix* M){
	assert(M->rows != 0);	
	assert(M->cols != 0);
	assert(M->start == nullptr && "Matrix has already been allocated, destroy/free memory first");

	M->start = (dataT*)malloc(sizeof(dataT)*M->rows*M->cols);
	assert(M->start != nullptr);
}

void MATRIX_DESTROY(Matrix* M){
	assert(M->start != nullptr && "Matrix has not been allocated.");
	free(M->start);
	M->start = nullptr;
}

void MATRIX_IDENTITY(Matrix* M){
	assert(M->rows != 0);
	assert(M->cols != 0);
	assert(M->start != nullptr);

	// Implement
}

// Miscellaneous functions 
void MATRIX_PRINT(Matrix* M){
	for(int i=0; i<M->rows; i++){
		for(int j=0; j<M->cols; j++){
			printf("%f	", MATRIX_GET_ITEM_AT(M, i, j));
		}
		printf("\n\n");
	}
}

dataT MATRIX_GET_ITEM_AT(Matrix* M, int rows, int cols){
	return M->start[rows*M->cols + cols];
}

void MATRIX_SET_ITEM_AT(Matrix* M, dataT item, int rows, int cols){
	assert(M->start != nullptr);
	assert(M->rows > rows);
	assert(M->cols > cols);
	
	M->start[rows*M->cols + cols] = item;
}

#endif // NEURAL_IMPLEMENTATIONS
