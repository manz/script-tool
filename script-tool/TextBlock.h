//
//  TextBlock.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "PointerTable.h"
#include "TextBlockDef.h"
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