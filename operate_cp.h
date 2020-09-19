
int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

void operate_cp(){
    if(agruments<=2){
        printf("Not enough arguments");
        return;
    }

    if(agruments==4 && ((strcmp(arg[1],"-r")==0) || (strcmp(arg[1],"-R")==0))){
        DIR *di = opendir(arg[2]);
        
        if(di){ 
        
        char *folderpath = (char *)malloc(sizeof(char)*500);
        folderpath[0] = '\0';
        strcat(folderpath,arg[agruments-1]);
        strcat(folderpath,"/");
        strcat(folderpath,arg[2]);
        if(is_regular_file(arg[2])==0){
        int statusdir = mkdir(folderpath,0777);
        struct dirent **list;
        int num_elements = scandir(arg[2],&list,NULL,alphasort);
        if(num_elements==0){
            return;
        }
        for(int i=0; i<num_elements; i++){
            if(list[i]->d_type==DT_REG && strcmp(list[i]->d_name,".")!=0 && strcmp(list[i]->d_name,"..")!=0){
                char *newname = (char *)malloc(sizeof(char)*500);
                newname[0] = '\0';
                strcat(newname,folderpath);
                strcat(newname,"/");
                strcat(newname,list[i]->d_name);
                char *oldname = (char *)malloc(sizeof(char)*500);
                oldname[0] = '\0';
                strcat(oldname,arg[2]);
                strcat(oldname,"/");
                strcat(oldname,list[i]->d_name);
                FILE* fpp = fopen(newname,"w");
                FILE *fold = fopen(oldname,"r");
                if(fold==NULL){
                    perror("Could not open file");
                    return;
                }
                char c = fgetc(fold);
                while(c!=EOF){
                    fputc(c,fpp);
                    c = fgetc(fold);
                }

                fclose(fpp);
                fclose(fold);
                free(oldname);
                free(newname);
            }

        }


        }
        else{
            FILE * ff = fopen(folderpath,"w");
            FILE *fr = fopen(arg[2],"r");
           char c = fgetc(fr); 
        while (c != EOF) 
        { 
        fputc(c, ff); 
        c = fgetc(fr); 
        } 
  
        fclose(ff); 
        fclose(fr);

        }

        }
        else{
            printf("%s : No such directory exist or no permission to open\n",arg[2]);
        }
    }
    else if(agruments==3 && is_regular_file(arg[1])==1 && is_regular_file(arg[2])==1){
        if(is_regular_file(arg[1])==1 && is_regular_file(arg[2])==1){
            FILE *fp1, *fp2; 
            char  c; 
            fp2 = fopen(arg[2], "w");
            fp1 = fopen(arg[1], "r"); 
            if (fp1 == NULL) 
         { 
            printf("Cannot open file %s", arg[1]); 
            perror("");
            printf("\n");
        }  
     
    if (fp2 == NULL) 
    { 
        printf("Cannot open file %s", arg[2]); 
        perror("");
        printf("\n");

    } 
  
    // Read contents from file 
    c = fgetc(fp1); 
    while (c != EOF) 
    { 
        fputc(c, fp2); 
        c = fgetc(fp1); 
    } 
  
    fclose(fp1); 
    fclose(fp2); 
 }
}
else if(agruments>3 && is_regular_file(arg[agruments-1])==0){
int q =0;
for(int i=1; i<agruments-1; i++){
    if(is_regular_file(arg[i])==0){
        q =1;
    }
}

if(q==0){
    for(int i=1; i<agruments-1; i++){
        char* newname = (char *)malloc(sizeof(char)*260);
        strcat(newname,arg[agruments-1]);
        strcat(newname,"/");
        strcat(newname,arg[i]);
        FILE* fp1;
        FILE* fp2 = fopen(newname,"w");
        fp1 = fopen(arg[i],"r");
        if (fp1 == NULL) 
         { 
            printf("Cannot open file %s", arg[1]); 
            perror("");
            printf("\n");
        }  
        char c = fgetc(fp1); 
        while (c != EOF) 
        { 
        fputc(c, fp2); 
        c = fgetc(fp1); 
        } 
  
    fclose(fp1); 
    fclose(fp2); 
    free(newname);
    }
}
else{
execvp(arg[0],arg);
}

}
// copying a file into the folder
else if(agruments==3 && is_regular_file(arg[1])==1 && is_regular_file(arg[2])==0){
    char *filepath = (char *)malloc(sizeof(char)*500);
    strcat(filepath,arg[agruments-1]);
    strcat(filepath,"/");
    strcat(filepath,arg[1]);
    FILE * ff = fopen(filepath,"w");
    FILE *fr = fopen(arg[1],"r");
    char c = fgetc(fr); 
        while (c != EOF) 
        { 
        fputc(c, ff); 
        c = fgetc(fr); 
        } 
  
        fclose(ff); 
        fclose(fr);
}
}
