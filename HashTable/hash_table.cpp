#include "hash_table.h"
#include <iostream>

static int TABLESIZE = 0;

HashEntry::HashEntry() {
  std::cout << "pass an argument to this constructor\n";
  HashItem();
}

HashEntry::HashEntry(int size) {
  
  TABLESIZE = size;
  HashEntry table = new HashItem[TABLESIZE](); /*this will initalize all array index's to NULL*/
  table.count = 0;
  std::cout << "test\n";
}

HashItem::HashItem() {
}

HashItem::HashItem(char key, char value) {

  setKey(key);
  setValue(value);
}



/*get and set methods for HashItems*/

char HashItem::getValue() {
  return this->value; 
}

char HashItem::getKey() {
  return this->key;
}

void HashItem::setValue(char value) {
  this->value = value;
}

void HashItem::setKey(char key) {
  this->key = key;
}



int HashEntry::hashFunc(char key) {

  int hash = (int)key % TABLESIZE;
  return hash;
  
}

void HashEntry::insert(char key, char value) {

  int hashIndex = hashFunc(key);

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

HashEntry HashEntry::find(char key) {
  
  int hashIndex = hashFunc(key);


  for(int i = 0; i < TABLESIZE; i++) {
    if(key == table[hashIndex].getKey())
      return table[hashIndex];

    hashIndex++;
  }
}

void HashEntry::remove(char key) {
  delete find(key);
  table.count--;
}

