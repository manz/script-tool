//
//  TextBlock.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 Ringum. All rights reserved.
//

#include "TextBlock.h"


TextBlock::TextBlock() {
    
}

TextBlock::~TextBlock() {
    
}

PointerTable* TextBlock::insert(string dump, TextBlockDef *def) {
    PointerTable *pointerTable = new PointerTable();
    
    xmlDocPtr doc;
    doc = xmlParseFile(dump.c_str());
    
    xmlNodePtr root = xmlDocGetRootElement(doc);
    
    xmlNodePtr pointers = root->children;
    
    xmlChar *count_str = xmlGetProp(root, (xmlChar*)"count");
    
    int count = std::atoi((const char*)count_str);
    
    xmlNodePtr n;
    for (n = pointers; n; n = n->next) {
        if (n->type == XML_ELEMENT_NODE) {
            xmlChar* index = xmlGetProp(n, (xmlChar*)"index");
            string s((const char*)xmlNodeGetContent(n));
            cout << "[" << index << "]" << "\"" << xmlNodeGetContent(n) << "\"" << endl;
        }
    } 
    
    if (doc == NULL) {
        // issue an error
    }
    
    if (count != pointerTable->size()) {
        cout << "Pointers count differs from elements count in the script file" << endl; 
    }
    
    xmlFreeDoc(doc);
    
    return 0;
}

unsigned char *TextBlock::insertRange(string s, TextBlockDef *def) {
    
    unsigned char *buffer = new unsigned char[s.size()*2];
    int i = 0;
    int k = 0;
    while (i < s.size()) {
        size_t maxsize = def->getTable()->getValueMaxLength();
        bool found = false;
        string val = "";
        for (size_t j=maxsize; j != 0; j--) {
            val = s.substr(0, j);
            vector<int> vec = def->getTable()->getBytesForValue(val);
            
            if (vec.size() > 0) {
                found = true;
                for (int l=0; l<vec.size(); l++) {
                    buffer[k+l] = (unsigned char)vec.at(l);
                }
                k += vec.size();
                i += val.size();
            }
            
        }
        if (!found) {
            // issue warning and skip one char
            
            cout << "(WW) can't find '" << s.at(i) << "' in the table skipping..." << endl;
            i++;
        }
        
        
    }
    return buffer;
}

string* TextBlock::dumpRange(long start, long end, TextBlockDef *def) {
    Table *table = def->getTable();
    string *retval = new string();
    
    string from = def->getFrom();
    
    ifstream *fromStream = new ifstream(from.c_str());
    
    
    long current_pos = start;
    
    char *buffer = new char[table->getKeyMaxLength()];
    size_t bufferSize = table->getKeyMaxLength();
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
            ret += "[0x";
            stringstream ss;
            
            ss << hex << (unsigned int)buffer[0];
            
            //ss << std::hex << (unsigned int)buffer[0];
            ret += ss.str();
            ret += "]";
            
            (*retval) += ret;
            current_pos ++;
        }

    }
    fromStream->close();
    //delete vec;
    
    return retval;
}

size_t TextBlock::dump(string to, TextBlockDef* def) {
    PointerTable *pointers = def->getPointers();
    //Table *table = def->getTable();
    
    ofstream dumpfile;
    dumpfile.open(to.c_str());
    
    
#ifdef __DISPATCH_PUBLIC__
    string **dumped_ranges= new string*[pointers->size()];
    
    dispatch_apply(pointers->size() - 1, dispatch_get_global_queue(0, 0), ^(size_t count) {
        const Pointer *start = pointers->at(count); // getting pointer.
        const Pointer *end = pointers->at(count + 1); //getting next pointer.
        
        //long start_addr = start->getValue();
        
        
        dumped_ranges[count] = this->dumpRange(start->getValue(), end->getValue(), def); 
    });
    
    dumpfile << "<dump count=\""<< pointers->size() <<"\">" << endl;
    for (int i=0; i<pointers->size()-1; i++) {
        dumpfile << "<pointer index=\"" << i << "\">";
        dumpfile << "<![CDATA[";
        dumpfile << *dumped_ranges[i];
        dumpfile << "]]>";
        dumpfile << "</pointer>" << endl;
    }
#else   
   
    int count;
    for (count=0; count<pointers->size() - 1; count++) {
        
        dumpfile << "<dump count=\""<< pointers->size() <<"\">" << endl;
        const Pointer *start = pointers->at(count); // getting pointer.
        const Pointer *end = pointers->at(count + 1); //getting next pointer.
        
        //long start_addr = start->getValue();
        
        
        string *value = this->dumpRange(start->getValue(), end->getValue(), def);
        dumpfile << *value;
        dumpfile << "</pointer>" << endl;
    }
#endif

    
    //now we handle the last Pointer
    const Pointer *lastPointer = pointers->at(pointers->size()-1);
    
    string *value = this->dumpRange(lastPointer->getValue(), def->getEnd(), def);
    dumpfile << "<pointer index=\"" << pointers->size() << "\">";
    dumpfile << "<![CDATA[";
    dumpfile << *value;
    dumpfile << "]]>";
    dumpfile << "</pointer>" << endl;
    dumpfile << "</dump>" << endl;
    return 0;
}

