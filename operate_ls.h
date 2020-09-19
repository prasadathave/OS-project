
void printname(struct dirent* name)
{   char *tab= "   ";
    if(name->d_type == DT_REG)          // file with .extension
    {
        printf("%s%s%s",COLOR_GREEN, name->d_name,tab);
    }
    else if(name->d_type == DT_DIR)    // a directory
    {
        printf("%s%s/%s",COLOR_BLUE, name->d_name,tab);
    }
    else                              // unknown file types
    {
        printf("%s%s%s",COLOR_RED, name->d_name,tab);
    }
}



void operate_ls()
{ 
    int i=0;
    struct dirent **file_list;
    int numeber_of_items = scandir(".", &file_list, NULL, alphasort);//checking everything in directory using system call
    
    int nitems;
    struct dirent **fllist;
    if(numeber_of_items>=0 && agruments==1){
        for(i = 0; i < numeber_of_items; i++ )
        {       if(strcmp(file_list[i]->d_name,".")==0 || strcmp(file_list[i]->d_name,"..")==0){
                    continue;
                }
                printname(file_list[i]);    
                if(i%8==0){
                    printf("\n");
                }
        }
        printf("\n");
        return;
    }



    if (numeber_of_items >= 0) // printing selected elements
    {
        
        printf("\n");
        char *path_to_direc;
        if(agruments>1 && strcmp(arg[1]," ")!=0){
        for(i = 0; i < numeber_of_items; i++ )
        {       if(strcmp(file_list[i]->d_name,".")==0 || strcmp(file_list[i]->d_name,"..")==0){
                    continue;
                }
                if(file_list[i]->d_type==DT_DIR){
                    for(int x=1; x<agruments; x++){
                        if(strcmp(arg[x],file_list[i]->d_name)==0){
                            printf("%s\n\nprinting content inside folder ",COLOR_DEF);
                            printf("%s:\n",arg[x]);
                            path_to_direc = (char *)malloc((strlen(arg[x])+4)*sizeof(char));
                            path_to_direc[0] = '.';
                            path_to_direc[1] = '/';
                            path_to_direc[2] = '\0';

                            strcat(path_to_direc,arg[x]);
                    nitems = scandir(path_to_direc,&fllist,NULL, alphasort);
                    if (nitems >= 0) // if elements exist then checking
                    {
                    for(int z = 0; z < nitems; z++ )
                    {   
                     if(strcmp(fllist[z]->d_name,".")==0 || strcmp(fllist[z]->d_name,"..")==0){
                        continue;
                     }
                    printname(fllist[z]);    
                    if(z%8==0){
                    printf("\n");
                    }
                    }
                    printf("\n");

                }
            }
        }
    }
    else if(file_list[i]->d_type==DT_REG){
        
        for(int z=1; z<agruments; z++){
            if(strcmp(arg[z],file_list[i]->d_name)==0){
                printf("%sfound after searching in current folder:",COLOR_DEF);
                printname(file_list[i]);
            }
        }
    }
    
    }
    }
    printf("\n");
    }
    else
    {
        perror (" internal error in ls");
    }

}
