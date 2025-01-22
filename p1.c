#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr;
    int n, i,choice,pos,x,key,found=0;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));

    printf("Enter the elements");
    
    for(i=0;i<n;i++)
        scanf("%d",(arr+i));
    printf("The elements of the array are :\n");
    for(i=0;i<n;i++)
    {
        printf("*(arr+%d)=%d\n",i,*(arr+i));
    }	
    while(1)
    {
        printf("\n1-> INSERT  2-> DELETE   3-> SEARCH    4->EXIT\n");
        printf("Give your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                printf("Enter the element to be inserted:");
                scanf("%d",&x);
                printf("Enter the position to be inserted:");
                scanf("%d",&pos);
                n++;
                for (i=n-1; i>=pos; i--)
                    *(arr+i) = *(arr+i-1);
                *(arr+pos - 1) = x;
                printf("After insertion the elements of the array are :\n");
                for(i=0;i<n;i++)
                {
                    printf("*(arr+%d)=%d\n",i,*(arr+i));
                }
                break;

            case 2: 
                printf("Enter the position of the element to be deleted:");
                scanf("%d",&pos);
                for (i=pos; i<=n-1; i++)
                    *(arr+i-1) = *(arr+i);
                n--; 
                printf("After deletion the elements of the array are :\n");
                for(i=0;i<n;i++)
                {
                    printf("*(arr+%d)=%d\n",i,*(arr+i));
                }
                break;
            case 3: 
                found=0;
                printf("Enter the  element to be searched:");
                scanf("%d",&key);
                for (i=0; i<=n; i++)
                    if(*(arr+i)==key)
                    {
                        found=1;
                        printf("\n Search key %d is found at position %d",key,i+1);
                    }
                if(found==0)
                    printf("Search key %d is not found",key);
                break;
            case 4: exit(1);
        }
    }
}