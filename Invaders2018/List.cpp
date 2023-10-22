#include "List.h"

/**
*	Default Constructor
*	Creates an empty list
**/
List::List()
{
	head = current = tail = (ListNode*)0;
	int length = 0;
	int selected = -1;
}

/**
*	Initial Constructor
*	Creates a List with an initial entry
*
*	@param _i initial value
**/
List::List(void* _i)
{
	head = current = tail = new ListNode(_i);
	int length = 1;
	int selected = 0;
}

void* List::get()
{
	if (current)
	{
		return(current->get());
	}
	return((void*)0);
}

// Copy Constructor
//List::List(const List& _c);

/**
*	Length Access Function
*
*	@returns The length of the sequence
**/
int List::getLength()
{
	return(length);
}

/**
*	Selected Index Access Function
*	
*	@returns The index of the node pointed to by <em>current</em>
**/
int List::getSelectedIndex()
{
	return(selected);
}

/**
*	Next Mutator Function
*	Moves <em>current</em> to the next node in the sequence
**/
int List::next()
{
	if (current && current != tail)
	{
		current = current->getNext();
		selected++;
	}
	return(selected);
}

/**
*	Previous Mutator Function
*	Moves <em>current</em> to the previous node in the sequence
**/
int List::prev()
{
	if (current && current != head)
	{
		current = current->getPrev();
		selected--;
	}
	return(selected);
}

/**
*	Reset Mutator
*	Moves <em>current</em> to the head of the list 
**/
int List::reset()
{
	if (current)
	{
		current = head;
		selected = 0;
	}
	return(selected);
}

/**
*	Selection Mutator
*	Moves <em>current</em> to the <em>_index</em> node in the sequence
*	If <em>_index</em> is negative then the offset is from the end 
*	of the sequence
*
*	@param _index An integer correstponding to the node to be selected
*	@returns Zero if "current" changes
**/
int List::select(int _index)
{
	int adj = adjustIndex(_index);
	if (adj)
	{
		return(adj);
	}
	reset();
	for(selected = 0; selected <= _index; selected++)
	{
		current = current->getNext();
	}
	return(0);
}

int List::push(void* _k)
{
	if (tail)
	{
		if (tail->insertNext(_k))
		{
			tail = tail->getNext();
			length++;
			return(1);
		}
	}
	else
	{
		head = current = tail = new ListNode(_k);
		length = 1;
		selected = 0;
		return(1);
	}
	return(0);
}



void* List::pop()
{
	void* temp = (void*)0;
	if (tail)
	{
		temp = tail->get();
		if (tail == head)
		{
			delete(tail);
			current = tail = head = (ListNode*)0;
			selected = -1;
			length = 0;
		}
		else if (tail == current)
		{
			current = current->getPrev();
			selected--;
			tail->untie();
			delete(tail);
			tail = current;
			length--;
		}
		else
		{
			ListNode* temptail = tail;
			tail = tail->getPrev();
			temptail->untie();
			delete(temptail);
			length--;
		}
		
	}
	return(temp);
}

int List::unshift(void* _k)
{
	if (head)
	{
		if (head->insertPrev(_k))
		{
			head = head->getPrev();
			length++;
			selected++;
			return(1);
		}
	}
	else
	{
		return(push(_k));
	}
	return(0);
}

int List::shift(void* _k)
{
	if (head && _k)
	{
		head->get(_k);
		if (head == tail)
		{
			delete(tail);
			current = tail = head = (ListNode*)0;
			selected = -1;
			length = 0;
		}
		else if (head == current)
		{
			current = current->getNext();
			head->untie();
			delete(head);
			head = current;
			length--;
		}
		else
		{
			ListNode* temp = head;
			head = head->getNext();
			temp->untie();
			delete temp;
			selected--;
			length--;
		}
		return(1);
	}
	return(0);
}

void* List::shift()
{
	void* temp = (void*)0;
	ListNode* k = (ListNode*)0;
	//ListNode* x;
	if (head)
	{
		k = head;
		temp = head->get();
		if (head == tail)
		{
			return(pop());
		}
		else if (current == k)
		{
			current = current->getNext();
			//selected++;
			
		}
		else
		{
			selected--;
		}
		head = head->getNext();
		k->untie();
		delete(k);
		length--;
	}
	return(temp);
}

