#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct arrayAdt
{
    int lastIndex;
    int capacity;
    int *ptr;
};
// Function declaration
struct arrayAdt* createArray(int capacity);
int getItem(struct arrayAdt *, int index);
int setItem(struct arrayAdt *, int index, int value);
int editItem(struct arrayAdt *, int index, int newvalue);
int countItem(struct arrayAdt *);
int removeItem(struct arrayAdt *, int index);
int searchItem(struct arrayAdt *, int item);
void sotrItem(struct arrayAdt *);
// Function Defination

// Ceate Function: it is function to create the Array
struct arrayAdt *createArray(int capacity)
{
    struct arrayAdt *arr;
    arr = (struct arrayAdt*)malloc(sizeof(struct arrayAdt));
    arr->capacity = capacity;
    arr->lastIndex = -1;
    arr->ptr = (int*)malloc(arr->capacity 
    * sizeof(int));
    return (arr);
}

// GET function : To get data from the Array
int getItem(struct arrayAdt *arr, int index)
{
    if (arr->lastIndex < index || index < 0)
    {
        printf("Invalid Index");
        return (-1);
    }
    else
    {
        return (arr->ptr[index]);
    }
}

// Set Function: it is function to  set the value in  array
int setItem(struct arrayAdt *arr, int index, int value)
{
    if (arr->lastIndex == arr->capacity - 1)
    {
        printf("overFlow");
        return (0);
    }
    if (index < 0 || index > arr->lastIndex + 1)
    {
        printf("Invalid Index");
        return (0);
    }

    if (index <= arr->lastIndex)
    {
        arr->lastIndex = arr->lastIndex + 1;
        int i = arr->lastIndex;
        while (i != index)
        {
            arr->ptr[i] = arr->ptr[i - 1];
            i--;
        }
        arr->ptr[index] = value;
        return (1);
    }
    if (index == arr->lastIndex + 1)
    {
        arr->lastIndex = arr->lastIndex + 1;
        arr->ptr[arr->lastIndex] = value;
        return (1);
    }
}
int editItem(struct arrayAdt *arr,int index, int newValue)
{
    if (index < 0 || index > arr->lastIndex)
    {
        printf("Invalid Index");
        return (0);
    }
    else
    {
        arr->ptr[index] = newValue;
        return (1);
    }
}
int countItem(struct arrayAdt *arr)
{
    return (arr->lastIndex + 1);
}
int removeItem(struct arrayAdt *arr, int index)
{

    if (index < 0 || index > arr->lastIndex)
    {
        printf("Invalid Index");
        return (0);
    }
    if (index == arr->lastIndex)
    {
        arr->lastIndex = arr->lastIndex - 1;
        return (1);
    }
    if (index < arr->lastIndex)
    {
        int i = index;
        while (i < arr->lastIndex)
        {
            arr->ptr[i] = arr->ptr[i + 1];
            i++;
        }
        arr->lastIndex = arr->lastIndex - 1;
        return (1);
    }
}
int searchItem(struct arrayAdt *arr, int item)
{
    if (arr->lastIndex == -1)
    {
        return (-1);
    }
    for (int i = 0; i <= arr->lastIndex; i++)
    {
        if (arr->ptr[i] == arr->ptr[item])
        {
            return (i);
        }
        else
        {
            return (-1);
        }
    }
}
void sotrItem(struct arrayAdt *arr)
{
    for (int i = 0; i < arr->lastIndex-1; i++)
    {
        int flag = 0;
        for (int j = 0; j < arr->lastIndex - 1 - i; j++)
        {
            if (arr->ptr[j] > arr->ptr[j + 1])
            {
                int temp = arr->ptr[j];
                arr->ptr[j] = arr->ptr[j + 1];
                arr->ptr[j + 1] = temp;
                flag = 1;
            }
            if (flag == 0)
            {
                break;
            }
        }
    }

}

int main(){
     
    struct arrayAdt *arr;
    arr = createArray(5);
    setItem(arr,0,10);
    setItem(arr,1,20);
    setItem(arr,2,30);
    setItem(arr,3,40);
    setItem(arr,4,50);

     for (int i = 0; i < countItem(arr); i++)
     {
         printf("%d ", getItem(arr,i));
     }
     return 0;

    
}