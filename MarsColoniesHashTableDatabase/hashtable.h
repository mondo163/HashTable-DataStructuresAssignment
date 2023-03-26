/********************************************************
* This is the hash table data structure that holds nodes
* of family data for each individiaul family
* It has a next link in case multiple families have
* the same hash. 
*********************************************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include<cstring>
#include "family.h"

class hashtable{

    private:
        struct node{
            family  data;
            node    *next;  
            node(const family &aData):data(aData), next(NULL){}    
        };
        node    **table;
        int     capacity;
        int     size;
        const int DEFAULT_CAP = 7877;

    public:
        //constructors and destructor
        hashtable();
        hashtable(const int &tempCap);
        hashtable(const hashtable &aTable);
        ~hashtable();
        
        //hashtable functions
        void insert(const char key[], const family &aData);
        void remove(const char key[]);
        void dumpTable(std::ostream &output);
        family lookup(const char key[]);
        void destroyTable();
        size_t calculateIndex(const char key[]);
        
        //assignment operator
        const hashtable& operator=(const hashtable &aTable);

};

#endif

