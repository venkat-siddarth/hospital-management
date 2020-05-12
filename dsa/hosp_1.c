#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
struct pa_node
{
    char name[100],mode_of_admission[100],gender[100];
    char mobile[10];
    char email[100],med[200],drugs[100],other[100],operations[100],dia[100],current[100],doctor_visit[100],patient_status[100];
    int year;
    int height,weight;
    struct pa_node*next;
}*top1=NULL;
struct doc_node
{
    char name[100];
    struct doc_node *pat;
    struct doc_node *pat1;
}*p,*temp;
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
if(a[m]==NULL)
    return NULL;
else
{
    p=a[m];
    while(p->pat!=NULL && strcmp(p->name,a1)!=0)
    p=p->pat;
    printf("%s\n",p->name);
    if (strcmp(p->name,a1)==0)
        return p;
    else
            return NULL;

}


}
void pat_entry_doctor()
{char a[100],b[100];
    struct pa_node *patient;
    patient=(struct pa_node*)(malloc(sizeof(struct pa_node)));
    printf("\nXXXXXXXXXXXXXXXXXXXXXX GENERAL iNFORMATION XXXXXXXXXXXXXXXX\n");
    printf("enter your name : ");
    scanf("%s",patient->name);
    printf("\n");
    printf("enter your gender:");
    scanf("%s",patient->gender);
    printf("\n");
    printf("enter your mobile number");
    scanf("%s",patient->mobile);
    printf("\n");
    printf("enter your email:(optional)\n");
    scanf("%s",patient->email);
    printf("\n");
    printf("XXXXXXXXXXXXXXXXXXXXXX PATIENT INFORMATION XXXXXXXXXXXXXXXX\n");
    printf("enter the year of u r birth : ");
    scanf("%d",&patient->year);
    printf("\nHave you taken any medication before (If yes) please mention below");
    printf("\n");
    scanf("%[^\n]%s",patient->med);
    printf("\nenter the doctor name");
    scanf("%s",patient->doctor_visit);
    p=NULL;
    p=doctor_find(patient->doctor_visit);
    int tok=0;
    if(p!=NULL)
    {while(p->pat1!=NULL)
    p=p->pat1;
    p->pat1=patient;
    tok++;
    printf("your token no is %d",tok);}
    else
    {
        printf("doctor doesn't exist");

}
}


main()
{
    int choice;
    make_it_NULL();
printf("Hello Welcome to ABC HOSPITAL\n");
do
{printf("\n1 : patients admission\n2 : new doctor entry\n3: patient status\n4:exit\nenter your choice\n");

scanf("%d",&choice);
    switch(choice)
    {
  case 1:
    printf("welcome to patient admission portal: ");
    pat_entry_doctor();
    break;
  case 2:
    printf("Welcome to ABC hospital family doctor!!");
    char g[100];
    printf("enter your name doctor");
    scanf("%s",g);
    new_doctor_entry(g);
    break;
  case 3:
      printf("under development");
      break;
  case 4:
      printf("under development");
      break;
}
}while(choice!=4);




}
