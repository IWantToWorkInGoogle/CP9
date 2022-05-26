//
// Created by usrname on 25.05.22.
//

#include "map.h"

table_item* create_item(double key, string* val) {
    table_item* ptr = (table_item*)malloc(sizeof(table_item));
    ptr->val = val;
    ptr->key = key;
    return ptr;
}

void delete_item(table_item* ptr) {
    ptr->key = 0;
    delete_string(ptr->val);
    free(ptr);
}

table* create_table() {
    table* ptr = (table*)malloc(sizeof(table));
    ptr->data = (table_item**)malloc(sizeof(table_item*));
    ptr->size = 0;
    ptr->capasity = 1;
    ptr->sorted = true;
    return ptr;
}

void delete_table(table* ptr) {
    for(int i = 0;i < ptr->size;i++) {
        delete_item(ptr->data[i]);
        ptr->data[i] = NULL;
    }
    free(ptr->data);
    ptr->size = 0;
    ptr->capasity = 0;
    free(ptr);
}

void read_table(table* ptr, FILE* fin) {
    double key = 0;
    while(fscanf(fin, "%lf", &key) != EOF) {
        string* str = create_string();
        char c;
        fscanf(fin,"%c",&c);
        while(c != '\n' || c != EOF) {
            append(str,c);
            fscanf(fin,"%c",&c);
        }
        push_back(ptr,key,str);
    }
}

void print_table(table* ptr) {
    for(int i = 0;i < ptr->size;i++) {
        printf("%lf ",ptr->data[i]->key);
        print_string(ptr->data[i]->val);
        printf("\n");
    }
}

void push_back(table* ptr,double key,string* val) {
    if(ptr->size == ptr->capasity) {
        ptr->capasity *= 2;
        ptr->data = realloc(ptr->data,sizeof(table_item) * ptr->capasity);
    }
    table_item* new_item = create_item(key,val);
    ptr->data[ptr->size] = new_item;
    ptr->size++;
    ptr->sorted = false;
}

void pop_back(table* ptr) {
    if(ptr->size == 0) {
        return;
    } else {
        if(ptr->size == ptr->capasity / 2 && ptr->capasity > 1) {
            ptr->capasity /= 2;
            ptr->data = realloc(ptr->data,sizeof(table_item) * ptr->size);
        }
        ptr->size--;
        delete_item(ptr->data[ptr->size]);
    }
    if(ptr->size == 0) {
        ptr->sorted = true;
    }
}

void erase(table* ptr,double key) {
    int found = -1;
    for(int i = 0;i < ptr->size;i++) {
        if(found != -1) {
            ptr->data[i - 1] = ptr->data[i];
        } else if(ptr->data[i]->key == key) {
            found = i;
            delete_item(ptr->data[i]);
        }
    }
    printf("%d\n",found);
    if(found != -1) {
        ptr->data[ptr->size - 1] = NULL;
        ptr->size--;
    }
    if(ptr->size == 0) {
        ptr->sorted = true;
    }
}

void sort(table* ptr) {
    if(ptr->sorted)
        return;
    for(int i = 0;i < ptr->size - 1;i++) {
        int ind = i;
        for(int j = i + 1;j < ptr->size;j++) {
            if(ptr->data[ind]->key > ptr->data[j]->key) {
                ind = j;
            }
        }
        table_item* t = ptr->data[i];
        ptr->data[i] = ptr->data[ind];
        ptr->data[ind] = t;
    }
    ptr->sorted = true;
}

void reverse(table* ptr) {
    if(!ptr->sorted) {
        sort(ptr);
    }
    for(int i = 0;i < ptr->size / 2;i++) {
        table_item* t = ptr->data[i];
        ptr->data[i] = ptr->data[ptr->size - 1 - i];
        ptr->data[ptr->size - 1 - i] = t;
    }
    ptr->sorted = false;
}

void randomiser(table* ptr) {
    for(int i = 0;i < ptr->size;i++) {
        int ind = rand() % ptr->size;
        table_item* t = ptr->data[i];
        ptr->data[i] = ptr->data[ind];
        ptr->data[ind] = t;
    }
    ptr->sorted = false;
}

void bin_search(table* ptr,double key) {
    if(!ptr->sorted) {
        sort(ptr);
    }
    int l = 0;
    int r = ptr->size - 1;
    int found = -1;
    while(l <= r) {
        int mid = (l + r)/ 2;
        if(ptr->data[mid]->key == key) {
            found = mid;
            break;
        } else if(ptr->data[mid]->key < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(found == -1) {
        printf("The value wasn't found!\n");
    } else {
        printf("The value: ");
        print_string(ptr->data[found]->val);
        printf("\n");
    }
}