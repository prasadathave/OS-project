
///getting the current directory name for shell
void get_direc_name(char *var, int iscommand){
 char temp[MAX_PATH];
 char *path = getcwd(temp,sizeof(temp));
 if(path!=NULL){
     strcpy(var,temp);
     if(iscommand==1){
         printf("%s%s\n%s",COLOR_YELLO,var,COLOR_BLUE);
     }
 }
 else{
     printf("error in getting name");
 }
}
