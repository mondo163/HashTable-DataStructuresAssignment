#ifndef FAMILYMGR_H
#define FAMILYMGR_H

#include "hashtable.h"
#include<iostream>
#include<fstream>

class familymgr{

    private:
        hashtable   *table;
        
    public:
        //constructor and destructor
        familymgr();
        ~familymgr();
        
        //family manager functions
        void addFamily(const family &aData);
        void printAllFamiliesToConsole();
        void printAllFamiliesToFile();
        void printSmallCircle(const char tempId[]);
};

#endif
