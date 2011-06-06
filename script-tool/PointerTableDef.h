//
//  PointerTableDef.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef POINTERTABLEDEF_H
#define POINTERTABLEDEF_H

#include <Block.h>

typedef long (^FormulaBlock)(long);

class PointerTableDef {
private:
    long begin;
    long count;
    int length;
    bool little_endian;
    FormulaBlock formula_callback;
public:
    PointerTableDef();
    void setFormulaCallback(long (^callback)(long));
    FormulaBlock getFormulaCallback();
   
    
    void setBegin(long begin);
    void setCount(long count);
    void setLength(int length);
    void setLittleEndian(bool little_endian);
    
    long getBegin();
    long getCount();
    long getLength();
    bool getLittleEndian();
    
    
};

#endif /* POINTERTABLEDEF_H */