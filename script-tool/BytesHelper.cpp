//
//  BytesHelper.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "BytesHelper.h"

std::vector<int>* str2byt(std::string mystr) {
    std::vector<int>* retval = new std::vector<int>();
    
    
    
    if ((mystr.size() & 1) == 1) {
        mystr = "0" + mystr;
    }
    
    std::string octet;
    
    for (int i=0; i< mystr.size(); i+=2) {
        octet = mystr.substr(i, i+2);
        int value = (int)strtol(octet.c_str(), NULL, 16);
        retval->push_back(value);
    }
    
    
    //converts a byteString to an byteVector
    
    return retval;
}