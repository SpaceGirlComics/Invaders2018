#include "ListNode.h"

/**
*	Default Constructor
*	Creates an empty, unattached node
**/
ListNode::ListNode()
{
	state = 0x00000000;
	value = (void*)0;
	next = prev = (ListNode*)0;
}

/**
*	Initial Ctor
*	Creates an unattached node paointing to the same address as _i
*
*	@param _i A pointer to the value this node will contain
**/
ListNode::ListNode(void* _i)
{
	state = 0x00000001;
	value = _i;
	next = prev = (ListNode*)0;
}

/**
*	Copy Ctor
*	Creates a copy of the referenced node. The node
*	will be attached top the original nodes sequence
*	but, the sequence will not be attached to it
*
*	@param _c reference to the node being copied
**/
ListNode::ListNode(const ListNode& _c)
{
	state = _c.state;
	next = _c.next;
	prev = _c.prev;
	if (state)
	{
		value = _c.value;
	}
}

/**
*	Assignment Operator
*	Assignes the value from _rhs to this node
*
*	@param _rhs reference to another node, it can be from the same 
*		sequence or a different one
*	@returns Reference to this node
**/
ListNode& ListNode::operator = (const ListNode& _rhs)
{
	if (_rhs.state & 0x00000001)
	{
		value = _rhs.value;
		state |= 0x00000001;
	}
	return(*this);
}

/**
*	Equality Comparison
*	compares the pointer in this node to the one referenced by _rhs
*
*	@param _rhs reference to another node
*	@returns boolean true if both nodes are pointing to
*		the same address; otherwise false.
**/
bool ListNode::operator == (const ListNode& _rhs)
{
	if (value == _rhs.value)
	{
		return(true);
	}
	return(false);
}

/**
*	Unsafe Accessor Function
*	Returns the contained pointer
*
*	@returns A void pointer, if the contents have not been 
*		set this will be NULL
**/
void* ListNode::get()
{
	return(value);
}

/**
*	Template Accessor Function
*	Sets the value of _v to the value being pointed to cast
*	as the provided datatype
*
*	@param _v pointer to where the value is going
*	@returns 1 if the value pointed to by _v changes; otherwise 0
**/
template<typename T> int ListNode::get(T* _v)
{
	if (state)
	{
		_v* = ((T*)value)*;
		return(1);
	}
	return(0);
}

/**
*	Safe Accesor Function
*	
**/
int ListNode::get(void* _v)
{
	if (state && _v)
	{
		_v = value;
		return(1);
	}
	return(0);
}

int ListNode::get(char* _v)
{
	if (state)
	{
		*_v = *((char*)value);
		return(1);
	}
	return(0);
}

int ListNode::get(int* _v)
{
	if (state)
	{
		*_v = *((int*)value);
		return(1);
	}
	return(0);
}

int ListNode::get(long int* _v)
{
	if (state)
	{
		*_v = *((long int*)value);
		return(1);
	}
	return(0);
}

int ListNode::get(float* _v)
{
	if (state)
	{
		*_v = *((float*)value);
		return(1);
	}
	return(0);
}

int ListNode::get(double* _v)
{
	if (state)
	{
		*_v = *((double*)value);
		return(1);
	}
	return(0);
}

int ListNode::set(void* _s)
{
	state |= 0x00000001;
	value = _s;
	return(1);
}

ListNode* ListNode::getNext()
{
	return(next);
}

ListNode* ListNode::getPrev()
{
	return(prev);
}

int ListNode::insertNext(ListNode* _l)
{
	if (next)
	{
		_l->next = next;
		next->prev = _l;
	}
	_l->prev = this;
	next = _l;
	return(1);
}

int ListNode::insertNext(void* _i)
{
	return(insertNext(new ListNode(_i)));
}

int ListNode::insertPrev(ListNode* _l)
{
	if (prev)
	{
		_l->prev = prev;
		prev->next = _l;
	}
	_l->next = this;
	prev = _l;
	return(1);
}

int ListNode::insertPrev(void* _i)
{
	return(insertPrev(new ListNode(_i)));
}

int ListNode::untie()
{
	int x = 0;
	if (next)
	{
		if (prev)
		{
			next->prev = prev;
			prev->next = next;
			x = 3;
		}
		else
		{
			next->prev = (ListNode*)0;
			x = 2;
		}
	}
	else if (prev)
	{
		prev->next = (ListNode*)0;
		x = 1;
	}
	next = prev = (ListNode*)0;
	return(0);
}

int ListNode::trade(ListNode* _ln)
{
	if (_ln)
	{
		void* temp = _ln->value;
		_ln->value = value;
		value = temp;
		return(1);
	}
	return(0);
}

int ListNode::swap()
{
	return(trade(next));
}

int ListNode::physicalSwap()
{
	if (next)
	{
		ListNode* temp = next;
		temp->untie();
		insertPrev(temp);
		return(1);
	}

	return(0);
}

int ListNode::bSort(Comparator* _comp)
{
	if (next && (!next->isSet() || _comp->lessThan(value, next->value)))
	{
		return(swap());
	}
	return(0);
}

int ListNode::reverse()
{
	ListNode* temp = next;
	next = prev;
	prev = temp;
	return(0);
}

int ListNode::isSet()
{
	if (value)
	{
		return(1);
	}
	return(0);
}

ListNode::~ListNode()
{

}
