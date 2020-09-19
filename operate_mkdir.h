
/// Function for making directory
void operate_mkdir(){
    const char *folderpath = arg[1];

    if(folderpath==NULL){
        printf("\n%sNo filename mentioned\n",COLOR_RED);
        return;
    }
    int status = mkdir(folderpath,0777); // all required permissions given with 0777
    if(status==-1){
        perror("Error in making directory:");
    }

}
