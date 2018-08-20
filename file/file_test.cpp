#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
 
#include "file.h"

int main() {
  std::string file="./test";
  bool ret = File::is_exist(file);
  if(ret){
    std::cout<<"file exist"<<std::endl;
  }
  ret = File::is_link(file);
  if(ret){
    std::cout<<"file is link"<<std::endl;
  }

}
