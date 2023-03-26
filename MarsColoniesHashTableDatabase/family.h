/**************************************************
* This class represents the family object that 
* containes the family id along with the rest of
* the information relating to the individual family. 
***************************************************/
#ifndef FAMILY_H
#define FAMILY_H

#include<iostream>
#include<cstring>

class family{
   
    //outputs family data 
    friend std::ostream& operator<<(std::ostream &out, family &aData);
 
    private:
        char    *id;
        char    *name;
        int     members;
        char    **friends;
        int     friendSize;
        const int MAX_FRIENDS = 3;

    public:
        //constructors and destructors
        family();
        family(char tempId[], char tempName[], int tempMembers);
        family(const family &aData);
        ~family();
        
        //accessor functions
        void getId(char *&returnId) const;
        void getName(char returnName[]) const;
        int getMembers() const;
        void getFriends(char **&returnFriends) const;
        int getSizeFriends() const;    

        //mutator functions
        void setId(char newId[]);
        void setName(char newName[]);
        void setMembers(int &newMembers);
        void addFriend(const char newFriend[]); 
  
        //assignment operator
        const family& operator= (const family &aData);
};

#endif
