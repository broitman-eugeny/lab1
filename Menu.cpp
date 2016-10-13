#include "Fraction.h"
//������� ����������� ����
void ShowMenu()
{
	std::cout << std::endl << "������������ ������ �1 (���)";
	std::cout << std::endl << "�. �������� ������";
	std::cout << std::endl << "�. ������� ������";
	std::cout << std::endl << "�. �������� ��� �������";
	std::cout << std::endl << "�. ���������� ��������";
	std::cout << std::endl << "�. �����";
	std::cout << std::endl << "������� ����� ���������� ������ ����: ";
}
//������� ����������� ������� ���������� �������
void ShowMenu2()
{
	std::cout << std::endl << "1. �������� �� ���������";
	std::cout << std::endl << "2. ����� ��� ������������� � ������� �������";
	std::cout << std::endl << "3. ���� �������� ��������� � �����������";
	std::cout << std::endl << "4. �����";
	std::cout << std::endl << "������� ����� ���������� ������ �������: ";
}
//������� ����������� ������� ���������� ��������
void ShowMenu3()
{
	std::cout << std::endl << "1. ��������� ����������� ������� � �������� �������";
	std::cout << std::endl << "2. ���������� ����� ������� � �������� �������";
	std::cout << std::endl << "3. ��������� ����� ������� � �������� �������";
	std::cout << std::endl << "4. ������� ����� ������� � �������� �������";
	std::cout << std::endl << "5. �����";
	std::cout << std::endl << "������� ����� ���������� ������ �������: ";
}
//������� ����
//PFraction - ������ ���������� �� ������� ���� Fraction, ��������� �� FractionDimSize ���������
void Menu(Fraction **PFraction)
{
	char C = -1;
	int i, c;
	while (C != '�')//� - �����
	{
		ShowMenu();
		std::cin >> C;
		while (C<'�' || C>'�')
		{
			std::cout << std::endl << "������� ������ ������, ������� ��� ���: ";
			std::cin >> C;
		}
		switch (C)
		{
		case '�'://�������� ������
			if (Fraction::GetCount() == FractionDimSize)//���� ������ ��������
			{
				std::cout << "��������, ������ ��������" << std::endl;
			}
			else
			{
				int C2 = -1;
				while (C2 != 4)//4 - �����
				{
					ShowMenu2();
					std::cin >> C2;
					while (C2<1 || C2>4)
					{
						std::cout << std::endl << "������� ������ �����, ������� ��� ���: ";
						std::cin >> C2;
					}
					int Index, IndexOfCopy;
					switch (C2)
					{
					case 1://�������� �� ���������
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction();
						std::cout << "���������� ��������: " << Fraction::GetCount() << std::endl;
						break;
					case 2://����� ��� ������������� � ������� �������
						if (Fraction::GetCount() == 0)
						{
							std::cout << "������� ������� �������!";
							break;
						}
						std::cout << "������� ������ ����������� �������: ";
						std::cin >> IndexOfCopy;
						while (IndexOfCopy<0 || IndexOfCopy >= Fraction::GetCount())
						{
							std::cout << std::endl << "������ ������ �������, ������� ��� ���: ";
							std::cin >> IndexOfCopy;
						}
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction(*PFraction[IndexOfCopy]);
						std::cout << "���������� ��������: " << Fraction::GetCount() << std::endl;
						break;
					case 3://���� �������� ��������� � �����������
						std::cout << "���������: ";
						int N,D;
						std::cin >> N;
						std::cout << "�����������: ";
						std::cin >> D;
						Index = Fraction::GetCount();
						PFraction[Index] = new Fraction(N,D);
						std::cout << "���������� ��������: " << Fraction::GetCount() << std::endl;
						break;
					}//switch (C)
				}//while (C2 != 4)//4 - �����
			}//case '�'://�������� ������
			break;
		case '�'://������� ������
			if (Fraction::GetCount() == 0)
			{
				std::cout << "������� ������� �������!";
				break;
			}
			std::cout << "������� ������ ���������� �������: ";
			int Index;
			std::cin >> Index;
			while (Index<0 || Index>= Fraction::GetCount())
			{
				std::cout << std::endl << "������ ������ �������, ������� ��� ���: ";
				std::cin >> Index;
			}
			c = Fraction::GetCount() - 1;
			for (i = Index; i < c; i++)
			{
				PFraction[i]->SetNumerator(PFraction[i+1]->GetNumerator());
				PFraction[i]->SetDenominator(PFraction[i + 1]->GetDenominator());
			}
			delete PFraction[i];
			std::cout << "���������� ��������: " << Fraction::GetCount() << std::endl;
			break;
		case '�'://�������� ��� �������
			std::cout << "�" << "\t" << "���������" << "\t" << "�����������" << std::endl;
			for (i = 0, c = Fraction::GetCount(); i < c; i++)
			{
				std::cout << i << "\t";
				PFraction[i]->Print();
			}
			break;
		case '�'://���������� ��������
			if (Fraction::GetCount() == 0)
			{
				std::cout << "������� ������� �������!";
				break;
			}
			std::cout << "������� ������ ������������ �������: ";
			std::cin >> Index;
			while (Index<0 || Index >= Fraction::GetCount())
			{
				std::cout << std::endl << "������ ������ �������, ������� ��� ���: ";
				std::cin >> Index;
			}
			int C3 = -1;
			while (C3 != 5)//5- �����
			{
				ShowMenu3();
				std::cin >> C3;
				while (C3 < 1 || C3>5)
				{
					std::cout << std::endl << "������� ������ �����, ������� ��� ���: ";
					std::cin >> C3;
				}
				Fraction *F = new Fraction();//�������� ������� � ��������� Count;
				switch (C3)
				{
				case 1://��������� ����������� ������� � �������� �������
					std::cout << "����� ���������: ";
					int N, D;
					std::cin >> N;
					std::cout << "����� �����������: ";
					std::cin >> D;
					PFraction[Index]->SetNumerator(N);
					PFraction[Index]->SetDenominator(D);
					break;
				case 2://���������� ����� ������� � �������� �������
					PFraction[Index]->Reduction();
					break;
				case 3://��������� ����� ������� � �������� �������
					std::cout << "��������� ���������: ";
					std::cin >> N;
					std::cout << "����������� ���������: ";
					std::cin >> D;
					F->SetNumerator(N);
					F->SetDenominator(D);
					PFraction[Index]->Mul(*F);
					break;
				case 4://������� ����� ������� � �������� �������
					std::cout << "��������� ��������: ";
					std::cin >> N;
					std::cout << "����������� ��������: ";
					std::cin >> D;
					F->SetNumerator(N);
					F->SetDenominator(D);
					PFraction[Index]->Div(*F);
					break;
				}//switch (C3)
				delete F;//�������� ������� � ��������� Count
			}//while (C3 != 5)//5- �����
			break;
		}//switch (C)
	}//while (C != '�')//� - �����
	//������� ������������ ������
	for (i = 0, c = Fraction::GetCount(); i < c; i++)
	{
		delete PFraction[i];
	}
}