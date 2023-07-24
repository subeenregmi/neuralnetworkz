#ifndef NEURAL_H
#define NEURAL_H

#include <iostream>

typedef float dataT;

struct Matrix{
	int rows;
	int cols;
	*dataT start;
}

// Init functions

void MATRIX_MEMORY_ALLOCATE();
void MATRIX_DESTROY();

// Mathematical functions
void MATRIX_DOT(Matrix D, Matrix A, Matrix B);
void MATRIX_ADD(Matrix D, Matrix A, Matrix B);

// Miscellaneous functions
void MATRIX_PRINT();
bool MATRIX_SET_ITEM_AT(Matrix M, dataT item);
dataT MATRIX_GET_ITEM_AT(Matrix M, int rows, int cols);

#endif // NEURAL_H

#ifdef NEURAL_IMPLEMENTATIONS
#define NEURAL_IMPLEMENTATIONS


#endif // NEURAL_IMPLEMENTATIONS
