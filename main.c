#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "binary-tree.h"

int main()
{
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
        "(A,(B,(),(C,(D,(),()),())),(E,(F,(),()),(G,(),())))",
        "(A,(B,(),()),(C,(F,(),()),(T,(),())))"    
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






// ( = 40
// ) == 41
// , = 44
