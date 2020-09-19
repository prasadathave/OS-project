
//operating the move command
void operate_mv(){
    if(agruments!=3){
        printf("Arguments are not proper");
        return;
    }
    else{
        int v =rename(arg[1],arg[2]);
        if(v){
            perror("Could not move file");
        }
    }

}
