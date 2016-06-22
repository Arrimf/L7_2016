#pragma once

template<typename T, int size>
class MyQueue {
	T* m_data = nullptr;
	size_t m_cap = size;
	size_t m_size = 0;

	T* Pushy = nullptr;
	T* Popy = nullptr;
	bool inverted = false;


	protected:
		

	public:
		MyQueue();
		void Push(const T&);
		void Push(T&&);
		T&& PoP();


};

template<typename T, int size>
 MyQueue<T, size>::MyQueue(){
	 m_data = static_cast<T*> (malloc(sizeof(T)*m_cap));
	 for (int i = 0; i < m_cap;i++) {
		 new(&m_data[i])T();
	 }
	Pushy = &m_data[0];
	Popy = &m_data[0];
}

 template<typename T, int size>
  void MyQueue<T, size >::Push(const T& obj) {
	  if(m_size<m_cap) {
			*Pushy = obj;
			(Pushy == &m_data[m_cap-1])? Pushy = &m_data[0] : Pushy++;
			m_size++;
		  }
		 else{ throw "I'm full"; }
  }
  template<typename T, int size>
   void MyQueue<T, size>::Push(T&& obj) {
	   if (m_size<m_cap) {
		   *Pushy = std::move(obj);
		   (Pushy == &m_data[m_cap - 1]) ? Pushy = &m_data[0] : Pushy++;
		   m_size++;
	   }
	   else { throw "I'm full"; }
  }

   template<typename T, int size>
   T&& MyQueue<T, size>::PoP(){
	   T* tmp = Popy;
	   (Popy == &m_data[m_cap - 1]) ? Popy = &m_data[0] : Popy++;
	   m_size--;
	   return std::move(*tmp);
   }
 


 
