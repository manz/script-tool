//
//  PointerTable.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 Ringum. All rights reserved.
//

#include "PointerTable.h"


PointerTable::PointerTable() {
    pointers = new vector<Pointer*>();
}

PointerTable::~PointerTable() {
    delete[] pointers;
}

const Pointer* PointerTable::at(unsigned long index) {
    //TODO: add boundaries check
    return pointers->at(index);
}

void PointerTable::add(Pointer *p) {
    pointers->push_back(p);
}

size_t PointerTable::size() {
    return pointers->size();
}

void PointerTable::loadFromFile(ifstream* stream, PointerTableDef *def) {
    //TODO implements loading pointers from file
    stream->seekg(def->getBegin());
    this->pointerTableDef = def;
    unsigned char *buffer = new unsigned char[def->getLength()];
    FormulaBlock callback = def->getFormulaCallback();
    
    for (int i=0; i<def->getCount(); i++) {
        
        stream->read((char*)buffer, def->getLength());
        long value = 0;
        
        if (def->getLittleEndian()) {
            for (int j=0; j<def->getLength(); j++) {
                
                value = value + (buffer[j] << (8 * j));
            }
        }
        else {
            for (int j=0; j<def->getLength(); j++) {
                value = value + (buffer[j] << (8 * (def->getLength() - j)));
            }
        }
        
        value = callback(value);
        
        Pointer *p = new Pointer(i, value);
        pointers->push_back(p);
        
    }
    
}