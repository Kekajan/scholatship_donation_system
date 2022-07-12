#include <stdio.h>
#include <string.h>
#include <ctype.h>

int totalinc(void);      //totalinc function declaration
void printMsg(char*, float);

FILE *fptr;        //file pointer variable

struct student{     //structure declaration
    char indexno[15]; //Because index numbers may contain characters and if needed to process using a method like checksum we can easily convert to int/float
    char name[20];
    char stream[15];
};
int n;
struct student s1;       //structure definition

int marks[3];
float avg=0,sum=0;

int totalinc(){       //total income function definition
    int ti,fsalary,msalary;

    printf("\nEnter the monthly income of father: ");  //salary of father
    scanf("%d",&fsalary);
    printf("Enter the monthly income of mother: ");  //salary of mother
    scanf("%d",&msalary);
    ti=fsalary+msalary;     //total income
    printf("Total income of parents' is : %d",ti);

    return ti;
}

void salaryCalc(int tot){
    if(tot < 20000){
        printf("\n%s is selected to scholarship.\n",s1.name);
        fprintf(fptr,"%s","This student is selected to scholarship.\n");
    }
    else{
        printf("\n%s is not selected to scholarship.\n",s1.name);
        fprintf(fptr,"%s","This student is not selected to scholarship.\n");
    }
}

void printMsg(char *stream, float average){

    if(!strcmp(stream,"MATHS") && average >= 65){  
          
    		salaryCalc(totalinc());
    } 
    else if(!strcmp(stream,"BIO") && average >= 60) {
    
    		salaryCalc(totalinc());
    }
    else if(!strcmp(stream,"COMMERCE") && average >= 70) {    
    		salaryCalc(totalinc());
    }
    else if(!strcmp(stream,"TECHNOLOGY") && average >= 72){    
     		salaryCalc(totalinc());
    }
    else if(!strcmp(stream,"ARTS") && average >= 75){    
     		salaryCalc(totalinc());
    }
    else{
        printf("\n%s is not selected to scholarship.\n",s1.name);
        fprintf(fptr,"%s","This student is not selected to scholarship.\n");
    }
}

int main(){
    fptr=fopen("students_details.txt","a");
       //file handling-fopen

    char stm[5][12]={"MATHS","BIO","COMMERCE","TECHNOLOGY","ARTS"}; //array of strings
    printf("\n\n");
    printf("*****************************************************************************************\n");
    printf("-------------------------STUDENTS SCHOLARSHIP DONATION SYSTEM----------------------------\n");
    printf("\t\t\t\t  RIDGE WOOD COLLEGE\n");
    printf("\t\t\t  Responsibility.Excellence.Respect\n");
    printf("\t\t\t\t      Est.1960\n\n\n");

    int n;
    printf("How many A/L students do you have in your school: ");
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        sum = 0;
        printf("\n\n%d.\n",i);
        printf("Enter student's index no: ");
        scanf("%s",&s1.indexno);
        printf("Enter student's name: ");
        scanf("%s",s1.name);
        ST:printf("Enter student's AL stream: ");	//ST - ST label
        scanf("%s",s1.stream);        
        char substream[12];
        strcpy(substream,s1.stream);
        int x=0;
        while(substream[x] != '\0'){
            substream[x] = toupper(substream[x]);
            x++;
        }
        substream[x+1] = '\0';  //\0=null termination character

        char status = 'F';
        int i;
        for( i=0; i<12; i++){
            if(!strcmp(substream,stm[i]))
            {
                status = 'T';
                break;
            }
        }
        if(status == 'F'){
            printf("\nWrong Value for Stream ! Please Try Again\n");
            goto ST;
        }
        printf("\n");
        fprintf(fptr,"\n%s \t %s \t %s\n",s1.indexno,s1.name,substream);       //file printf

        printf("Enter student's first subject's marks: ");      //marks entry
        scanf(" %d",&marks[0]);
        printf("Enter student's second subject's marks: ");
        scanf("%d",&marks[1]);
        printf("Enter student's third subject's marks: ");
        scanf("%d",&marks[2]);

        for(i=0;i<3;i++){
           sum+=(float)marks[i];       //sum
        }
        avg=sum/3;   //avg=average of 3 subjects
        printf("Average of 3 subjects is: %.3f\n",avg);

        printMsg(substream, avg);
    }

    fclose(fptr);
    return 0;
}