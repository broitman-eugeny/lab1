#pragma once
#include <iostream>
#include <Windows.h>
const int FractionDimSize = 10;
//����� �����
class Fraction
{
	int Numerator;		//���������
	int Denominator;	//�����������
	static int Count;	//������� ��������
	static int Evklid(int N, int D);	//����������� ��� �� ��������� �������
public:
	Fraction();							//����������� �� ���������
	Fraction(int N, int D);				//����������� � �����������
	Fraction(Fraction &F);				//����������� �����������
	~Fraction();						//����������
	void Reduction();					//���������� �����
	void Mul(Fraction &F);				//��������� �����
	void Div(Fraction &F);				//������� �����
	void SetNumerator(int N);			//��������� �������� ���������
	void SetDenominator(int D);			//��������� �������� �����������
	int GetNumerator();					//���������� �������� ���������
	int GetDenominator();				//���������� �������� �����������
	static int GetCount();				//���������� ���������� ��������� ��������
	void Print();						//����� �� �����
};
//������� ����
//PFraction - ������ ���������� �� ������� ���� Fraction, ��������� �� FractionDimSize ���������
void Menu(Fraction **PFraction);