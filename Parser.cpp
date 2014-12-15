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
    if(currentToken.type == And){
        currentToken = lexer->NextToken();
        Node *der = Sp();
        return new AndNode(izq, der);
    }else if(currentToken.type == Or){
        currentToken = lexer->NextToken();
        Node *der = Sp();
        return new OrNode(izq, der);
    }else{
        return izq;
    }
}

Node* Parser::T(){
    if(currentToken.type == Id){
        string id = currentToken.lexeme;
        currentToken = lexer->NextToken();
        return new IdNode(id);
    }else if(currentToken.type == Not){
        currentToken = lexer->NextToken();
        Node *n = T();
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
}


