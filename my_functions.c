int my_strlen(const char *str){
	int len;
	for(len = 0;str[len] != '\0';len++){}
	return len;
}

char * my_strcpy(char *destin,const char *source){
	int i = -1;
	do{
		i++;
		destin[i] = source[i];
	}while(source[i] != '\0');
	return destin;
}

int my_strcmp(const char *str1,const char *str2){
	for(int i=0;(str1[i] != '\0')||(str2[i] != '\0');i++){
		if((str1[i] - str2[i]) != 0 ){return(str1[i] - str2[i]);}
	}
	return 0;
}