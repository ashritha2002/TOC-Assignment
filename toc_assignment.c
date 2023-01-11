#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct variables
{


int var1;
char* name;
int assigned;


} *var, temp;

int size=0;
void execute_for(char *s);




// READS AN INTERGER VARIABLE

void execute_read(char *s)
{



   	 char* pch= malloc(strlen(s)*sizeof(char));
   	 for(int i=4;i<=strlen(s);i++)
   	 {
   	 
   	 
   	 
   		 pch[i-4]= s[i];
   		 
   			 
   	 
   	 }

   		 for(int i=0;i<size;i++)
			 {
			 
			 
				 if(strcmp(var[i].name ,pch)==0)
				 {
 
					 scanf("%d",&var[i].var1);
					 var[i].assigned=1;
					 break;
				 
				 
				 
				 
				 }
				 

			 
			 }
		 free(pch);    
   	 

}


// WRITE EITHER A VARIABLE OR A NUMBER
void execute_write(char *s)
{



   	 char* pch= malloc(strlen(s)*sizeof(char));
   	 for(int i=5;i<=strlen(s);i++)
   	 {
   	 
   	 
   	 
   		 pch[i-5]= s[i];
   		 
   			 
   	 
   	 }
    

			 

   		 for(int i=0;i<size;i++)
			 {
			 
			 
				 if(strcmp(var[i].name ,pch)==0)
				 {
				 
					 printf("%d\n",var[i].var1);
					 free(pch);
					 return;
				 
				 
				 
				 
				 }
				 
			 
			 
			 
			 
			 }
			 
			 printf("%d\n",atoi(pch));    
			 
   	 


}

//ASSIGNMENT OR EXPRESSION ARE EXECUTED HERE WHICH DONT HAVE PARENTHESIS

int execute_assign(char *str1)
{

    char *search="=";
    int res1=0;
    while(strcmp(search,"#")!=0)
    {   	 
   	 str1 = strtok(str1, search);
   	 char *str2 = strtok(NULL, search);
   	 
   	 
   	
    for(int i=0;i<size;i++)
    {
   			 
   	 if(strcmp(str1,var[i].name)==0)
   		 {
   			 return var[i].var1;
   		 }   				 
   				 

   			 
   			 
    }
    

    return atoi(str1);
    
    

    
	 




}


// FIRST EXECUTES PARENTHESIS , WRITE WHATEVER VALUE IT GOT IN THE EXPRESSION AND WE DO THAT TILL ALL PARENTHESIS ARE OVE//

//do this

//DETERMINES TYPE OF STATEMENT AND EXECUTES IT
void read(char *s)
{



   		 //S are the group of statements -pch1 is the first statement and pch2 are the rest of statements (pch1+pch2 =S)
   		 char *pch1=malloc((strlen(s)+1)*sizeof(char));
   		 char *pch2=malloc((strlen(s)+1)*sizeof(char));
   		 
   		 // for "for" loop we seperate statements by { and } not by ;
   		 //do this
   			 
   					 
   		 
   					 
   		
   				 int i;
                
   				 for(i=0; s[i] !=';';i++)
   				 {
   		            
   					 pch1[i]=s[i];
   					 
   					 
   				 }
   				 for(int j=i+1;j<=strlen(s);j++)
   				 {
   		 
   					 pch2[j-i-1]=s[j];
   					 
   					 
   				 }
   				 	 
   		 
   		 
 
   		 //EXECUTES DECLARATION
   		 if(strstr(pch1, "int") != NULL&&strstr(pch1, "=") == NULL)
   		 {
   		 
   			 if(s[0]=='i'&&s[1]=='n'&&s[2]=='t')
   			 {
   			 
   				 execute_declare(pch1);
   				 if(pch2[0]!='\0')
   				 read(pch2);
   				 return;
   			 
   			 
   			 }
   		 
   		 
   		 
   		 }
   		
   		 
   		 //EXECUTES READ
   		 if(strstr(pch1, "read") != NULL&&strstr(pch1, "=") == NULL)
   		 {
   		 
   		 
   		 
   			 if(s[0]=='r'&&s[1]=='e'&&s[2]=='a'&&s[3]=='d')
   			 {


   				 execute_read(pch1);
   				 if(pch2[0]!='\0')
   				 read(pch2);
   				 return;


   			 }
   		 
   		  		 
   		 }
   		 
   		 //EXECUTES WRITE
   		 if(strstr(pch1, "write") != NULL&&strstr(pch1, "=") == NULL)
   		 {
   		 
   		 
   		 
   			 if(s[0]=='w'&&s[1]=='r'&&s[2]=='i'&&s[3]=='t'&&s[4]=='e')
   			 {


   				 execute_write(pch1);
   				 if(pch2[0]!='\0')
   				 read(pch2);
   				 return;


   			 }
   		 
   		 
   		 
   		 }
   		 //EXECUTES ASSIGNMENT
   		 if(strstr(pch1, "=") != NULL)
   		 {
   		 
   			 //parenthese_exec(pch1);
                         //create this function
   			 if(pch2[0]!='\0')
   			 read(pch2);
   			 return;
   		 
   		 
   		 
   		 
   		 }
   		 
}


void execute_program()
{

    FILE* ptr;
    var = malloc(100*sizeof(temp));

    int count=0;
    //do this...find a way to count the chars in the file without reading it
   
    
    char *state= malloc(count*sizeof(char)); //file contents are converted to chars
    int i=0;
    ptr = fopen("in1.txt", "r");
    while(!feof(ptr))
    {
    
    
   	 fscanf(ptr,"%c", &state[i]);
   	 i++;
   	 
    
    }
    fclose(ptr);
    
    char *no_space_string= malloc((strlen(state))*sizeof(char));
	printf("%s\n", state);
   // int j=0;
    
    
    printf("%s\n", state);
    read(state);
    free(state);
	
}

int main()
{
    execute_program();
    return 0;
}
