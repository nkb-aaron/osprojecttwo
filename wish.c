#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#define MAXCHAR 1000


int interactive_mode();
void chdr(char* filepath);
int batch_mode( char* file );
void exitt();
char * append(char* s, char c);
void strip(char *s);
void errorr();

int main(int argc, char *argv[]) {
	//printf("%d", argc);
	if (argc == 1){
		interactive_mode();
	}else if(argc == 2){
		//batch_mode(argv[1]);
	}else if(argc >= 3){
		perror("Only one or less arguments accepted");
	}
	/* local variable definition */
   int a = 10;
   
   
	
}

int interactive_mode() {
	//path
	char * path = "/bin";
   //buffer
   size_t buffer_size = 80;
    char *buffer = malloc(buffer_size * sizeof(char));
	printf("wish> ");
   /* while loop execution */
   while(-1 != getline(&buffer, &buffer_size, stdin)) {
    	
    	//break string into pieces at spaces
    	const char s[2] = " ";
	   char *token;
	   char *token2;
	   /* get the first token */
	   token = strtok(buffer, s);
	   
   		//check exit
   		char * check = "exit";
   		//string i = "exit";
   		//strcpy(check, i);
   		strip(token);
   		//printf( " %d\n", strcmp(token, check) );
	    	if (strcmp(token, "exit") == 0){
    		exitt();
			}
		
		//Check chdir
		//printf( " %d\n", strcmp(token, "exit") );
		if (strcmp(token, "cd") == 0){
			token = strtok(NULL, s);
			token2 = strtok(NULL, s);
			if (token2 != NULL){
				errorr();
			}
			//printf('/' + token2);
			strip(token);
			printf( " %s\n", token );
    		chdr(token);
		}
		
//		FILE *fp;
//int myInt = 5;
//fp = fopen("Output.txt", "w");// "w" means that we are going to write on this file
//fprintf(fp, "This is being written in the file. This is an int variable: %d", myInt);
//fclose(fp);
		
		
		
		//printf( " %s\n", token );
	   /* walk through other tokens */
	   while( token != NULL ) {
	      
	      //Check path
		if (strcmp(token, "path") == 0){
			
			//printf('/' + token2);
			strip(token);
			printf( " %s\n", token );
		}
	      
	      token = strtok(NULL, s);
	      strip(token);
	   }
    	
      //printf("Enter a command", a);
      //printf("%s", buffer);
      //a++;
      printf("wish> ");
   }
}

void strip(char *s) {
    char *p2 = s;
    while(*s != '\0') {
        if(*s != '\t' && *s != '\n') {
            *p2++ = *s++;
        } else {
            ++s;
        }
    }
    *p2 = '\0';
}

void exitt(){
	exit(0);
}

void errorr(){
	char error_message[30] = "An error has occurred\n";
    write(STDERR_FILENO, error_message, strlen(error_message)); 
}

//char * append(char* s, char c)
//{
//        int len = strlen(s);
//        char* ret = "";
//        ret = 'r' + ret;
//        for (int a = 0; a < len + 1; a++){
//        	
//		}
//        s[len] = c;
//        s[len+1] = '\0';
//}

void chdr(char * filepath){
//	char * file = append(filepath, "/");
	//printf('/' + filepath);
	printf( " %s\n", filepath );
	char * test = "C:\\Users\\NKB\\Documents\\OS\\Project Two\\test";
	char * path = "//";
	//	printf( " %s\n", strcat (path,filepath) );
	//path = strcat (path,filepath);
	if (chdir(filepath) != 0)
    errorr();
}


int batch_mode( char* file ) {
   /* for loop execution */
   //for( int a = 1; a < argc; a = a + 1 ){
      //printf("Text in File: %d\n", a);
   
    FILE *fop;
    char str[MAXCHAR];
    char* filename = file;
 
    fop = fopen(filename, "r");
    if (fop == NULL){
        printf("my-cat: cannot open file");
        printf("\n");
        return 1;
    }
    while (fgets(str, MAXCHAR, fop) != NULL){
    	//break string into pieces at spaces
    	const char s[2] = " ";
	   char *token;
	   char *token2;
	   /* get the first token */
	   token = strtok(str, s);
	   
   		//check exit
   		char * check = "exit";
   		//string i = "exit";
   		//strcpy(check, i);
   		strip(token);
   		//printf( " %d\n", strcmp(token, check) );
	    	if (strcmp(token, "exit") == 0){
    		exitt();
			}
		
		//Check chdir
		//printf( " %d\n", strcmp(token, "exit") );
		if (strcmp(token, "cd") == 0){
			token = strtok(NULL, s);
			token2 = strtok(NULL, s);
			if (token2 != NULL){
				errorr();
			}
			//printf('/' + token2);
			strip(token);
			printf( " %s\n", token );
    		chdr(token);
		}		
		
		
		//printf( " %s\n", token );
	   /* walk through other tokens */
	   while( token != NULL ) {
	      
	      //Check path
		if (strcmp(token, "path") == 0){
			
			//printf('/' + token2);
			strip(token);
			printf( " %s\n", token );
		}
	      
	      token = strtok(NULL, s);
	      strip(token);
	   }
    	
      //printf("Enter a command", a);
      //printf("%s", buffer);
      //a++;
      
	}
	printf("wish> ");
        //printf("%s", str);
    fclose(fop);
	//}
}
