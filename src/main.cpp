#include <iostream>
#include "dshashtable.h"
#include <string>

int main() {

  hash_table<std::string, std::string> my_table;

  my_table.insert("SMU", "Peruna");

  std::string ret_val = my_table.get_value("SMU");
  std::cout << ret_val << std::endl;

  
}