import java.util.*;
class board{

public static void main (String[]args)
{ 	int up=-map.S;
	int down=map.S;
	int left=-1;
	int right=1;
	int move;
	Scanner in = new Scanner (System.in);
	int p;
	map A = new map ();
	for ( p =1;p<=(map.S*map.S);p++)
	{
	move=p+ up+up+left; A.validate1(move,p) ;
	move=p+ up+up+right; A.validate1(move,p);
	move=p+ down+down+left;A.validate4(move,p);
	move=p+ down+down+right;A.validate4(move,p);
	move=p+left+left+down;A.validate3(move,p);
	move=p+left+left+up; A.validate2(move,p);
	 move=p+right+right+up;A.validate2(move,p);
	move=p+right+right+down;A.validate3(move,p);
	}
	A.display();
	System.out.println("Enter position:");
	p = in.nextInt();
	A.visit[p]=1;
	A.moves[1]=p;
	int y=0;

	do{
	   p=A.options(p);
	   }while(p!=0);

}
}
class map {
static int S=8;
static int movecount=2;
int [][]matrix=new int[(S*S)+1][S*S+1];
int []visit=new int [S*S+1];
int []moves=new int [S*S+1];
boolean win=true;

  int [][] a = new int[S][S];
void validate1(int m,int pos)
{
	int br=(pos/S)*S-S;
	if(pos%S==0)
    {
        br= br - S;
    }
	int bl=br-S;
		if (m<=br&&m>bl&&m>=1&&m<=S*S)
			{
				matrix[pos][m]=1;
				//matrix[m][pos]=1;
			}

}
 void validate2(int m,int pos)
{
	int br=(pos/S)*S;
	if(pos%S==0)
    {
        br= br - S;
    }
	int bl=br-S;
		if (m<=br&&m>bl&&m>=1&&m<=S*S)
			{
				matrix[pos][m]=1;
				//matrix[m][pos]=1;
			}


}
void validate3(int m,int pos)
{
	int br=(pos/S)*S+2*S;
	if(pos%S==0)
    {
        br= br - S;
    }
	int bl=br-S;
		if (m<=br&&m>bl&&m>=1&&m<=S*S)
			{System.out.println("pos and m "+m +pos);
				matrix[pos][m]=1;
				//matrix[m][pos]=1;
			}
}
void validate4(int m,int pos)
{
	int br=(pos/S)*S+3*S;
	if(pos%S==0)
    {
        br= br - S;
    }
	int bl=br-S;
		System.out.println(" m =  "+m +"p =  "+pos);
		if (m<=br&&m>bl&&m>=1&&m<=S*S)
			{
				matrix[pos][m]=1;
				//matrix[m][pos]=1;
			}
}
int options (int p )
{Scanner in = new Scanner (System.in);
	boolean op=false;
	for (int i =1;i<=S*S;i++)
	{
		if (matrix[p][i]==1&&visit[i]==0)
		{ System.out.println("option: " +i);op=true;}
		if ( movecount>64)
		 {finishGame();	} 

	}if ( op==false)
		{win = false ;finishGame();}
	System.out.println("enter choice ");
	int w = in.nextInt();

	if (matrix[p][w]==1)
		{ System.out.println("moved to " +w);visit[w]=1;moves[movecount++]=w;}
	else
		{System.out.print ("That was not a legal move ");win=false;finishGame();}
	return w;

}


void display ()
{
for (int i=0;i<=S*S;i++)
{
	System.out.print(i%10+ " ");
}System.out.println();
for (int i=1;i<=S*S;i++)
	{
		System.out.print(i%10+" ");
		for (int j=1;j<=S*S;j++)
		{
			System.out.print(matrix[i][j]+" ");
		}System.out.println();
	}
}
void finishGame()
{
	if (!win)
	System.out.println("You Lose");
	else
		{System.out.println("You Won ");
		System.out.println("Your moves");
		for (int i =1;i<moves.length; i++)
		{
			System.out.print(moves[i]+" ");
		}
		}
	System.exit(0);
}

}

