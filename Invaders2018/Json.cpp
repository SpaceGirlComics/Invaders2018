#include "Json.h"

int Json::parse(char* _str)
{
	int y = 0;
	int x = 0;

	switch (_str[x])
	{
		case '{':					// Object
		{
			break;
		}

		case '\"':					// String
		{
			break;
		}

		case '[':					// Array
		{
			break;
		}

		case 't':
		case 'f':					// Boolean
		{
			break;
		}

		case 'n':
		{
			break;
		}

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '.':
		{
			break;
		}

		case '\0':					// done
		{
			break;
		}
	}
	return(y);
}

