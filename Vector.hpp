#pragma once
#include <iostream>
#include <vector>
namespace ft {

	template<typename T>
		class Vector {
			private:
				T *array;
				int size;
				int capacity;
				std::allocator<T> alloc;
			public:
				Vector();
				Vector(size_t, T const &);
				template<typename ItType>
				Vector(ItType, ItType);
				Vector(Vector<T> const &);
				Vector &operator=(Vector<T> const &);
				~Vector();
		};
}
