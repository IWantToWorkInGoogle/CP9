//
// Created by usrname on 27.05.22.
//

#include "reading.h"
#include <stdlib.h>
#include <stdio.h>

char* get_line() {
    char* ans = (char*)malloc(sizeof(char));
    char c;
    int size = 0;
    int capacity = 1;
    scanf("%c",&c);
    while(c != '\n' || c != EOF) {
        if(c == '\n' || c == EOF) {
            break;
        }
        if(size == capacity) {
            capacity *= 2;
            ans = realloc(ans,capacity);
        }
        ans[size] = c;
        size++;
        scanf("%c",&c);
    }
    return ans;
}

char* get_string() {
    char* ans = (char*)malloc(sizeof(char));
    char c;
    int size = 0;
    int capacity = 1;
    scanf("%c",&c);
    while(c != '\n' || c != EOF || c == ' ') {
        if(c == '\n' || c == EOF || c == ' ') {
            break;
        }
        if(size == capacity) {
            capacity *= 2;
            ans = realloc(ans,capacity);
        }
        ans[size] = c;
        size++;
        scanf("%c",&c);
    }
    return ans;
}
