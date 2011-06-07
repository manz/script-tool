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
    
    /*
     1 extbp .\roms\FF4J2E.smc .\tables\FF4t12.tbl .\txt_us\Bank1-1.txt $80600 $8F693 $80200 $200 2 X+$600 snes
     2 extbp .\roms\FF4J2E.smc .\tables\FF4t12.tbl .\txt_us\Bank1-2.txt $110400 $115650 $110200 $100 2 X+$400 snes
     3 extbp .\roms\FF4J2E.smc .\tables\FF4t12.tbl .\txt_us\Bank2.txt $100500 $10F033 $100200 $150 2 X+$500 snes
     4 extf .\roms\FF4J2E.smc .\tables\ff4f.tbl .\txt_us\monst_mag.txt $119D80 $b8 8 $00 $00
     5 extf .\roms\FF4J2E.smc .\tables\ff4f.tbl .\txt_us\magic.txt $11AFC0 $48 8 $00 $00
     6 extf .\roms\FF4J2E.smc .\tables\ff4f.tbl .\txt_us\items.txt $78200 $100 9 $00 $00

     */
    
    long bank1 = 0x80600;
    
    // todo a scriptable block :)
    // converts raw pointer to absolute PC address.
    FormulaBlock ff4_bank1 = ^(long value) {
        long retval = value + bank1;
        return retval;  
    };
    
    PointerTableDef *bank1PtrDef = new PointerTableDef();
    bank1PtrDef->setBegin(0x080200);
    bank1PtrDef->setCount(0x200);
    bank1PtrDef->setLength(2);
    bank1PtrDef->setFormulaCallback(ff4_bank1);
    bank1PtrDef->setLittleEndian(true);
    
    PointerTable *bank1Ptr = new PointerTable();
    
    ifstream *rom = new ifstream("/Users/manz/FF4J2e.smc");
    
    bank1Ptr->loadFromFile(rom, bank1PtrDef);
    
    cout << "pointer loaded " << bank1Ptr->size() << endl;
    
    for (int i=0; i<bank1Ptr->size(); i++) {
        cout << dec << bank1Ptr->at(i)->getIndex() << ":" << hex << bank1Ptr->at(i)->getValue() << endl;
    }
    
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

