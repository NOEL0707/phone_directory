
/*Name:Noel vincent Polakallu
  Roll Number:1903127*/
#include<stdio.h>
#include<stdlib.h>
//this is the structure which has an array of charecters and int.
struct ph{
    char pur[100];
    long int y;
};
//this is the structure which contains an array of charecters,integer and struct phone.
struct person
{
    char x[100];
    long int j;
    struct ph *phno;
};
/*this function takes info from user like name,numbers etc. and returns the structure containing them.
INPUT:NAME OF CONTACT,Number of numbers,Phone numbers,purpose of phone numbers
Output:structure of person containing all the inputs as the attribute os structure*/
struct person getinfo(){
    int j,i,k;
    struct person p;
    printf("\nenter name:");
    scanf(" %[^\n]",p.x);
    printf("enter the number of phno:");
    scanf("%ld",&p.j); 
    p.phno=(struct ph*)malloc(p.j*sizeof(struct ph));
    for (i=0;i<p.j;i++){
        printf("enter the %d  phone number:",i+1);
        scanf(" %ld",&p.phno[i].y);
        printf("enter the purpose for %d  phone number:",i+1);
        scanf(" %[^\n]",p.phno[i].pur);
    }
    return p;
}
/*Input:Takes a structure of person and writes it into a file directory.txt.It writes in the below format.
THis is your contact
name:---
number of numbers:---
purpose of number   number*/
void writetofile(struct person b){
    int i;
    FILE *fp= fopen("directory.txt","a");
    fprintf(fp,"This is Your contact\n");
    fprintf(fp,"%s\n",b.x);
    fprintf(fp,"%ld\n",(b.j));
    for(int i=0;i<b.j;i++){
        fprintf(fp,"%s\t",b.phno[i].pur);
        fprintf(fp,"%ld\n",(b.phno[i].y));
    }
    fclose(fp);
    free(b.phno);
}
/*Input:Takes a pointer of structure of person and writes it into a file directory1.txt.It writes in the below format.It opens the file in write mode.
name:---
number of numbers:---
purpose of number   number*/
void writetofile_1(struct person *b){
    int i;
    FILE *fp_2= fopen("directory1.txt","w");
    fprintf(fp_2,"%s\n",(*b).x);
    fprintf(fp_2,"%ld\n",(b->j));
    for(int i=0;i<b->j;i++){
        fprintf(fp_2,"%s\t",b->phno[i].pur);
        fprintf(fp_2,"%ld\n",(b->phno[i].y));
    }
    fclose(fp_2);
}
/*Input:Takes a pointer of structure of person and writes it into a file directory1.txt.It writes in the below format.It opens the file in write mode.
THis is your contact
name:---
number of numbers:---
purpose of number   number*/
void writetofile_2(struct person *b){
    int i;
    FILE *fp_2= fopen("directory1.txt","w");
    fprintf(fp_2,"This is Your contact\n");
    fprintf(fp_2,"%s\n",(*b).x);
    fprintf(fp_2,"%ld\n",(b->j));
    for(int i=0;i<b->j;i++){
        fprintf(fp_2,"%s\t",b->phno[i].pur);
        fprintf(fp_2,"%ld\n",(b->phno[i].y));
    }
    fclose(fp_2);
}
/*Input:Takes a pointer of structure of person and writes it into a file directory1.txt.It writes in the below format.It opens the file in append mode.
THis is your contact
name:---
number of numbers:---
purpose of number   number*/
void appendtofile_1(struct person *b){
    int i;
    FILE *fp_2= fopen("directory1.txt","a");
    fprintf(fp_2,"This is Your contact\n");
    fprintf(fp_2,"%s\n",(*b).x);
    fprintf(fp_2,"%ld\n",(b->j));
    for(int i=0;i<b->j;i++){
        fprintf(fp_2,"%s\t",b->phno[i].pur);
        fprintf(fp_2,"%ld\n",(b->phno[i].y));
    }
    fclose(fp_2);
}
/*Input:Takes a pointer of structure of person and writes it into a file directory.txt.It writes in the below format.It opens the file in append mode.
THis is your contact
name:---
number of numbers:---
purpose of number   number*/
void appendtofile_2(struct person *b){
    int i;
    FILE *fp_2= fopen("directory.txt","a");
    fprintf(fp_2,"This is Your contact\n");
    fprintf(fp_2,"%s\n",(*b).x);
    fprintf(fp_2,"%ld\n",(b->j));
    for(int i=0;i<b->j;i++){
        fprintf(fp_2,"%s\t",b->phno[i].pur);
        fprintf(fp_2,"%ld\n",(b->phno[i].y));
    }
    fclose(fp_2);
}
/*Input:It takes file pointer as input.
this function reads a file line to line and takes it as a structure of phone and returns it */
struct person* readfromfile(FILE *fp){
    struct person* b=(struct person* )malloc(1*sizeof(struct person));
    fscanf(fp,"%[^\n] \n %ld\n",b->x,&b->j);
    b->phno=(struct ph*)malloc(b->j*sizeof(struct ph));
    for(int i=0;i<b->j;i++){
        fscanf(fp,"%[^\t]",b->phno[i].pur);
        fscanf(fp,"%ld\n",&(b->phno[i].y));
    }
    return b;
    //printing(b);
}
/*Input:Two charecter arrays
Output:returns int 1 or 0
this function returns 1 if two charecter arrays match else returns 0*/
int sub(char a[],char b[]){
    int x=0;
    int d;
    while(a[x]!='\0' && b[x]!='\0'){
        if(a[x]!=b[x]) return d=0;
        x++;
    }
    if(a[x]=='\0' && b[x]=='\0') return d=1;
    return d;
}
//This function prints a structure phone.Input:a structure phone pointer
void printing(struct person *a){
    printf("NAME:%s\n",a->x);
    printf("%ld\n",(a->j));
    for(int i=0;i<(a->j);i++){
        printf("%s\t",a->phno[i].pur);
        printf("%ld\n",(a->phno[i].y));
    }
}
//input: takes a structure phone.it frees phone numbers of struct.
void clearmemory(struct person z){
    free(z.phno);
}
/*Input:a file pointer and a charecter array.
Output: returns one if matched else returns 0.This function takes a string and compares it with all names in given file pointer and prints if it is present else does nothing*/
int search(char b[],FILE *fp){
    int d,k;
    d=0;
    struct person *c;
    c=readfromfile(fp);
    int i=0;
    k=sub(c->x,b);
    //printf("%s",c->x);
    if (k==1){printing(c);d=d+1;}
    return d;
}
/*Input:a file pointer and a charecter array.
Output: returns one if matched else returns 0.This function takes a string and compares it with all names in given file pointer and writes it to file if it is present else does nothing*/
int search_1(char b[],FILE *fp){
    int d,z;
    d=0;
    struct person *c;
    c=readfromfile(fp);
    int i=0;
    z=sub(c->x,b);
    //printf("retur d:%d\n",d);
    if (z==1){writetofile_1(c);d=d+1;}
    //printf("retur d:%d\n",d);
    return d;
}
/*Input:a file pointer and a charecter array.
Output: returns one if matched else returns 0.This function takes a string and compares it with all names in given file pointer and appends it to file if it is present else does nothing*/
int search_2(char b[],FILE *fp){
    int d,z;
    d=0;
    struct person *c;
    c=readfromfile(fp);
    int i=0;
    z=sub(c->x,b);
    if (z==0){appendtofile_1(c);d=d+1;}
    return d;

}
int main(){
    char c,e;
    int x=0;
    struct person l;
    struct person* d ;
printf("WELCOME to NOEL'S phone directory\n");
while (1==1)
{
    printf("To add a Contact press'a'\nTo modify a contact press 'm'\nTo search a contact press 's'\nTo quit press'q':");
    scanf(" %c",&c);
    if (c=='A'||c=='a'){ //if the input is a or A we can append an contact.
        l=getinfo();//this fuction gets info.
        writetofile(l);//writes it into file.
    }
    if (c=='s'||c=='S'){ //if the input is S or s we can append an contact.
        char str[100];
        char c[100];
        char k[50];
        int d,co=0;
        printf("enter the required name to search:");
        scanf(" %[^\n]",str);//name required to search
        FILE *fp=fopen("directory.txt","r");
        while (fscanf(fp,"%s %[^\n] \n",c,k)!=EOF)//while "this is your contact is not the end of file this loop runs."
        {     
            d=search(str,fp);//this fuction runs and returns integer.
            if (d==1){co=1;}
            
        }
        if (co!=1)//if d is not equal to 1 this means no name was found with such input.
        {
           printf("not found\n");
        }
        fclose(fp);
        
    }
    if (c=='q'||c=='Q')return 0;//if input is Q or q it returns 0.
    if (c=='M'||c=='m'){//if input is M or m  below code runs.
        char str[100];
        char c[100];
        char k[50];
        int e;
        char a,zz;
        int count=0;
        printf("enter the required  NAME to search:");
        scanf(" %[^\n]",str);
        FILE *fp=fopen("directory.txt","r");
        while (fscanf(fp,"%s %[^\n] \n",c,k)!=EOF)
        {   //printf("inside while\n");
            e=search_1(str,fp);
            //printf("%d",e);
            if (e==1)
            {
                count=1;
                break;
            }
            //else{continue;}

        }
        if (count!=1)
        {
            printf("not found");
        }
        fclose(fp);
        //till here it is the search function but the one structure (person) which is needed to be modified is written into a new file.
        
        //printf("-------------%d-----------------\n",count);
        if (count==1)
        {   
        
            struct person *f;
            struct person d;
            FILE *fp_1=fopen("directory1.txt","r");
            /*struct person* b=(struct person* )malloc(1*sizeof(struct person));
            fscanf(fp_1,"%s %d",b->x,&b->j);
             b->phno=(struct ph*)malloc(b->j*sizeof(struct ph));
            for(int i=0;i<b->j;i++){
                fscanf(fp_1,"%s",b->phno[i].pur);
                fscanf(fp_1,"%d",&(b->phno[i].y));
            }
            printing(b);*/
            f=readfromfile(fp_1);
            ///printf("\n%d",f->j);
            printing(f);
            fclose(fp_1);
        while(1==1){
           
            printf("To modify Name choose 'N'\nTo modify Comment choose 'C'\nTo modify Mobile Number choose 'M'\nchoose 'Q' to Quit:");
            scanf(" %c",&a);
            if (a=='n'|| a=='N'){
                char y[10];
                printf("Enter modified name:");//takes modifies name.
                scanf(" %[^\n]",f->x);//overwrites the name.
                writetofile_1(f);//writes into a file.
                //y=d.x;
                //f->x=d.x;
            }
            if (a=='c'|| a=='C'){
                char y[10];
                long int t;
                printf("choose the number which you want to change:");
                scanf(" %ld",&t);
                printf("Enter modified comment:");//takes modified comment.
                scanf(" %[^\n]",f->phno[t-1].pur);//overwrites it
                writetofile_1(f);
            }
            if (a=='M'|| a=='m'){
                char y[10];
                long int t;
                printf("choose number which you want  to change:");
                scanf(" %ld",&t);
                printf("Enter modified number:");
                scanf(" %ld",&(f->phno[t-1].y));//same as above but it is number in this case.
                writetofile_1(f);
            }
            if (a=='q'|| a=='Q'){writetofile_2(f);break;}/*if you want to quit it quits and writes the new(overwrited) structure to the file(directory1.txt dummy file)*/
                //scanf("%c",&a);
            
        }
        FILE *fp_3=fopen("directory.txt","r");
        if (fp_3==NULL)
        {
            printf("NULL");
        }
        
        int g;
        char aa[100];
        char bb[50];
        while (fscanf(fp_3,"%s %[^\n] \n",aa,bb)!=EOF)
        {   //printf("inside while\n");
            g=search_2(str,fp_3);//it writes all the structures into dummy file except the one which you cho0se to modify
        }
        fclose(fp_3);
        remove("directory.txt");//deletes directory txt.
        }
        FILE *fp_4=fopen("directory1.txt","r");
        char aa[100];
        char bb[50];
        /* this loop reads the dummy file as a structures of phones and appends it to directory.txt(main file). */
        while (fscanf(fp_4,"%s %[^\n] \n",aa,bb)!=EOF)
        {   //printf("inside while\n");
            struct person* b=(struct person* )malloc(1*sizeof(struct person));
            fscanf(fp_4,"%[^\n] %ld",b->x,&b->j);
            b->phno=(struct ph*)malloc(b->j*sizeof(struct ph));
            for(int i=0;i<b->j;i++){
                fscanf(fp_4,"%[^\t]",b->phno[i].pur);
                fscanf(fp_4,"%ld",&(b->phno[i].y));
            }
            appendtofile_2(b);
            //g=search_2(str,fp_3);
        }
        fclose(fp_4);
        remove("directory1.txt");
        
    }
}
}
