// Copyright 2018 Mayachkin Arseny

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <stdexcept>

#include "include/heap_app.hpp"

using ::testing::internal::RE;
using std::vector;
using std::string;

class HeapAppTest : public ::testing::Test {
 protected:
  void Act(vector<string> args_) {
    vector<const char*> options;

    options.push_back("appname");
    for (size_t i = 0; i < args_.size(); ++i) {
      options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) {
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  HeapApp app_;
  string output_;
};

TEST_F(HeapAppTest, Can_Print_Help_Without_Arguments) {
  vector<string> args = {};

  Act(args);

  Assert("This is a heap application\\..*");
}

TEST_F(HeapAppTest, Can_Detect_Wrong_Number_Format) {
  vector<string> args = {"q", "13", "8", "10"};

  Act(args);

  Assert("Wrong format or value is out of range");
}

TEST_F(HeapAppTest, Can_Make_Heap_And_Get_Result) {
  vector<string> args = {"2", "5", "16", "7", "13"};

  Act(args);

  Assert("Your heap:\n{ size = 4, dim = 2, top = 16 }");
}
