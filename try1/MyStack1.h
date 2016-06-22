#pragma once
//Стек - встроенный массив

template<typename T,int size>
class MyStack {
		T m_data[size] = {};
		size_t m_cap = size;
		size_t m_size = 0;
	public:
		MyStack(){};
		MyStack(const T& val);
		void Push(const T&)throw(const char*);
		void Push(T&&)throw(const char*);
		T PoP()throw(const char*);
		void Pop()throw(const char*);
		const T& Top()const;
		T& operator[](size_t)throw(const char*);
		//T*& operator--(T*&);
		void Print();
		void Clear();
		//MyStack& operator==(MyStack&)

};


template<typename T, int size>
MyStack<T, size>::MyStack(const T& val) {
	   for (int i = 0; i < size; i++) {
		   		 m_data[i]=  T(val);
		}
				m_size = size;
   }



template<typename T, int size>
void MyStack<T, size>::Push(const T& obj) {
	if (m_size < m_cap) {
		m_data[m_size] = T(obj);
		m_size++;
	}
	else { throw "I'm full"; };
}

template<typename T, int size>
void MyStack<T, size>::Push(T&& obj) throw(const char *){
	if (m_size < m_cap) {
		m_data[m_size] = T(std::move(obj));
		m_size++;
	}
	else { throw "I'm full"; };
}

template<typename T, int size>
T MyStack<T, size>::PoP() throw(const char *){
	if (m_size) {
		m_size--;
		return T(std::move(m_data[m_size]));
	}
	else { throw "I'm empty"; };
}

template<typename T, int size>
void MyStack<T, size>::Pop() throw(const char *){
	if (m_size) {
		m_size--;
		m_data[m_size]= T();
	}
	else { throw "I'm empty"; };
}

template<typename T, int size>
const T& MyStack<T, size>::Top()const{
	if (m_size) {
		return m_data[m_size - 1];
	}
	else { 
		throw "I'm empty"; };
}

template<typename T, int size>
T& MyStack<T, size>::operator[](size_t i) {
	if (i < m_size) {return m_data[i];	}
	else { throw "U've missed"; };
}

template<typename T, int size>
 void MyStack<T, size>::Print(){
	 for (size_t i = 0; i < m_size; i++)
	 {
		 std::cout << m_data[i]<<std::endl;
	 }
}

 template<typename T, int size>
  void MyStack<T, size>::Clear() {
	  while (m_size) {
		  Pop();
	  }
 }

//template<typename T, int size>
//inline T*& MyStack<T, size>::operator--(T*& dat){
//	return --this->*m_data[dat];
//}
