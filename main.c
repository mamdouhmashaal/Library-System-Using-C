#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct books{
       int id;
       int quantity;
       char name[20];
        };
       struct books b[3];

void Add_a_book (void)
       { FILE *fpointer;
       int i=3;
       fpointer=fopen("library.txt","a");
       if (fpointer==NULL)
        printf("file could not be opened");
       else{
        printf("Please enter book id: \n ");
        scanf("%d",&b[i].id);
        fflush(stdin);
        printf("Please enter book quantity : \n");
        scanf("%d",&b[i].quantity);
        fflush(stdin);
        printf("Please enter book name :\n");
        gets(b[i].name);
        fprintf(fpointer,"%d\t",b[i].id);
        fprintf(fpointer,"%d\t",b[i].quantity);
        fprintf(fpointer,"%s\t",b[i].name);
       }
       fclose(fpointer);
       }

void delete_a_book(int y){

FILE *fpointer;
fpointer=fopen("library.txt","w");
if(fpointer == NULL)
    printf("file cannot be opened");
    else{
            int length=4;
        for(int i=0;i<length;i++){
            if(b[i].id==y){
                    char h[20];
                for(int x=i;x<length;x++){
                    b[x].id=b[x+1].id;
                    b[x].quantity=b[x+1].quantity;
                    strcpy(h,b[x].name);
                    strcpy(b[x].name,b[x+1].name);
                    strcpy(b[x+1].name,h);

                }
                length--;
            }
        }
        for(int i=0;i<length;i++){
        fprintf(fpointer,"%d\t%d\t%s\n",b[i].id,b[i].quantity,b[i].name);
        }
}
fclose(fpointer);


}

int linear_IDsearch(const struct books b[],int size,int ID,int strt ){

    FILE *fpointer;
    fpointer=fopen("library.txt","r");
    if (fpointer==NULL){
        printf("Not found \n");
    }
    else{
    if (strt<size&&b[strt].id==ID){
        printf("%s\t%s\t%s\n","id","quantity","name");
        printf("%d\t%d\t%s\n",b[strt].id,b[strt].quantity,b[strt].name);
        return 1;
    }
    else{
        linear_IDsearch(b,size,ID,strt+1);
    }
}
fclose(fpointer);
}
int srch_byname(char src_name[20]){
    int o=0;
    for (int p=1;p<3;p++){
    for( int i=0;i<3-p;i++){
             int temp;
             char x[20];
            if(strcmp(b[i].name,b[i+1].name)>0){
                    temp=b[i].id;
                    b[i].id=b[i+1].id;
                    b[i+1].id=temp;
                    temp=b[i].quantity;
                    b[i].quantity=b[i+1].quantity;
                    b[i+1].quantity=temp;
                    strcpy(x,b[i].name);
                    strcpy(b[i].name,b[i+1].name);
                    strcpy(b[i+1].name,x);
            }
    }
}
      int low=0;
      int mid;
      int high=2;
    while (low<=high){
        mid=(low+high)/2;
        if (strcmp(src_name,b[mid].name)==0){
                o++;
            printf("%s\t%s\t%s\n","id","quantity","name");
            printf("%d\t%d\t%s\n",b[mid].id,b[mid].quantity,b[mid].name);
            return 1;
        }
        else if (strcmp(src_name,b[mid].name)==1){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    } if(o==0)
    {
        printf("Not Found \n");
    }

   return 0;
}

void display_Sbooks(void){
  printf("%s\t\t%s\t\t%s\t\n\n","Name","ID","Quantity");
  for (int p=1;p<3;p++){
 for( int i=0;i<3-p;i++){
             int temp;
             char x[20];
            if(strcmp(b[i].name,b[i+1].name)>0){
                    temp=b[i].id;
                    b[i].id=b[i+1].id;
                    b[i+1].id=temp;
                    temp=b[i].quantity;
                    b[i].quantity=b[i+1].quantity;
                    b[i+1].quantity=temp;
                    strcpy(x,b[i].name);
                    strcpy(b[i].name,b[i+1].name);
                    strcpy(b[i+1].name,x);
            }

    }
  }
     for(int i=0;i<3;i++){
            printf("%s\t\t%d\t\t%d\t\t\n\n",b[i].name,b[i].id,b[i].quantity);
            }

}

void display_ubooks(void){

FILE *fpointer;
fpointer = fopen("library.txt","r");
    int i=0;
    while((!feof(fpointer)) && (i<3) )
    {
     fscanf(fpointer,"%d",&b[i].id);
     fscanf(fpointer,"%d",&b[i].quantity);
     fgets(b[i].name,20,fpointer);
     printf("%d\t%d\t%s\n",b[i].id,b[i].quantity,b[i].name);
     i++;
    }
    fclose(fpointer);

}

int main()
{
int i =0;
char j;
FILE *fpointer;
fpointer = fopen("library.txt","r");
if(fpointer == NULL)
    printf("file cannot be opened");
else
{
    while((!feof(fpointer)) && (i<4) )
    {
     fscanf(fpointer,"%d",&b[i].id);
     fscanf(fpointer,"%d",&b[i].quantity);
     fscanf(fpointer,"%s",b[i].name);
     i++;
    }
    fclose(fpointer);
}
do{
    int number,k,x;
    char nme[20];
    printf("\n Welcome, Please choose ur operation \n Type (1) to add a book \n Type (2) to delete a book \n Type (3) to search by ID  \n Type (4) to search by name \n Type (5) to display the books sorted by name \n Type (6) to display the books unsorted \n :");
    scanf("%d",&number);
 switch(number){
 case 1:
    Add_a_book();
    break;
 case 2:
    printf("Please enter the ID of the book u want to delete \n");
    scanf("%d",&k);
    delete_a_book(k);
    break;
 case 3:
     printf("please enter the ID of the book u want to search about \n");
     scanf("%d",&x);
     linear_IDsearch(b,3,x,0);
     break;
 case 4:
    printf("Please enter the book name \n ");
    scanf("%s",nme);
    srch_byname(nme);
    break;
 case 5:
    display_Sbooks();
    break;
 case 6:
    display_ubooks();
    break;
 default:
    printf("ERROR, invalid operation \n");
    break;
 }
 printf("Do you want to do another operation? \n ");
 printf("Type (y) for another operation Or Type (n) to exit \n");
 scanf("%s",&j);

}
 while (j!='n');{

    return 0;
}
}
