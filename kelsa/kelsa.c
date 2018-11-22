#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<wchar.h>
#define M 50
#define K 100
#define W 10
#define S 1000


typedef struct meaning
{
char mean[M];
wchar_t Ktext [K];
} meaning;

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}
typedef struct trie
{
struct trie*  children [M];	
char word [W]; 
int hit ;
meaning * m;

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
	//printf("hello1");
	for(i=0;i<M&&temp->children[i]!=NULL&& strcmp(temp->children[i]->word,newword)!=0;i++)
			{
			//checking if it already exists if not then we inserting	 
setbuf(stdout, NULL);
//printf("hello3");			
			}
			//printf("%d",i);
			if (temp->children[i]==NULL) //inserting here do we call isnert instead ?
			{setbuf(stdout, NULL);
			printf("\ninserting new child%s",newword);
			trie * newnode = (trie *)malloc(sizeof(trie));
			strcpy(newnode->word,newword)  ;          
			temp->children[i]=newnode;
			temp->children[i]->hit ++;
			setbuf(stdout, NULL);
			//printf("hit%d",temp->children[i]->hit);
			}
			strcat (sentence," ");
			strcat (sentence,newword);
			where=temp->children[i];
			return i;
			
	
		
}

int  displaysuggestions(trie *where, char sentence[])
{
	trie * temp = where;
	//finding(temp);
	int cnt=1,op,i=0;
	int max1 =0;
	int max2 =0;
	int max3 =0;  //assuming integer elements in the array
        setbuf(stdout, NULL);
	//printf("suuuuugeeestions");
	
	for(i=0;i<M&& temp->children[i]!=NULL;i++)
			{
					//printf("l value :%d",i);
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
	//printf("hello2");
	setbuf(stdout, NULL);
	printf("suggestions\n");
	//printf("l valudsfsde :%d",i);
	if(i>0)                                                                                //so we display suggestions only if we get three but we should be able to handle lesser
	{
	if (i>2)
	{
	printf("1.%s\n",temp->children[max3]->word);
	printf("2.%s\n",temp->children[max2]->word);
	printf("3.%s\n",temp->children[max1]->word);
	setbuf(stdout, NULL);
	}
	else if (i==2)
	{
	printf("1.%s\n",temp->children[max3]->word);
	printf("2.%s\n",temp->children[max2]->word);
	setbuf(stdout, NULL);
	}
	else if (i==1)
	{
	printf("1.%s\n",temp->children[max3]->word);
	setbuf(stdout, NULL);
	}
	printf("select one\n");
	
	scanf ("%d",&op);
	//printf("option :%d",op);
	
	switch(op)
	{
		case 1 :	{
				strcat (sentence," ");
				strcat (sentence,temp->children[max3]->word);
				temp->children[max3]->hit ++; where=temp->children[max3];
				return max3;
				
			}break;
		case 2 : {
				strcat (sentence," ");
				strcat (sentence,temp->children[max2]->word);
				temp->children[max2]->hit ++;where=temp->children[max2];
				return max2;
				
			}break;
		case 3 : {
				strcat (sentence," ");
				strcat (sentence,temp->children[max1]->word);
				temp->children[max1]->hit ++;where=temp->children[max1];
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
char m;
int y,o,l=0,pos;
char z; //checks space
trie*prev;
trie * where=kannada;
char sentence [S];


FILE *filePtr;
    char file[] = "input.txt";	//change to relevant filename
   char currword[30]; int ind=0;    char c;
    int i = 0;
  strcpy(currword,"");
//printf("currword%s",currword);

    if((filePtr = fopen(file, "r")) == NULL) {
        printf("\nError opening file!");
        getchar();
        exit(101);
    }
    printf("\nFile is opened for reading.\n");
	rewind(filePtr);
    while(!feof(filePtr)) {
			c = fgetc(filePtr);	
			//printf("%c",c);
      			 if(c!=' ' && c!='\n' ) {
            			//currword[ind]=c;
            			//ind++;
			append(currword,c);
			//printf("currword%s",currword);
           		 }
			if(c=='\n')
			{ //currword[ind]='\0';
			//printf("hihih");
			pos=nosuggestion(where,currword,sentence); //ind=0;
			where=kannada;
			//printf("new line");
			strcpy(currword,"");
			}
			else if (c==' ')
			{//currword[ind]='\0';
			  pos=nosuggestion(where,currword,sentence); //ind=0;
			where=where->children[pos];
			strcpy(currword,"");
			}
	}
    


do
{
where=kannada;
printf("enter your sentence word by word");
strcpy(sentence,"");
	do
	{
	prev=where;
	//	printf("\nsuggestions ? if not press 0"); on typing $ gives suggestions
	setbuf(stdout, NULL);
	

	setbuf(stdout, NULL);
	printf("enter new word");
	scanf("%s",w);
	pos=nosuggestion(where,w,sentence);
	setbuf(stdout, NULL);
	//printf("Do You Want To Continue Entering Words in this sentence? 0-stop ");
	where=where->children[pos];
	setbuf(stdout, NULL);
	scanf("%c",&z);
	if(z=='\n')
	{
	setbuf(stdout, NULL);
	printf("do you want suggestion or are you terminating the sentence press 1-to continue the same sentence 0-to terminate");
	scanf("%d",&y);
	if(y)
	{
	pos=displaysuggestions(where,sentence);
	where=where->children[pos];
	}
	}
	else 
	{
	y=1; 
	setbuf(stdout, NULL);
	//printf("dollar was pressed");
	}
	printf("Your Sentence so far %s\n",sentence);
	}while(y);
setbuf(stdout, NULL);
if (where->m==NULL)
{
	setbuf(stdout, NULL);
	printf("%s",where->word);
	meaning * n=(meaning *)malloc(sizeof(meaning));
	printf("\nEnter meaning");
	setbuf(stdin, NULL);
 	scanf("%[^\n]",n->mean); 
	where->m=n;
	setbuf(stdout, NULL);
	//printf("\nEnter Kannada Script");
	printf("%s",where->m->mean);
	setbuf(stdin, NULL);
	setbuf(stdin, NULL);
 	//fgetws(n->Ktext,100,stdin); 	 	
}
else 
{
	printf("Meaning In English");
	setbuf(stdout, NULL);
	printf("\n%s\n",where->m->mean);

}

setbuf(stdout, NULL);
//strcpy(prev->children[pos]->m,sentence);
setbuf(stdout, NULL);
printf("Do You wanna Enter another sentence?0-stop");
scanf("%d",&o);
}while(o);

return 0;

}
