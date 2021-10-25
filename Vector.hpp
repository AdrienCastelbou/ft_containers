#pragma once
#include <iostream>

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
		};
}
