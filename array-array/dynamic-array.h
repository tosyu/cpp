#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#include <stddef.h>

template <class T>
class DynamicArray {
	T* data;
	int len;
	int rlen;
	public:
		DynamicArray() {
			data = NULL;
			len = 0;
			rlen = 0;
		};		
		DynamicArray(T* initialArr, int initialLength) {
			int i;
			data = new T[initialLength];
			for (i = 0; i < initialLength; ++i) {
				this[i] = initialArr[i];
			}
			len = initialLength;
			rlen = initialLength + 16;
		};
		~DynamicArray() {
			delete[] data;
		};
		T& operator [] (int index) {
			T* newData;
			int i;
			if (rlen == len || index > len) {
				if (index > len) {
					rlen += (index - len);
				}
				rlen += 16;
				
				newData = new T[rlen];
				for (i = 0; i < len; ++i) {
					newData[i] = data[i];
				}
				delete[] data;
				data = newData;
			}
				
			return &(*data[index]);
		};
		int length() {
			return len;
		};
};

#endif
