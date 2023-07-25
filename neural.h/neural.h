#ifndef NEURAL_H
#define NEURAL_H

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <time.h>
#include <math.h>

typedef float dataT;

// General functions
dataT randD();

// Loss Functions
namespace LossF{
	
}

// Matricies
namespace NMatrix{

	typedef float dataT;

	struct Matrix{
		int rows = 0;
		int cols = 0;
		dataT* start = nullptr;
	};

	// Init functions
	void MEMORY_ALLOC(Matrix* M);
	void MEMORY_DEALLOC(Matrix* M);
	void IDENTITY(Matrix* M);
	void RANDOMIZE(Matrix* M);

	// Mathematical functions
	void DOT(Matrix* D, Matrix* A, Matrix* B);
	void ADD(Matrix* D, Matrix* A, Matrix* B);

	// Miscellaneous functions
	void PRINT(Matrix* M);
	dataT GET_ITEM(Matrix* M, int rows, int cols);
	void SET_ITEM(Matrix* M, dataT item, int rows, int cols);
}

#endif // NEURAL_H

#ifdef NEURAL_IMPLEMENTATIONS
#define NEURAL_IMPLEMENTATIONS

dataT randD(){
	return (dataT) rand() / RAND_MAX;
}

// Loss Functions
namespace LossF{

}

// Matricies
namespace NMatrix{
	// Init functions
	void MEMORY_ALLOC(Matrix* M){
		assert(M->rows != 0);	
		assert(M->cols != 0);
		assert(M->start == nullptr && "Matrix has already been allocated, destroy/free memory first");
		M->start = (dataT*)malloc(sizeof(dataT)*M->rows*M->cols);
		assert(M->start != nullptr);
	}

	void MEMORY_DEALLOC(Matrix* M){
		assert(M->start != nullptr && "Matrix has not been allocated.");
		free(M->start);
		M->start = nullptr;
	}

	void IDENTITY(Matrix* M){
		assert(M->rows != 0);
		assert(M->cols != 0);
		assert(M->start != nullptr);

		for(int i=0; i<M->rows; i++){
			for(int j=0; j<M->cols; j++){
				if(i == j){
					M->start[i*M->cols + j] = 1.0f;
				}
				else{
					M->start[i*M->cols + j] = 0.0f;
				}
			}
		}
	}

	void RANDOMIZE(Matrix* M){
		assert(M->rows != 0);
		assert(M->cols != 0);
		assert(M->start != nullptr);

		for(int i=0; i<M->rows; i++){
			for(int j=0; j<M->cols; j++){
				M->start[i*M->cols + j] = randD();
			}
		}
	}


	// Mathematical functions

	void DOT(Matrix* D, Matrix* A, Matrix* B){
		// D = A * B
		assert(A->cols == B->rows);	
		assert(D->rows == A->rows);
		assert(D->cols == B->cols);

		for(int i=0; i<A->rows; i++){
			for(int j=0; j<B->cols; j++){
				for(int k=0; k<A->cols; k++){
					D->start[i*D->cols+j] += A->start[i*A->cols+k] * B->start[k*B->rows+j];
				}
			}
		}
	}

	void ADD(Matrix* D, Matrix* A, Matrix* B){
		assert(A->rows == B->rows);
		assert(A->cols == B->cols);
		assert(D->rows == A->rows);
		assert(D->cols == A->cols);
		assert(A->start != nullptr && "Matrix A (2nd param) has not been allocated");
		assert(B->start != nullptr && "Matrix B (3rd param) has not been allocated");
		assert(D->start != nullptr && "Matrix D (1nd param) has not been allocated");
		
		for(int i=0; i<A->rows; i++){
			for(int j=0; j<A->cols; j++){
				D->start[i*A->cols + j] = A->start[i*A->cols + j] + B->start[i*A->cols + j];
			}
		}

	}


	// Miscellaneous functions 
	void PRINT(Matrix* M){
		for(int i=0; i<M->rows; i++){
			for(int j=0; j<M->cols; j++){
				printf("%f	", GET_ITEM(M, i, j));
			}
			printf("\n\n");
		}
	}

	dataT GET_ITEM(Matrix* M, int rows, int cols){
		return M->start[rows*M->cols + cols];
	}

	void SET_ITEM(Matrix* M, dataT item, int rows, int cols){
		assert(M->start != nullptr);
		assert(M->rows > rows);
		assert(M->cols > cols);
		
		M->start[rows*M->cols + cols] = item;
	}
}
#endif // NEURAL_IMPLEMENTATIONS
