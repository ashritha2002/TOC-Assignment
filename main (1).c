#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct variables
{


int var1;
char* name;
int assigned;


} *var, temp,parent;
int loop_for=0;
int total_count=0;
int dec1=0;
int size=0;
void execute_for(char *s);
int parse =1;
int patr=0;

char* parse_assign(char *st,char *str,char *sei)
{
    char *search=malloc((strlen(sei)+1)*sizeof(char));
    strcpy(search,sei);
    char *s= malloc((strlen(st)+1)*sizeof(char));
    strcpy(s, st);
   	
    
    char * pre=malloc((1000)*sizeof(char));
    char * post=malloc((10)*sizeof(char));

    while(strcmp(search,"#")!=0)
    {   	 
       
       	char *str1 = strtok(s, search);
       	char *str2 = strtok(NULL, "");
       	
       	
       	 
       	 
       	 
       	 
       	 if(str2!=NULL)
       	 {
       	 
       	    
       		 char *res1=parse_assign(str1,"a",search);
       		 char *res2=parse_assign(str2,"a",search);
       		 int size_res= strlen(res1)+strlen(res2)+100;
       		 char *result=malloc(size_res*sizeof(char));
       		 
       		 
       		 if(strcmp(search,"?")==0)
       		 sprintf(result,"[<T1> %s [==] %s]",res1,res2);
       		 
       		 if(strcmp(search,">")==0)
       		sprintf(result,"[<T2> %s [>] %s]",res1,res2);
       		
       		if(strcmp(search,"+")==0)
       		sprintf(result,"[<T3> %s [+] %s]",res1,res2);
       		
       		if(strcmp(search,"-")==0)
       		sprintf(result,"[<T4> %s [-] %s]",res1,res2);
       		
       		if(strcmp(search,"*")==0)
       		sprintf(result,"[<T5> %s [*] %s]",res1,res2);
       		
       		if(strcmp(search,"/")==0)
       		sprintf(result,"[<T6> %s [/] %s]",res1,res2);
       		 
       		
       	
       		
       		strcat(result,post);
       		strcat(pre,result);
       		strcpy(result,pre);
       		     
       		    
       		 if(strcmp(str,"a")!=0)
       		 {
       		     sprintf(str,"[<E> %s]",result);
       		 }
       		 
       		 free(res1);
       		 free(res2);
       		 return result;
       
       	 
       	 }
       	 else
       	 {
       	 
       	 
       		
       		 if(strcmp(search,"?")==0)
       		 {
       		      
       		      strcat(pre,"[<T1> ");
                    strcat(post,"]");
                      search=">";

       		 }
       		
       		 else if(strcmp(search,">")==0)
       		 {
       		     search="+";
       		      strcat(pre,"[<T2> ");
                    strcat(post,"]");
       		 }
       		 else if(strcmp(search,"+")==0)
       		 {
       		      search="-";
       		       strcat(pre,"[<T3> ");
                    strcat(post,"]");
       		 }
       		
       		 else if(strcmp(search,"-")==0)
       		 {
       		     search="*";
       		      strcat(pre,"[<T4> ");
                    strcat(post,"]");
       		 }
       		 
       		 else if(strcmp(search,"*")==0)
       		 {
       		      search="/";
       		       strcat(pre,"[<T5> ");
                    strcat(post,"]");
       		 }
       		
       		 else
       		 {
       		     search="#";
       		      strcat(pre,"[<T6> ");
                    strcat(post,"]");
       		 }
       		 
       	 
        
        }
    }
    
    
    char *re= malloc((strlen(st)+100)*sizeof(char));
    if(strcmp(s,"!")==0)
    sprintf(re,"[<T7> [<Y> %s]]",st);
    else
    sprintf(re,"[<T7> [<Y> [%s]]]",st);
   strcat(re,post);
    strcat(pre,re);
    strcpy(re,pre);
    free(s);
    free(pre);
    free(post);
    if(strcmp(str,"a")!=0)
    {
       		     sprintf(str,"[<E> %s]",re);
    }
    return re;

}


