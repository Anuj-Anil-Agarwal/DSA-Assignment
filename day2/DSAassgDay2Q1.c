
//Write the program for deleting an element from the beginning and from any position.


#include <stdio.h>
int Array[10]={10,20,30,40,50,60,70,80,90,100};
int n=10;


void delBeg()
{
    int i,temp=Array[0];
    if(n<=0)
    {
         printf("\n Array is empty");
    }
    else
    {    
        for(i=1;i<n;i++)
            Array[i-1]=Array[i];
        Array[i-1]=0;
        --n;

        printf("\n %d is deleted successfully ",temp);
    }
}

void delPos(int pos)
{
    int i,temp=Array[pos];
    
    if(n<=0)
    {
         printf("\n Array is empty");
    }
    else
    {
        for(i=pos;i<n;i++)
            Array[i-1]=Array[i];
        Array[i-1]=0;
        --n;

        printf("\n %d is deleted successfully ",temp);
    }
}


void displayArray()
{
    int i;
    if(n<=0)
    {
         printf("\n Array is empty");
    }
    else
    {
        printf("\n Elements of Array are \n");
        for(i=0;i<n;i++)
            printf(" %d ",Array[i]);
    }
}
int main() {

   int pos;
   // Array[10]


    displayArray();
    
    //delete from beganing
    delBeg();
    printf("Updated Array \n");
    displayArray();

    //delete from any position
    printf("\n Enter the position from which you want to delete element ");
    scanf("%d",&pos);
    if(pos>n)
        printf("INVALID Input Enter between 1-10");
    else
        delPos(pos);
    
    displayArray();
    
    return 0;
}
