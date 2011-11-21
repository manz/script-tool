//
//  PointerTableDef.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 Ringum. All rights reserved.
//

#include "PointerTableDef.h"

PointerTableDef::PointerTableDef() : formula_callback(NULL) {
    
}

void PointerTableDef::setFormulaCallback(long (^callback)(long)) {
    formula_callback = Block_copy(callback);
}

FormulaBlock PointerTableDef::getFormulaCallback() {
    return formula_callback;
}

void PointerTableDef::setBegin(long begin) {
    this->begin = begin;
}

long PointerTableDef::getBegin() {
    return this->begin;
}

void PointerTableDef::setCount(long count) {
    this->count = count;
}

long PointerTableDef::getCount() {
    return this->count;
}

void PointerTableDef::setLength(int length) {
    this->length = length;
}

long PointerTableDef::getLength() {
    return this->length;
}

void PointerTableDef::setLittleEndian(bool little_endian) {
    this->little_endian = little_endian;
}

bool PointerTableDef::getLittleEndian() {
    return this->little_endian;
}