int List::add(void* _k)
{
	if (!current || current == tail)
	{
		return(push(_k));
	}
	else
	{
		if (current->insertNext(_k))
		{
			length++;
			return(1);
		}
	}
	return(0);
}

int List::insert(void* _k)
{
	if (!current || current == head)
	{
		return(unshift(_k));
	}
	else
	{
		if (current->insertPrev(_k))
		{
			length++;
			selected++;
			return(1);
		}
	}
	return(0);
}

//int List::concat();
void* List::remove()
{
	void* k = (void*)0;
	if (current)
	{
		if (current == head)
		{
			return(shift());
		}
		else if (current == tail)
		{
			return(pop());
		}
		else
		{
			k = current->get();
			ListNode* x = current;
			current = current->getNext();
			x->untie();
			length--;
			delete(x);
		}
	}
	return(k);
}

int List::remove(void* _k)
{
	if (current)
	{
		if (current == head)
		{
			return(shift(_k));
		}
		else if (current == tail)
		{
			return(*((int*)pop()));
		}
		else
		{
			ListNode* temp = current;
			current = current->getNext();
			//selected--;
			temp->untie();
			temp->get(_k);
			delete temp;
			length--;
		}
		return(1);
	}
	return(0);
}

int List::remove(void* _k, int _x)
{
	if (!adjustIndex(_x))
	{
		return(-1);
	}
	if (_x == selected)
	{
		return(remove(_k));
	}
	else if (_x == 0)
	{
		return(shift(_k));
	}
	else if (_x == length - 1)
	{
		return(*((int*)pop()));
	}
	else
	{
		ListNode* temp = head;
		for (int i = _x; i >= 0; i--)
		{
			temp = temp->getNext();
		}
		temp->untie();
		temp->get(_k);
		delete(temp);
		if (_x < selected)
		{
			selected--;
		}
		length--;
		return(1);
	}
	return(0);
}

void List::clear()
{
	ListNode* temp;
	while (head)
	{
		temp = head;
		head = head->getNext();
		temp->untie();
		delete(temp);
	}
	length = 0;
	selected = -1;
}

void List::clear(void** _a, int _l)
{
	int x = 0;
	ListNode* temp;
	while (head)
	{
		if (_l > 0 && _a && x < _l)
		{
			head->get(_a[x++]);
		}
		temp = head;
		head = head->getNext();
		temp->untie();
		delete(temp);
	}
	length = 0;
	selected = -1;
}

void List::reverse()
{
	if (!head)
	{
		return;
	}
	ListNode* temp = head;
	while(temp)
	{
		temp->reverse();
		temp = temp->getPrev();
	}
	temp = head;
	head = tail;
	tail = temp;
}

void List::bSort(Comparator* _comp)
{
	if (!head)
	{
		return;
	}
	int swaps = 1;
	ListNode* temp;
	while (swaps)
	{
		swaps = 0;
		temp = head;
		while (temp)
		{
			swaps += temp->bSort(_comp);
			temp = temp->getNext();
		}
	}
}

/**int List::first(void* _f);
int List::last(void* _l);

int List::copy(int _from, int _to)
{
	if (head && !adjustIndex(_from) && !adjustIndex(_to))
	{
		ListNode* from = head;
		ListNode* to = head;

		for (int x = 0; x <= _from; x++)
		{
			from = from->getNext();
		}
		for (int x = 0; x <= _to; x++)
		{
			to = to->getNext();
		}
		to->set(from->get());
	}
}
int List::swap(int _from, int _to)
{
	`
}

void List::slice(void* _array, int _count);
void List::slice(int _start, void* _array, int _count);

void List::splice(void** _in, int _inCount, void** _out, int _outCount);
void List::splice(int _start, void** _in, int _inCount, void** _out, int _outCount);*/

List::~List()
{
	clear();
}

int List::adjustIndex(int& _i)
{
	if (_i < 0)
	{
		_i = length + _i;
	}
	if (_i >= length)
	{
		return(1);
	}
	else if(_i < length*(-1))
	{
		return(-1);
	}
	return(0);
}
