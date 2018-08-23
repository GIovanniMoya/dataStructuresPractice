#include "hash_table.h"
#include <iostream>


HashEntry::HashEntry(size) {
  
  static int TABLESIZE = size;
  table = new HashEntry*[TABLESIZE](); /*this will initalize all array index's to NULL*/
  table.count = 0;
  return table;
}

HashItem::HashItem(char key, char value) {

  setKey(key);
  setValue(value);
}



/*get and set methods for HashItems*/

HashItem::char getValue() {
  this->value = value; 
}

HashItem::char getKey() {
  return this->key;
}

HashItem::void setValue(char value) {
  this->key = key;
}

HashItem::void setKey(char key) {
  this->value = value;
}



HashEntry::hashFunc(char key) {

  hash = (int)key % TABLESIZE;
  return hash;
  
}

HashEntry::insert(char key, char value) {

  hashIndex = hashFunc(key);

  HashItem item = new HashItem(key, value);

  for(int i = 0; i < TABLESIZE; i++) {
    if(item.getKey() != table[hashIndex].getKey() && table[hashIndex] == NULL) {
      table[hashIndex] = item;
      table.count++;
      return;
    }

    hashIndex++;
  }
}

HashEntry::find(char key) {
  
  hashIndex = hashFunc(key);


  for(int i = 0; i < TABLESIZE; i++) {
    if(key == table[hashIndex].getKey())
      return table[hashIndex];

    hashIndex++;
  }
}

HashEntry::delete(char key) {
  delete find(key);
  table.count--;
}

