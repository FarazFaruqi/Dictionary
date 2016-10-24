/*This is the one that takes user input
Working good
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum{FALSE,TRUE}bool;

typedef struct node
{
	bool isWord;
	struct node* next[26];
}Node;

void insert(Node* head,char item[]);
int GiveIndex(char c);
Node* getNode();
bool isPresent(Node*, char[]);
int main()
{
	char str[20];
	int i,j,size;
	Node* trie  = getNode();
	printf("Enter the number of strings you want to enter\n");
	scanf("%d",&size);
	for(i = 0;i < size;i++)
	{
		printf("Enter the next word\n");
		scanf("%s",str);
		insert(trie,str);
	}
	bool res = FALSE;
	printf("Enter the number of searches\n");
	scanf("%d",&size);
	for(i = 0; i < size;i++)
	{
		printf("The word to be searched\t");
		scanf("%s",&str);
		res = isPresent(trie,str);	
		if(res)
			printf("This word is present\n");
		else
			printf("This word is not present\n");
	}
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

int GiveIndex(char c)
{
	if(c >= 'a' && c <= 'z')
		return ( (int)c - 'a');
	else if(c >= 'A' && c <= 'Z')
		return ((int)c - 'A');
	else
		return((int)c);
}

void insert(Node* head,char item[])
{
	int length = strlen(item);
	int i,index;
	for(i = 0;i < length;i++)
	{
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


