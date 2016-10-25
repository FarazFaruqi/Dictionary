typedef enum{FALSE,TRUE}bool;

typedef struct node
{
	bool isWord;
	struct node* next[26];
}Node;

void swap(char* a, char* b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int GiveIndex(char c)
{
	return(tolower(c) - 'a');
}


bool isAWord(char soFar[],Node* head)
{
	int i,index,length;
	length = strlen(soFar);
	for(i = 0;i < length;i++)
	{
		index = GiveIndex(soFar[i]);
		head = head->next[index];
	}
	return head->isWord;
}



bool Find(char str[],Node* head)
{
	Node* ref = head;
	//printf("I am again here\n");
	if(head == NULL)
	{
		printf("Dictionary is Empty\n");
		return FALSE;
	}
	int length = strlen(str);
		int i,index;
		//printf("I have reached the ultimate 1st char\n");
	for(i = 0;i < length;i++)
	{
		index = GiveIndex(str[i]);
		if(head->next[index] == FALSE)
		{
			printf("Word not found  %s\n",str);
			return FALSE;
		}
		head = head->next[index];
	}
	if (head == NULL)
		return FALSE;
	//printf("I have reached the ultimate char\n");
	for(i = 0;i < 26;i++)
	{
		if(head->next[i] != NULL)
			return TRUE;

	}
	return FALSE;
}

void Permute(char soFar[],int l,int r,Node* head)
{
	//printf("I am here\n");
	bool res;
	bool is;
	if(l == r)
	{
		is = isAWord(soFar,head);
		if(is)
			printf("%s\n",soFar);
		return;
	}
	else
	{
		res = Find(soFar,head);
		//printf("I have come out of this function\n");
		if(res == FALSE)
			return;
		int i;
		char temp;
		for(i = 0;i < r-l;i++)
			{
				swap(&soFar[l],&soFar[i]);
				Permute(soFar,l+1,r,head); 
				swap(&soFar[l],&soFar[i]);
			}
	}
}

