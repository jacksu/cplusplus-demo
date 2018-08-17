#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include "hash.h"
#include <unistd.h>
 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  std::string file = "./test";
  if(access(file.c_str(), F_OK) != -1){
  remove(file);
  }
}
