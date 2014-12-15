/* 
 * File:   AndNode.h
 * Author: furan
 *
 * Created on December 14, 2014, 9:30 PM
 */

#ifndef ANDNODE_H
#define	ANDNODE_H

#include "Node.h"


class AndNode : public Node {
public:
    AndNode(Node* izq, Node*der);
    Node* getIzqNode();
    Node* getDerNode();
    virtual NodeType getType();

private:
    Node *izq;
    Node *der;
};

#endif	/* ANDNODE_H */