char* parse_parent(char *st)
{
   
    char *s= malloc((strlen(st)+1)*sizeof(char));
    strcpy(s, st);
    
 
   	
   	 if(strstr(s, "(") == NULL)
   	 {
   	     char* ubu1= malloc(10000*sizeof(char));
   	     parse_assign(st,ubu1,"?");
   	      return ubu1;
   	 }
   	 
   	  
   	 
   	
   
       	 int start=0;
       	 int end=0;
       	 char* char_parent=malloc(strlen(s)*sizeof(char));
       	 char * jemp,*ubu2;
       	 int count=0;
       	 int j=0;
    
       	 
       	 for(int i=0; i<strlen(s);i++)
       	 {
        
        
        
       		 if(count!=0)
       		 {
       			 if(s[i]!=')'||count!=1)
       			 {
       				 char_parent[j]=s[i];
       				 j++;
       			 }
       		 }
        
       		 if(s[i]=='(')
       		 {
       			 
       			 if(count==0)
       			 start=i;
       			 count++;
       			 
       		 
       		 }
       		 
       		 
       		 
       		 if(s[i]==')')
       		 {
       			 
       			 count--;
       			 if(count==0)
       			 {
       				 end=i;
       				 char_parent[j]='\0';
       				 jemp=parse_parent(char_parent);
       				 break;
       			 }
       		 }
       	 }
       	  free(char_parent);
       	 
       	 
       	 char* strn=malloc((1+strlen(s))*sizeof(char));
       	 
      	 for(int i=0; i<start;i++)
       	 {
        
       	 
       			 strn[i]=s[i];
       		 
       	 }
       	 strn[start]= patr+33;
       	 
       	 j = start+1;
       	 int i;
       	 
       	 for(i=end+1; i<=strlen(s);i++)
       	 {
        
       	 
       			 strn[j]=s[i];
       			 j++;
       		 
       	 }
       	 patr++;
       	 ubu2 =parse_parent(strn);
       	 patr--;
       	 char search[]={patr+33,'\0'};
       	 char *str1 = strtok(ubu2, search);
       	 char *str2 = strtok(NULL, "");
       	 char *res= malloc((strlen(str1)+strlen(str2)+strlen(jemp)+10)*sizeof(char));
       	 strcat(res,str1);
       	 strcat(res,"[(] ");
       	 strcat(res,jemp);
       	 strcat(res,"[)]");
       	 strcat(res,str2);
       
       	
       	
       	 //free(s);
       	 //free(jemp);
       	 //free(ubu2);
       	 free(strn);
       	 
       	 
       	
       	 return res  ;
       	 
       	 
   	
    
    

}




// FIRST EXECUTES PARENTHESIS , WRITE WHATEVER VALUE IT GOT IN THE EXPRESSION AND WE DO THAT TILL ALL PARENTHESIS ARE OVER





void check_duplicate_var_name(){
int i=0,j=0;
for(i=0;i<size;i++)
{
    for(j=i+1;j<size;j++)
    {
   	 if(strcmp(var[i].name,var[j].name)==0)
   		 {printf("\n Error:Duplicate variable %s declared \n ",var[i].name);
   		 exit(0);
   		 
   		 }
    
    }
}
}
void check_keyword_in_var_name(){
int i=0,j=0;
for(i=0;i<size;i++)
{
    {
   	 if((strcmp(var[i].name,"for")==0)||(strcmp(var[i].name,"read")==0)||(strcmp(var[i].name,"int")==0)||(strcmp(var[i].name,"write")==0))
   		 {printf("\n  Error:variablename can't be a keyword (%s) \n ",var[i].name);
   		 exit(0);
   		 
   		 }
    
    }
}
}
//checks if variable name starts with a nonletter
void check_var_name(){
int i=0,j=0,k=0;
int res;

for(i=0;i<size;i++)
{    
    {
   	 
   	 if(isalpha(var[i].name[0])==0)
   		
   		 {
   		 printf("\n variable %s can't begin with nonletter character \n ",var[i].name);
   		 exit(0);
   		 }
   	
    
    }
}
}


