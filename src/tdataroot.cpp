// ����, ���, ���� "������ ����������������-2", �++, ���
//
// tdataroot.cpp - Copyright (c) ������� �.�. 28.07.2000 (06.08)
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (21.04.2015)
//
// ������������ ��������� ������ - ������� (�����������) ����� - ������ 3.1
//   ������ ���������� ����������� ��� �������� ������� SetMem

#include <stdio.h>
#include "tdataroot.h"

TDataRoot::TDataRoot(int Size) : TDataCom()
{
	DataCount = 0;
	MemSize = Size;
	if (Size == 0) // ������ ����� ����������� ������� SetMem
	{
		pMem = NULL;
		MemType = MEM_RENTER;
	}
	else // ������ ���������� ��������
	{
		pMem = new TElem[MemSize];
		MemType = MEM_HOLDER;
	}
} /*-------------------------------------------------------------------------*/

TDataRoot::~TDataRoot()
{
	if (MemType == MEM_HOLDER)
		delete[] pMem;
	pMem = NULL;
} /*-------------------------------------------------------------------------*/

void TDataRoot::SetMem(void *p, int Size) // ������� ������
{
	if (MemType == MEM_HOLDER)
		delete[] pMem; // ! ���������� �� �����������
	pMem = (TElem*)p;
	MemType = MEM_RENTER;
	MemSize = Size;
} /*-------------------------------------------------------------------------*/

bool TDataRoot::IsEmpty(void) const // �������� ������� ��
{
	return DataCount == 0;
} /*-------------------------------------------------------------------------*/

bool TDataRoot::IsFull(void) const // �������� ������������ ��
{
	return DataCount == MemSize;
} /*-------------------------------------------------------------------------*/