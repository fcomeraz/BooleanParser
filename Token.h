/* 
 * File:   Token.h
 * Author: furan
 *
 * Created on December 14, 2014, 8:44 PM
 */

#ifndef TOKEN_H
#define	TOKEN_H

#include <string>

using namespace std;

enum TokenType{
    Not=1,
    Or,
    And,    
    LeftParenthesis,
    RightParenthesis,
    Id,
    EndOfFile
};

class Token {
public:
    
    string lexeme;
    TokenType type;
    Token();
    Token(const Token& orig);
    virtual ~Token();
private:

};

#endif	/* TOKEN_H */

