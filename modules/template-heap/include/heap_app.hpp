// Copyright 2018 Mayachkin Arseny

#ifndef MODULES_TEMPLATE_HEAP_INCLUDE_HEAP_APP_HPP_
#define MODULES_TEMPLATE_HEAP_INCLUDE_HEAP_APP_HPP_

#include <string>

class HeapApp {
 public:
  HeapApp();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string message_;
};

#endif  // MODULES_TEMPLATE_HEAP_INCLUDE_HEAP_APP_HPP_
