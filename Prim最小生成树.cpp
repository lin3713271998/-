#include<stdio.h>
#define M  20 
#define FIN 5000 

typedef struct{
	char vexs[M];
	int edges[M][M];
	int n,e;//n:顶点数e:边数 
}Mgraph;

typedef struct edgedata{
	int beg,en;//边顶点序号 
	int length;	
}edge; 
edge tree[M-1];	
//图的邻接矩阵建立
void creat(Mgraph *g,char *s,int c){            //c表示图的类型，c=0表示无向图 
int i,j,k,w;
FILE *rf;
rf = fopen(s,"r");	//fopen函数使用方法：https://baike.baidu.com/item/fopen/10942321?fr=aladdin 
if(rf)
{
	fscanf(rf,"%d%d",&g->n,&g->e);
	for(i=0;i<g->n;i++)
	fscanf(rf,"%ls",&g->vexs[i]);
	
	for(i=0;i<g->n;i++)//初始化邻接矩阵 
	    for(j=0;j<g->n;j++)
	       if(i==j) g->edges[i][j]=0;
		   else g->edges[i][j]=FIN;
	   
	for(k=0;k<g->e;k++)//读入边 
	{   fscanf(rf,"%d%d%d",&i,&j,&w);
		g->edges[i][j]=w;
		if(c==0) g->edges[j][i]=w; }   	
    fclose(rf);	 }	
	else g->n=0; 
}

//Prim
void prim(Mgraph g,edge tree[M-1]){
 edge x;
 int d,min,j,k,s,v;
 for(v=1;v<=g.n-1;v++)
 {
 	tree[v-1].beg=0;
	tree[v-1].en=v;
	tree[v-1].length=g.edges[0][v]; 
	}	
 for(k=0;k<g.n-3;k++)
 {
 	min = tree[k].length;
	for(j=k+1;j<g.n-2;j++)
	  if(tree[j].length<min)
	   {
	   	min = tree[j].length;
	   	s=j;
		} 
 	v=tree[s].en;
 	for(j=k+1;j<g.n-2;j++)
 	{d=g.edges[v][tree[j].en];
 	 if(d<tree[j].length)
 	   {tree[j].length=d;
 	    tree[j].beg=v;
		}
	 }
}	
printf("\n%c--%c %d\n",g.vexs[tree[j].beg],g.vexs[tree[j].en],tree[j].length);
printf("the root of it is %c\n",g.vexs[0]);		
}


int main(){
Mgraph g;
char filename[30];
printf("Please input you want to open the file name:\n");
gets(filename);
creat(&g,filename,0);
prim(g,tree);
return 0;		
}






