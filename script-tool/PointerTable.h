//
//  PointerTable.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 Ringum. All rights reserved.
//

#ifndef POINTERTABLE_H
#define POINTERTABLE_H

#include <vector>
#include <fstream>
#include "Pointer.h"
#include "PointerTableDef.h"

using namespace std;

class PointerTable {
private:
    vector<Pointer*>* pointers;
    PointerTableDef *pointerTableDef;
public:
    PointerTable();
    ~PointerTable();
    
    const Pointer* at(unsigned long index);
    
    void add(Pointer *p);
    
    size_t size();
    
    
    void loadFromFile(ifstream* stream, PointerTableDef *def);
    void writeToFile(ofstream* stream, PointerTableDef *def);

};

#endif /* POINTERTABLE_H */