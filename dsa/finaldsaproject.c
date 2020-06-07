
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int total_cases=0,Normal=0,Emergency=0;
 int opt;
struct pa_node//Patient Node
{
    char name[100],mode_of_admission[100],gender[100];
    char mobile[10];
    char email[100],med[200],drugs[100],other[100],operations[100],dia[100],current[100],doctor_visit[100],modeofconsultation[100],year[4];
    int height,weight,token;
    struct pa_node *pat1;
    struct doc_node *doctor;
}*t,*tem,*head=NULL;
struct doc_node//Doctor NOde
{
    char name[100],dept[100];

    struct doc_node *pat,*id;
    struct pa_node *pat1;
}*p,*temp;
struct doc_node *a[26];
void make_it_NULL()//this  is a function which makes every element of a pointer is equal to NULL
{
    int i;
    for(i=0;i<26;i++)
        a[i]=NULL;
}
void new_doctor_entry(char a1[])//This functions is a entry portal to the new doctors to enter into the data base of the system
{
    int m;
struct doc_node *newnode,*p;
newnode=(struct doc_node*)(malloc(sizeof(struct doc_node)));
newnode->pat=NULL;
newnode->pat1=NULL;
printf("Department of work: ");
scanf("%s",newnode->dept);
a1[0]=tolower(a1[0]);
printf("Hey DOC I AM HMS ASSISTANT BOT !!!!\n\n");
strcpy(newnode->name,a1);
m=a1[0]-97;//hash function
if (a[m]==NULL)
{a[m]=newnode;
}
else
{   p=a[m];
 while(p->pat!=NULL)
    p=p->pat;
p->pat=newnode;
}


printf("Hey Doc!! This is your mem ID: %x %s\n",newnode,newnode->name);
}

struct doc_node* doctor_find()//THis function prints the all possible doctors it can be with input as name something like search engine
{int m,asd;
char a1[100];
int flag=0,flag1;
struct doc_node* aacc;
printf("SEARCH\n1:byname\n2:by mem id");
scanf("%d",&flag1);
if (flag1==1)
{

printf("enter the doctor name\n");
    scanf("%s",a1);
m=a1[0]-97;
if(a[m]==NULL)
    {
        printf("Doctor Not found\n1.Do you want to try again\n2.exit");

    scanf("%d",&asd);
    if(asd==1)
    doctor_find();
    else
        return NULL;
    }
else
{
    p=a[m];
    while(p->pat!=NULL)
    {
    if (strcmp(p->name,a1)==0)
    {printf("%s %s %x\n",p->name,p->dept,p);
    flag++;}
    p=p->pat;
}
 if (strcmp(p->name,a1)==0)
    {printf("%s %s %x\n",p->name,p->dept,p);
    flag++;}
if (flag==0)
{
    printf("The doctor doesn't exist");
    printf("\n1.Do you want to try again\n2.exit");
    scanf("%d",&asd);
    if(asd==1)
    doctor_find();
    else
    {if(asd==2)
    return NULL;}
}

else{
    printf("enter the doctor mem id");
    scanf("%x",&aacc);
    return aacc;
}

}
}
else{ if (flag1==2)

    printf("enter the doctor mem id");
    scanf("%x",&aacc);
    return aacc;
}
}
void doc_status(struct doc_node *doctor)//This is a profile report or the working details of the doctor
{
    struct pa_node *coun_pa,*patient;
    printf("doctor name   %s\n",doctor->name);
    printf("mem id :   %x\n",doctor);
    p=doctor;
    coun_pa=p->pat1;
    int m=0;
    while(coun_pa!=NULL && p!=NULL && p->pat1!=NULL)
        {coun_pa=coun_pa->pat1;
        m++;}
    printf("\nThe remaining number of patients are %d",m);
}
void patient_log(struct doc_node *doctor)//This is the log report of the patients who are remaining for the consultation
{
    struct pa_node *coun_pa,*patient;
    printf("doctor name   %s",doctor->name);
    printf("mem id :   %x\n",doctor);
    p=doctor;
    coun_pa=p->pat1;
    int m=0;
    while(coun_pa!=NULL && p!=NULL && p->pat1!=NULL)
        {
        printf("%s %x\n",coun_pa->name,coun_pa);
        coun_pa=coun_pa->pat1;
        }

}



