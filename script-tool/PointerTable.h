//
//  PointerTable.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#include <vector>
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
    
    Pointer* at(int index);
    
    void loadFromFile(istream* stream, PointerTableDef *def);

};