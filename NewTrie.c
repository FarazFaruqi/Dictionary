#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PossibleWords.h"

void insert(Node* head,char item[]);
Node* getNode();
bool isPresent(Node*, char[]);

int main()
{
	char* str = NULL;
	char st[50];
	int i,j,size;
	Node* trie  = getNode();

	printf("Loading the words\n");

	FILE* fp = fopen("/home/Faraz/Desktop/C C++ Programs/large","r");
    if(fp == NULL)
    	printf("NULL\n");
    else
    {
    	printf("Entering the loop\n");  
	    
	    for(;;)
	    {
	    	//printf("Inside loop\n");
	    	if(fscanf(fp,"%s",st)!=1)
	    	{
	    		printf("End of line reached\n");
	    		break;
	    	}

	    	printf("%s\n",st);
	        insert(trie,st);
	       // printf("Inserted\n");
	    }
	}
    char s[50];
	bool res = FALSE;
	printf("Enter the string\n");
	scanf("%s",s);
	printf("\n\n");
	//Permute(s,0,strlen(s),trie);
	int length = strlen(s);
	char* fin = malloc(sizeof(char) * strlen(s));
	//for(j = 0;j < length;j++)
	//{
	//	fin[j] = s[j];
		Permute(fin,0,j+1,trie);
    //}
	printf("Printed all the permutations possible\n");

	return 0;

}

Node* getNode()
{
	Node* ptr = (Node*)malloc(sizeof(Node));
	int i;
	ptr->isWord = FALSE;
	for(i = 0;i < 26;i++)
		ptr->next[i] = NULL;
	return ptr;
}

void insert(Node* head,char item[])
{
	int length = strlen(item);
	int i,index;
	for(i = 0;i < length;i++)
	{
		if(!isalpha(item[i]))
			break;
		index = GiveIndex(item[i]);
		if(head->next[index] == NULL)
			head->next[index] = getNode();

		head = head->next[index];
	}
	head->isWord = TRUE;
}

bool isPresent(Node* head,char item[])
{
	if(head == NULL)
		return FALSE;
	int length = strlen(item);
	int i;
	int index;
	for(i = 0;i < length;i++)
	{
		index = GiveIndex(item[i]);
		if(head->next[index] == NULL)
		return FALSE;
		head = head->next[index]; 
	}
	return (head->isWord && head!=NULL);
}