// STORES VARIABLE NAMES in the form of STRUCT VARIABLES ( an array of all variables declared)
void execute_declare(char *s)
{

    char *t= malloc(strlen(s)*sizeof(char));
    for(int i=3;i<=strlen(s);i++)
    t[i-3]= s[i];
   	int count_parse=1;	 
    char *pch = strtok (t,",");
    while (pch != NULL)
      {
		 
           
   		    
			
			 if(parse==0)
			 {
			     
    			  var[size].name=malloc((strlen(pch)+1)*sizeof(char));
    			 for(int i=0;i<=strlen(pch);i++)
    			 {
    			 
    				 var[size].name[i]=pch[i];
    			     int val=var[size].name[i];
    				 //printf("ascii val is %d",val);
    			 	if(!((val>96&&val<123)||(val>64&&val<91))&&(val!=0)){
    			 	//printf("ascii val is %d\n",val);
    			 	printf("\nError:variable name can't have non alphabet characters");
    			 	exit(0);
    			 	}
    			 
    			 
    			 }
    			 var[size].assigned=0;
    			 var[size].var1=-1;
    			 size++;
			 }
			 else
			 {
			     printf("[<X> [%s]]",pch);
			       pch = strtok (NULL, ",");
			       if(pch!=NULL)
			       {
			           printf("[,] [<V> ");
			           count_parse++;
			       }
			       else
			       {
			           for(int it=0;it<count_parse-1;it++)
			           printf("]");
			           
			       }
			       continue;
			    
			    
			 }
			 
			 
		
  	      pch = strtok (NULL, ",");
  	      
  	      
	  }
	  free(pch);
	  free(t);
	 
	 
   	    check_duplicate_var_name();
   		   check_keyword_in_var_name();
   		   check_var_name();



}

// READS AN INTERGER VARIABLE

void execute_read(char *s)
{


    
   	 char* pch= malloc(strlen(s)*sizeof(char));
   	 for(int i=4;i<=strlen(s);i++)
   	 {
   	 
   	 
   	 
   		 pch[i-4]= s[i];
   		 
   			 
   	 
   	 }
   	 
   	 if(parse!=0)
	{	 
	     printf("[%s]",pch);
	     return;
	    
	}
    else
    {
        
        for(int i=0;i<size;i++)
			 {
			 
			 
				 if(strcmp(var[i].name ,pch)==0)
				 {
 
					 scanf("%d",&var[i].var1);
					 if(var[i].var1<0){
					     printf("Input values cant be negative");
					     scanf("%d",&var[i].var1);
					 }
					 var[i].assigned=1;
					 free(pch);  
					 return;
				 
				 
				 
				 
				 }
				 
				 
			 
			 
			 
			 
			 }
        
        
    }
    
    printf("ERROR :variable undeclared or incorrect");
	exit(0);	 
		 
			 


  	      



}


// WRITE EITHER A VARIABLE OR A NUMBER
void execute_write(char *s)
{



   	 char* pch= malloc(strlen(s)*sizeof(char));
   	 for(int i=5;i<=strlen(s);i++)
   	 {
   	 
   	 
   	 
   		 pch[i-5]= s[i];
   		 
   			 
   	 
   	 }
   	 if(parse!=0)
	{	 
	     printf("[%s]",pch);
	     return;
	    
	}
	else
	{
    

			 

   		 for(int i=0;i<size;i++)
			 {
			 
			 
				 if(strcmp(var[i].name ,pch)==0)
				 {  
				     
				 
					 printf("%d\n",var[i].var1);
					 free(pch);
					 return;
				 
				 
				 
				 
				 }
				 
			 
			 
			 
			 
			 }
			 
			   
	}
	
	for(int i=0;i<strlen(pch);i++)
	{
	    if(pch[i]>58||pch[i]<47)
	   
	    {
	        printf("VARIABLE NOT DECLARED OR INCORRECT SYMBOL OR INTEGER CONSTANT CANT BE NEGATIVE");
	        exit(0);
	    }
	    
	    
	}
	 printf("%d\n",atoi(pch)); 
	
	
	free(pch);
			 
   	 


} 

//ASSIGNMENT OR EXPRESSION ARE EXECUTED HERE WHICH DONT HAVE PARENTHESIS

