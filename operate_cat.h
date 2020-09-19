

void operate_cat(){
    if(agruments==1){
        printf("\n ERROR :No file mentioned\n\n");
        return;
    }


    for(int i=1; i<agruments; i++){
        char *filename = arg[i];
        char ch;
        FILE *fp = fopen(filename,"r");//opening file in read mode
        if(fp==NULL){
            printf("\n%sCan not open the file: %s\n",COLOR_RED,filename);
            perror("Error in opening file");
            
            
        }
        else{
            printf("\n%sContents of the file %s are:\n",COLOR_GREEN,filename);
            while((ch=fgetc(fp))!=EOF){
                    printf("%s%c",COLOR_BLUE,ch);
            }
            //reading and printing the files
            printf("\n\n");
            fclose(fp);
        }
    
    
    }
}
