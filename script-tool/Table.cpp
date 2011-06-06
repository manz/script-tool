//
//  Table.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Table.h"


Table::Table() {
    
}

Table::~Table() {
    
}

void Table::loadTableFromFile(istream stream) {
    
}

vector<int> Table::getBytesForValue(string value) {
    return insert.at(value);
}

string Table::getValueForBytes(vector<int> bytes) {
    return extract.at(bytes);
}