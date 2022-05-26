#include "map.h"
#include "reading.h"
#include <unistd.h>
#include <string.h>

int main() {
    table* t = create_table();
    bool program = true;
    while(program) {

        printf("1)Print table\n2)Insert\n3)Erase\n4)Binary Search\n5)Sort\n6)Reverse\n7)Random order\n8)Exit\n");
        printf("\n");
        printf("Choose the command:");
        char* command;
        command = get_line();

        if (!strcmp("1", command)) {
            printf("The table:\n");
            print_table(t);
        } else if (!strcmp("2", command)) {
            double key;
            string* s = create_string();
            printf("Insert value:");
            scan_string(s);
            printf("Insert key:");
            key = atof(get_string());
            push_back(t,key,s);
            printf("The value was added!\n");
        } else if (!strcmp("3", command)) {
            double key;
            printf("Insert key of value that will be deleted:");
            key = atof(get_string());
            erase(t,key);
            printf("The value was deleted!\n");
        } else if (!strcmp("4", command)) {
            double key;
            printf("Insert key:");
            key = atof(get_string());
            bin_search(t,key);
        } else if (!strcmp("5", command)) {
            sort(t);
            printf("The table was sorted!\n");
        } else if (!strcmp("6", command)) {
            reverse(t);
            printf("The table was reversed!\n");
        } else if (!strcmp("7", command)) {
            randomiser(t);
            printf("The table was randomised!\n");
        } else if (!strcmp("8", command)) {
            program = false;
            break;
        } else {
            printf("Invalid value.\n");
        }
    }
    delete_table(t);
    return 0;
}
