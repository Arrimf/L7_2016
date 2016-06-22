#pragma once

template<typename T>
class MyStack2 {
	struct Node	{
		T* m_data;
		Node* m_Next;

		Node(const T&,Node*);
		Node(T&&, Node*);
		~Node();

		
	};
	//friend class Node;
	Node* Head = nullptr;
	size_t m_size = 0;
	size_t m_cap = 100;
protected:
	void PrintNodes(const Node&)const;
	void CopyNodes(const Node&)
	inline Node& GetNext(Node& cur) {return *cur.m_Next}
public:

	MyStack2() {};
	void Push(const T&)throw(const char*);
	void Push(T&&)throw(const char*);
	T PoP()throw(const char*);
	void Pop()throw(const char*);
	const T& Top()const throw(const char*);
	void Print()const ;
	void Clear();
	//inline Node& operator--(Node& cur) {cur.m_Next};
	
	MyStack2& operator=(const MyStack2&);
	//T& operator[](size_t)throw(const char*);


};
template<typename T>
MyStack2<T>::Node::Node(const T& obj, Node*H) {
	m_Next = H;
	//if (obj) {
		m_data = new T(obj);
	//}
	//else {&obj = nullptr;}
}

template<typename T>
 MyStack2<T>::Node::Node( T&& obj, Node *H){
	 m_Next = H;
	// if (obj) {
		 m_data = new T(std::move(obj));
	// }
}

 template<typename T>
 MyStack2<T>::Node::~Node() {
	 delete m_data;
	// Head = m_Next;
 }

 //template<typename T>
	//void MyStack2<T>::Node::PrintNode() {
	//	std::cout << *m_data;
 //}


template<typename T>
 void MyStack2<T>::Push(const T& obj){
	 if (m_size < m_cap) {
		Head = new Node(obj , Head);
		MyStack2::m_size++;
	}
	else { throw "max size exceeded, bat u may resize stack"; }
}

 template<typename T>
 void MyStack2<T>::Push(T&& obj) throw(const char *) {
	 if (m_size < m_cap) {
		 Head = new Node(static_cast<T&&>(obj), Head);
		 MyStack2::m_size++;
	 }
	 else { throw "max size exceeded, bat u may resize stack"; }
 }

 template<typename T>
 T MyStack2<T>::PoP() throw(const char *)
 {
	 if (m_size) {
		 T tmp(std::move(*Head->m_data));
		 Node*tmpH = Head->m_Next;
		 delete Head;
		 Head = tmpH;
		 m_size--;
		 return std::move(tmp);  ///????
	 }
	 else { throw "I'm empty"; };
	
 }

 template<typename T>
  void MyStack2<T>::Pop() throw(const char *) {
	  if (m_size) {
		  Node*tmpH = Head->m_Next;
		  delete Head;
		  Head = tmpH;
		  m_size--;
	  }
	  else { throw "I'm empty"; };
 }

  template<typename T>
  inline const T& MyStack2<T>::Top() const{
	  if (m_size) {
		  return *Head->m_data;
	  }
	  else {
		  throw "I'm empty";
	  };
  }

 template<typename T>
  void MyStack2<T>::Print()const {
	 PrintNode(*Head);
 }

  template<typename T>
  void MyStack2<T>::PrintNodes(const Node& cur)const {
	   if (cur.m_Next){
		    PrintNode(*cur.m_Next);
			std::cout << *cur.m_data << std::endl;
	   }
	   else{
		   std::cout << *cur.m_data<<std::endl;
	   }
   }

  template<typename T>
  void MyStack2<T>::CopyNodes(const Node& cur) {
		if(cur.m_Next)
  }
  template<typename T>
  MyStack2<T>& MyStack2<T>::operator=(const MyStack2<T> & other) {
	  Clear();
	  if (other.GetNext(Head)) {

	  }
	  return
  }
  template<typename T>
  void MyStack2<T>::Clear(){
	  while (m_size) {
		  Pop();
	  }
  }



   

 
