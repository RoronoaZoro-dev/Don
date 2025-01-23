#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

struct node 
{ 
    char  info[20]; 
    struct node *left; 
    struct node *right; 
}; 
typedef struct node *NODEPTR; 

NODEPTR maketree(char word[]); 
void setleft(NODEPTR p, char word[]); 
void setright(NODEPTR p, char word[]); 
void intrav(NODEPTR p); 
void pretrav(NODEPTR p); 
void posttrav(NODEPTR p); 
void search(NODEPTR p, char key[]); 

int main() 
{ 
    NODEPTR ptree = NULL; 
    NODEPTR p, q; 
    char word[20], key[20]; 
    int opt; 
    do { 
        printf("\n1->CREATE DICTIONARY  2->TRAVERSE 3->SEARCH  4->EXIT "); 
        printf("\nEnter your option:"); 
        scanf("%d", &opt); 
        switch(opt) 
        { 
            case 1: 
                printf("\nEnter a word :"); 
                scanf("%s", word); 
                if (strcmp(word, "END") != 0) {
                    ptree = maketree(word); 
                    while(1) 
                    { 
                        printf("\nEnter a word(Type END to stop):"); 
                        scanf("%s", word); 
                        if(strcmp(word, "END") == 0) 
                            break; 
                        p = q = ptree; 
                        while(q != NULL) 
                        { 
                            if(strcmp(word, p->info) == 0) 
                                break; // duplicate, handle as needed
                            if(strcmp(word, p->info) < 0) 
                                q = p->left; 
                            else 
                                q = p->right; 
                            if (q != NULL)
                                p = q;
                        } 
                        if(strcmp(word, p->info) < 0) 
                            setleft(p, word); 
                        else 
                            setright(p, word); 
                    } 
                    printf("\n DICTIONARY CREATED SUCCESSFULLY"); 
                } else {
                    printf("\nCannot create empty dictionary!");
                }
                break; 
            case 2: 
                printf("\n PREORDER TRAVERSAL OF THE DICTIONARY IS:"); 
                pretrav(ptree); 
                printf("\n INORDER TRAVERSAL OF THE DICTIONARY IS:"); 
                intrav(ptree); 
                printf("\n POSTORDER TRAVERSAL OF THE DICTIONARY IS:"); 
                posttrav(ptree); 
                break; 
            case 3: 
                printf("\n Enter the key to search in the dictionary:"); 
                scanf("%s", key); 
                search(ptree, key); 
                break; 
            case 4: 
                printf("\nEXITING BINARY TREE"); 
                exit(0); 
            default:
                printf("\nInvalid option!");
        } 
    } while(opt != 4); 
    return 0;
} 

NODEPTR maketree(char w[]) 
{ 
    NODEPTR t = (NODEPTR)malloc(sizeof(struct node)); 
    if(t == NULL) 
    { 
        printf("\n Node allocation failed"); 
        exit(1); 
    } 
    strcpy(t->info, w); 
    t->left = t->right = NULL; 
    return t; 
} 

void setleft(NODEPTR p, char w[]) 
{ 
    if(p == NULL) 
        printf("Void Insertion"); 
    else if(p->left != NULL) 
        printf("Invalid Insertion"); 
    else 
        p->left = maketree(w); 
} 

void setright(NODEPTR p, char w[]) 
{ 
    if(p == NULL) 
        printf("Void Insertion"); 
    else if(p->right != NULL) 
        printf("Invalid Insertion"); 
    else 
        p->right = maketree(w); 
} 

void intrav(NODEPTR tree) 
{ 
    if(tree != NULL) 
    { 
        intrav(tree->left); 
        printf("%s\t", tree->info); 
        intrav(tree->right); 
    } 
} 

void pretrav(NODEPTR tree) 
{ 
    if(tree != NULL) 
    { 
        printf("%s\t", tree->info); 
        pretrav(tree->left); 
        pretrav(tree->right); 
    } 
} 

void posttrav(NODEPTR tree) 
{ 
    if(tree != NULL) 
    { 
        posttrav(tree->left); 
        posttrav(tree->right); 
        printf("%s\t", tree->info); 
    } 
} 

void search(NODEPTR tree, char key[]) 
{ 
    NODEPTR p = tree; 
    while(p != NULL) 
    { 
        int cmp = strcmp(key, p->info); 
        if(cmp == 0) 
        { 
            printf("\n Key %s is found in the dictionary", key); 
            return; 
        } 
        else if(cmp < 0) 
            p = p->left; 
        else 
            p = p->right; 
    } 
    printf("\n Key %s is not found in the dictionary", key); 
}
