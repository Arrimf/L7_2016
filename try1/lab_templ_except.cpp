//����������

//�������: 
	//		������� �������,
	//		������� �������,


#include <tchar.h>
//#include <stdlib.h>
#include "myString.h"
#include "Rect.h"
#include "MyStack1.h"
#include "MyStack2.h"
#include "MyQueue.h"
#include "FuncTeml.h"
#include <stack>

//#include <stdexcept>


#define stop __asm nop
#define _CLS system("cls");
#define _SP system("pause");


//MyStack2::Head* = nullptr;

int _tmain(int argc, _TCHAR* argv[])
{
	


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

	//_SP
	//��������� 2: ���������, ��� ����� �����������, ��� ����,
	//			����� ��������� ����� ������� � ��������� MyString
	//			�� ������ ���������, �� � ����������

	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	//_SP

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

	
	MyStack<int, 6> iStack;//(5);
	iStack.Push(1);
	int&& tmp = iStack.PoP();
	iStack.Push(2);
	//_SP
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
	Str2St.Push("st1");
	Str2St.Push("st2");
	//Str2St.Push(MyString());
	//Str2St.Print();
	//Str2St.Clear();
	Str2St.Push("st3");
	//Str2St.Print();
	MyStack2<MyString> r8;
	
	//MyString r4(Str2St.Top());
	//r8.Print();
	
	r8 = Str2St;
	
	
		//MoveStack(Str2St, strStack);
	//MyString r2 = Str2St.PoP();
	_SP
		//strStack

	//������� 3. ���������� ������ ������� - MyQueue ����� �������, ����� 
	//��� �������� ��������� ������������� ������������ ������.
	//��� ������������� ������� ������� ������ ��������� �������, �� ����
	//����� �������� "�����", � "������" ������ ����� ��� ������� ��������� ��������
	//=> ������ ���� ����������� ��������� �����

	//MyQueue<Rect, 5>Q_r;
	//Q_r.Push(Circle(2, 1, 4));
	//MyQueue<int, 10> Q1;
	MyQueue<MyString> Q2(8);
	Q2.Push("qwe");

	MoveStack(Q2, Str2St);
	Q2.Push("ku");
	Q2.Push("ku-ku");
	Q2.Push("Boo");
	Q2.PoP();
	//MoveStack(r8, Q2);
	//r8.Push(Q2.PoP());
	Q2.Push("Last");
	MyQueue<MyString> QStr4(2);
	QStr4.Push("privet");
	QStr4.Print();
	QStr4 = balovstvo();
	QStr4.Print();
 	_SP
	//MyQueue<Shape, 10>Sh1;

	//try { Q2.Push("Be"); }
	//catch (const char*) {
	//	Q2.Resize();
	//	Q2.Push("Be");
	//}

	//_SP
		//r8.Push(Q2.PoP());
		//_SP
		MyQueue<MyString>Q3(Q2);
 		_SP
	return 0;
}

