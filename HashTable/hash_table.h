#ifndef hash_table_h
#define hash_table_h


class HashItem {

 private:
  char key;
  char value;
  
 public:
  HashItem();
  HashItem(char key, char value);
  void setKey(char key);
  void setValue(char value);
  char getKey();
  char getValue();
  
};

class HashEntry : public HashItem {

 private:
  HashItem table[];
  
 public:
  void insert(char key, char value);
  void remove(char key);
  int hashFunc(char key);
  HashItem find(char key);
  void resize();
  HashEntry(int size);
  HashEntry();
};
#endif
