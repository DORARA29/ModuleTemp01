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
     ���{���D�n�Φb�إߤ@�M�x�}�B��禡�w�B�w�q�F�x�}�B�⤧�禡�A
	 �]�t�ϯx�}�B��C���ȡB�x�}�[��k���B��A
	 �U�禡�P�ܼƤ������иԨ��U��ŧi�P�w�q�B������
	 �ݥ��w��LAPACK
	 include path: C:\Program Files (x86)\CLAPACK-3.1.1\INCLUDE  C:\Program Files (x86)\CLAPACK-3.1.1\LIB\Win32
	 ��L�{���w�ؿ�: C:\Program Files (x86)\CLAPACK-3.1.1\LIB\Win32
	 ��L�̩ۨ�:clapack.lib	 libf2c.lib	 blas.lib
	 �����S�w���w�]�{���w:libcmt.lib
Note: None
***************************************************************************************************/
#include <iostream> 
#include "math.h"

#include "windows.h" // ���Finclude timer �i�� �n��b�o��A clapack.h���e tvmet ����

// ���ǭn��
#include <f2c.h>
#include "blaswrap.h"
extern "C"
{
#include <clapack.h> 
}
// ���ǭn��

using namespace std;


	void InvSqMat(double * Data, int NCol); // ��J���x�}�� M.data(), �H�� M.Cols, �ģ��Ӧ^�ǯx�}�s�̭����������СA�ĤG�Ӧ^�ǯx�}������
	double AbsDetSqMat(double * Data, int NCol);  // �Q��LU decomposition �s�򭼤W�﨤�u�A�o�� det�������
	void SubMat(double *MMother, int ColMother, int RowMother, double *MSon, int *CutRegion); // ���X�l�x�}
	void SubMatIndex(double *MMother, int ColMother, int RowMother, double *MSon, int *ColRegion, int *RowRegion); // ���X���w��C�Ƥ��l�x�}
// basic matrix computation
	void MatScalarMul(double* A, int LenA, double* Scalar, double* result); // �x�}��jScalar��
	void MatScalarMul(double* A, int LenA, double Scalar, double* result); // �x�}��jScalar��
	void MatMulAB(double* A, int MA, int NA, double* B, int MB, int NB, double* result); // �x�}���k A*B
	void MatMulAtB(double* A, int MA, int NA, double* B, int MB, int NB, double* result); // �x�}���k A'*B
	void MatMulABt(double* A, int MA, int NA, double* B, int MB, int NB, double* result); // �x�}���k A*B'
	void MatMiuAB(double* A, double* B, double* result, int Len);  // �x�}��k A-B
	void MatAddAB(double* A, double* B, double* result, int Len);  // �x�}�[�k A+B
// advanced matrix function
	void SchurDecomposition(double * Data, double * Data_U, int NCol);//�i��"��}"��schur decomposition ��XU�MT�x�}�A[U,T] = schur(A,...) also returns a unitary matrix U so that A = U*T*U' and U'*U = eye(size(A)).

	logical SELECT_eigen(double *ar,double *ai);//for lapack dgees function���A�Ψӿ�ܯS�x�ȶi��ƦC�����