int execute_assign(char *str1)
{
    // char* p =  parse_parent(str1);
    // printf("%s",p);
    char *search="=";
    int res1=0;
    while(strcmp(search,"#")!=0)
    {   	 
   	 str1 = strtok(str1, search);
   	 char *str2 = strtok(NULL, "");
   	 
   	 
   	 if(str2!=NULL)
   	 {
   	      
   	 
   		 int result;
   		 
   		 if(strcmp(search,"=")!=0){
   		    
   		 res1=execute_assign(str1);
   		 }
   	
   		 if(str2[0]=='-'){
   		   printf("\n ERROR : Negative number assigned to variable");  
   		 }
   		 int res2=execute_assign(str2);
   		 
   		 if(strcmp(search,"=")==0)
   		 {
   			  if(parse != 0){
   		         char* p =  parse_parent(str1);
                 printf("%s",p);
               
   		     }
   			 
   			 for(int i=0;i<size;i++)
   			 {
   			 
   				 if(strcmp(str1,var[i].name)==0)
   				 {
   				    
   					 result=res2;
   					 var[i].var1=result;
   					 var[i].assigned=1;
   					 return result;
   				 
   				 
   				 }
   			 
   			 
   			 }
   			 
   			 
   		 }
   		 if(strcmp(search,"?")==0)
   		 result=(res1==res2);
   		 if(strcmp(search,">")==0)
   		 result=(res1>res2);    
   		 if(strcmp(search,"+")==0)
   		 result=res1+res2;
   		 if(strcmp(search,"-")==0)
   		 result=res1-res2;
   		 if(strcmp(search,"/")==0)
   		 result=res1/res2;
   		 if(strcmp(search,"*")==0)
   		 result=res1*res2;
   		 return result;
   	 
   	 }
   	 else
   	 {
   	 
   	 
   		 
    
   		 if(strcmp(search,"=")==0)
   		 search="?";
   		 else if(strcmp(search,"?")==0)
   		 search=">";
   		 else if(strcmp(search,">")==0)
   		 search="+";
   		 else if(strcmp(search,"+")==0)
   		 search="-";
   		 else if(strcmp(search,"-")==0)
   		 search="*";
   		 else if(strcmp(search,"*")==0)
   		 search="/";
   		 else
   		 search="#";
   	 
    
   	 }
    }
    
    for(int i=0;i<size;i++)
    {
   			 
   	 if(strcmp(str1,var[i].name)==0)
   		 {
   			 return var[i].var1;
   		 }   				 
   				 

   			 
   			 
    }
    for(int i=0;i<strlen(str1);i++)
	{
	    if(str1[i]>58||str1[i]<47)
	    {
	       
	        printf("VARIABLE NOT DECLARED OR INCORRECT SYMBOL");
	        exit(0);
	    }
	    
	    
	}
	

    return atoi(str1);

}



// FIRST EXECUTES PARENTHESIS , WRITE WHATEVER VALUE IT GOT IN THE EXPRESSION AND WE DO THAT TILL ALL PARENTHESIS ARE OVER
int parenthese_exec(char *tiq)
{



   	 char *s=malloc((strlen(tiq)+1)*sizeof(char));
   	 for(int i=0;i<=strlen(tiq);i++)
   	 {
   	 
   	 s[i]=tiq[i];
   	 
   	 
   	 }
   	 


   	 if(strstr(s, "(") == NULL)
   	 {        
   	      return execute_assign(s);
   	 
   	 }
   	
   	 
   	 
   	 int result=0;
   	 int start=0;
   	 int end=0;
   	 char* char_parent=malloc(strlen(s)*sizeof(char));
   	 char source[100];
   	 int count=0;
   	 int j=0;
   	 
   	 for(int i=0; i<strlen(s);i++)
   	 {
    
    
    
   		 if(count!=0)
   		 {
   			 if(s[i]!=')'||count!=1)
   			 {
   				 char_parent[j]=s[i];
   				 j++;
   				  printf("[;]]");
   			 }
   		 }
    
   		 if(s[i]=='(')
   		 {
   			 
   			 if(count==0)
   			 start=i;
   			 count++;
   			 
   		 
   		 }
   		 
   		 
   		 
   		 if(s[i]==')')
   		 {
   			 
   			 count--;
   			 if(count==0)
   			 {
   				 end=i;
   				 char_parent[j]='\0';
   				 result=parenthese_exec(char_parent);
   				 sprintf(source, "%d",result);
   				 break;
   			 }
   		 }
   	 }
   	 

   	 free(char_parent);
   	 
   	 char* strn=malloc((strlen(source)+strlen(s))*sizeof(char));
   	 
   	 for(int i=0; i<start;i++)
   	 {
    
   	 
   			 strn[i]=s[i];
   		 
   	 }
   	 
   	 for(int i=0; i<strlen(source);i++)
   	 {
    
   	 
   			 strn[i+start]=source[i];
   		 
   	 }
   	 j = start+strlen(source);
   	 for(int i=end+1; i<=strlen(s);i++)
   	 {
    
   	 
   			 strn[j]=s[i];
   			 j++;
   		 
   	 }
   	 
   	 
   	 parenthese_exec(strn);
   	 free(s);
   	 
   	 
   	 
   	 
    
    
    
    
    




}



