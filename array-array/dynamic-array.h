#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#include <stddef.h>
#include <iostream>

template <class T>
class DynamicArray {
	private:
		class Node {
			private:
				T data;
			public:
				T& operator = (const T &value) {
					data = value;
					return data;
				};			
				friend std::ostream& operator << (std::ostream& out, const Node& n) {
					return out << n.data;
				};
		};
		Node* data;
		int realDataLength;
		int dataLength;
		int overflowSize;
	public:
		DynamicArray() {
			data = NULL;
			dataLength = 0;
			realDataLength = 0;
			overflowSize = sizeof(T) * 4;
		};			
		DynamicArray(T* inputArray, int inputLength) {
			dataLength = inputLength;
			overflowSize = sizeof(T) * 4;
			realDataLength = inputLength + overflowSize;
			data = new Node[realDataLength];

			int i;
			for (i = 0; i < dataLength; ++i) {
				data[i] = inputArray[i];
			}
		};
		~DynamicArray() {
			delete[] data;
		};
		Node& operator [] (int index) {
			if (index > dataLength - 1) {
				if (index >= realDataLength) {
					realDataLength = index + overflowSize;
					Node* newData = new Node[realDataLength];
					int i;
					for (i = 0; i < dataLength; ++i) {
						newData[i] = data[i];
					}
					delete[] data;
					data = newData;
				}
				dataLength = index + 1;
			}

			return data[index];
		};		
		bool remove (int index) {
			int maxIndex = dataLength - 1;
			if (index > maxIndex) {
				return false;
			}

			--dataLength;
			--realDataLength;
			if (index == maxIndex) {
				data[index] = Node();
				return true;
			}

			int i;
			int j = 0;
			Node* newData = new Node[realDataLength];			
			for(i = 0; i < realDataLength; ++i) {
				if (i != index) {
					newData[j++] = data[i];
				}
			}
			delete[] data;
			data = newData;
		
			return true;
		}
		int length() {
			return dataLength;
		};
};

#endif
