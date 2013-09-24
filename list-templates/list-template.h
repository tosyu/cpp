#ifndef _LIST_TEMPLATE_H_
#define _LIST_TEMPLATE_H_

template <class T>
class Node {
	public:
		T* data;
		Node<T>* next;
		Node<T>* prev;

		Node();
		Node(T*);
};

template <class T>
class LinkedList {
	Node<T>* current;
	Node<T>* head;
	Node<T>* tail;
	int items;

	public:
		LinkedList();
		~LinkedList();
		Node<T>* add(T&);
		bool remove(T&);
		void rewind(void);
		T next(void);
		T prev(void);
		int length(void);
		void clear(void);
};

#endif