//DETERMINES TYPE OF STATEMENT AND EXECUTES IT
void read(char *a)
{

        total_count++;
        char *s=malloc((strlen(a)+1)*sizeof(char));
        strcpy(s,a);
   		 //S are the group of statements -pch1 is the first statement and pch2 are the rest of statements (pch1+pch2 =S)
   		 char *pch1=malloc((strlen(s)+1)*sizeof(char));
   		 char *pch2=malloc((strlen(s)+1)*sizeof(char));
   		 
   		 // for "for" loop we seperate statements by { and } not by ;
   		 if(strstr(s, "for") != NULL)
   		 {
   		 
   		 
   			 if(s[0]=='f'&&s[1]=='o'&&s[2]=='r'&&s[3]=='(')
   			 {
   			 
   			 
   				 int count=0;
   				 int done=0;
   				 for(int i=0;i<=strlen(s);i++)
   				 {
   				 
   					 pch1[i]=s[i];
   					 if(s[i]=='{')
   					 
   					 {
   						 count++;
   						 done=1;
   					 }
   					 if(s[i]=='}')
   					 {
   					 
   						 count--;
   					 }
   					 if(count==0&&done==1)
   					 {
   					 
   						 
   						 for(int j=i+2;j<=strlen(s);j++)
   						 {
   							 pch2[j-i-2]=s[j];
   							 
   						 }
   						 pch1[i+1]='\0';
   						 break;
   					 
   					 }

   				 
   				 }
   			 
   			 
   			 }
   		 //If its not a for loop we can seperate statements by ;
   			 else
   			 {
   					 
   		 
   					 int i;
   					 for(i=0;s[i]!=';';i++)
   					 {
   			 
   						 pch1[i]=s[i];
   	 
   						 
   						 
   					 }
   					  pch1[i]='\0';
   					 for(int j=i+1;j<=strlen(s);j++)
   					 {
   			 
   						 pch2[j-i-1]=s[j];
   						 
   						 
   					 }
   					 
   					 
   					 
   					 
   				 
   				 
   			 }
   		 }
   		 
   		 else
   		 {
   				 int i;
   				 for(i=0;s[i]!=';';i++)
   				 {
   		 
   					 pch1[i]=s[i];
   					 
   					 
   					 
   				 }
   				 pch1[i]='\0';
   				 
   				 for(int j=i+1;j<=strlen(s);j++)
   				 {
   		 
   					 pch2[j-i-1]=s[j];
   					 
   					 
   				 }
   				 
   				 
   				 
   				 
   			 
   			 
   		 }
   		 
   		 
   		 
   		 //EXECUTES DECLARATION
   		 if(strstr(pch1, "int") != NULL&&strstr(pch1, "=") == NULL)
   		 {
   		 
   		   total_count--;
   		    if(total_count>0||dec1==1)
   		    {
   		        printf("DECLARATION SHOULD BE THE FIRST STATEMENT");
   		        
   		        exit(0);
   		    }
   		    dec1=1;
   		     
   			 if(s[0]=='i'&&s[1]=='n'&&s[2]=='t')
   			 {
   			 
   			    if(parse!=0)
   			    {
   			        printf("[<D> [int] [<V> ");
   			       
   			        execute_declare(pch1);
   			        printf("]] [;] ");
   			        
   			        
   			    }
   			    else
   				 execute_declare(pch1);
   				 
   				 if(pch2[0]!='\0')
   				 read(pch2);
   				 return;
   			 
   			 
   			 }
   		 
   		 
   		 
   		 }
   		 
   		 //EXECUTES FOR
   		 if(strstr(pch1, "for(") != NULL)
   		 {
   		 
   		 
   		    
   			 if(s[0]=='f'&&s[1]=='o'&&s[2]=='r'&&s[3]=='(')
   			 {

                if(parse!=0)
   			    {
   				   printf("[<SList> [<I> [<F> [for] ");
   				    execute_for(pch1);
   				     loop_for++;
   				     printf(" ]] [;]");
   				     
   				    
   				    
   				     
   				  
   				    
   			    }
   			    else
   			    execute_for(pch1);
   			    
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

                if(parse!=0)
                {
                     printf("[<SList> [<I> [<R> [read] [<X> ");
                    execute_read(pch1);
                    printf("]]] [;]");
                }
                else
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

                if(parse!=0)
                {
                  printf("[<SList> [<I> [<W> [write] [<Y> ");
                   execute_write(pch1);
                   printf("]]] [;]");
                }
                else
                execute_write(pch1);
   				 
   				 if(pch2[0]!='\0')
   				 read(pch2);
   				 return;


   			 }
   		 
   		 
   		 
   		 }
   		 //EXECUTES ASSIGNMENT
   		 if(strstr(pch1, "=") != NULL)
   		 {
   		 
   		    if(parse!=0)
            {
                    
                    
                    char *s1 = strtok (pch1,"=");
                    char *s2 = strtok (NULL,"");
                     char *t = parse_parent(s2);
                     printf("[<SList> [<I> [<A> [<X> [%s]] [=] %s",s1,t);
                     printf("]] [;]");
            }
            else
   			 parenthese_exec(pch1);
   			 
   			 if(pch2[0]!='\0')
   			 read(pch2);
   			 return;
   		 
   		 
   		 
   		 
   		 }
   		 
   		 
   		 
   		 
   		 
   		 
   		 
   		 
   		 

}




