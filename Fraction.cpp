#include "Fraction.h"
int Fraction::Count = 0;
Fraction::Fraction():Numerator(1), Denominator(1)
{
	Count++;
}
Fraction::Fraction(int N, int D) : Numerator(N), Denominator(D)
{
	Count++;
}
Fraction::Fraction(Fraction & F) : Numerator(F.Numerator), Denominator(F.Denominator)
{
	Count++;
}
Fraction::~Fraction()
{
	Count--;
}
void Fraction::Reduction()//Сокращение дроби
{
	int CommonDevider= Evklid(Numerator, Denominator);//наибольший общий делитель по алгоритму Евклида
	Numerator /= CommonDevider;
	Denominator /= CommonDevider;
}
void Fraction::Mul(Fraction & F)//Умножение дроби
{
	Numerator *= F.Numerator;
	Denominator *= F.Denominator;
}
void Fraction::Div(Fraction & F)
{
	Numerator *= F.Denominator;
	Denominator *= F.Numerator;
}
void Fraction::SetNumerator(int N)
{
	Numerator = N;
}
void Fraction::SetDenominator(int D)
{
	Denominator = D;
}
int Fraction::GetNumerator()
{
	return Numerator;
}
int Fraction::GetDenominator()
{
	return Denominator;
}
int Fraction::GetCount()
{
	return Count;
}
void Fraction::Print()
{
	std::cout << Numerator << "\t\t" << Denominator << std::endl;
}
