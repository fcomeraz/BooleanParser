/* 
 * File:   SyntacticException.h
 * Author: furan
 *
 * Created on December 14, 2014, 10:52 PM
 */

#ifndef SYNTACTICEXCEPTION_H
#define	SYNTACTICEXCEPTION_H

#include <exception>

using namespace std;

class SyntacticException: public exception{
private:
    const char* msg;
public:
    SyntacticException(const char* msg);
    virtual const char* what() const throw();
};

#endif	/* SYNTACTICEXCEPTION_H */

