#pragma once

template<typename T> void Swap( T&obj1,  T&obj2) {
	T tmp (std::move(obj1));
	obj1 = std::move(obj2);
	obj2 = std::move(tmp);
}