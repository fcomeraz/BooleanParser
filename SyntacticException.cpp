/* 
 * File:   SyntacticException.cpp
 * Author: furan
 * 
 * Created on December 14, 2014, 10:52 PM
 */

#include "SyntacticException.h"

SyntacticException::SyntacticException(const char* msg){
    this->msg = msg;
}

const char * SyntacticException::what() const throw(){
    return msg;
}
