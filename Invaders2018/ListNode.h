#ifndef LISTNODE_H
#define LISTNODE_H

#include "Comparator.h"

/**
*	Container for a single entry in a list sequence
*	Contents are pointed to with a void pointer
**/
class ListNode
{
	public:
		ListNode();
		ListNode(void* _i);
		ListNode(const ListNode& _c);

		ListNode& operator = (const ListNode& _rhs);
		bool operator == (const ListNode& _rhs);

		void* get();
		template<typename T> int get(T* _v);
		int get(void* _v);
		int get(char* _v);
		int get(int* _v);
		int get(long int* _v);
		int get(float* _v);
		int get(double* _v);
		int set(void* _s);

		ListNode* getNext();
		ListNode* getPrev();

		int insertNext(ListNode* _l);
		int insertNext(void* _i);
		int insertPrev(ListNode* _l);
		int insertPrev(void* _i);

		int untie();

		int trade(ListNode* _ln);
		int swap();
		int physicalSwap();
		
		int bSort(Comparator* _comp);
		int reverse();

		int isSet();

		~ListNode();

	protected:
		ListNode* next;
		ListNode* prev;
		void* value;
		int state;
};

#endif
