#pragma once

template<typename T, int size>
class MyQueue {
	T* m_data = nullptr;
	size_t m_cap = size;
	size_t m_size = 0;

	T* Pushy = nullptr;
	T* Popy = nullptr;
	
	protected:
		

	public:
		MyQueue();
		void Push(const T&)throw(const char*);
		void Push(T&&)throw(const char*);
		T&& PoP()throw(const char*);
		void Pop()throw(const char*);
		const T& Top()const throw(const char*);
		void Clear();
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
	   if (m_size) {
		   T* tmp = Popy;
		   (Popy == &m_data[m_cap - 1]) ? Popy = &m_data[0] : Popy++;
		   m_size--;
		   return std::move(*tmp);
	   }
	   else { throw "I'm empty"; };
   }

   template<typename T, int size>
   void MyQueue<T, size>::Pop(){
	   if (m_size) {
		   m_size--;
		   *Popy = T();
		   (Popy == &m_data[m_cap - 1]) ? Popy = &m_data[0] : Popy++;
	   }
	   else { throw "I'm empty"; };
   }

   template<typename T, int size>
    const T & MyQueue<T, size>::Top()const {
	   if (m_size) {
		   return *Popy;
	   }
	   else {
		   throw "I'm empty";
	   };
   }

   template<typename T, int size>
    void MyQueue<T, size>::Clear(){
		while (m_size) {
			Pop();
		}
   }
 


 
