#pragma once

template<typename T>
class MyQueue {
	T* m_data = nullptr;
	size_t m_cap = 0;
	size_t m_size = 0;

	T* Pushy = nullptr;
	T* Popy = nullptr;
	
	protected:
		

	public:
		MyQueue(int =1);
		MyQueue(const MyQueue&);
		MyQueue(MyQueue&&);
		void Push(const T&)throw(const char*);
		void Push(T&&)throw(const char*);

		T PoP()throw(const char*);
		void Pop()throw(const char*);
		const T& Top()const throw(const char*);
		void Resize(int = 1);
		void Clear();
		void Print();
		MyQueue& operator=(const MyQueue&);
		MyQueue& operator=(MyQueue&&);
};

template<typename T>
 MyQueue<T>::MyQueue(int size){
	 m_cap = size;
	 m_data = static_cast<T*> (malloc(sizeof(T)*m_cap));
	 for (int i = 0; i < m_cap;i++) {
		 new(&m_data[i])T();
	 }
	Pushy = &m_data[0];
	Popy = &m_data[0];
}

 template<typename T>
  MyQueue<T>::MyQueue(const MyQueue& other) {
	  m_size = other.m_size;
	  m_cap = other.m_size+1;
	  m_data = static_cast<T*> (malloc(sizeof(T)*m_cap));
	  T* tmpPop = other.Popy;
	  for (int i = 0; i < m_size;i++) {
		  new(&m_data[i])T(*tmpPop);
		  (tmpPop == &m_data[other.m_cap - 1]) ? tmpPop = &other.m_data[0] : tmpPop++;
	  }
	  new(&m_data[m_size])T();
	  Popy = &m_data[0];
	  Pushy = &m_data[0]+m_size;
 }

  template<typename T>
   MyQueue<T>::MyQueue(MyQueue &&other) {

		  m_size = other.m_size;
		  m_cap = other.m_cap;
		  //T* tmpData = m_data;
		  m_data = other.m_data;
		  other.m_data = nullptr;
		  Popy = other.Popy;
		  other.Popy = nullptr;
		  Pushy = other.Pushy;
		  other.Pushy = nullptr;
	  }
  

 template<typename T>
  void MyQueue<T >::Push(const T& obj) {
	  if(m_size<m_cap) {
			*Pushy = obj;
			(Pushy == &m_data[m_cap-1])? Pushy = &m_data[0] : Pushy++;
			m_size++;
		  }
		 else{ throw "I'm full, but u may resize me"; }
  }
  template<typename T>
   void MyQueue<T>::Push(T&& obj) {
	   if (m_size<m_cap) {
		   *Pushy = std::move(obj);
		   (Pushy == &m_data[m_cap - 1]) ? Pushy = &m_data[0] : Pushy++;
		   m_size++;
	   }
	   else { throw "I'm full, but u may resize me"; }
  }

   template<typename T>
   T MyQueue<T>::PoP(){
	   if (m_size) {
		   T* tmp = Popy;
		   (Popy == &m_data[m_cap - 1]) ? Popy = &m_data[0] : Popy++;
		   m_size--;
		   return std::move(*tmp);
	   }
	   else { throw "I'm empty"; };
   }

   template<typename T>
   void MyQueue<T>::Pop(){
	   if (m_size) {
		   m_size--;
		   *Popy = T();
		   (Popy == &m_data[m_cap - 1]) ? Popy = &m_data[0] : Popy++;
	   }
	   else { throw "I'm empty"; };
   }

   template<typename T>
    const T& MyQueue<T>::Top()const {
	   if (m_size) {
		   return *Popy;
	   }
	   else {
		   throw "I'm empty";
	   };
   }

	template<typename T>
	 void MyQueue<T>::Resize(int delta){
		 T*  tmp = static_cast<T*> (malloc(sizeof(T)*(m_cap +delta)));
		 
		 for (int i = 0; i < m_cap;i++) {
			 new(&tmp[i])T(std::move(*Popy));
			 (Popy == &m_data[m_cap - 1]) ? Popy = &m_data[0] : Popy++;
		 }
		 for (int i = m_cap; i < (m_cap+delta);i++) {
			 new(&tmp[i])T();
		 }
		 delete m_data;
		 m_data = tmp;
		 Popy = &m_data[0];
		 Pushy = &m_data[m_cap];
		 m_cap += delta;
	}

   template<typename T>
    void MyQueue<T>::Clear(){
		m_size = 0;
		//while (m_size) {
		//	Pop();
		//}
   }

	template<typename T>
	 void MyQueue<T>::Print(){
		 T* tmpPopy = Popy;
		 do{
			 std::cout << *tmpPopy << std::endl;
			 (tmpPopy == &m_data[m_cap - 1]) ? tmpPopy = &m_data[0] : tmpPopy++;
		 } while (tmpPopy != Pushy);
	}

	template<typename T>
	MyQueue<T>& MyQueue<T>::operator=(const MyQueue & other)
	{
		T* tmpPopy = other.Popy;
		if (other.m_size > m_cap) {
			delete m_data;
			m_cap = other.m_size + 1;
			m_data = static_cast<T*> (malloc(sizeof(T)*(m_cap)));

			for (int i = 0; i < other.m_size;i++) {
				new(&m_data[i])T(*tmpPopy);
				(tmpPopy == &other.m_data[other.m_cap - 1]) ? tmpPopy = &other.m_data[0] : tmpPopy++;
			}
			new(&m_data[other.m_size])T();
			
		}
		else{
			for (int i = 0; i < other.m_size;i++) {
				m_data[i] = *tmpPopy;
				(tmpPopy == &other.m_data[other.m_cap - 1]) ? tmpPopy = &other.m_data[0] : tmpPopy++;
			}
		}
		Popy = &m_data[0];
		m_size = other.m_size;
		Pushy = &m_data[0] + m_size;

		return *this;
	}

	template<typename T>
	 MyQueue<T>& MyQueue<T>::operator=(MyQueue&& other){
		 if (this != &other) {
			 m_size = other.m_size;
			 m_cap = other.m_cap;
			 //T* tmpData = m_data;
			 delete m_data;
			 m_data = other.m_data;
			 other.m_data = nullptr;
			 Popy = other.Popy;
			 other.Popy = nullptr;
			 Pushy = other.Pushy;
			 other.Pushy = nullptr;
			 return *this;
		 }
	}

	 
 //template<typename T>
MyQueue<MyString> balovstvo() {
	 MyQueue<MyString>QQ(8);
	 QQ.Push("balovstvo1");
	 QQ.Push("balovstvo2");
	 QQ.Push("balovstvo3");
	 return std::move(QQ);
}

	
