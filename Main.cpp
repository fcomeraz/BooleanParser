/* 
 * File:   main.cpp
 * Author: furan
 *
 * Created on December 14, 2014, 8:36 PM
 */

#include <iostream>

#include "Parser.h"
#include "AndNode.h"
#include "NotNode.h"
#include "IdNode.h"
#include "OrNode.h"

using namespace std;

void printNode(Node *n){
    if(n->getType() == AndNodeType){
        cout << "(";
        printNode(((AndNode*)n)->getIzqNode());
        cout << ")&(";
        printNode(((AndNode*)n)->getDerNode());
        cout << ")";
    }else if(n->getType() == OrNodeType){
        cout << "(";
        printNode(((OrNode*)n)->getIzqNode());
        cout << ")|(";
        printNode(((OrNode*)n)->getDerNode());
        cout << ")";        
    }else if(n->getType() == NotNodeType){
        cout << "~(";
        printNode(((NotNode*)n)->getNode());
        cout << ")";        
    }else if(n->getType() == IdNodeType){
        cout << ((IdNode*)n)->getId();
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    char * input = "a|d|b&c";  
    
    Parser p(input);
    Node *n = p.Parse();
    printNode(n);
    
    
    
    return 0;
}

