#pragma once

template<typename T>
class MyStack2 {
	struct Node	{
		T* m_data;
		Node* m_Next;

		Node(const T&,Node*);
		Node( T&&, Node*);
		~Node();
		friend class MyStack2<T>;
	};
	//friend class Node;
	Node* Head = nullptr;// = MyStack2<T>::Node::Head;
	size_t m_size = 0;
	size_t m_cap = 100;
public:

	MyStack2() {};
	void Push(const T&)throw(const char*);
	void Push(T&&)throw(const char*);
	T PoP()throw(const char*);
	//void Pop()throw(const char*);
	//const T& Top()const;
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

 
