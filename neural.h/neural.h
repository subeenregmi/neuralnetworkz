#ifndef NEURAL_H
#define NEURAL_H

#include <iostream>

typedef float dataT;

class Matrix{
	private:
		dataT* pMatrix;
		int rows;
		int cols;

	public:
	
		Matrix(int r, int c);
		~Matrix();

		dataT getItem(int ri, int ci);
		bool setItem(int ri, int ci, dataT item);
		int getRows();
		int getCols();
};

#endif // NEURAL_H

#ifdef NEURAL_IMPLEMENTATIONS
#define NEURAL_IMPLEMENTATIONS

Matrix::Matrix(const int r, const int c){
	pMatrix = new dataT[r][c];
}

dataT Matrix::getItem(int ri, int ci){
	return *pMatrix[ri][ci];	
}

bool Matrix::setItem(int ri, int ci, dataT item){
	if(ri + 1 > rows){
		return false;
	}

	if(ci + 1 > cols){
		return false;
	}
	*pMatrix[ri][ci] = item;
	return true;
}

Matrix::~Matrix(){
	delete pMatrix;
}


#endif // NEURAL_IMPLEMENTATIONS
