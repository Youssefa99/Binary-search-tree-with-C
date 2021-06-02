#include <stdio.h>
#include <stdlib.h>
typedef struct{
char var[100];
char value[100];
}data;

struct node{
        char var[100];
        char value[100];
        struct node *left;
        struct node *right;
        struct node *parent;
  };
struct node *root = NULL;

struct node * createNode(char word[],char value[]) {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        strcpy(newnode->var, word);
        strcpy(newnode->value,value);
        newnode->left = newnode->right = newnode->parent= NULL;
        return newnode;
  }
  int put(char var[], char value[]) {
        struct node *parent = NULL, *current = NULL, *newnode = NULL;
        int rest = 0;
        int cmp = 0;
        if (!root) {
                root = createNode(var,value);
                return 0;
        }
        for (current = root; current !=NULL;
           current = (cmp > 0) ? current->right : current->left) {
                rest = strcasecmp(var, current->var);
                cmp = strcasecmp(value,current->value);
                if (rest == 0) {
                        if(strcasecmp(value,current->value) != 0){
                        strcpy(current->value,value);

                        return 1;
                        }else{
                        return 0;
                        }
                }
                parent = current;
        }
        newnode = createNode(var,value);
        cmp > 0 ? (parent->right = newnode) : (parent->left = newnode);
        newnode->parent=parent;
        return 0;
  }
  int build_UnBalanced(data d[],int size){
     int ret;
     int check = 0;
      for(int i = 0; i < size ; i++){
        ret = put(d[i].var,d[i].value);
        if(ret == 1)
            check = 1;
      }
      return check;

}
void inOrder(struct node* root){
if(root == NULL)
    return;
inOrder(root->left);
printf("%s  =  %s\n",root->var,root->value);
inOrder(root->right);
}
int main()
{
  char var[100];
    char val[100];
    data d[100];
    int dec = 0;
    int sign = 0;
    int size = 0;
    char str;
    FILE* fptr;
    char* filename = "src.txt";
    fptr = fopen(filename,"r");

    if(fptr == NULL)
        printf("Could not open file");

   // while(!feof(fp)){
     //   fscanf("%[^=],%s",&var, &val);
    //}
  //  printf("yen3al deen omak \n");
while(!feof(fptr)){
    //    printf("kosom 2erayet el file\n");
fscanf(fptr, " %[^=]s  ", &d[size].var );
//printf("var name: %s",d[size].var);
fscanf(fptr, " %[^\n]s", &val);
strcpy(d[size].value,&val[2]);
//printf("\n var value: %s",d[size].value);
size++;
}
  // fscanf(fptr, " %[^=]s %[^\n]s ", &var, &val );
//printf("kosomeen 2omak yabn el 3ars");
    fclose(fptr);

    //printf("kosom el a5tara3 el c");
size = size - 1;
int check;
    //strcpy(d.value,&val[2]);
//printf("%d\n",size);
  for(int j = 0 ; j < size ; j++){
  printf("%s",d[j].var);
  printf("%s \n",d[j].value);
  }
  check = build_UnBalanced(d,size);
  printf("value of check is %d\n",check);
  while(check == 1){
        printf("gowa el while\n");
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            if(strcmp(d[i].var,d[j].var) == 0 && i != j){
                strcpy(d[i].value,d[j].value);
            }
        }

    }
    printf("2nd build of tree:\n");
    for(int k = 0 ; k < size ; k++){
        printf("%s--------------%s\n",d[k].var,d[k].value);
    }
    root = NULL;
    check = build_UnBalanced(d,size);
  }
  struct node* current = root;
  inOrder(current);


    return 0;
}
