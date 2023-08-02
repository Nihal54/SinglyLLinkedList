/*
Name - Nihal Juber Sayyad
Code- SinglyLinierLinkedList


Description- Code Contins 8 functions which do do different operatios;
1) InsertFirst()
2) InsertLast()
3) DeleteFirst()
4) DeleteLast()
5) InsertAtPos()
6) DeleteAtPos()
7) Display()
8) Count()

*/

#include<stdio.h>
#include<stdlib.h>


struct Node
{

    int Data;
    struct Node *Next;
};
//simplyfying the code using typedef
typedef struct Node NODE ;  //NoPointr
typedef struct Node* PNODE; //Onepointer
typedef struct Node** PPNODE; //twoPointer;



/*
InsertFirst Function -- this function is used to insert node at starting position
it takes two parameters (PPNODE, No) PPNODE= modifiying node , No= Value of node 
*/

void InsertFirst(PPNODE Head , int No)
{


    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));// Allocate memory dynamicallly

    newn->Next = NULL;
    newn ->Data = No;

//If Linkedlist is Empty
    if(*Head == NULL)
    {
        *Head = newn;           
    }

//if linkedlist is not empty
    else
    {
        newn->Next = *Head;
       *Head = newn;
    }



}


//Insert last is used to insert node  at last position

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->Next = NULL;
    newn->Data = No;



    //if LL is empty;

    if(*Head == NULL)
    {
        *Head = newn;

    }

    else
    {
        //ll contains more than one node


        while(temp->Next!= NULL)
        {
            temp = temp->Next;

        }
        temp->Next =newn;

    }

    
}


void DeleteFirst(PPNODE Head)
{

    PNODE temp = *Head;

    //If linked list is empty
    if(*Head == NULL)
    {
        return;
    }
    //if Linkedlist Contains only one node
    if((*Head)->Next == NULL)
    {

        free(*Head);
        *Head = NULL;
    }

    else

    //if linked list contain more than one node
    {
       *Head = temp->Next;
       free(temp);
    }

    
}

void DeleteLast(PPNODE Head)
{

    PNODE temp = *Head;


    /// if LL is Empty 
    if(*Head == NULL)

    {
        return ;
    }

    // If LL contains only one node

    else if((*Head)->Next == NULL)

    {
         free(*Head);
        *Head = NULL;
       

    }

    else
    {

        while((temp)->Next->Next != NULL)
        {
            temp = temp->Next ;


        }
        free(temp->Next);
        temp->Next = NULL;


    }
}

void Display(PNODE Head)
{

    while(Head != NULL)
    {
        printf("|%d|->",Head->Data);
        Head = Head->Next;

    }
    printf("NULL\n");



}

int Count(PNODE Head)
{

    int iCnt = 0;
    while(Head != NULL)
    {
        iCnt++;
        Head=Head->Next;
    }
    return iCnt;
}

void InsertAtPos(PPNODE Head, int No, int iPos)
{

    PNODE newn = NULL;
    PNODE temp  = *Head;
    int iCnt = 0;
    int iLength = 0;
    iLength = Count(*Head);


    //Filters

    if((iPos<1) || (iPos >iLength) || (iPos > iLength +1)) 
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {

        InsertFirst(Head,No);
    }
    else if(iPos  == iLength+1)
    {
        InsertLast(Head , No);

    }

    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->Next =NULL;
        newn->Data = No;
        
        
        for(iCnt = 1; iCnt <iPos-1; iCnt++)
        {
            temp = temp ->Next;
        }
        newn->Next = temp->Next;
        temp->Next = newn;
        

    }



}
void DeleteAtPos(PPNODE Head, int iPos)
{
    PNODE temp = *Head;
    PNODE tempX = NULL;
    int iLength = 0;
    iLength = Count(*Head);


    //Filter
    
        if(iPos<1 || iPos> iLength || iPos > iLength +1)
        {

            printf("Invalid Position");
        }
        if(iPos ==1)
        {
            DeleteFirst(Head);

        }
        else if (iPos ==iLength+1)
        {
            DeleteLast(Head);

        }
    else
    {


    for(int iCnt  = 1; iCnt < iPos-1; iCnt++ )
    {
        temp = temp->Next;
    }
    tempX = temp->Next;
    temp->Next =tempX->Next;

    free(tempX);
    }


}
int main()
{


    int iRet = 0;
    PNODE First = NULL;

    InsertFirst(&First, 11);
    InsertFirst(&First, 21);
    InsertFirst(&First, 51);
    InsertFirst(&First, 71);
    InsertFirst(&First, 81);
    Display(First);
    iRet = Count(First);

    printf("Count Of Node after insert first is in LinkedList: %d\n",iRet);
    InsertLast(&First, 101);
    
    Display(First);
    iRet = Count(First);

    printf("Count Of Node after insert Last is in LinkedList: %d\n",iRet);
    DeleteFirst(&First);
    Display(First);
    iRet = Count(First);

    printf("Count Of Node after Delete first is in LinkedList: %d\n",iRet);
    
    DeleteLast(&First);
    Display(First);
    iRet = Count(First);

    printf("Count Of Node after Delete Last is in LinkedList: %d\n",iRet);
    InsertAtPos(&First,100,1);
    Display(First);
    iRet = Count(First);

    printf("Count Of Node after Insert AT Position is in LinkedList: %d\n",iRet);
    
    DeleteAtPos(&First,2);
    Display(First);
    iRet = Count(First);

    printf("Count Of Node after Delete AT Position is in LinkedList: %d\n",iRet);
    return 0;


}