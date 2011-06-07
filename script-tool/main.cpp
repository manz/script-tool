//
//  main.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "libscript.h"
#include <fstream>
int main (int argc, const char * argv[])
{
    PointerTableDef *def = new PointerTableDef();
    def->setBegin(0x108D00);
    def->setCount(0x336);
    def->setLength(3);
    
    def->setFormulaCallback( ^(long value) {
		long ret = value*10;
		return ret;
	});
    
    
    Table * ff4 = new Table();
    
    ifstream *tablefile = new ifstream("/Users/manz/Desktop/TMP CARO/Traduction/Hacking/FF4/tables/FF4vwf.tbl");
    
    if (tablefile->bad()) {
        std::cout << "Error while opening file" << std::endl;
    }
    
    ff4->loadTableFromFile(tablefile);
    
    vector<int> vec = vector<int>();
    
    vec.push_back(0x00);
    
    vector<int> bytesForA = ff4->getBytesForValue("<FIN>\\n");
    
    string stringFor4A = ff4->getValueForBytes(vec);
    
    cout << stringFor4A.size() << endl;
    for (int i=0; i<bytesForA.size(); i++) {
        cout << "0x" << hex << bytesForA.at(i) << endl;
    }
    
    cout << stringFor4A << endl;
    
    FormulaBlock callback = def->getFormulaCallback();
    
    std::cout << "calling callback(3) should return 30 :(" << dec << callback(3) << ")" << std::endl;
    
    // insert code here...
    
    return 0;
}

