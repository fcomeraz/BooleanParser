/* 
 * File:   NotNode.cpp
 * Author: furan
 * 
 * Created on December 14, 2014, 9:30 PM
 */

#include "NotNode.h"

NotNode::NotNode(Node* node) {
    this->node = node;
}

Node* NotNode::getNode() {
    return node;
}



NodeType NotNode::getType() {
    return NotNodeType;
}
