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
    
    /**
     * Getting pointer at specified index.
     */
    const Pointer* at(unsigned long index);
    
    /**
     * Adding a pointer to the table
     */
    void add(Pointer *p);
    
    /**
     * Getting the size of the pointer table
     */
    size_t size();
    
    /**
     * loads the pointer table from the stream
     * with the def passed as parameter.
     */
    void loadFromFile(ifstream* stream, PointerTableDef *def);
    
    /**
     * Write the pointer table to the stream.
     */
    void writeToFile(ofstream* stream, PointerTableDef *def);

};

#endif /* POINTERTABLE_H */
