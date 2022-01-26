#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tokens.h"

#define SIZE 20

struct tokens_hashtable {
   char data[20];
   int key;
};

struct tokens_hashtable* hashArray[SIZE];
struct tokens_hashtable* dummyItem;
struct tokens_hashtable* item;

int hashCode(int key) {
   return key % SIZE;
}

struct tokens_hashtable *search(int key) {
   //get the hash 
   int hashIndex = hashCode(key);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert_in_hashtable(int key, char **data) {

   struct tokens_hashtable *item = (struct tokens_hashtable*) malloc(sizeof(struct tokens_hashtable));
   strcpy(item->data, data);
   item->key = key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}

struct tokens_hashtable* delete_from_hashtable(struct tokens_hashtable* item) {
   int key = item->key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key) {
         struct tokens_hashtable* temp = hashArray[hashIndex];
			
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}

void display_hashtable() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

// int main() {
//    dummyItem = (struct tokens_hashtable*) malloc(sizeof(struct tokens_hashtable));
// //   strcpy(dummyItem->data, "");
// //   dummyItem->key = -1;
//     insert_in_hashtable(TK_IDENTIFIER, "AJC");
//     insert_in_hashtable(LIT_INTEGER, "70");
//     insert_in_hashtable(LIT_STRING, "\"ksdsjhf\"");
//    display();
// }