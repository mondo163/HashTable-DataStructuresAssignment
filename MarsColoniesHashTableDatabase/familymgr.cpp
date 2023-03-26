#include "familymgr.h"

familymgr::familymgr(){
    table = new hashtable;
}

familymgr::~familymgr(){
    delete table;
}

//Adds to hashtable
void familymgr::addFamily(const family &aData){
       char     *id = NULL;
       
        aData.getId(id);
        table->insert(id, aData);
        
        delete [] id;
}

//prints hashtable
void familymgr::printAllFamiliesToConsole(){
    table->dumpTable(std::cout);
}

//prints hashtable
void familymgr::printAllFamiliesToFile() {
    std::ofstream fout("./results.txt");
    table->dumpTable(fout);
    fout.close();
}

//prints small circle of friends
void familymgr::printSmallCircle(const char tempId[]){
    family  fam = table->lookup(tempId);
    int     size = fam.getSizeFriends();
    char    **friends = NULL;    
    

    std::cout << "Printing family and immediate friends " << tempId << std::endl
         << "== Family == " << std::endl
         << fam << std::endl;
    
    std::cout << "== Friends (1 level) ==" << std::endl;
    fam.getFriends(friends);
    for (int i = 0; i < size; i++){
        family fPrint = table->lookup(friends[i]);
        std::cout << fPrint;    
    }  

    for (int i = 0; i < size; i++){
        delete [] friends[i];
    }
    delete [] friends;
}
