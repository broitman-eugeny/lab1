#pragma once
#include <iostream>
#include <Windows.h>
const int FractionDimSize = 10;
//Класс дроби
class Fraction
{
	int Numerator;		//Числитель
	int Denominator;	//Знаменатель
	static int Count;	//Счетчик объектов
public:
	Fraction();							//Конструктор по умолчанию
	Fraction(int N, int D);				//Конструктор с параметрами
	Fraction(Fraction &F);				//Конструктор копирования
	~Fraction();						//Деструктор
	void Reduction();					//Сокращение дроби
	void Mul(Fraction &F);				//Умножение дроби
	void Div(Fraction &F);				//Деление дроби
	void SetNumerator(int N);			//Установка значения числителя
	void SetDenominator(int D);			//Установка значения знаменателя
	int GetNumerator();					//Извлечение значения числителя
	int GetDenominator();				//Извлечение значения знаменателя
	static int GetCount();				//Извлечение количества созданных объектов
	void Print();						//Вывод на экран
};
//Определение НОД по алгоритму Евклида
int Evklid(int a, int b);
//Функция меню
//PFraction - массив указателей на объекты типа Fraction, состоящий из FractionDimSize элементов
void Menu(Fraction **PFraction);