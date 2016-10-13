#include "Fraction.h"
//Функция отображения меню
void ShowMenu()
{
	std::cout << std::endl << "Лабораторная работа №1 (ООП)";
	std::cout << std::endl << "а. Добавить объект";
	std::cout << std::endl << "б. Удалить объект";
	std::cout << std::endl << "в. Показать все объекты";
	std::cout << std::endl << "г. Управление объектом";
	std::cout << std::endl << "д. Выход";
	std::cout << std::endl << "Введите букву требуемого пункта меню: ";
}
//Функция отображения подменю добавления объекта
void ShowMenu2()
{
	std::cout << std::endl << "1. Значения по умолчанию";
	std::cout << std::endl << "2. Копия уже существующего в массиве объекта";
	std::cout << std::endl << "3. Ввод значений числителя и знаменателя";
	std::cout << std::endl << "4. Выход";
	std::cout << std::endl << "Введите номер требуемого пункта подменю: ";
}
//Функция отображения подменю управления объектом
void ShowMenu3()
{
	std::cout << std::endl << "1. Изменение содержимого объекта с заданным номером";
	std::cout << std::endl << "2. Сокращение дроби объекта с заданным номером";
	std::cout << std::endl << "3. Умножение дроби объекта с заданным номером";
	std::cout << std::endl << "4. Деление дроби объекта с заданным номером";
	std::cout << std::endl << "5. Выход";
	std::cout << std::endl << "Введите номер требуемого пункта подменю: ";
}
//Функция меню
//PFraction - массив указателей на объекты типа Fraction, состоящий из FractionDimSize элементов
void Menu(Fraction **PFraction)
{
	char C = -1;
	int i, c;
	while (C != 'д')//д - выход
	{
		ShowMenu();
		std::cin >> C;
		while (C<'а' || C>'д')
		{
			std::cout << std::endl << "Неверно введен символ, введите еще раз: ";
			std::cin >> C;
		}
		switch (C)
		{
		case 'а'://Добавить объект
			if (Fraction::GetCount() == FractionDimSize)//Если массив заполнен
			{
				std::cout << "Извините, массив заполнен" << std::endl;
			}
			else
			{
				int C2 = -1;
				while (C2 != 4)//4 - выход
				{
					ShowMenu2();
					std::cin >> C2;
					while (C2<1 || C2>4)
					{
						std::cout << std::endl << "Неверно введен номер, введите еще раз: ";
						std::cin >> C2;
					}
					int Index, IndexOfCopy;
					switch (C2)
					{
					case 1://Значения по умолчанию
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction();
						std::cout << "Количество объектов: " << Fraction::GetCount() << std::endl;
						break;
					case 2://Копия уже существующего в массиве объекта
						if (Fraction::GetCount() == 0)
						{
							std::cout << "Сначала добвьте объекты!";
							break;
						}
						std::cout << "Введите индекс копируемого объекта: ";
						std::cin >> IndexOfCopy;
						while (IndexOfCopy<0 || IndexOfCopy >= Fraction::GetCount())
						{
							std::cout << std::endl << "Индекс введен неверно, введите еще раз: ";
							std::cin >> IndexOfCopy;
						}
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction(*PFraction[IndexOfCopy]);
						std::cout << "Количество объектов: " << Fraction::GetCount() << std::endl;
						break;
					case 3://Ввод значений числителя и знаменателя
						std::cout << "Числитель: ";
						int N,D;
						std::cin >> N;
						std::cout << "Знаменатель: ";
						std::cin >> D;
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction(N,D);
						std::cout << "Количество объектов: " << Fraction::GetCount() << std::endl;
						break;
					}//switch (C)
				}//while (C2 != 4)//4 - выход
			}//case 'а'://Добавить объект
			break;
		case 'б'://Удалить объект
			if (Fraction::GetCount() == 0)
			{
				std::cout << "Сначала добвьте объекты!";
				break;
			}
			std::cout << "Введите индекс удаляемого объекта: ";
			int Index;
			std::cin >> Index;
			while (Index<0 || Index>= Fraction::GetCount())
			{
				std::cout << std::endl << "Индекс введен неверно, введите еще раз: ";
				std::cin >> Index;
			}
			c = Fraction::GetCount() - 1;
			for (i = Index; i < c; i++)
			{
				PFraction[i]->SetNumerator(PFraction[i+1]->GetNumerator());
				PFraction[i]->SetDenominator(PFraction[i + 1]->GetDenominator());
			}
			delete PFraction[i];
			std::cout << "Количество объектов: " << Fraction::GetCount() << std::endl;
			break;
		case 'в'://Показать все объекты
			std::cout << "№" << "\t" << "Числитель" << "\t" << "Знаменатель" << std::endl;
			for (i = 0, c = Fraction::GetCount(); i < c; i++)
			{
				std::cout << i << "\t";
				PFraction[i]->Print();
			}
			break;
		case 'г'://Управление объектом
			if (Fraction::GetCount() == 0)
			{
				std::cout << "Сначала добвьте объекты!";
				break;
			}
			std::cout << "Введите индекс управляемого объекта: ";
			std::cin >> Index;
			while (Index<0 || Index >= Fraction::GetCount())
			{
				std::cout << std::endl << "Индекс введен неверно, введите еще раз: ";
				std::cin >> Index;
			}
			int C3 = -1;
			while (C3 != 5)//5- выход
			{
				ShowMenu3();
				std::cin >> C3;
				while (C3 < 1 || C3>5)
				{
					std::cout << std::endl << "Неверно введен номер, введите еще раз: ";
					std::cin >> C3;
				}
				Fraction *F = new Fraction();//Создание объекта и инкремент Count;
				switch (C3)
				{
				case 1://Изменение содержимого объекта с заданным номером
					std::cout << "Новый числитель: ";
					int N, D;
					std::cin >> N;
					std::cout << "Новый знаменатель: ";
					std::cin >> D;
					PFraction[Index]->SetNumerator(N);
					PFraction[Index]->SetDenominator(D);
					break;
				case 2://Сокращение дроби объекта с заданным номером
					PFraction[Index]->Reduction();
					break;
				case 3://Умножение дроби объекта с заданным номером
					std::cout << "Числитель множителя: ";
					std::cin >> N;
					std::cout << "Знаменатель множителя: ";
					std::cin >> D;
					F->SetNumerator(N);
					F->SetDenominator(D);
					PFraction[Index]->Mul(*F);
					break;
				case 4://Деление дроби объекта с заданным номером
					std::cout << "Числитель делителя: ";
					std::cin >> N;
					std::cout << "Знаменатель делителя: ";
					std::cin >> D;
					F->SetNumerator(N);
					F->SetDenominator(D);
					PFraction[Index]->Div(*F);
					break;
				}//switch (C3)
				delete F;//Удаление объекта и декремент Count
			}//while (C3 != 5)//5- выход
			break;
		}//switch (C)
	}//while (C != 'д')//д - выход
	//Очистка динамической памяти
	for (i = 0, c = Fraction::GetCount(); i < c; i++)
	{
		delete PFraction[i];
	}
}