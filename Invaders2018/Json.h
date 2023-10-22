#ifndef JSON_H
#define JSON_H

#include"List.h"

class Json
{
	public:
		int parse(char* _str);
		int read(char* _fileName);
		int getType(char* _var);
		int clear();
	protected:
		List objs;
};


#endif
