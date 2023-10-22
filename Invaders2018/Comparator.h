#ifndef COMPARATOR_H
#define COMPARATOR_H

class Comparator
{
	public:
		virtual int lessThan(void* _lhs, void* _rhs) = 0;
		virtual int greaterThan(void* _lhs, void* _rhs) = 0;
		virtual int equals(void* _lhs, void* _rhs) = 0;
	protected:
};

#endif

