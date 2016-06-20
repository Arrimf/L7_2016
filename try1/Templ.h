#pragma once

template<typename T> void Swap( T&obj1,  T&obj2) {
	T tmp (std::move(obj1));
	obj1 = std::move(obj2);
	obj2 = std::move(tmp);
}

template<typename T,int size>
class MyStack {
		T data[size] = {};
		size_t capa = size;
		size_t cur_p = 0;
	public:
		MyStack() {};
		void Push(const T&)throw(const char*);
		void Push(T&&)throw(const char*);
		T PoP()throw(const char*);
		void Pop()throw(const char*);
		const T& Top()const;
		T& operator[](size_t)throw(const char*);
		//MyStack(const T& val );
};


//template<typename T, int size>
//MyStack<T, size>::MyStack(const T& val)  {
//
//	   for (int i = 0; i < size; i++) {
//		   		 data[i]=  T(val);
//		}
//				cur_p = size;
//   }

template<typename T, int size>
void MyStack<T, size>::Push(const T& obj) {
	if (cur_p < capa) {
		data[cur_p] = T(obj);
		cur_p++;
	}
	else { throw "I'm full"; };
}

template<typename T, int size>
void MyStack<T, size>::Push(T&& obj) throw(const char *){
	if (cur_p < capa) {
		data[cur_p] = T(std::move(obj));
		cur_p++;
	}
	else { throw "I'm full"; };
}

template<typename T, int size>
T MyStack<T, size>::PoP() throw(const char *){
	if (cur_p) {
		cur_p--;
		return T(std::move(data[cur_p]));
	}
	else { throw "I'm empty"; };
}

template<typename T, int size>
void MyStack<T, size>::Pop() throw(const char *){
	if (cur_p) {
		cur_p--;
		data[cur_p]= T();
	}
	else { throw "I'm empty"; };
}

template<typename T, int size>
const T& MyStack<T, size>::Top()const{
	return data[cur_p - 1];
}

template<typename T, int size>
T& MyStack<T, size>::operator[](size_t i) {
	if (i < cur_p) {return data[i];	}
	else { throw "U've missed"; };
}
