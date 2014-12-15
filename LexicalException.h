/* 
 * File:   LexicalException.h
 * Author: furan
 *
 * Created on December 14, 2014, 8:53 PM
 */

#ifndef LEXICALEXCEPTION_H
#define	LEXICALEXCEPTION_H

#include <exception>

using namespace std;

class LexicalException: public exception{
private:
    const char* msg;
public:
    LexicalException(const char* msg);
    virtual const char* what() const throw();
};

#endif	/* LEXICALEXCEPTION_H */

