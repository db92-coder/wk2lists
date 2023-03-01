#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void option_insert(List* list);
void option_delete(List* list);
void option_print(List* list);

int main() {
    List my_list = new_list();

    int quit = 0;
    int option;

    do {
        printf("option 0: QUIT | option 1: INSERT | option 2: DELETE | option 3: PRINT \n");
        scanf_s("%d", &option);

        switch (option) {
            case 0:
                quit = 0;
                break;
            case 1:
                option_insert(&my_list);
                break;
            case 2:
                option_delete(&my_list);
                break;
            case 3:
                option_print(&my_list);
                break;
        }


    }while (!quit);
}

void option_insert(List *list)
{
    int value;
    printf("Enter an integer to insert: ");
    scanf_s("%d", &value);
    insert_at_front(list, value);
}
void option_delete(List *list)
{
    int value;
    printf("Enter an integer to delete: ");
    scanf_s("%d", &value);
    delete_list(list, value);
}

void option_print(List *list)
{
    print_list(list);
}