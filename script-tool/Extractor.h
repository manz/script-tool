//
//  Extractor.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "Table.h"
#include "PointerTable.h"
#include "TextBlockDef.h"
#include <istream>

using namespace std;

class Extractor {
private:
    Table *fTable;
    istream *rom;
    
public:
    Extractor(istream *rom);
    ~Extractor();
    
    long extractTextWithPointers(TextBlockDef *def, PointerTable *pointers);
    
    long extractText(TextBlockDef *def);
};

#endif /* EXTRACTOR_H */