//EXECUTES FOR LOOP

void execute_for(char *a)
{

   	//EXTRACTS ALL 4 types of statements of for loop in S1, S2, S3, T for(S1;S2;S3){T};
    char *s=malloc((strlen(a)+1)*sizeof(char));
    strcpy(s,a);
    char*S1=malloc(strlen(s)*sizeof(char));
    char*S2=malloc(strlen(s)*sizeof(char));
    char*S3=malloc(strlen(s)*sizeof(char));
    char*T=malloc(strlen(s)*sizeof(char));
    int i;
    
    for(i=4;s[i]!=';';i++)
    {
    
   	 S1[i-4]=s[i];
    
    }
    S1[i]='\0';

    int j=0;
    for(i=i+1;s[i]!=';';i++)
    {
    
   	 S2[j]=s[i];
   	 j++;
    
    }
     S2[i]='\0';
    
    j=0;
    for(i=i+1;s[i]!=')';i++)
    {
    
   	 S3[j]=s[i];
   	 j++;
    
    }
    S3[j]='\0';
    j=0;
    
    for(i=i+2;i<=strlen(s);i++)
    {
    
   	 if(i!=strlen(s)-1)
   	 {
   		 T[j]=s[i];
   		 j++;
   	 }
    
    }
     
    //FOR LOOP SIMULATION
   
    if(parse==0)
    {
        
         parenthese_exec(S1);
        while(1==1)
        {    
    
    
    
       	 if(parenthese_exec(S2)==0)
       	 break;
       	 
       	 read(T);
       	 
       	 parenthese_exec(S3);
       	 
       	 
       	 
        }
       
    }
    else
    {
        
       
        char *t;
        char *s1 = strtok (S1,"=");
        char *s2 = strtok (NULL,"");
        if(s2!=NULL)
            {
                t =parse_parent(s2);
                printf("[(] [<Z> [<A> [<X> [%s]] [=] %s]] [;] ",s1,t);
            }
        else
        {
            t =parse_parent(s1);
            printf("[<Z> %s] [;]",t);
        }
        
        
        
        s1 = strtok (S2,"=");
        s2 = strtok (NULL,"");
        if(s2!=NULL)
            {
                t =parse_parent(s2);
                printf("[<Z> [<A> [<X> [%s]] [=] %s]] [;] ",s1,t);
            }
        else
        {
            t =parse_parent(s1);
            printf("[<Z> %s] [;]",t);
        }
        
        
        
        
        s1 = strtok (S3,"=");
        s2 = strtok (NULL,"");
        if(s2!=NULL)
            {
                t =parse_parent(s2);
                 printf("[<Z> [<A> [<X> [%s] [=] %s]]] [)] ",s1,t);
            }
        else
        {
            t =parse_parent(s1);
            printf("[<Z> %s] [)]",t);
        }
        
    
       
        //free(t);
       
        int temp= total_count;
        total_count=0;
        printf("[{]");
        
        read(T);
        for(int i=0;i<total_count;i++)
        printf("]");
        
        printf("[}]");
        
        total_count=temp;
        
        
    
        
    
        
        
    }
    free(T);
     free(S1);
        free(S2);
        free(S3);
        free(s);
        
    

}



