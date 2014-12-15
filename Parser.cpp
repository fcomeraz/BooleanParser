/* 
 * File:   parser.cpp
 * Author: furan
 * 
 * Created on December 14, 2014, 9:40 PM
 */

#include "Parser.h"
#include "AndNode.h"
#include "IdNode.h"
#include "NotNode.h"
#include "SyntacticException.h"
#include "OrNode.h"

Parser::Parser(char* input) {
    lexer = new Lexer(input);
}

Parser::~Parser(){
    delete lexer;
}

Node* Parser::Parse(){
    currentToken = lexer->NextToken();
    Node* ret = S();
    if(currentToken.type != EndOfFile){
        string msj = "expected EOF, found " + currentToken.lexeme;
        throw SyntacticException(msj.c_str());
    }
    return ret;
}

Node* Parser::S(){
    if(currentToken.type != EndOfFile){
        return Sp();
    }else{
        return NULL;
    }
}

Node* Parser::Sp(){
    Node *izq = T();
    if(currentToken.type == Or){
        currentToken = lexer->NextToken();
        Node *der = Sp();
        return new OrNode(izq, der);
    }else{
        return izq;
    }
}

Node* Parser::T() {
    Node *izq = U();
    if(currentToken.type == And){
        currentToken = lexer->NextToken();
        Node *der = Sp();
        return new AndNode(izq, der);
    }else {
        return izq;
    }
}


Node* Parser::U(){
    if(currentToken.type == Id){
        string id = currentToken.lexeme;
        currentToken = lexer->NextToken();
        return new IdNode(id);
    }else if(currentToken.type == Not){
        currentToken = lexer->NextToken();
        Node *n = U();
        return new NotNode(n);
    }else if(currentToken.type == LeftParenthesis){
        currentToken = lexer->NextToken();
        Node *n = Sp();
        if(currentToken.type == RightParenthesis){
            currentToken = lexer->NextToken();
            return n;
        }else{
            string msj = "a ) was expected";
            throw SyntacticException(msj.c_str());
        }
    }
    string msj = "'" + currentToken.lexeme + "' not expected";
    throw SyntacticException(msj.c_str());
}


