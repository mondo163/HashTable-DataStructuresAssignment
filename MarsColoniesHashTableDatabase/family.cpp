#include "family.h"

//constructor without parameters
family::family(){
    id = new char[strlen("No ID")+1];
    strcpy_s(id, strlen("No ID")+1, "No ID");
    name = new char[strlen("No Name")+1];
    strcpy_s(name, strlen("No Name")+1, "No Name");
    members = 0;
    friends = new char*[MAX_FRIENDS];
    for (int i = 0; i < MAX_FRIENDS; i++){
        friends[i] = NULL;
    }
    friendSize = 0;
}

//constructor with parameters
family::family(char tempId[], char tempName[], int tempMembers){
    int idBufferSize= strlen(tempId) + 1;
    id = new char[idBufferSize];
    strcpy_s(id, idBufferSize, tempId);

    int nameBufferSize = strlen(tempName) + 1;
    name = new char[nameBufferSize];
    strcpy_s(name, nameBufferSize, tempName);

    members = tempMembers;
    friends = new char *[MAX_FRIENDS];
    for (int i = 0; i < MAX_FRIENDS; i++){
        friends[i] = NULL;
    }
    friendSize = 0;
}

//copy constructor
family::family(const family &aData){
    int idBufferSize = strlen(aData.id) + 1;
    id = new char[idBufferSize];
    strcpy_s(id, idBufferSize, aData.id);

    int nameBufferSize = strlen(aData.name) + 1;
    name = new char[nameBufferSize];
    strcpy_s(name, nameBufferSize, aData.name);

    members = aData.members;
    friendSize = aData.friendSize;
    friends = new char *[MAX_FRIENDS];
    for (int i = 0; i < MAX_FRIENDS; i++){
        friends[i] = NULL;
    }
    for (int i = 0; i < aData.friendSize; i++){
        int friendsBufferSize = strlen(aData.friends[i]) + 1;
        friends[i] = new char[friendsBufferSize];
        strcpy_s(friends[i], friendsBufferSize, aData.friends[i]);
    }
}

//destructor
family::~family(){
    if (id){
        delete [] id;
        id = NULL;
    }
    if (name){
        delete [] name;
        name = NULL;
    }
    for (int i = 0; i < friendSize; i++){   
       delete [] friends[i];
    }
    delete [] friends;
    friends = NULL;
}

//accessor functions
void family::getId(char *&returnId) const{
    if (returnId){
        delete [] returnId;
        returnId = NULL;
    }

    int returnIdBufferSize = strlen(id) + 1;
    returnId = new char[returnIdBufferSize];
    strcpy_s(returnId, returnIdBufferSize, id);
}

void family::getName(char returnName[]) const{
    int returnNameBufferSize = strlen(name) + 1;
    strcpy_s(returnName, returnNameBufferSize, name);
}

int family::getMembers() const{
    return members;
}

//sets a referenced double pointer with all the friends
void family::getFriends(char **&returnFriends) const{
    if (returnFriends){
            delete returnFriends;
            returnFriends = NULL;
    }
    returnFriends = new char*[friendSize];
    for (int i = 0; i < friendSize; i++){
        int returnFriendsBufferSize = strlen(friends[i]) + 1;
        returnFriends[i] = new char[returnFriendsBufferSize];
        strcpy_s(returnFriends[i], returnFriendsBufferSize, friends[i]);
    }
}
 
int family::getSizeFriends() const{
    return friendSize;
}   

//mutator functions
void family::setId(char newId[]){
    if (id)
    {
        delete [] id;
        id = NULL;
    } 
    int idBufferSize = strlen(newId) + 1;
    id = new char[idBufferSize];
    strcpy_s(id, idBufferSize, newId);
}

void family::setName(char newName[]){
    if (name){
        delete [] name;
        name = NULL;
    }
    int nameBufferSize = strlen(newName) + 1;
    name = new char[nameBufferSize];
    strcpy_s(name, nameBufferSize, newName);
}

void family::setMembers(int &newMembers){
    members = newMembers;
}

void family::addFriend(const char newFriend[]){
    if (friendSize != MAX_FRIENDS){
        if (newFriend[0] != '\0'){
            int friendBufferSize = strlen(newFriend) + 1;
            friends[friendSize] = new char[friendBufferSize];
            strcpy_s(friends[friendSize], friendBufferSize, newFriend);
            friendSize++; 
        }
    } 
}

//assignment operator
const family& family::operator= (const family &aData){
    if(this == &aData)
        return *this;   
    else{
        this->members = aData.members;
        this->setId(aData.id);
        this->setName(aData.name);
        for (int i = 0; i < this->friendSize; i++){
            delete [] this->friends[i];
            this->friends[i] = NULL;
        }
        this->friendSize = aData.friendSize;
        for (int i = 0; i < aData.friendSize; i++){
            int friendsBufferSize = strlen(aData.friends[i]) + 1;
            this->friends[i] = new char[friendsBufferSize];
            strcpy_s(this->friends[i], friendsBufferSize, aData.friends[i]);
        }
        return *this;
    }
}

//family output operator
std::ostream& operator<<(std::ostream &out, family &aData){
    out << "Family Id: "<< aData.id << std::endl
        << "  Name: " << aData.name << std::endl
        << "  Members: " << aData.members << std::endl
        << "  Friends: ";
    for (int i = 0; i < aData.friendSize; i++){
        out << aData.friends[i] << " ";
    }
    out << std::endl;
    return out;
}
