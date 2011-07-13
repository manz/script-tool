//
//  TextBlock.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TextBlock.h"


TextBlock::TextBlock() {
    
}

TextBlock::~TextBlock() {
    
}

string* TextBlock::dumpRange(long start, long end, TextBlockDef *def) {
    Table *table = def->getTable();
    string *retval = new string();
    
    string from = def->getFrom();
    
    ifstream *fromStream = new ifstream(from.c_str());
    
    
    long current_pos = start;
    
    char *buffer = new char[4];
    size_t bufferSize = 4;
    vector<int> vec;
    
    while (current_pos < end) {
        fromStream->seekg(current_pos);
        
        fromStream->read(buffer, bufferSize);
        
                
        bool found = false;
        string ret = "";
        size_t testsize = bufferSize;
        
        while (!found && testsize > 0) {
            
            vec.clear();
            
            for (int i=0; i<testsize; i++) {
                int tmp = (unsigned int)buffer[i] & 0xFF;
                vec.push_back(tmp);
            }

            
            
           string ret = table->getValueForBytes(vec);
            
            if (ret.size() > 0) {
                current_pos += vec.size();
                (*retval) += ret;
                found = true;
                break;
            }
            else {
                testsize--;
            }
        }
        
        if (!found) {
            ret += "<unknown value=\"";
            stringstream ss;
            
            ss << hex << (unsigned int)buffer[0];
            
            //ss << std::hex << (unsigned int)buffer[0];
            ret += ss.str();
            ret += "\"/>";
            
            (*retval) += ret;
            current_pos ++;
        }

    }
    
    //delete vec;
    
    return retval;
}

size_t TextBlock::dump(string to, TextBlockDef* def) {
    PointerTable *pointers = def->getPointers();
    //Table *table = def->getTable();
    
    ofstream dumpfile;
    dumpfile.open(to.c_str());
    
    
    dumpfile << "<dump>";
    
    int count;
    for (count=0; count<pointers->size() - 1; count++) {
        
        dumpfile << "<pointer index=\"" << count << "\">";
        const Pointer *start = pointers->at(count); // getting pointer.
        const Pointer *end = pointers->at(count + 1); //getting next pointer.
        
        //long start_addr = start->getValue();
        
        
        string *value = this->dumpRange(start->getValue(), end->getValue(), def);
        dumpfile << *value;
        dumpfile << "</pointer>";
    }
    

    
    //now we handle the last Pointer
    const Pointer *lastPointer = pointers->at(pointers->size()-1);
    
    string *value = this->dumpRange(lastPointer->getValue(), def->getEnd(), def);
    dumpfile << "<pointer index=\"" << count << "\">";
    dumpfile << *value;
    dumpfile << "</pointer>";
    dumpfile << "</dump>";
    return 0;
}

