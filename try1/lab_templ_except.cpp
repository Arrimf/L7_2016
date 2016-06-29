//Исключения

//Шаблоны: 
	//		шаблоны функций,
	//		шаблоны классов,


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
	//Тема. Шаблоны функций.
	//Создайте шаблон функции перестановки местами двух
	//значений - Swap(). Проверьте работоспособность созданного
	//шаблона с помощью приведенного ниже фрагмента кода.
	//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.

	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);

	//_SP
	//Подсказка 2: подумайте, что нужно реализовать, для того,
	//			чтобы следующий вызов работал с объектами MyString
	//			не только корректно, но и эффективно

	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	//_SP

/////////////////////////////////////////////////////////////////////
	
	//Тема. Шаблоны классов.
	//Задание 1.
	//Создайте шаблон класса MyStack для хранения элементов любого типа T.
	//Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
	//			для хранения последовательно расположенных в памяти элементов
	//			является массив, 
	//			2.для задания максимального размера стека может быть использован
	//			параметр-константа шаблона
	//			3.обязательными операциями со стеком являются "push" и "pop". Для
	//			того, чтобы гарантировать корректное выполнение этих операций 
	//			хорошо было бы генерировать исключение в аварийной ситуации
	//			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
	//			мог читать/изменять значения только тех элементов, которые он формировал

	
	//С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
	//стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
	//push() и pop(), operator[]

	
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




	//Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы 
	//для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
	//Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
	//пользователь


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

	//Задание 3. Реализуйте шаблон очереди - MyQueue таким образом, чтобы 
	//для хранения элементов использовался динамический массив.
	//При использовании массива следует учесть специфику очереди, то есть
	//когда заполнен "хвост", в "голове" скорее всего уже имеются свободные элементы
	//=> должен быть организован кольцевой буфер

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