void execute_program()
{

    FILE* ptr;
    FILE* ptr2;
    if(parse==0)
    var = malloc(100*sizeof(temp));


    int count=0;
    
  
   
    ptr = fopen("input.txt", "r");
     

    //COUNTS NUMBER OF CHARACTERS OF INPUT
    
      
   // ptr = fopen("input.txt", "r");
    while(!feof(ptr))
    {
    
    
   	 count++;
   	 char ch;
   	 fscanf(ptr,"%c", &ch);
   	 
    
    }
    
    fclose(ptr);
    //INITIALISES A CHARACTER ARRAY WITH SIZE COUNT
    
    char *state= malloc(count*sizeof(char));
    int i=0;
    ptr = fopen("input.txt", "r");
    while(!feof(ptr))
    {
    
    
   	 fscanf(ptr,"%c", &state[i]);
   	 i++;
   	 
    
    }
    fclose(ptr);
    
    char *no_space_string= malloc((strlen(state))*sizeof(char));
    int j=0;
    
    //REMOVES ALL SPACES AND REPLACES == with ?
    for(int t=0; t<=strlen(state);t++)   			 
    {
        
        if(state[t]=='\0')
         {
             no_space_string[j]='\0';
             break;
         }
   	 
   	 
   	 if(state[t]!=' '&&state[t]!='\r'&&state[t]!='\t'&&state[t]!= 10&&state[t]!='\n')   					 
   	 {
   						 
   			 
   		 if(state[t]!='='||state[t+1]!='=')
   		 {
   			 no_space_string[j]=state[t];
   			 j++;
   		 }
   		 else
   		 {   							 
   			 no_space_string[j]='?';
   			 j++;
   			 t++;
   								 
   		 }
   	 }
   		 
    }
    
    //printf("%s\n", no_space_string);
    if(parse!=0)
       {
           printf("[<P> ");
            read(no_space_string);
            printf("]");
       }
    else
    read(no_space_string);
    
    free(no_space_string);






}

int main()
{
    
    FILE* ptr2;
    int size1=0;
    //char *r=parse_parent("(a>b)+(c?d)/(e*f)");
    //printf("%s",r);
   // free(r);
    ptr2 = fopen("input.txt", "r");
   
     if (NULL != ptr2) { 
      fseek (ptr2, 0, SEEK_END);
    size1 = ftell(ptr2);
  
    if (size1 == 0) {
        printf("file is empty\n");
       
    }
}
   
   execute_program();
   
   for(int i=0;i<total_count;i++)
   printf("]");
   dec1=0;
   total_count=0;
   
    
    //PUT PARSE=0 for normal execution
    parse=0;
   execute_program();
    return 0;



}








