/* 
 * File:   parser.h
 * Author: furan
 *
 * Created on December 14, 2014, 9:40 PM
 */

#ifndef PARSER_H
#define	PARSER_H

#include "ContentReader.h"
#include "Lexer.h"
#include "Node.h"


class Parser {
public:
    Parser(char *input);
    ~Parser();
    Node* Parse();
private:
    Lexer* lexer;
    Token currentToken;
    
    Node* S();
    Node* Sp();
    Node* T();
};

#endif	/* PARSER_H */

