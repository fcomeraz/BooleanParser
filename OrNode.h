/* 
 * File:   OrNode.h
 * Author: furan
 *
 * Created on December 14, 2014, 9:30 PM
 */

#ifndef ORNODE_H
#define	ORNODE_H

#include "Node.h"


class OrNode : public Node {
public:
    OrNode(Node* izq, Node*der);
    Node* getIzqNode();
    Node* getDerNode();
    virtual NodeType getType();

private:
    Node* izq;
    Node* der;
};

#endif	/* ORNODE_H */

