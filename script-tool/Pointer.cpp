//
//  Pointer.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 Ringum. All rights reserved.
//

#include "Pointer.h"


Pointer::Pointer(int index, long value) : index(index), value(value) {
    
}

Pointer::~Pointer() {
    
}

bool Pointer::writeTo(ostream stream, long at) {
    return true;
}

long Pointer::getValue()const {
    return value;
}

void Pointer::setValue(long value) {
    this->value = value;
}

int Pointer::getIndex()const {
    return index;
}

void Pointer::setIndex(int index) {
    this->index = index;
}
