import java.awt.*;
import java.awt.event.*;
import java.applet.Applet;


import java.util.*;
class board{

public void function (String[]args)
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



public class TicTacToe extends Applet implements MouseListener 
{
    Frame f;
    int n,m,i=0;
    char ch[]=new char[65];
    
    
    
    public TicTacToe()         
    {
        f=new Frame("Knight's Tour");
        f.setLayout(null);
        f.setVisible(true);
        f.setSize(500,500);
        f.addMouseListener(this); 
        for(i=1;i<65;i++)
        ch[i]='U';

    }
    public void mouseClicked(MouseEvent e)
    {  
	Graphics g=f.getGraphics();
	g.drawLine(100,100,100,500);
        g.drawLine(150,100,150,500);
	g.drawLine(200,100,200,500);
	g.drawLine(250,100,250,500);
	g.drawLine(300,100,300,500);
	g.drawLine(350,100,350,500);
        g.drawLine(400,100,400,500);
	g.drawLine(450,100,450,500);
	g.drawLine(500,100,500,500);
   	
	g.drawLine(100,100,500,100);
        g.drawLine(100,150,500,150);
	g.drawLine(100,200,500,200);
	g.drawLine(100,250,500,250);
	g.drawLine(100,300,500,300);
	g.drawLine(100,350,500,350);
	g.drawLine(100,400,500,400);
	g.drawLine(100,450,500,450);
	g.drawLine(100,500,500,500);	
        int x=e.getX();
        int y=e.getY();
            g.setColor(Color.red);
	
           x=x-100;
	y=y-100;
		if ( x<50)
		{	m= 25;		
			find(y);	
			
		}
		else if ( x>50&& x<100)
		{	m= 75;		
			find(y);
			
		}
		else if ( x>100&&x<150)
		{	m= 125;		
			find(y);
			
		}
		else if ( x>150&&x<200)
		{	m= 175	;	
			find(y);
			
		}
		else if (x>200&& x<250)
		{	m= 225	;	
			find(y);
			
		}
		else if (x>250&& x<300)
		{	m= 275	;	
			find(y);
			
		}
		else if (x>300&&x<350) 
		{
			m=325;
			find(y);
			
		}
		else if(x>350&&x<400)
		{
			m=375;
			find(y);
			
			
		}
	System.out.println(m +" "+n);
	m=m+100;
	n=n+100;
	if(m<500&&n<500&&m>100&&n>100)
	{g.drawLine(m,n,m,n+5);
       int p=find_validate(m,n) ;
	}
        
    }
	public int find_validate(int n,int m )
	{
		return  n;
	}
	public void find (int y)
		{
		if (y<50)
		{	n= 25;		
			
		}
		else if (y>50&& y<100)
		{	n= 75;		
			
		}
		else if ( y>100&&y<150)
		{	n= 125;		
		
		}
		else if (y>150&& y<200)
		{	n= 175	;	
			
		}
		else if (y>200&& y<250)
		{	n= 225	;	
			
		}
		else if (y>250&& y<300)
		{	n= 275	;	
			
		}
		else if (y>300&&y<350) 
		{
			n=325;
			
		}
		else if(y>350&&y<400)
		{
			n=375;
			
		}
	
		}

    public Frame win()
    {
        
        Frame m=new Frame("Result");
        Label l=new Label("you win");
        m.setLayout(null);
        m.add(l);
        l.setBounds(20,20,60,60);
        m.setVisible(true);
        m.setSize(100,100);
        return m;
    }
    
    public Frame draw()
    {
        Frame m=new Frame("Result");
        Label l1=new Label("Stalemate");
        m.setLayout(null);
        m.add(l1);
        l1.setBounds(20,20,60,60);
        m.setVisible(true);
        m.setSize(100,100);
        return m;
        
    }
    public void mouseReleased(MouseEvent e)
    {
        System.out.print("");
    }
    
    
    
    
    public void mouseEntered(MouseEvent e)
    
    {
        System.out.print("");
    }
    public void mouseExited(MouseEvent e)
    {
        System.out.print("");
    }
    public void mousePressed(MouseEvent e)
    {
        System.out.print("");
    }
    
    public static void main(String args [])
    {
        new TicTacToe();
    }
}
