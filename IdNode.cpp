/* 
 * File:   IdNode.cpp
 * Author: furan
 * 
 * Created on December 14, 2014, 9:31 PM
 */

#include "IdNode.h"

IdNode::IdNode(string id) {
    this->id = id;
}

string IdNode::getId(){
    return id;
}


NodeType IdNode::getType() {
    return IdNodeType;
}

