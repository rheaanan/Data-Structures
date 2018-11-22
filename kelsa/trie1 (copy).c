#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#define M 50
#define W 10
#define S 1000
typedef struct trie
{
struct trie*  children [M];	
char word [W]; 
int hit ;
char meaning [S];
} trie;


/*void insertnewword (trie * where, char word [])
{
	int i;
	
		trie * newnode = (trie *)malloc(sizeof(trie));
		strcpy(newnode->word,word)               //nothing different here na ?
		trie temp=where;
		for(i=0;i<M&& strcmp(temp->children[i]->word,"")!=0;i++)
			{
							
			}
			
			temp->children[--i]=newnode;
	
}*/

int nosuggestion (trie * where, char newword [],char sentence [])
{
	
	int i ;
	trie* temp=where;
	setbuf(stdout, NULL);
	printf("hello1");
	for(i=0;i<M&&temp->children[i]!=NULL&& strcmp(temp->children[i]->word,newword)!=0;i++)
			{
			//checking if it already exists if not then we inserting	 
setbuf(stdout, NULL);
printf("hello3");			
			}
			if (temp->children[i]==NULL) //inserting here do we call isnert instead ?
			{
			trie * newnode = (trie *)malloc(sizeof(trie));
			strcpy(newnode->word,newword)  ;          
			temp->children[i]=newnode;
			temp->children[i]->hit ++;
			setbuf(stdout, NULL);
			printf("hit%d",temp->children[i]->hit);
			}
			strcat (sentence," ");
			strcat (sentence,newword);
			return i;
			
	
		
}

int  displaysuggestions(trie *where, char sentence[])
{
	trie * temp = where;
	//finding(temp);
	int cnt=1,op,i;
	int max1 =0;
	int max2 =0;
	int max3 =0;  //assuming integer elements in the array

	printf("hello1");
	for(i=0;i<M&& temp->children[i]!=NULL;i++)
			{
				    if (temp->children[i]->hit > max1)
				    {
					max3 = max2; max2 = max1; max1 = i;
				    }
				    else if (temp->children[i]->hit > max2)
				    {
					max3 = max2; max2 = i;
				    }
				    else if (temp->children[i]->hit > max3)
				    {
					max3 = i;
				    }
					
			}
	printf("hello2");
	printf("suggestions\n");
	if(i>3)                                                                                //so we display suggestions only if we get three but we should be able to handle lesser
	{printf("1.%s\n",temp->children[max3]->word);
	printf("2.%s\n",temp->children[max2]->word);
	printf("3.%s\n",temp->children[max1]->word);
	setbuf(stdout, NULL);
	printf("select one\n");
	
	scanf ("%d",&op);
	printf("option :%d",op);
	switch(op)
	{
		case 1 :	{
				strcat (sentence," ");
				strcat (sentence,temp->children[max3]->word);
				temp->children[max3]->hit ++;
				return max3;
				
			}break;
		case 2 : {
				strcat (sentence," ");
				strcat (sentence,temp->children[max2]->word);
				temp->children[max2]->hit ++;
				return max2;
				
			}break;
		case 3 : {
				strcat (sentence," ");
				strcat (sentence,temp->children[max1]->word);
				temp->children[max1]->hit ++;
				return max1;
			}break;
		default:printf("wrong key");
	}
	}
	
}


int main ()
{
trie * kannada =(trie *)malloc(sizeof(trie));
char w[S];
int y,o,l,pos;
trie*prev;
trie * where=kannada;
char sentence [S];
do
{
printf("enter your sentence word by word");
strcpy(sentence,"");
	do
	{
	prev=where;
	strcpy(kannada->word,"start");
	printf("\nsuggestions ? if not press 0");
	setbuf(stdout, NULL);
	scanf("%d",&l);
	if(l)
	pos=displaysuggestions(where,sentence);
	else
	{
	setbuf(stdout, NULL);
	printf("enter new word");
	scanf("%s",w);
	pos=nosuggestion(where,w,sentence);
	setbuf(stdout, NULL);
	}
	setbuf(stdout, NULL);
	printf("Do You Wanna Continue Entering Words in this sentence? 0-stop ");
	where=where->children[0];
	scanf("%d",&y);
	printf("Your Sentence so far %s\n",sentence);
	}while(y);

printf("Do You wanna save the meaning ?");
scanf("%s",sentence);
setbuf(stdout, NULL);
printf("%s",prev->children[pos]->word);
//strcpy(prev->children[pos]->meaning,sentence);
printf("Do You wanna Enter another sentence?0-stop");
scanf("%d",&o);
}while(o);

return 0;

}
