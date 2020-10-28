#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int tok=0;
struct pa_node
{
    char name[100];
    struct pa_node*next;
}*top1=NULL;
struct doc_node
{
    char name[100];
    struct doc_node *pat;
    struct doc_node *pat1;
}*p;
struct doc_node *a[26];
void make_it_NULL()
{
    int i;
    for(i=0;i<26;i++)
        a[i]=NULL;
}
void new_doctor_entry(char a1[])
{
    int m;
struct doc_node *newnode,*p;
newnode=(struct doc_node*)(malloc(sizeof(struct doc_node)));
newnode->pat=NULL;
newnode->pat1=NULL;
strcpy(newnode->name,a1);
m=a1[0]-97;
if (a[m]==NULL)
{a[m]=newnode;
}
else
{   p=a[m];
 while(p->pat!=NULL)
    p=p->pat;
p->pat=newnode;
}
}
struct doc_node* doctor_find(char a1[])
{int m;
m=a1[0]-97;
printf("%d\n",m);
if(a[m]==NULL)
    printf("doctor doesn't exist1");
else
{
    p=a[m];
    while(p->pat!=NULL && strcmp(p->name,a1)!=0)
    p=p->pat;
    printf("%s\n",p->name);
    if (strcmp(p->name,a1)==0)
        return p;
    else
        {printf("the doctor doesn't exist");
         return NULL;
        }
}


}
void pat_entry_doctor()
{char a[100],b[100];
    struct pa_node *patient;
    patient=(struct pa_node*)(malloc(sizeof(struct pa_node)));
    printf("enter your name : ");
    scanf("%s",a);
    strcpy(patient->name,a);
    printf("enter the doctor name");
    scanf("%s",b);
    p=doctor_find(b);
    if(p!=NULL)
    {while(p->pat1!=NULL)
    p=p->pat1;
    p->pat1=patient;
    tok++;
    printf("your token no is %d",tok);}
}
void pat_status()

main()
{make_it_NULL();
    new_doctor_entry("anand");
    new_doctor_entry("ajay");
    printf("%s\n",a[0]->pat->name);
    pat_entry_doctor();



}
