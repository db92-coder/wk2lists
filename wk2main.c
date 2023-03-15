#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "bst.h"

//void option_insert(List* list);
//void option_delete(List* list);
//void option_print(List* list);
//
//int main() {
//    List my_list = new_list();
//
//    int quit = 0;
//    int option;
//
//
//    do {
//        printf("option 0: QUIT | option 1: INSERT | option 2: DELETE | option 3: PRINT | option 4: REVERSE | option 5: MERGE \n");
//        scanf("%d", &option);
//
//        switch (option) {
//            case 0:
//                quit = 1;
//                break;
//            case 1:
//                option_insert(&my_list);
//                break;
//            case 2:
//                option_delete(&my_list);
//                break;
//            case 3:
//                option_print(&my_list);
//                break;
//            case 4:
//                my_list = reverse(my_list);
//                break;
//            case 5:
//            {
//                List list1 = new_list();
//                List list2 = new_list();
//                printf("Enter elements of the first list (in ascending order, -1 to stop):\n");
//                int element;
//                do {
//                    scanf("%d", &element);
//                    if (element != -1) {
//                        insert_in_order(&list1, element);
//                    }
//                } while (element != -1);
//                printf("Enter elements of the second list (in ascending order, -1 to stop):\n");
//                do {
//                    scanf("%d", &element);
//                    if (element != -1) {
//                        insert_in_order(&list2, element);
//                    }
//                } while (element != -1);
//                my_list = merge(list1, list2);
//                destroy_list(&list1);
//                destroy_list(&list2);
//            }
//                break;
//            default:
//                printf("Invalid option\n");
//                break;
//        }
//
//
//    }while (!quit);
//}
//
//void option_insert(List *list)
//{
//    int value;
//    printf("Enter an integer to insert: ");
//    scanf("%d", &value);
//    insert_at_front(list, value);
//}
//void option_delete(List *list)
//{
//    int value;
//    printf("Enter an integer to delete: ");
//    scanf("%d", &value);
//    delete_list(list, value);
//}
//
//void option_print(List *list)
//{
//    print_list(list);
//}
//
//// Function to reverse the given linked list.
//List reverse(List list) {
//    List reversed = new_list();
//    ListNodePtr current = list.head;
//
//    while (current != NULL) {
//        insert_at_front(&reversed, current->data);
//        current = current->next;
//    }
//
//    return reversed;
//}
//
//// Function to merge two given linked lists.
//List merge(List list1, List list2) {
//    List merged = new_list();
//    ListNodePtr current1 = list1.head;
//    ListNodePtr current2 = list2.head;
//
//    while (current1 != NULL && current2 != NULL) {
//        if (current1->data < current2->data) {
//            insert_at_front(&merged, current1->data);
//            current1 = current1->next;
//        }
//        else {
//            insert_at_front(&merged, current2->data);
//            current2 = current2->next;
//        }
//    }
//
//    // Append the remaining nodes from list1 or list2
//    while (current1 != NULL) {
//        insert_at_front(&merged, current1->data);
//        current1 = current1->next;
//    }
//
//    while (current2 != NULL) {
//        insert_at_front(&merged, current2->data);
//        current2 = current2->next;
//    }
//
//    return merged;
//}

//main function to call the bst_test function in bst source file.
int main() {
    void bst_test(void);
    bst_test();
    return 0;
}