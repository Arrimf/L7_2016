//����������

//�������: 
	//		������� �������,
	//		������� �������,


#include <tchar.h>
#include "myString.h"
#include "MyStack1.h"
#include "MyStack2.h"
#include "FuncTeml.h"

//#include <stdexcept>


#define stop __asm nop
#define _CLS system("cls");
#define _SP system("pause");


//MyStack2::Head* = nullptr;

int _tmain(int argc, _TCHAR* argv[])
{
	

/*
////////////////////////////////////////////////////////////////////////////
	//����. ������� �������.
	//�������� ������ ������� ������������ ������� ����
	//�������� - Swap(). ��������� ����������������� ����������
	//������� � ������� ������������ ���� ��������� ����.
	//��������� 1: ���������� ������� ���������� ��������� � .h-����.

	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);

	_SP
	//��������� 2: ���������, ��� ����� �����������, ��� ����,
	//			����� ��������� ����� ������� � ��������� MyString
	//			�� ������ ���������, �� � ����������
	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	_SP
*/
/////////////////////////////////////////////////////////////////////
	
	//����. ������� �������.
	//������� 1.
	//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
	//���������: 1.�������� ����� ���-�� ������� - ������� � ������� ���������
	//			��� �������� ��������������� ������������� � ������ ���������
	//			�������� ������, 
	//			2.��� ������� ������������� ������� ����� ����� ���� �����������
	//			��������-��������� �������
	//			3.������������� ���������� �� ������ �������� "push" � "pop". ���
	//			����, ����� ������������� ���������� ���������� ���� �������� 
	//			������ ���� �� ������������ ���������� � ��������� ��������
	//			4. ������������� ���������� operator[] ����� �������, ����� ������������
	//			��� ������/�������� �������� ������ ��� ���������, ������� �� ����������

	
	//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
	//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
	//push() � pop(), operator[]


	MyStack<int, 6> iStack();//(5);
	MyStack<double, 2> St2;
	MyStack<MyString, 5> strStack;//("r");

	strStack.Push("q-q");
	MyString r = MyString(strStack.Top());
	strStack.Push("we");
	//_SP




	//������� 2. ���������� ������ ����� - MyStack2 ����� �������, ����� 
	//��� �������� ��������� ������������� ����������� ������.
	//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
	//������������


	MyStack2<int>St3;
	MyStack2<MyString>Str2St;
	Str2St.Push("q-q");
	Str2St.Push("oy");
	//Str2St.Push(MyString());
	
		//MoveStack(Str2St, strStack);
	MyString r2 = Str2St.PoP();
	_SP


	//������� 3. ���������� ������ ������� - MyQueue ����� �������, ����� 
	//��� �������� ��������� ������������� ������������ ������.
	//��� ������������� ������� ������� ������ ��������� �������, �� ����
	//����� �������� "�����", � "������" ������ ����� ��� ������� ��������� ��������
	//=> ������ ���� ����������� ��������� �����

	return 0;
}

