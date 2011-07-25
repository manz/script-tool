//
//  TextBlock.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 Ringum. All rights reserved.
//

#ifndef TEXTBLOCK_H
#define TEXTBLOCK_H

#include "PointerTable.h"
#include "TextBlockDef.h"

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_6
#include <dispatch/dispatch.h>
#endif

#include <libxml/parser.h>

#include <string>
#include <sstream>

#include <cstdlib>

using namespace std;

class TextBlock {
  
public:
    TextBlock();
    ~TextBlock();
    
    size_t dump(string to, TextBlockDef* def);
    size_t insert(string dump, TextBlockDef*def); 
    string* dumpRange(long start, long end, TextBlockDef *def);
    unsigned char *insertRange(string s, TextBlockDef *def);
};

#endif /* TEXTBLOCK_H */