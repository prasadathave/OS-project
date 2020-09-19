
void operate_chmod(){
    if(agruments!=3){
        printf("Not proper arguments");
        return;
    }

    int i;
    i = strtol(arg[1], 0, 8);
    if (chmod (arg[2],i) < 0)
    {
        perror("Could not channge mode");
    }

}
