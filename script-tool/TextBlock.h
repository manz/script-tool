//
//  TextBlock.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TEXTBLOCK_H
#define TEXTBLOCK_H

#include "PointerTable.h"
#include "TextBlockDef.h"

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_6
#include <dispatch/dispatch.h>
#endif

#include <string>
#include <sstream>

using namespace std;

class TextBlock {
  
public:
    TextBlock();
    ~TextBlock();
    
    size_t dump(string to, TextBlockDef* def);
    
    string* dumpRange(long start, long end, TextBlockDef *def);
};

#endif /* TEXTBLOCK_H */