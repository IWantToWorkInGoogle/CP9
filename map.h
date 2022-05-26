//
// Created by usrname on 25.05.22.
//

#ifndef CP9_MAP_H
#define CP9_MAP_H

#endif //CP9_MAP_H

#include "String.h"

typedef struct {
    char* val;
    double key;
} table_item;

typedef struct {
    table_item** data;
    int size;
    int capasity;
    bool sorted;
} table;

table_item* create_item();
void delete_item(table_item* ptr);
table* create_table();
void delete_table(table* ptr);
void read_table(table* ptr,FILE* fin);
void print_table(table* ptr);
void push_back(table* ptr,double key,string* val);
void pop_back(table* ptr);
void erase(table* ptr,double key);
void sort(table* ptr);
void reverse(table* ptr);
void randomiser(table* ptr);
void bin_search(table* ptr,double key);