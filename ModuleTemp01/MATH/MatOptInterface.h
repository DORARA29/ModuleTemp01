/**************************************************************************************************
Copyright, 2010-2012, Robotics Lab., Dept. of M.E., National Taiwan University
File Name: MatOptInterface.h

Author: Jiu-Lou Yan
Version: 1.0
Date: 2010/07/10

Functions:
     InvSqMat() AbsDetSqMat()  SubMat() SubMatIndex() MatScalarMul()
     MatMulAB() MatMulAtB() MatMulABt() MatMiuAB() MatAddAB()

Classes: None

Description:
     本程式主要用在建立一套矩陣運算函式庫、定義了矩陣運算之函式，
	 包含反矩陣、行列式值、矩陣加減乘法之運算，
	 各函式與變數之說明請詳見下方宣告與定義處之說明
	 需先安裝LAPACK
	 include path: C:\Program Files (x86)\CLAPACK-3.1.1\INCLUDE  C:\Program Files (x86)\CLAPACK-3.1.1\LIB\Win32
	 其他程式庫目錄: C:\Program Files (x86)\CLAPACK-3.1.1\LIB\Win32
	 其他相依性:clapack.lib	 libf2c.lib	 blas.lib
	 忽略特定的預設程式庫:libcmt.lib
Note: None
***************************************************************************************************/
#include <iostream> 
#include "math.h"

#include "windows.h" // 為了include timer 進來 要放在這邊， clapack.h之前 tvmet 之後

// 順序要對
#include <f2c.h>
#include "blaswrap.h"
extern "C"
{
#include <clapack.h> 
}
// 順序要對

using namespace std;


	void InvSqMat(double * Data, int NCol); // 輸入為矩陣的 M.data(), 以及 M.Cols, 第ㄧ個回傳矩陣存裡面元素的指標，第二個回傳矩陣的維度
	double AbsDetSqMat(double * Data, int NCol);  // 利用LU decomposition 連續乘上對角線，得到 det的絕對值
	void SubMat(double *MMother, int ColMother, int RowMother, double *MSon, int *CutRegion); // 取出子矩陣
	void SubMatIndex(double *MMother, int ColMother, int RowMother, double *MSon, int *ColRegion, int *RowRegion); // 取出指定行列數之子矩陣
// basic matrix computation
	void MatScalarMul(double* A, int LenA, double* Scalar, double* result); // 矩陣放大Scalar倍
	void MatScalarMul(double* A, int LenA, double Scalar, double* result); // 矩陣放大Scalar倍
	void MatMulAB(double* A, int MA, int NA, double* B, int MB, int NB, double* result); // 矩陣乘法 A*B
	void MatMulAtB(double* A, int MA, int NA, double* B, int MB, int NB, double* result); // 矩陣乘法 A'*B
	void MatMulABt(double* A, int MA, int NA, double* B, int MB, int NB, double* result); // 矩陣乘法 A*B'
	void MatMiuAB(double* A, double* B, double* result, int Len);  // 矩陣減法 A-B
	void MatAddAB(double* A, double* B, double* result, int Len);  // 矩陣加法 A+B
// advanced matrix function
	void SchurDecomposition(double * Data, double * Data_U, int NCol);//進行"方陣"的schur decomposition 算出U和T矩陣，[U,T] = schur(A,...) also returns a unitary matrix U so that A = U*T*U' and U'*U = eye(size(A)).

	logical SELECT_eigen(double *ar,double *ai);//for lapack dgees function中，用來選擇特徵值進行排列的函數
