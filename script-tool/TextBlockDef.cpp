//
//  TextBlockDef.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TextBlockDef.h"

TextBlockDef::TextBlockDef() {
    
}

void TextBlockDef::setBegin(long begin) {
    this->begin = begin;
}

long TextBlockDef::getBegin() {
    return this->begin;
}

void TextBlockDef::setEnd(long end) {
    this->end = end;
}

long TextBlockDef::getEnd() {
    return this->end;
}

void TextBlockDef::setTable(Table *table) {
    this->table = table;
}

Table* TextBlockDef::getTable() {
    return this->table;
}

void TextBlockDef::setPointers(PointerTable *pointers) {
    this->pointers = pointers;
}

PointerTable* TextBlockDef::getPointers() {
    return this->pointers;
}

void TextBlockDef::setFrom(string &from) {
    this->from = from;
}

string TextBlockDef::getFrom() {
    return this->from;
}

