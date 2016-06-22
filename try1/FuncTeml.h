#pragma once


template<typename T> void Swap(T&obj1, T&obj2) {
	T tmp(std::move(obj1));
	obj1 = std::move(obj2);
	obj2 = std::move(tmp);
}

template<typename St1, typename St2 >
void MoveStack(St1& dst, St2& src) {
	while (1) {
		try {
			dst.Push(src.PoP());
		}
		catch (const char* ex) {
			std::cout << ex;
			break;
		}
	}
}
template<typename St>
void PrintStack(St&) {
	St.Print()
}
