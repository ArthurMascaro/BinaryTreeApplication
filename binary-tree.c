#include <stdlib.h>
#include "binary-tree.h"

t_binary_tree* create_tree(){
    t_binary_tree* tree = malloc(sizeof(t_binary_tree));
    tree->root = NULL;
    return tree;
};

t_node* create_node(char item){
    t_node* node = malloc(sizeof(t_node));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
};


void insert_right(t_node* node, t_node* parent_node){
    parent_node->right = node;
};


void insert_left(t_node* node, t_node* parent_node){
    parent_node->left = node;
}

void pre_order(t_node* node){
    if(node!=NULL){
        printf("%c ", node->item);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(t_node* node){
    if(node!=NULL){
        in_order(node->left);
        printf("%c ", node->item);
        in_order(node->right);
    }
}

void in_order_right(t_node* node){
    if(node!=NULL){
        in_order_right(node->right);
        printf("%c ", node->item);
        in_order_right(node->left);
    }
}

void post_order(t_node* node){
    if(node!=NULL){
        post_order(node->left);
        post_order(node->right);
        printf("%c ", node->item);
    }
}

void post_order_right(t_node* node){
    if(node!=NULL){
        post_order_right(node->right);
        post_order_right(node->left);
        printf("%c ", node->item);
    }
}

void destroy_tree_rec(t_node *node){
    if(node){
        destroy_tree_rec(node->left);
        destroy_tree_rec(node->right);
        free(node);
    }
}

void destroy_tree(t_binary_tree* tree){
    if(tree){
        destroy_tree_rec(tree->root);
        free(tree);
    }
}

int height(t_binary_tree* tree){
    return height_rec(tree->root, 1);
};

int height_rec(t_node* node, int height){
    if(node == NULL){
        return height-1;
    }
    int leftHeight = height_rec(node->left, height+1);
    int rightHeight = height_rec(node->right, height+1);
    if(leftHeight >= rightHeight){
        return leftHeight;
    } else {
        return rightHeight;
    }
};

int height_2(t_binary_tree* tree){
    if (tree) {
        return height_rec_2(tree->root);
    }
    
    return 0;
}

int height_rec_2(t_node* node){
    if (node != NULL) {
        int left_height = height_rec_2(node->left);
        int right_height = height_rec_2(node->right);

        if (left_height > right_height) {
            return 1 + left_height;
        }
        return 1 + right_height;
    }

    return 0;
}

void print(t_binary_tree* tree){
    print_rec(tree->root, 1);
}
int print_rec(t_node* node, int height){
    if(node == NULL){
        return height-1;
    }
    print_rec(node->right, height+1);
    for (int i = 0; i < height - 1; i++) {
        printf("\t");
    }
    printf("%c\n", node->item);
    print_rec(node->left, height+1);
};

t_binary_tree* createTree(char* string){
    t_binary_tree* tree = create_tree();
    t_node* root = createRootNode(string, 0, strlen(string) - 1);
    tree->root = root;
    return tree;
}

int getEndBracketIndex(char* string, int start){
    int count = 0;
    for (int i = start; string[i] != '\0'; i++) {
        if (string[i] == '(') count++;
        if (string[i] == ')') count--;
        if (count == 0) return i;
    }
    return -1;
}

t_node* createRootNode(char* string, int start, int end){
    if (start >= end || string[start] != '(' || string[start+1] == ')') {
        return NULL; 
    }

    t_node* rootNode = create_node(string[start + 1]);

    int leftStart = start + 3;
    int leftEnd = getEndBracketIndex(string, leftStart);
    
    int rightStart = leftEnd + 2;
    int rightEnd = getEndBracketIndex(string, rightStart);

    printf("Node: %c\n", rootNode->item);

    insert_left(createRootNode(string, leftStart, leftEnd), rootNode);

    insert_right(createRootNode(string, rightStart, rightEnd), rootNode);

    return rootNode;
}