#pragma once
//Стек - встроенный массив

template<typename T,int size>
class MyStack {
		T data[size] = {};
		size_t capa = size;
		size_t Head = 0;
	public:
		MyStack(){};
		MyStack(const T& val);
		void Push(const T&)throw(const char*);
		void Push(T&&)throw(const char*);
		T PoP()throw(const char*);
		void Pop()throw(const char*);
		const T& Top()const;
		T& operator[](size_t)throw(const char*);
		
};


template<typename T, int size>
MyStack<T, size>::MyStack(const T& val) {
	   for (int i = 0; i < size; i++) {
		   		 data[i]=  T(val);
		}
				Head = size;
   }



template<typename T, int size>
void MyStack<T, size>::Push(const T& obj) {
	if (Head < capa) {
		data[Head] = T(obj);
		Head++;
	}
	else { throw "I'm full"; };
}

template<typename T, int size>
void MyStack<T, size>::Push(T&& obj) throw(const char *){
	if (Head < capa) {
		data[Head] = T(std::move(obj));
		Head++;
	}
	else { throw "I'm full"; };
}

template<typename T, int size>
T MyStack<T, size>::PoP() throw(const char *){
	if (Head) {
		Head--;
		return T(std::move(data[Head]));
	}
	else { throw "I'm empty"; };
}

template<typename T, int size>
void MyStack<T, size>::Pop() throw(const char *){
	if (Head) {
		Head--;
		data[Head]= T();
	}
	else { throw "I'm empty"; };
}

template<typename T, int size>
const T& MyStack<T, size>::Top()const{
	if (Head) {
		return data[Head - 1];
	}
	else { 
		throw "I'm empty"; };
}

template<typename T, int size>
T& MyStack<T, size>::operator[](size_t i) {
	if (i < Head) {return data[i];	}
	else { throw "U've missed"; };
}
