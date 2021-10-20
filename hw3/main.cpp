#include <iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
int i=0;
int co=0;
using namespace std;
 class node {
     public :
         int index ;
 char taskname [30];
 double duration  ;
 double starttime=-10000 ;
 int child[20];
 int counter=0 ;
  int parent=-1;
  bool dis=false;
};

class graph  {
    public :
node g[20];
graph(int x);
void addvertex(int ind,char name[30], double du);
void addedge (int index,int child);
int longestpath (int v ,int siz);
void print(int start, int en);
};
graph::graph(int x ){

  node *g= new node [x]  ;
}
void graph::addvertex(int ind,char name[30], double du){

g[ind].index=ind ;
strcpy(g[ind].taskname,name);
g[ind].duration=du ;


}
int q=0;
int fg=0;
int counter=0;
void graph::addedge(int index , int ch){
   if (fg==index&&counter>0){
    q++;
    counter=0;

   }
  else {q=0;}

g[index].child[q]=ch;
g[index].counter++;


 fg= index;
 counter++;
}
int graph::longestpath(int v ,int siz){
bool found ;
int t,j , maxe,index ,w, sum ,ed;
g[v].dis=true ;
co++;
if (co==1)g[v].starttime=3;

for (j=0; j<g[v].counter;j++){
w=g[v].child[j];
ed=g[v].starttime ;
sum=g[w].duration+ed;
if (sum>g[w].starttime){
    g[w].starttime=sum;
    g[w].parent=v;

}
}
found = false ;
maxe=-10000;
for (t=0; t<siz;t++){

    if(!g[t].dis){
        if(g[t].starttime>maxe){

            found=true ;
            maxe=g[t].starttime;
            index=t;

        }


    }
    if (found)longestpath(index,siz);

}
}
void graph::print(int start, int en){

if (g[en].parent==start){cout<<start<<"=>"<<en;}
else {print(start, g[en].parent);
    cout<<"=>"<<en ;
}


}

int main()
{int x = 8 ;
    graph ga(x);
     int ss,ee; int y=1;
    while (y){
    cout<<"***************main menu *************"<<endl;
    cout<<"1.load new file :"<<endl;
    cout<<"2. find and print the critical path"<<endl;
    cout<<"3. exit"<<endl;
    cout<<"______________________________________________"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>y;
    switch (y){
    case 1:{
        int x;
ifstream file ;
file.open("hw3.txt",ios::in );
file>>x ;
int w;
w=x ;
int k=x;
int y;
char s[20];
double e;


int i=0;
while (x--){
    file>>y>>s>>e;
ga.addvertex(y,s,e);



}
int n ;
file>>n;
int id;
int ch;
while (n--){
        file >>id>>ch;
    ga.addedge(id,ch);}
break;}

 case 2:{

  cout<<"enter the starting task "<<endl;
  cin>>ss;
  cout<<"enter the ending task "<<endl;
  cin>>ee;

        ga.longestpath(0,8);
ga.print(ss,ee); break; }

    case 3: y= 0;
    }}


    return 0;
}
