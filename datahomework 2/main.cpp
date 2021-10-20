#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;
int s=20;
int * flage=new int [s];
struct TASK {
char TaskName[32];
int ST;
int ET;
TASK* nextTask;
};
struct MACHINE {
int id;
TASK* firstTask;
MACHINE* nextMachine;
int flage ;
};
TASK *creattask (char *name, int initaial,int ending ){
TASK*n ;
n=new TASK;
n->nextTask=NULL;
n->ST=initaial;
n->ET=ending  ;
strcpy(n->TaskName,name);
return n ;
}
TASK *head =NULL ;
TASK * addtask (TASK*head , TASK *n){
 TASK *p1,*p2;
 if (head==NULL){
    head =n ;
    return head ;
 }
 else if (n->ST<head->ST){


    n->nextTask =head;
    head=n;
    return head ;
 }
 p1=p2=head;
 while (p2->nextTask !=NULL)
 {
     if (n->ST<p2->ST){

        n->nextTask=p2;
        p1->nextTask=n;
        return head ;
     }



     else{
        p1=p2 ;
        p2=p2->nextTask;

     }//else
 }//while
 n->nextTask= NULL ;
 p1->nextTask =n;
  return head ;


 }


 void printtasks (TASK *head,int counter )
{
    TASK *p=head ;

      cout<<"TASK    START       ENDED"<<endl ;
      cout<<"======================================"<<endl ;

      while (counter--){
         cout<<p->TaskName<<"\t";
        cout<<p->ST <<"\t";
        cout<<p->ET<<endl ;
 p=p->nextTask ;




      }
      }
      /*
TASK *sorttask (TASK *head){
TASK *p ,*q ;
p=head ;
int temp1 ;
int temp2 ;
char temp[40];
q=p->nextTask;
if (p->ST==q->ST){

for (;p!=NULL;){
q=p->nextTask;
for (;q!=NULL;){
    if (q->ET<p->ET){
       temp1= p->ST;
       temp2=p->ET ;
       strcpy(temp,p->TaskName);
       p->ST=q->ST ;
       p->ET=q->ET ;
       strcpy(p->TaskName,q->TaskName);
       q->ST=temp1 ;
       q->ET=temp2 ;
       strcpy(q->TaskName,temp);

    }

    q=q->nextTask ;


}


p=p->nextTask;
}
}
}

MACHINE *header =NULL ;int i=0;
MACHINE *creatmachine(int id ,int flage ,TASK *p,TASK *head){

TASK *q;
 p=head ;
 q=p->nextTask ;

 MACHINE *m ;
 m->id= ++i ;
 m->nextMachine=NULL ;
 m->firstTask =p ;
 m->flage=p->ET ;
p->nextTask=NULL;
p=q ;
head=p ;
q=q->nextTask;

return m;




}
 TASK * returntolist(TASK *head ){
 TASK *b ,*x;
 x=b=head ;
 head =head->nextTask ;
 x->nextTask=NULL;
 return b;


 }
MACHINE * linking (MACHINE *header, MACHINE *m ){
    MACHINE *r =header  ;
if  (header==NULL){
    header=m ;
    m->nextMachine=NULL ;


}
else {
    while (r->nextMachine!=NULL){
        r=r->nextMachine ;


    }
    r->nextMachine=m;
    m->nextMachine =NULL ;

}



}
MACHINE * timing (MACHINE *header ,TASK *head ,int cnt){
    TASK *p =head;
    MACHINE * m ;
    TASK*z ;
   m=  creatmachine(1,head->ET,p,head);
   header = linking( header,m);
    cnt--;
while (cnt--){
        while (m->nextMachine!=NULL){
                    if (m->flage<=head->ST){
        z=m->firstTask;
        while(z->nextTask!=NULL){
                z=z->nextTask;
                   }
        z->nextTask= returntolist(head);
break ;
    }
else {



}



}


}
return header;
}
void printmachines(MACHINE *header){

cout <<




}
*/
MACHINE * createmachine (int id){
MACHINE *m=new MACHINE ;

m->id=id ;
m->nextMachine=NULL ;
m->firstTask=NULL;
return m ;
}
int i=1 ;
MACHINE *firstmachine=new MACHINE;
MACHINE * addmachine  (MACHINE *firstmachine,MACHINE *ma, TASK *n){
if (firstmachine==NULL){
    firstmachine=ma ;
    ma->nextMachine=NULL;
    ma->firstTask=n;
    flage[ma->id]=n->ET;
    return firstmachine;

    }

MACHINE * p=firstmachine;

while (p->nextMachine!=NULL){p=p->nextMachine;}
p->nextMachine=ma;
ma->nextMachine=NULL ;
ma->firstTask=n;
flage[ma->id]=n->ET;

return firstmachine;
}
int counternode=0;
TASK *getnode(TASK *head){
    int o= counternode;
TASK *p=head ;
while (o--){

    p=p->nextTask;
}
TASK *q;
q=creattask(p->TaskName,p->ST,p->ET);


counternode++;
return q;

}
int v=1;
int l=1;
MACHINE * timing (MACHINE *firstmachine, TASK * t ){
int u =1 ;
 MACHINE *p =firstmachine;
MACHINE *ma;
if (firstmachine==NULL){

    ma=createmachine(v);
    firstmachine=addmachine(firstmachine,ma,t);
    flage[v]=ma->firstTask->ET;
    v++;
    return firstmachine ;
}




for (;p->nextMachine!=NULL;){
   if (flage[p->id]<=t->ST){
    flage[p->id]=t->ET;
    break ;}
p=p->nextMachine;

}

if  (p->nextMachine==NULL){
         if (flage[p->id]<=t->ST){
    flage[p->id]=t->ET;
    TASK*q =p->firstTask;
for (;q->nextTask!=NULL;){q=q->nextTask;}
q->nextTask=t;
t->nextTask=NULL;

return firstmachine;
}
ma=createmachine(v++);
firstmachine=addmachine(firstmachine,ma,t);
return firstmachine;
}
else{

TASK*q =new TASK;
 q=p->firstTask;
for (;q->nextTask!=NULL;){q=q->nextTask;}
q->nextTask=t;
t->nextTask=NULL;


return firstmachine;
}
}

