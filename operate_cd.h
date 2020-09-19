void get_name(char *var, int iscommand){
 char temp[MAX_PATH];
 char *path = getcwd(temp,sizeof(temp));
 if(path!=NULL){
     strcpy(var,temp);
     if(iscommand==1){
         printf("%s%s\n",COLOR_RED,var);
     }
 }
 else{
     printf("error in getting name");
 }
}
// changing the directory using the default function



void change_directory(char* path)
{
    if(agruments==1){
        printf("Not enough arguments");
        return;
    }

    int ret = chdir(path);
    if(ret==0) // path could be changed if cd successful
    {
        get_name(direc_name,0);
    }
    else perror("can not change the directory ");
}
