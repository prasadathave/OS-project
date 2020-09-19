
void operate_grep(){
    if(agruments!=3){
        printf("\nArguments are not proper\n");
        return;
    }
    char *pattern = arg[1];
    char *path = arg[2];
    char *out=NULL;
  char *line_temp = NULL;
  size_t line_temp_size = 0;
  ssize_t line_size;
  FILE *fp = fopen(path, "r");
  if (fp==NULL)
  {
    perror("\nCannot open file:");
    printf("\n");
    return;
    
  }
  line_size = getline(&line_temp, &line_temp_size, fp);
  while (line_size >= 0)
  {
    line_size = getline(&line_temp, &line_temp_size, fp);

    out = strstr(line_temp,pattern);
    if(out!=NULL){
        int i=0;
        while (i<line_size)
        {
            if((line_temp+i)==out){
                printf("%s%s",COLOR_RED,pattern);
                i = i+ strlen(pattern);
            }
            else{
                printf("%s%c",COLOR_DEF,line_temp[i]);
                i++;
            }
        }
    }
}
  free(line_temp);
  line_temp = NULL;
printf("\n");

  fclose(fp);
}

