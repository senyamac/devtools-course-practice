// Copyright 2018 Pozdeeva Varvara

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/q_sort_app.h"

int main(int argc, const char** argv) {
    QuickSortApp app;
    std::string output = app(argc, argv);
    //printf("AAA");
    printf("%s\n", output.c_str());
    return 0;
}
