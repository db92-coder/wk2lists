#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

// create an empty bst
BST new_bst() {
    BST temp;
    temp.root = NULL;
    return temp;
}

// this function recursively searches for a node with the value 'n' in the tree, and returns a pointer to the node if found, or 'null' if not found.
BSTNodePtr find_bst_node(BSTNodePtr self, int n) { //pointer to root node of bst 'self and int value n
    if (self != NULL || (n == self->data_item)) { /* if statement checks whether the input 'self' is null, or if the value at 'self' is equal to 'n'
 * if either of these conditions is true, that means 'n' is present at the current node, so the function returns 'self' */
        return self;
    } else if (n < self->data_item) { /* if 'n' is not present at the current node, the function checks whether 'n' is less than the value at 'self'
 * if it is, that means 'n' must be in the left subtree of 'self', so the function recursively calls itself with the left child of 'self' as the new 'self'*/
        return find_bst_node(self->left, n);
    } else {
        return find_bst_node(self->right, n); /* If n is greater than or equal to the value at self, that means n must be in the right subtree of self,
 * so the function recursively calls itself with the right child of self as the new self. This recursion continues until either n is found in a node,
 * in which case a pointer to that node is returned, or until the end of a leaf node is reached, in which case NULL is returned to signify that n is not present in the tree.*/
    }
}

// find a value in the tree and return the node
BSTNodePtr find_bst(BST* self, int n) {
    return find_bst_node(self->root, n);
}

// recursive function to insert a value
BSTNodePtr insert_bst_node(BSTNodePtr self, int n) {
    if (self == NULL) { /* checks whether the input self is NULL. If it is, that means we have found the correct position in the tree to insert n, so the function creates a
 * new node using malloc and initializes its data item with the value n. The left and right child pointers of
 * the new node are set to NULL, and a pointer to the new node is returned as the root of the modified tree.*/
        self = malloc(sizeof *self);
        self->data_item = n;
        self->left = self->right = NULL;
    } else if (n < self->data_item) { /* If self is not NULL, the function compares n to the data item of the current node self.
 * If n is less than the current node's data item, the function recursively calls itself with the left child of self as the new self,
 * in order to insert n into the left subtree of self*/
        self->left = insert_bst_node(self->left, n);
    } else if (n >self->data_item) { /* If n is greater than the current node's data item, the function recursively calls itself with the right child of self as the new self,
 * in order to insert n into the right subtree of self.*/
        self->right = insert_bst_node(self->right, n);
    } /* This recursion continues until NULL is found, indicating that n can be inserted at the current position, or until a node with the same data item as n is found, indicating that n is already present in the tree.*/
    return self; // Finally, the function returns the modified tree rooted at self, with the new node containing n inserted into its correct position.

}

// insert a value into the tree
void insert_bst(BST* self, int n) { //takes two arguments: a pointer to a BST struct (self) and an integer value n that we want to insert into the binary search tree
    self->root = insert_bst_node(self->root, n); /* The function calls insert_bst_node with the root of the binary search tree (self->root) and the integer value n as arguments.
 * The insert_bst_node function returns a pointer to the modified binary search tree, with the new node containing n inserted in the correct position according to the ordering property of the tree.
 The function assigns the resulting pointer from insert_bst_node to self->root. This updates the root of the binary search tree to reflect the insertion of the new node with value n.*/
}

