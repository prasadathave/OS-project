
/// getting the arguments from the shell
void inputval(){

fflush(stdout);//clearing of the buffers
input = NULL;
size_t a =0;//auxilary input for library function readline
for(int i=0; i<20; i++){
    free(arg[i]);
    arg[i] = NULL;
}


 getline(&input,&a,stdin);

 foruse = (char *)malloc(strlen(input)*sizeof(char));
 strncpy(foruse,input,strlen(input));
 agruments=0; doinbackground=0;
 char* tok;
 const char *s =" ";
 tok = strtok(input,s);
 
 arg[agruments] = tok;
 while(tok!=NULL){
     arg[agruments]= (char *)malloc(sizeof(tok)*strlen(tok));
     strcpy(arg[agruments],tok);
     agruments++;
     tok = strtok(0,s);
 }

 if(arg[agruments-1][strlen(arg[agruments-1])-1]=='\n'){
     arg[agruments-1][strlen(arg[agruments-1])-1]='\0';
 }
if(strcmp(arg[agruments-1],"&")==0){
    doinbackground=1;
}
if(agruments>1 && strcmp(arg[1],"\0")==0){
    agruments-=1;
    arg[1] = NULL;
}

free(foruse);
}
