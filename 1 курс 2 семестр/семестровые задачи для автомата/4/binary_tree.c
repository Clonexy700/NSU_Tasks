#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    char word[200];
    struct node *left;
    struct node *right;
}Node;

Node* create_node(char* word){
    Node* tmp =(Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    strcpy(tmp->word,word);
    return tmp;
}

void add_node(Node** tree,char* word){
    if ((*tree) == NULL){
        (*tree) = create_node(word);
        return;
    }
    Node *tmp = (*tree);
    int compare;
    while (0==0){
        compare = strcmp(word,tmp->word);
        if (compare == 0)
            return;
        else if (compare>0){
            if (tmp->right == NULL){
                tmp->right = create_node(word);
                return;
            }
            else{
                tmp = tmp->right;
                continue;
            }
        }
        else{
            if (tmp->left == NULL){
                tmp->left = create_node(word);
                return;
            }
            else{
                tmp = tmp->left;
                continue;
            }
        }
    }
}

void delete_node(Node** tree){
    Node* tmp = (*tree);
    if (tmp->left == NULL && tmp->right == NULL)
        (*tree) = NULL;
    if (tmp->left == NULL && tmp->right != NULL)
        (*tree) = tmp->right;
    if (tmp->left != NULL && tmp->right == NULL)
        (*tree) = tmp->left;
    if (tmp->left != NULL && tmp->right != NULL){
        Node* a = tmp->right;
        while (a->left != NULL)
            a = a->left;
        a->left = tmp->left;
        (*tree) = tmp->right;
    }
    free(tmp);
}

void delete_by_key(Node** tree,char* word){
    if ((*tree) == 0)
        return;
    if (strcmp(word,(*tree)->word) == 0){
        delete_node(tree);
        return;
    }

    int compare;
    while (0==0){
        compare = strcmp(word,(*tree)->word);
        if (compare == 0){
            delete_node(tree);
            return;
        }

        else if (compare>0){
            if ((*tree)->right == NULL)
                return;
            else{
                tree = &((*tree)->right);
                continue;
            }
        }
        else{
            if ((*tree)->left == NULL)
                return;
            else
            {
                tree = &((*tree)->left);
                continue;
            }
        }
    }
}

int amount(Node* tree){
    if (tree == NULL)
        return 0;
    else return 1 + amount(tree->left) + amount(tree->right);
}

void output(Node* tree, int level, int current){
    if (tree == NULL)
        return;
    if (level == current){
        printf("%s ",tree->word);
        return;
    }
    output(tree->left,level,current+1);
    output(tree->right,level,current+1);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Node *tree = NULL;
    int text=0,delete_ind=0,level=0;
    char tmp[200];
    while (scanf("%s",&tmp)!= EOF){
        if (strcmp(tmp,"TEXT:")==0)
            text = 1;
        else if (strcmp(tmp,"DELETE:")==0){
            text = 0;
            delete_ind = 1;
        }
        else if (strcmp(tmp,"LEVEL:")==0){
            break;
        }
        else if (text)
            add_node(&tree,tmp);
        else if (delete_ind)
            delete_by_key(&tree,tmp);
    }
    scanf("%d",&level);
    printf("%d\n", amount(tree));
    output(tree,level,0);
    return 0;
}
