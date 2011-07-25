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

void dump_bank1(Table *ff4) {
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
    

    
    TextBlockDef *bank1Text = new TextBlockDef();
    
    bank1Text->setPointers(bank1Ptr);
    bank1Text->setTable(ff4);
    
    bank1Text->setBegin(0x80600);
    bank1Text->setEnd(0x8F693);
    string f = "/Users/manz/FF4J2e.smc";
    bank1Text->setFrom(f);
    TextBlock *block = new TextBlock();
    block->dump("/tmp/bank1.txt", bank1Text);
}

void dump_bank2(Table *ff4) {
    long bank1 = 0x110400;
    
    // todo a scriptable block :)
    // converts raw pointer to absolute PC address.
    FormulaBlock ff4_bank1 = ^(long value) {
        long retval = value + bank1;
        return retval;  
    };
    
    PointerTableDef *bank1PtrDef = new PointerTableDef();
    bank1PtrDef->setBegin(0x110200);
    bank1PtrDef->setCount(0x100);
    bank1PtrDef->setLength(2);
    bank1PtrDef->setFormulaCallback(ff4_bank1);
    bank1PtrDef->setLittleEndian(true);
    
    PointerTable *bank1Ptr = new PointerTable();
    
    ifstream *rom = new ifstream("/Users/manz/FF4J2e.smc");
    
    bank1Ptr->loadFromFile(rom, bank1PtrDef);
    
    cout << "pointer loaded " << bank1Ptr->size() << endl;

    
    
    TextBlockDef *bank1Text = new TextBlockDef();
    
    bank1Text->setPointers(bank1Ptr);
    bank1Text->setTable(ff4);
    
    bank1Text->setBegin(0x110400);
    bank1Text->setEnd(0x115650);
    string f = "/Users/manz/FF4J2e.smc";
    bank1Text->setFrom(f);
    TextBlock *block = new TextBlock();
    block->dump("/tmp/bank2.txt", bank1Text);
}

void dump_bank3(Table *ff4) {
    long bank1 = 0x100500;
    
    // todo a scriptable block :)
    // converts raw pointer to absolute PC address.
    FormulaBlock ff4_bank1 = ^(long value) {
        long retval = value + bank1;
        return retval;  
    };
    
    PointerTableDef *bank1PtrDef = new PointerTableDef();
    bank1PtrDef->setBegin(0x100200);
    bank1PtrDef->setCount(0x150);
    bank1PtrDef->setLength(2);
    bank1PtrDef->setFormulaCallback(ff4_bank1);
    bank1PtrDef->setLittleEndian(true);
    
    PointerTable *bank1Ptr = new PointerTable();
    
    ifstream *rom = new ifstream("/Users/manz/FF4J2e.smc");
    
    bank1Ptr->loadFromFile(rom, bank1PtrDef);
    
    cout << "pointer loaded " << bank1Ptr->size() << endl;
    
   
    
    TextBlockDef *bank1Text = new TextBlockDef();
    
    bank1Text->setPointers(bank1Ptr);
    bank1Text->setTable(ff4);
    
    bank1Text->setBegin(0x100500);
    bank1Text->setEnd(0x10F033);
    string f = "/Users/manz/FF4J2e.smc";
    bank1Text->setFrom(f);
    TextBlock *block = new TextBlock();
    block->dump("/tmp/bank3.txt", bank1Text);
}

int main (int argc, const char * argv[])
{
    
    /*
     1 extbp .\roms\FF4J2E.smc .\tables\FF4t12.tbl .\txt_us\Bank1-1.txt $80600 $8F693 $80200 $200 2 X+$600 snes
     2 extbp .\roms\FF4J2E.smc .\tables\FF4t12.tbl .\txt_us\Bank1-2.txt $110400 $115650 $110200 $100 2 X+$400 snes
     3 extbp .\roms\FF4J2E.smc .\tables\FF4t12.tbl .\txt_us\Bank2.txt $100500 $10F033 $100200 $150 2 X+$500 snes
     4 extf .\roms\FF4J2E.smc .\tables\ff4f.tbl .\txt_us\monst_mag.txt $119D80 $b8 8 $00 $00
     5 extf .\roms\FF4J2E.smc .\tables\ff4f.tbl .\txt_us\magic.txt $11AFC0 $48 8 $00 $00
     6 extf .\roms\FF4J2E.smc .\tables\ff4f.tbl .\txt_us\items.txt $78200 $100 9 $00 $00

     */
    Table * ff4 = new Table();
    
    ifstream *tablefile = new ifstream("/Users/manz/Desktop/TMP CARO/Traduction/Hacking/FF4/tables/Ff4t12.tbl");
    
    if (tablefile->bad()) {
        std::cout << "Error while opening file" << std::endl;
    }
    
    ff4->loadTableFromFile(tablefile);
    tablefile->close();
    
    dump_bank1(ff4);
    dump_bank2(ff4);
    dump_bank3(ff4);
    
    TextBlock *block = new TextBlock();
    TextBlockDef *def = new TextBlockDef();
    def->setTable(ff4);
    block->insert("/tmp/bank1.txt", def);
    
    
    return 0;
}

