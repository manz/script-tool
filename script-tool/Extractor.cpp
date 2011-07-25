//
//  Extractor.cpp
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 Ringum. All rights reserved.
//

#include "Extractor.h"

Extractor::Extractor(istream *rom) {
    this->rom = rom;
}

Extractor::~Extractor() {
    if (rom !=- NULL)
        delete rom;
}

long Extractor::extractText(TextBlockDef *def) {
    return 0L;
}

long Extractor::extractTextWithPointers(TextBlockDef *def, PointerTable *pointers) {
    return 0L;
}