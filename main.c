#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "binary-tree.h"

int main(int argc, char const *argv[])
{
    t_binary_tree* tree = create_tree();
    
    t_node* node_a = create_node('A');
    t_node* node_b = create_node('B');
    t_node* node_c = create_node('C');
    t_node* node_d = create_node('D');
    t_node* node_e = create_node('E');
    t_node* node_f = create_node('F');
    t_node* node_g = create_node('G');
    t_node* node_h = create_node('H');
    t_node* node_i = create_node('I');
    t_node* node_j = create_node('J');

    tree->root = node_a;
    insert_left(node_b, node_a);

    insert_left(node_d, node_b);
    insert_right(node_e, node_b);

    insert_left(node_h, node_d);

    insert_right(node_c, node_a);

    insert_left(node_f, node_c);
    insert_right(node_g, node_c);

    insert_left(node_i, node_g);
    insert_right(node_j, node_g);

    printf("\npre:\n");
    pre_order(tree->root);

    printf("\nin:\n");
    in_order(tree->root);

    printf("\nin right:\n");
    in_order_right(tree->root);

    printf("\npost:\n");
    post_order(tree->root);

    printf("\npost right:\n");
    post_order_right(tree->root);

    int h = height(tree);
    printf("\naltura: %d\n", h);

    print(tree);

    destroy_tree(tree);

    char* inputs[] = {
        "(A,(),())",
        "(A,(B,(),()),())",
        "(A,(),(C,(),()))",
        "(A,(B,(),()),(C,(),()))",
        "(A,(B,(D,(),()),()),(C,(),()))",
        "(A,(B,(),()),(C,(),(F,(),())))",
        "(A,(B,(D,(),()),()),(C,(),()))",
        "(A,(B,(D,(),()),(E,(),())),(C,(F,(),()),(G,(),())))",
        "(A,(B,(E,(),()),()),(C,(),()))",                        
        "(A,(B,(),(E,(),())),(C,(),()))",                         
        "(A,(B,(D,(H,(),()),()),(E,(),())),(C,(F,(),()),(G,(),())))", 
        "(A,(B,(),()),(C,(D,(),()),(E,(F,(),()),())))",          
        "(A,(B,(C,(D,(),()),()),()),())",                        
        "(A,(),(B,(),(C,(),(D,(),()))))",                        
        "(A,(B,(C,(),()),()),(D,(),(E,(F,(),()),())))",          
        "(A,(B,(),(C,(D,(),()),())),(E,(F,(),()),(G,(),())))"    
    };

    int total_inputs = sizeof(inputs) / sizeof(inputs[0]);

    for (int i = 0; i < total_inputs; i++) {
        printf("Arvore %d:\n", i + 1);
        char* input = inputs[i];
        t_binary_tree* tree = createTree(input);
        print(tree);
        destroy_tree(tree);
    }
    return 0;
}
