#ifndef LIST_H
#define LIST_H

#include "ListNode.h"

class List
{
	public:
		List();
		List(void* _i);
	//	List(const List& _c);

		void* get();
		int getLength();
		int getSelectedIndex();
		
		int next();
		int prev();
		int reset();
		int select(int _index);

		int push(void* _k);
		void* pop();
		int unshift(void* _k);
		void* shift();
		int shift(void* _k);
		int add(void* _k);
		int insert(void* _k);
		//int concat();

		void* remove();
		int remove(void* _k);
		int remove(void* _k, int _x);

		void clear();
		void clear(void** _a, int _l);

		void reverse();
		void bSort(Comparator* _comp);

		/*int first(void* _f);
		int last(void* _l);

		int copy(int _from, int _to);
		int swap(int _from, int _to);

		void slice(void* _array, int _count);
		void slice(int _start, void* _array, int _count);

		void splice(void** _in, int _inCount, void** _out, int _outCount);
		void splice(int _start, void** _in, int _inCount, void** _out, int _outCount);*/

		~List();
	protected:
		ListNode* head;
		ListNode* current;
		ListNode* tail;
		int length;
		int selected;

		int adjustIndex(int& _i);
};





#endif
