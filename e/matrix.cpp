//   matrix.cpp


#include "matrix.h"

Matrix::Matrix(int r, int c):rowsM(r), colsM(c) // 1 , 2
{
    matrixM = new double* [rowsM];
    assert(matrixM != NULL);
    
    for(int i=0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
}


Matrix::~Matrix()
{
    destroy();
}

Matrix::Matrix(const Matrix& source)
{
    copy(source);
}

Matrix& Matrix::operator= (const Matrix& rhs)
{
    if(&rhs != this){
        destroy();
        copy(rhs);
    }
   
    return *this;
}

double Matrix::get_sum_col(int i) const
{
    assert(i >= 0 && i < colsM);
    return sum_colsM[i];
}

double Matrix::get_sum_row(int i) const
{
    assert(i >= 0 && i < rowsM);
    return sum_rowsM[i];
}


void Matrix::sum_of_rows()const
{
   
    for(int i = 0; i < rowsM; i++){
        double sum = 0;
        for(int j = 0; j<colsM; j++){
            sum += matrixM[i][j];
        }
        sum_rowsM[i] = sum; 
    }
    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
    //cout << "\nSorry I don't know how to calculate sum of rowsM in a matrix. ";

}

void Matrix::sum_of_cols()const
{
        for(int i = 0; i < colsM; i++){
        double sum = 0;
        for(int j = 0; j<rowsM; j++){
            sum += matrixM[j][i];
        }
        sum_colsM[i] = sum; 
    }
    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
    //cout << "\nSorry I don't know how to calculate sum of columns in a matrix. ";
    
}

void Matrix::copy(const Matrix& source)
{
    // THIS FUNCITON IS DEFECTIVE AND DOSEN'T PROPERLY MAKE THE COPY OF SROUCE
    if(source.matrixM == NULL){ //sets matrix to NULL if Matrix is null
        matrixM = NULL;
        sum_rowsM = NULL;
        sum_colsM = NULL;
        rowsM = 0;
        colsM = 0;
        return;
    }
    
    rowsM = source.rowsM; // if source not NULL, changes rowsM and colsM to = source 
    colsM = source.colsM;
    
    sum_rowsM = new double[rowsM]; //sum rows is a double* so make a new
    assert(sum_rowsM != NULL);
    
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
    
    matrixM = new double*[rowsM]; //matrixM is a double** so have one pointer dereference star
    assert(matrixM !=NULL);

    for(int i =0; i < rowsM; i++){ // copies the matrix, each row
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
        for(int j = 0; j < colsM; j++){
            matrixM[i][j] = source.matrixM[i][j];     
        }
    }
    for(int e = 0; e< colsM; e++){ //copies the sum values of each column
        sum_colsM[e] = source.sum_colsM[e];
    }
    for(int e = 0; e< rowsM; e++){ // copies the sum values of each row
        sum_rowsM[e] = source.sum_rowsM[e];
    }

    // STUDENTS MUST COMMENT OUT THE FOLLOWING LINE AND FIX THE FUNCTION'S PROBLEM
    //cout << "\nSorry copy fucntion is defective. ";
}

    

void Matrix::destroy()
//every value in the class that is a pointer needs to be delete
{
    delete [] sum_colsM; 
    delete [] sum_rowsM;
    for(int i = 0; i < rowsM; i++) delete[] matrixM[i]; //need loop because double pointer
    delete [] matrixM;
    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
    //cout << "\nProgram ended without destroying matrices.\n";
}
