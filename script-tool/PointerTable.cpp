//
//  PointerTable.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "PointerTable.h"


PointerTable::PointerTable() {
    
}

PointerTable::~PointerTable() {
}

Pointer* PointerTable::at(int index) {
    //TODO: add boundaries check
    return pointers->at(index);
}

void PointerTable::loadFromFile(istream* stream, PointerTableDef *def) {
    //TODO implements loading pointers from file
    
    this->pointerTableDef = def;
    
    for (int i=0; i<def->getCount(); i++) {
        
    }
    
}