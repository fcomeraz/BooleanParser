/* 
 * File:   ContentReader.cpp
 * Author: furan
 * 
 * Created on December 14, 2014, 8:52 PM
 */

#include "ContentReader.h"

ContentReader::ContentReader(){
    currentLine = 1;
    currentColumn = 1;
    currentPosition = 0;
}

ContentReader::ContentReader(char * content){
    currentLine = 1;
    currentColumn = 1;
    currentPosition = 0;
    this->content = content;
}

void ContentReader::setContent(char *content){
    this->content = content;
}

Symbol ContentReader::NextSymbol(){
    Symbol ret;
    if (content[currentPosition]) {
        char c = content[currentPosition++];
        if (c == 10) {
            currentColumn++;
            currentLine = 1;
            if (content[currentPosition] == 13) {
                currentPosition++;
            }
        } else if (c == 13){
            currentColumn++;
            currentLine = 1;
            if (content[currentPosition] == 10) {
                currentPosition++;
            }
        } else {
            currentColumn++;
        }
        ret.symbol = c;
        
    }else{
        ret.symbol = 0;
    }
    ret.line = currentLine;
    ret.column = currentColumn;
    return ret;
}

