#include<stdio.h>// importing the standerd library
#include "imports.h"// necessary variables and libraries to import
#include "get_input.h" // function for getting input
#include "operate_cat.h" // cat command
#include "operate_cd.h" // cd command
#include "operate_cp.h" //cp command
#include "operate_grep.h" // command
#include "operate_mkdir.h" // mkdir command
#include "operate_rm.h" // rm and rm -r/R command 
#include "operate_pwd.h" // pwd command
#include "operate_ls.h" // ls
#include "operate_mv.h" // mv 
#include "operate_chmod.h" //chmod command

int main(int argc,char *argv[]){
//getting the directory name for display on cmd
get_direc_name(direc_name,0);
//run loop this is the loop for working
while(flag==0){
    printf("%s%s->%s",COLOR_CYAN,direc_name,COLOR_DEF); //printing pathname in white
    inputval();// function for taking input
    if(!doinbackground && strcmp(arg[0],"exit")==0 || strcmp(arg[0],"quit")==0){
        flag=1; //ending the loop
    }
    else if( doinbackground!=1 && strcmp(arg[0],"ls")==0 && agruments>1 && strcmp(arg[1],"-l")!=0){
        // ls command
            operate_ls();
        continue;
    }
    else if( doinbackground!=1 && strcmp(arg[0],"ls")==0 && agruments==1){
        // ls command
            operate_ls();
        continue;

    }
    else if(doinbackground!=1 && strcmp(arg[0],"pwd")==0){
        //printing the path pwd command
        get_direc_name(direc_name,1);
    }
    else if(doinbackground!=1 && strcmp(arg[0],"cd")==0)
        {   //change directory function
            if(agruments==1){
                printf("Not enough arguments\n");// handeling the useless input
                continue;
            }
            char* path = arg[1];
            if(path[strlen(path)-1]=='\\'){//handling the filename with one rspace
                path[strlen(path)-1]='\0';
                strcat(path," ");
                strcat(path,arg[2]);
            }
            

            change_directory(path);
            continue;
        }

    else if(doinbackground!=1 && strcmp(arg[0],"cat")==0){
        // printing the file contents
        operate_cat();
        continue;
    }
    else if(doinbackground!=1 && strcmp(arg[0],"mkdir")==0){
       //making the directory
        operate_mkdir();
        continue;
    }
    else if(doinbackground!=1 && strcmp(arg[0],"grep")==0){
        // searching in the file
        operate_grep();
        continue;
    }
    else if(doinbackground!=1 && strcmp(arg[0],"mv")==0){
            // moving file from one place to other
            operate_mv();
            continue;
    }
    else if(doinbackground!=1 && strcmp(arg[0],"rm")==0 && agruments>1 && arg[1][0]=='-' && (arg[1][1]=='r' || arg[1][1]=='R')){
        struct dirent **file_list;
        // deleting the list of files inputed
        for(int i=2; i<agruments; i++){
            if(is_regular_file(arg[i])==1){
                operate_rm(arg[i]);
            }
            else if(scandir(arg[i],&file_list,NULL,alphasort)==0){
                int x = rmdir(arg[i]);
                if(x!=0){
                    perror("Could Not delete this folder:");
                }
            }
            else{
                operate_rmdir(arg[i]);
                //function for removing the directory rm -r/R
            }
        }
    }
    else if(doinbackground!=1 && agruments>2 && strcmp(arg[0],"rm")==0){
     //removing the non-directory stuff with the rm
        for(int i=1; i<agruments; i++){
            operate_rm(arg[i]);
        }
        continue;
    }
    else if(doinbackground!=1 && strcmp(arg[0],"cp")==0){
        operate_cp();
        //copying the files
    }
    else if(!doinbackground){
        //running the default binaries
        pid_t pid;
        pid = fork();
        if(pid==0){
            
            execvp(arg[0],arg);
            exit(0);
            //used fork because execvp kills process
        }
        else{
                // moving for next command after finishing of the first
                wait(NULL);
                continue;
            
        }
    }

    else{
        // running things in background
        arg[agruments-1] = NULL;
        pid_t pid;
        
        pid = fork();
        if(pid==0){
            printf("\n");
            printf("Process running in background with id: %d\n",(int) getpid());
            // runnning the background 
            execvp(arg[0],arg);
            // execvp at the end will kill the process
        
        }
        else{
            // in parent process we can continue for next input without sleeping
            continue;
        }
        
        

        
    }


}
return 0;
}
