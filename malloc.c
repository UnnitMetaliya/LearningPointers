/*
	Title: Dynamic Memory Allocation in C using Pointer (taking LinkedList as an example).

	Author Details:
	Name: Unnitkumar Metaliya
	StudentID: 104702352
	UserID: metaliy

	Date Created: 11/02/2017
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//Declaring Self-Referential Structure
struct node
{
	int value;
	struct node *ptrNext;
};

//Function Prototypes

struct node *InputNumberByUser(struct node *ptrNew);

void InsertNumber(struct node *ptrNew);

void FreeList(struct node *ptrF);

void DisplayList(struct node *ptrF);


//Declaring Global variables which will be used in almost every function
struct node *ptrFirst = NULL;
struct node *ptrLast = NULL;

//a main function for final interpretation
int main()
{
	int num,i;
	struct node *ptrArg; //needed because 'InputNumberByUser' is function with argument
	clrscr();

	//asking user for numbers of inputs
	printf("How many elements you are planning to enter?");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		InsertNumber(InputNumberByUser(ptrArg)); //this function will run for user specified 'num' times
	}


	//Displaying The List..
	DisplayList(ptrFirst);

	//Freeing the Memory..
	FreeList(ptrFirst);

	ptrFirst=NULL;
	ptrLast=NULL;

	/*Now Technically if we run DisplayList() again then it should print numbers again. Right? But logically it will not because memory has been freed */
	DisplayList(ptrFirst); //This is just for the sake of explanation that it will not print the list again.
	getch();
	return 0;

}

//A function for taking input from user
struct node* InputNumberByUser(struct node *ptrNew)
{
	int num,i;

	//Dynamic Memory allocation
	ptrNew = (struct node*)(malloc(sizeof(struct node)));

	scanf("%d",&ptrNew->value);
	ptrNew->ptrNext = NULL;

		return ptrNew;
}


//Inserting Numbers in LinkedList
void InsertNumber(struct node *ptrNew)
{
	if(ptrFirst == NULL)
	{
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
	}
	else

	{
		ptrLast->ptrNext=ptrNew;
		ptrLast = ptrNew;
	}
}

//A Function for freeing the memory
void FreeList(struct node * ptrF)
{
	if (ptrF == NULL)
		return;
	else
	{
		//Dynamic Memory Deallocation
		FreeList(ptrF->ptrNext);
		free(ptrF);
	}
}

//Displaying the produced list
void DisplayList(struct node * ptrF)
{
	if(ptrF == NULL)
		return;
	else
	{
		//Unlike array, it will check for value at every next address and print it accordingly.
		printf("%d",ptrF->value);
		DisplayList(ptrF->ptrNext);
	}
}
