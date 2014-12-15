/* 
 * File:   Lexer.cpp
 * Author: furan
 * 
 * Created on December 14, 2014, 8:51 PM
 */

#include "Lexer.h"



Lexer::Lexer(ContentReader contentReader){
    this->contentReader = contentReader;
    currentSymbol = this->contentReader.NextSymbol();
    
    InitDictionary();
}

Lexer::Lexer(char * input){
    ContentReader cr(input);
    contentReader = cr;
    currentSymbol = this->contentReader.NextSymbol();
    
    InitDictionary();
    
}

void Lexer::InitDictionary(){
    singleSymbolDictionary["("] = LeftParenthesis;
    singleSymbolDictionary[")"] = RightParenthesis;
    singleSymbolDictionary["&"] = And;
    singleSymbolDictionary["|"] = Or;
    singleSymbolDictionary["~"] = Not;
}

Token Lexer::NextToken(){
    string lexeme = "";
    int currentState = 0;
    Token token;
    
    string symbol;
    string lcSymbol;    
    
    while (true)
    {
        symbol = "";
        symbol += currentSymbol.symbol;
        switch (currentState)
        {
            case 0:
                if(isalpha(currentSymbol.symbol))
                {
                    lexeme += currentSymbol.symbol;
                    currentState = 1;
                    currentSymbol = contentReader.NextSymbol();
                }
                else if (currentSymbol.symbol == '\0')
                {
                    currentState = 3;
                }
                else if (isspace(currentSymbol.symbol))
                {
                    currentState = 0;
                    currentSymbol = contentReader.NextSymbol();
                }
                else if(singleSymbolDictionary[symbol])
                {
                    lexeme += currentSymbol.symbol;
                    currentState = 2;
                    currentSymbol = contentReader.NextSymbol();
                }
                else
                {
                    string msj = "Symbol " + symbol + " is not recognized";
                    throw LexicalException(msj.c_str());
                }
                break;
            case 1:
                if (isalnum(currentSymbol.symbol) || currentSymbol.symbol == '_' || currentSymbol.symbol == '-')
                {
                    lexeme += currentSymbol.symbol;
                    currentState = 1;
                    currentSymbol = contentReader.NextSymbol();
                }
                else{
                    token.lexeme = lexeme;
                    token.type = Id;
                    return token;
                }
                break;
            case 2:
                token.lexeme = lexeme;
                token.type = singleSymbolDictionary[lexeme];
                return token;
            case 3:
                token.type = EndOfFile;
                return token;
            default:
                break;
        }
    }
    
    return token;
}