void printmachines (MACHINE * firstmachine){
MACHINE *p=firstmachine;
TASK*q;
int y =1;
for (;p!=NULL;){
        cout<<"machine #"<<y++<<":"<<"\t";
        q=p->firstTask;
    for (;q!=NULL;){
        cout<<q->TaskName<<"("<<q->ST<<"-"<<q->ET<<")"<<"_________";


        q=q->nextTask;


    }
    p=p->nextMachine;
    cout<<endl;
}



}

int main()
{
    TASK * t ;
    MACHINE *mach=NULL;
    TASK *we,*head ;
    int x ;
    char y [40];
    int i,e ;
ifstream file ;
file.open("input.txt",ios::in );
file>>x ;
int w;
w=x ;
int k=x;
while (x){
    file>>y>>i>>e;
   we = creattask (y, i, e );
    head=addtask (head ,  we);
    x--;
}
t=getnode(head);
mach= timing(mach,t);
t=getnode(head);
mach= timing(mach,t);
t=getnode(head);
mach= timing(mach,t);
t=getnode(head);
mach= timing(mach,t);
t=getnode(head);
mach= timing(mach,t);
t=getnode(head);
mach= timing(mach,t);
t=getnode(head);
mach= timing(mach,t);
t=getnode(head);
mach= timing(mach,t);
t=getnode(head);
mach= timing(mach,t);
t=getnode(head);
mach= timing(mach,t);

printmachines(mach);
for(int i=1; i<20;i++){
    cout<<flage[i]<<"\t";
cout<<v<<endl;


}







    return 0;
}
