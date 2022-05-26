//
// Created by usrname on 25.05.22.
//

#include "String.h"

string* create_string() {
    string* ptr = (string*)malloc(sizeof(string));
    ptr->str = (char*)malloc(sizeof(char));
    ptr->size = 0;
    ptr->capasity = 1;
    return ptr;
}

void append(string* str,char c) {
    if(str->size == str->capasity) {
        str->capasity *= 2;
        str->str = realloc(str->str,str->capasity);
    }
    str->str[str->size] = c;
    str->size++;
}

void delete_string(string* ptr) {
    for(int i = 0;i < ptr->capasity;i++) {
        ptr->str[i] = 0;
    }
    free(ptr->str);
    ptr->size = 0;
    ptr->capasity = 0;
    free(ptr);
}

void scan_string(string* ptr) {
    char c;
    scanf("%c",&c);
    while(c != EOF || c != '\n') {
        if(c == EOF || c == '\n') {
            break;
        }
        append(ptr,c);
        scanf("%c",&c);
    }
}

void print_string(string* ptr) {
    for(int i = 0;i < ptr->size;i++) {
        printf("%c",ptr->str[i]);
    }
}