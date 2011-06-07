//
//  FontDef.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef FONTDEF_H
#define FONTDEF_H

enum OutputFormat {
    _1BPP = 1,
    _2BPP = 2,
    _3BPP = 3,
    _4BPP = 4
    };

class FontDef {
    
private:
    OutputFormat outputFormat;
    boolean has_grid;
    short int height;
    short int width;
public:
    void setOutputFormat(OutputFormat outputFormat);
    void setHasGrid(bool has_grid);
    void setHeight(short int height);
    void setWidth(short int width);
};

#endif /* FONTDEF_H */
