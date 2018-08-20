#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <unistd.h>
 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include "utils.h"

using namespace std;

bool read(const char* path){
  ifstream resource_file;
    resource_file.open(path, ios::in | ios::binary | ios::ate);
      if (!resource_file.is_open()) {
        std::cout<< "open resource file failed: " << path <<std::endl;
        return false;
      }
      streampos size = resource_file.tellg();
      char *resource_buf = new char[size];
      resource_file.seekg(0, ios::beg);
      resource_file.read(resource_buf, size);

      int size_len = 4;
      streampos i = 0;
      streampos offset = 0;
      // read size of resource item, then new a pointer buffer is better
      while (i < size) {
        offset = i;
        int key_len = util::bytes_to_int_little(resource_buf + offset);
        offset += size_len;
        string key(resource_buf + offset, key_len);
        offset += key_len;
        
       int value_len = util::bytes_to_int_little(resource_buf + offset);
       offset += size_len;
       string value(resource_buf + offset, value_len);
       offset += value_len;
       std::cout<<"key:"<<key<<" value:"<<value<<std::endl;
       i = offset;
     }
     delete[] resource_buf;
     resource_file.clear();
     resource_file.seekg(0);
     resource_file.close();
     return true;
}


int main() {
  char path[1024] ="./test.dat";
  ofstream resource_file;
  resource_file.open(path, ios::out | ios::binary | ios::ate);
  if (!resource_file.is_open()) {
    std::cout << "open resource file failed: " << path <<std::endl;
    return 1;
  }
  std::string key = "key";
  int key_len = key.size();
  resource_file.write( reinterpret_cast <const char*> (&key_len), sizeof( key_len ) );
  resource_file.write( key.c_str(), key_len );
  std::string value = "value";
  int value_len = value.size();
  resource_file.write( reinterpret_cast <const char*> (&value_len), sizeof( value_len ) );
  resource_file.write( value.c_str(), value_len );
  resource_file.flush();
  resource_file.close();
  read(path);
  return 0;
}
