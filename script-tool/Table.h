//
//  Table.h
//  script-tool
//
//  Created by Emmanuel Peralta on 06/06/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <map>
#include <vector>
#include <istream>

using namespace std;

class Table {
private:
    map<vector<int>, string> extract;
    map<string, vector<int> > insert;
public:
    
    Table();
    ~Table();
    
    void loadTableFromFile(istream stream);
    
    string getValueForBytes(vector<int> bytes);
    vector<int> getBytesForValue(string value);
};
