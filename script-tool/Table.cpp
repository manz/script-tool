//
//  Table.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 Ringum. All rights reserved.
//

#include "Table.h"


Table::Table() {
    
}

Table::~Table() {
    
}

size_t Table::loadTableFromFile(ifstream *stream) {
    /*
    if (!stream->is_open()) {
        std::cout << "file isn't opened" << std:: endl;
        abort();
    }
*/
    
    std::string line;
    std::string bytes;
    std::string values;
    
    int count = 0;
    while (!stream->eof()) {
        
        std::getline(*stream, line);

        size_t len = line.size();
        
        if (len > 0) {
            
            if ((line.at(len-1) == '\n' && line.at(len-2) == '\r') || (line.at(len-2) == '\n' && line.at(len-1) == '\r')){
                line = line.substr(0, len-2);
            }
            
            if (line.at(len-1) == '\n' ||line.at(len-1) == '\r') {
                line = line.substr(0, len-1);
            }
            
            size_t pos = line.find("=");
            
            bytes = line.substr(0, pos);
            
            values = line.substr(pos+1, line.size()-pos-1);
            
            string tmp = "";
            int k = 0;
            for (int j=0; j<values.size(); j++) {
                if (values[j] == '\\') {
                    if (values[j+1] == 'n') {
                        tmp += '\n';
                        k++;
                        j++;
                    }
                }
                else { tmp+= values[j];}
                
            }
            
            values = tmp;
            
            vector<int>* vec = str2byt(bytes);
            
            this->slen = max(this->slen, values.size());
            this->blen = max(this->blen, vec->size());
            
            extract.insert(pair<vector<int>, string>(*vec, values));
            insert.insert(pair<string, vector<int> >(values, *vec));
            
            //FIXME: is this thing still needed as we don't print anything to the stdout here ?
            std::flush(cout);
        }
        count++;
    }
        
    return count;
}

vector<int> Table::getBytesForValue(string value) {
    map<string, vector<int> >::iterator it = insert.find(value);
    
    if (it == insert.end()) {
        return vector<int>();
    }
    
    return it->second;
}

string Table::getValueForBytes(vector<int> bytes) {
    map<vector<int>, string>::iterator it = extract.find(bytes);
    if (it == extract.end()) {
        return string();
    }
    
    return it->second;
}

size_t Table::getValueMaxLength() const {
    return this->slen;
}

size_t Table::getKeyMaxLength() const {
    return this->blen;
}
