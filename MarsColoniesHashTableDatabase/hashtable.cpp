#include "hashtable.h"

//constructor
hashtable::hashtable(){
    capacity = DEFAULT_CAP;
    table = new node*[DEFAULT_CAP];
    for (int i = 0; i < DEFAULT_CAP; i++){
        table[i] = NULL;
    }
    size = 0;
}

//constructor new capacity
hashtable::hashtable(const int &tempCap){
    table = new node*[tempCap];
    for (int i = 0; i < tempCap; i++){
        table[i] = NULL;
    }
    capacity = tempCap;
    size = 0;
}    

//copy constructor
hashtable::hashtable(const hashtable &aTable){
    capacity = aTable.capacity; 
    size = aTable.capacity;
    table = new node*[aTable.capacity];
    for (int i = 0; i < aTable.capacity; i++){
        if (aTable.table[i] == NULL)
            table[i] = NULL;
        else{
            table[i] = new node(aTable.table[i]->data);

            node    *src = aTable.table[i]->next;
            node    *dest = table[i];
        
            while(src){
                dest->next = new node(src->data);
                dest = dest->next;
                src = src->next;
            }    
            dest->next = NULL;
        }
    }
}

//destructor
hashtable::~hashtable(){
    destroyTable();
}

//insert data
void hashtable::insert(const char key[], const family &aData){
    size_t  index = calculateIndex(key);
    node    *newNode = new node(aData);
    
    newNode->next = table[index];
    table[index] = newNode;
    size++;
}

//lookups family and returns that data
family hashtable::lookup(const char key[]){
    size_t  index = calculateIndex(key);
    char    *id = NULL;
    family  aData;
    node    *curr = table[index];

    while (curr){
        curr->data.getId(id);
        if (strcmp(key, id) == 0){
            aData = curr->data;
        }
        curr = curr->next;
    } 

    delete [] id;
    return aData;
}

//prints out table
void hashtable::dumpTable(std::ostream &output){
    node    *curr = NULL;

    if (table == NULL)
        output << "Table is empty" << std::endl;
    else{
        for (int i = 0; i < capacity; i++){
            curr = table[i];
            output << "table[" << i << "]:" << std::endl
                 << "List:" << std::endl;
            if (curr){
                while (curr){
                    output << curr->data;
                    curr = curr->next;
                }    
            }    
            output << "-------------------" << std::endl;
        }
    }
}

//removes data
void hashtable::remove(const char key[]){
    size_t  index = calculateIndex(key);
    char    *id = NULL;
    node    *curr = table[index];
    node    *prev = NULL;
    
    while (curr){
        curr->data.getId(id);
        if (strcmp(key, id) == 0){
            if (!prev)      
                table[index] = curr->next;
            else
                prev->next = curr->next;
            
            curr->next = NULL;
            delete curr;
            size--;
            return;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    
    delete [] id;
}

//clears table of all data
void hashtable::destroyTable(){
    node    *curr = NULL;
    node    *prev = NULL;
    
    for (int i = 0; i < capacity; i++){
        curr = table[i];
        while (curr){
            prev = curr;
            curr = curr->next;
            prev->next = NULL;
            delete prev;
            prev = curr;
        }
    }
    delete [] table;
}

//calculates where family will go
size_t hashtable::calculateIndex(const char key[]){
    
    int*    values = new int[strlen(key) + 1] {0};
    int     length = strlen(key);
    int     iterations = strlen(key) - 1;
    size_t  index;

    //stores ascii value for each letter in seperate array
    for (int i = 0; i < length; i++){
        values[i] = int(key[i]);
    }
    
    //calculates index value using Horner's rule
    for (int i = 0; i < iterations; i++){
        if (i == 0){
            index = values[i]*32+values[i+1];
        }
        else{
            index = index * 32 + values[i+1];
        }   
    }

    delete [] values;
    //returns moded index value
    return index%capacity;
}

//assignment operator
const hashtable& hashtable::operator= (const hashtable &aTable){
    if (this == &aTable)
        return *this;
    else{
        destroyTable();

        capacity = aTable.capacity;
        size = aTable.size;
        table = new node*[aTable.capacity];
        
        for (int i = 0; i < aTable.capacity; i++){
            if (aTable.table[i] == NULL)
                table[i] = NULL;
            else{
                table[i] = new node(aTable.table[i]->data);

                node    *src = aTable.table[i]->next;
                node    *dest = table[i];
        
                while(src){
                    dest->next = new node(src->data);
                    dest = dest->next;
                    src = src->next;
                }    
                dest->next = NULL;
            }
        }
        return *this;
    }
}



