#include "common.h"

const char* stringToChar(std::string res){
	char *cptr = new char[res.size()+1]; // +1 to account for \0 byte
	std::strncpy(cptr, res.c_str(), res.size());
	cptr[res.size()] = '\0';
	return cptr;
}