void pat_entry_doctor()//This function makes an appointment with the respetive consultant
{char a[100],b[100];
    struct pa_node *patient;
    struct doc_node *l;
    patient=(struct pa_node*)(malloc(sizeof(struct pa_node)));
    t=(struct pa_node*)(malloc(sizeof(struct pa_node)));
    patient->pat1=NULL;
    printf("\nXXXXXXXXXXXXXXXXXXXXXX GENERAL INFORMATION XXXXXXXXXXXXXXXX\n");
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
    scanf("%s",patient->year);
    printf("what type of consultation?\n1.Normal\n2.Emergency\nenter your choice:");
    int as;
    scanf("%d",&as);
    if (as==1)
    {
    patient->doctor=doctor_find();
    l=patient->doctor;

    if(l!=NULL)
    {
    strcpy(patient->doctor_visit,patient->doctor->name);
    t=l->pat1;
    if(t==NULL)
    {t=patient;
    l->pat1=t;
    printf("The patient mem id: %x\n",patient);
    Normal++;
    }
    else{
    while(t->pat1!=NULL)
    t=t->pat1;
    t->pat1=patient;
    printf("The patient mem id: %x\n",patient);
    Normal++;
    }
    }
    else
    printf("doctor doesn't exist\n");
    }
    else
    {
        Emergency++;
        if(head==NULL)
        {
            head=patient;
        }
        else
        {tem=head;
         while(tem->pat1!=NULL)
            tem=tem->pat1;
            tem->pat1=patient;
        }

    }
}
void delet(struct doc_node *doctor)//After completion this function deletes the  patient node visited
{

    struct pa_node * node;
    if(doctor->pat1==NULL)
        printf("The queue is Empty");
    else{
        node=doctor->pat1;
        doctor->pat1=node->pat1;
        free(node);
    }
}


main()
{
    int choice;
    char g[100];
    make_it_NULL();
printf("Hello Welcome to ABC HOSPITAL\n");
do
{
 total_cases=Normal+Emergency;
printf("THE TOTAL NUMBER ODF ACTIVE CASES:%d\n THE TOTAL NUMBER OF NORMAL CONSULTATIONS:%d\nTHE TOTAL NUMBER  OF EMERGENCY CASES:%d\n",total_cases,Normal,Emergency);
printf("\n1 : patients admission\n2 : new doctor entry\n3:  status\n4:exit\nenter your choice\n");
scanf("%d",&choice);
    switch(choice)
    {
  case 1:
    printf("welcome to patient admission portal: ");
    pat_entry_doctor();
    break;
  case 2:
    printf("Welcome to ABC hospital family doctor!!\n");
    printf("enter your name doctor\n");
    scanf("%s",g);
    new_doctor_entry(g);
    break;
  case 3:
      printf("enter your mem id:\n");
      struct pa_node *coun_pa,*patient;
      scanf("%x",&patient);
          printf("name :%s\ngender :%s\nmobile number :%s\nemail:%s\n year :%s \n Consultant :%s\n Consultant mem id:%x\n",patient->name,patient->gender,patient->mobile,patient->email,
                 patient->year,patient->doctor_visit,patient->doctor);
        p=patient->doctor;
        coun_pa=p->pat1;
        int m=0;
        while(coun_pa!=patient && p!=NULL && p->pat1!=NULL)
        {coun_pa=coun_pa->pat1;

        m++;}
        printf("token number %d\n",m);
      break;
  case 4:
      printf("Have a great day!!!....\n");
      break;
  case 100://By using this we enter the doctor mode from patient mode
    printf("Greetings doctor how can i help u??\n");
    int choo=0;
    do{
    printf("\n1:Consultation completion\n2:remaining number\n3:patient log for remaining patients\n4:exit");
    scanf("%d",&choo);
    printf("PLease enter your mem id\n");
    scanf("%x",&temp);
     switch(choo)
     {
     case 1:
         delet(temp);
         Normal--;
         break;

     case 2:
        doc_status(temp);
        break;
     case 3:
        patient_log(temp);
        break;
     case 4:
        printf("HAve a NIce Day Doctor!!!!\n");
        break;
     }
    }while(choo!=4);


}
}while(choice!=4);




}

