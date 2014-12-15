/* 
 * File:   IdNode.h
 * Author: furan
 *
 * Created on December 14, 2014, 9:31 PM
 */

#ifndef IDNODE_H
#define	IDNODE_H

#include <string>

#include "Node.h"

using namespace std;


class IdNode : public Node {
public:
    IdNode(string id);
    virtual NodeType getType();
    string getId();
private:
    string id;

};

#endif	/* IDNODE_H */

