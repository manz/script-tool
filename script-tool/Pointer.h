//
//  Pointer.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

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
    
    long getValue();
    void setValue(long value);
    int getIndex();
    void setIndex(int index);
};

