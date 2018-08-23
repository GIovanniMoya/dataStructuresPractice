#ifndef hash_table_h
#define hash_table_h


class HashEntry {

 private:
  HashItem table[];
  
 public:
  int char;
  void insert(char key, char value);
  void delete(char key);
  int hashFunc(char key);
  HashEntry find(char key);
  void resize();
  HashEntry(size);
  ~HashEntry
};

class HashItem {

 private:
  char key;
  char value;
  
 pnublic:
  HashItem(char key, char value);
  void setKey();
  void setValue();
  char getKey();
  char getValue();
};

#endif hash_table_h
