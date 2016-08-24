//
//  hashtable.c
//  
//
//  Created by Malik Woods on 8/23/16.
//
//

//practicing implementing code in c basic algorithms this time is a simple hashtable that utilize a linked list for "chaining"

#include <stdlib.h>
#include <stdio.h>



#define DEFAULT_HASH_SIZE 20


struct Entry {
    int data;
    int key;
    struct Entry * nextItem;
};

typedef struct Entry * EntryPtr;

struct Entry* HASH_TABLE[DEFAULT_HASH_SIZE];


void print_hash_table();

int summ_of_digits()

int hash_func(int key){
    return (key) % DEFAULT_HASH_SIZE;
}


int better_hash_func(int key){
    return ()
}

void insert(int key, int data){
    printf("key %d\n", key);
    EntryPtr item = malloc(sizeof(EntryPtr));
    item->key = key;
    item->data = data;
    item->nextItem = NULL;
    
    int bin = hash_func(key);
    if(HASH_TABLE[bin] == NULL){
        HASH_TABLE[bin] = item;
    } else {
        EntryPtr bucket = HASH_TABLE[bin];
        
        while(((bucket->nextItem) != NULL)){
            if(bucket->key == key){
                bucket->data = data;
                free(item);
            } else {
                bucket = bucket->nextItem;

            }
        }
        bucket->nextItem = item;
    }

}

EntryPtr get(int key){
    printf("key %d\n", key);
    
    int bin = hash_func(key);
    if(HASH_TABLE[bin] == NULL){
        return NULL;
    } else {
        
        EntryPtr bucket = HASH_TABLE[bin];
        
        do{
            if(bucket->key == key){
                return bucket;
            } else {
                bucket = bucket -> nextItem;
            }
        } while ((bucket->nextItem) != NULL);
    }
    return NULL;
}

void print_hash_table(){
    for(int i = 0; i < DEFAULT_HASH_SIZE; i++){
        printf("Bucket %d ", i);
        EntryPtr item = HASH_TABLE[i];
        while(item != NULL){
            printf(" -> (%d, %d)", item->key, item->data);
            item = item->nextItem;
        }
        printf("\n");
    }
}


int main(){
    //Initalize Hash Table
    insert(0, 3);
    insert(20, 5);
    insert(40, 10);
    insert(2, 10);
    
    print_hash_table();
    
    EntryPtr item = get(10);
    
    if(item != NULL){
        printf("Found (%d, %d)\n", item->key, item->data);
    }else{
        printf("Item Not Found\n");
    }
    
    EntryPtr item2 = get(20);
    
    if(item2 != NULL){
        printf("Found (%d, %d)\n", item2->key, item2->data);
    }else{
        printf("Item Not Found\n");
    }
    
    return 0;
}
