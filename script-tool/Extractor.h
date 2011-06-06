//
//  Extractor.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Table.h"
#include "PointerTable.h"
#include "TextBlockDef.h"

class Extractor {
private:
    Table *fTable;
public:
    
    Extractor();
    
    long extractWithTextBlockDef(TextBlockDef *def);
};