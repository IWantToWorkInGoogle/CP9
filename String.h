//
// Created by usrname on 25.05.22.
//

#ifndef CP9_STRING_H
#define CP9_STRING_H

#endif //CP9_STRING_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    char* str;
    int size;
    int capasity;
} string;

string* create_string();
void append(string* str,char c);
void delete_string(string* ptr);
void scan_string(string* ptr);
void print_string(string* ptr);
