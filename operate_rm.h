

void operate_rm(char *path){
int out = remove(path);
if(out!=0){
    perror("Could not delete the file");
    return;
}

}

void operate_rmdir(const char* path){
struct dirent **list_of_files;
int nitems = scandir(path, &list_of_files, NULL, alphasort); 
if(nitems==0){
    int res = rmdir(path);
}   
else{
    for(int i=0; i<nitems; i++){
        if(list_of_files[i]->d_type==DT_REG && strcmp(list_of_files[i]->d_name,".")!=0 && strcmp(list_of_files[i]->d_name,"..")!=0){
            char *newname = (char *)malloc(sizeof(char)*256);
            newname[0] = '\0';
            strcpy(newname,path);
            strcat(newname,"/");
            strcat(newname,list_of_files[i]->d_name);
            operate_rm(newname);
            free(newname);
        }
        else if(list_of_files[i]->d_type==DT_DIR && strcmp(list_of_files[i]->d_name,".")!=0 && strcmp(list_of_files[i]->d_name,"..")!=0){
            char *newname = (char *)malloc(sizeof(char)*256);
            newname[0] = '\0';
            strcpy(newname,path);
            strcat(newname,"/");
            strcat(newname,list_of_files[i]->d_name);
            operate_rmdir(newname);
            free(newname);
        }
    }
    int res = rmdir(path);
    if(res!=0){
        perror("error in deleting");
    }

}
}
