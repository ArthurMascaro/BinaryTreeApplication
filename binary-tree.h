#ifndef BYNARYTREE_H
#define BYNARYTREE

typedef struct _node {
    char item;
    struct _node* left;
    struct _node* right;
} t_node;

typedef struct {
    t_node* root;
} t_binary_tree;

t_binary_tree* create_tree();
t_node* create_node(char item);
void insert_right(t_node* node, t_node* parent_node);
void insert_left(t_node* node, t_node* parent_node);
void pre_order(t_node* root_node);
void in_order(t_node* root_node);
void in_order_right(t_node* root_node);
void post_order(t_node* root_node);
void post_order_right(t_node* root_node);
void destroy_tree_rec(t_node* node);
void destroy_tree(t_binary_tree* tree);
int height(t_binary_tree* tree);
int height_rec(t_node*, int height);
int height_2(t_binary_tree* tree);
int height_rec_2(t_node*);
void print(t_binary_tree* tree);
int print_rec(t_node* node, int height);
int getEndBracketIndex(char* string, int start);
t_binary_tree* createTree(char* string);
t_node* createRootNode(char* string, int start, int end);
#endif