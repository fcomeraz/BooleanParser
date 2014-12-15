/* 
 * File:   LexicalException.cpp
 * Author: furan
 * 
 * Created on December 14, 2014, 8:53 PM
 */

#include "LexicalException.h"

LexicalException::LexicalException(const char* msg){
    this->msg = msg;
}

const char * LexicalException::what() const throw(){
    return msg;
}

