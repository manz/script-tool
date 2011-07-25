//
//  Pointer.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 Ringum. All rights reserved.
//
#ifndef POINTER_H
#define POINTER_H

#include <ostream>

using namespace std;

class Pointer {
private:
    long value;
    int index;
    
public:
    Pointer(int index, long value);
    ~Pointer();
    
    bool writeTo(ostream stream, long at);
    
    long getValue()const;
    void setValue(long value);
    int getIndex()const;
    void setIndex(int index);
};

#endif /* POINTER_H */