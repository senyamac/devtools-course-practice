// Copyright 2018 Mayachkin Arseny

#include <iostream>
#include <string>

#include "include/heap_app.hpp"

int main(int argc, const char** argv) {
  HeapApp app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
