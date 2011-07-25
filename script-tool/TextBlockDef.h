//
//  TextBlockDef.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 Ringum. All rights reserved.
//

#ifndef TEXTBLOCKDEF_H
#define TEXTBLOCKDEF_H

#include "Table.h"
#include "PointerTable.h"

class TextBlockDef {
private:
    long begin;
    long end;
    
    Table *table;
    PointerTable *pointers;
    string from;
    
public:
    TextBlockDef();
    
    void setBegin(long begin);
    long getBegin();
    
    void setEnd(long end);
    long getEnd();
    
    void setTable(Table *table);
    Table *getTable();
    
    void setPointers(PointerTable *pointers);
    PointerTable *getPointers();
    
    string getFrom();
    void setFrom(string &from);
};

#endif /* TEXTBLOCKDEF_H */