//
//  Table.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 Ringum. All rights reserved.
//
#ifndef TABLE_H
#define TABLE_H

#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "BytesHelper.h"

using namespace std;

typedef std::pair<std::string, std::vector<int>* > InsertTableElement;
typedef std::pair<std::vector<int>, std::string> ExtractTableElement;

class Table {
private:
    map<vector<int>, string> extract;
    map<string, vector<int> > insert;
    size_t slen;
    size_t blen;
    
public:
    
    Table();
    ~Table();
    
    size_t loadTableFromFile(ifstream *stream);
    
    string getValueForBytes(vector<int> bytes);
    vector<int> getBytesForValue(string value);
    
    size_t getValueMaxLength()const;
    size_t getKeyMaxLength()const;
    
};
#endif /* TABLE_H */