// helper function for delete
BSTNodePtr min_node(BSTNodePtr self) {
    BSTNodePtr current = self;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// recursive function to delete a value
BSTNodePtr delete_bst_node(BSTNodePtr self, int n) {
    if (self != NULL) {
        if (n == self->data_item) { // found item
            if (self->left != NULL && self->right != NULL) {
                // two child case
                BSTNodePtr successor = min_node(self->right);
                self->data_item = successor->data_item;
                self->right = delete_bst_node(self->right, self->data_item);
            } else { // one or zero child case
                BSTNodePtr to_free = self;
                if (self->left) {
                    self = self->left;
                } else {
                    self = self->right;
                }
                free(to_free);
            }
        } else if (n < self->data_item) {
            self->left = delete_bst_node(self->left, n);
        } else {
            self->right = delete_bst_node(self->right, n);
        }
    }
    return self;
}

// delete a value from the tree
void delete_bst(BST* self, int n) {
    self->root = delete_bst_node(self->root, n);
}

// recursive function to print in order
void print_in_order_bst_node(BSTNodePtr self){
    if (self == NULL) {
        printf("_");
    } else {
        printf("(");
        print_in_order_bst_node(self->left);
        printf(" %d ", self->data_item);
        print_in_order_bst_node(self->right);
        printf(")");
    }
}
// recursive function to print pre order
void print_pre_order_bst_node(BSTNodePtr self){ //take pointer to a bst node 'self'
    if (self == NULL) { //check if current node is null. if so the function prints a placeholder symbol '_' to indicate that the subtree rooted at this node is empty.
        printf("_");
    } else { //if the current node is not null, the function prints the data item stored in the node ('self->data_item') to the console.
        printf(" %d ", self->data_item);
        print_pre_order_bst_node(self->left);
        print_pre_order_bst_node(self->right);
    }
}

// recursive function to print post order
void print_post_order_bst_node(BSTNodePtr self){
    if (self == NULL) {
        printf("_");
    } else {
        print_post_order_bst_node(self->left);
        print_post_order_bst_node(self->right);
        printf(" %d ", self->data_item);
    }
}


// print the tree in order
void print_in_order_bst(BST *self) {
    print_in_order_bst_node(self->root);
}

// recursive function to detroy all node
void destroy_bst_node(BSTNodePtr self) {
    if (self != NULL) {
        destroy_bst_node(self->left);
        self->left = NULL;
        destroy_bst_node(self->right);
        self->right = NULL;
        free(self);
    }
}

// recursive function to count the number of nodes in the tree
int count_bst_nodes(BSTNodePtr self) {
    if (self == NULL) { //checks if the current not is null. if so, return 0 because there are no nodes in an empty subtree.
        return 0;
    } else {
        return 1 + count_bst_nodes(self->left) + count_bst_nodes(self->right); //the function recursively calls itself with the left and right most child of the current node as its arguement ('count_bst_nodes(self->left)'). this counts the nodes in the left and right subtree
    }
}

// count the number of nodes in the tree
int count_bst(BST *self) {
    return count_bst_nodes(self->root);
}

// recursive function to find the minimum value in the tree
int find_min_bst_node(BSTNodePtr self) {
    if (self->left == NULL) {
        return self->data_item;
    } else {
        return find_min_bst_node(self->left);
    }
}

// find the minimum value in the tree
int find_min_bst(BST *self) {
    if (self->root == NULL) {
        printf("Tree is empty.\n");
        return -1;
    } else {
        return find_min_bst_node(self->root);
    }
}

// recursive function to find the maximum value in the tree
int find_max_bst_node(BSTNodePtr self) {
    if (self->right == NULL) {
        return self->data_item;
    } else {
        return find_max_bst_node(self->right);
    }
}

// find the maximum value in the tree
int find_max_bst(BST *self) { //pointer to BST 'self'
    if (self->root == NULL) { //checks if the root of the bst is null. if so, the function prints an error message, indicating the bst is empty
        printf("Tree is empty.\n");
        return -1;
    } else {
        return find_max_bst_node(self->root); //if the root of the bst is not null, the function calls the 'find_max_bst_node' with the root of the bst ('self->root')
    }
}

// recursive function to calculate the height of the tree
int height_bst_node(BSTNodePtr self) { //function is called
    if (self == NULL) { //check whether the input self is NULL
        return -1; //if self is null, that means the current node is an empty leaf node, so the function returns -1
    } else { //if self is not null, the function recursively calls itself twice, once for the left child of 'self' and once for the right child of 'self', to find the height of the left and right subtrees.
        int left_height = height_bst_node(self->left);
        int right_height = height_bst_node(self->right);
        if (left_height > right_height) { //comparing the heights of the left and right subtrees.
            return left_height + 1; //if the left subtree is higher then the function is passed and +1 is added to the height of the left
        } else {
            return right_height + 1;//if the right subtree is higher then the function is passed and +1 is added to the height of the right
        }
    }
}

// calculate the height of the tree
int height_bst(BST *self) {
    return height_bst_node(self->root);
}

// destroy the tree
void destroy_bst(BST *self) {
    destroy_bst_node(self->root);
    self->root = NULL;
}

void bst_test() {
    BST tree = new_bst();
    int quit = 0;
    int data;
    while (quit == 0) {
        printf("Enter some data: ");
        scanf("%d", &data);
        if (data != 0) {
            insert_bst(&tree, data);
        }
        else {
            quit = 1;
        }
    }
    printf("In-order traversal: ");
    print_in_order_bst(&tree);
    printf("\n");
    printf("Minimum value: %d\n", find_min_bst(&tree));
    printf("Maximum value: %d\n", find_max_bst(&tree));
    printf("Number of nodes: %d\n", count_bst(&tree));
    printf("Height of tree: %d\n", height_bst(&tree));
    destroy_bst(&tree);

}
