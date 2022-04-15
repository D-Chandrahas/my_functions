
/*checks if parenthesis are balanced , max is maximum number of parenthesis
returns 1 if balanced, 0 if not*/
int balanced(char *expression,int max) {
	for(int k=1;k<=max;k++){
		for(int i=0;expression[i]!='\0';i++){
			if(((expression[i]=='(')&&(expression[i+1]==')'))||((expression[i]=='[')&&(expression[i+1]==']'))||((expression[i]=='{')&&(expression[i+1]=='}'))){
				int j;
				for(j=i;(expression[j+2]!='\0');j++){
					expression[j]=expression[j+2];
				}
				expression[j]='\0';
			}
		}
	}
	if(expression[0]=='\0') {return 1;}
	else {return 0;}
}

/*returns gcd of a,b*/
int gcd (int a,int b){
	if(a>b){
		int temp=a;
		a=b;
		b=temp;
	}
	int ret;
	
	if(b%a == 0){
		ret = a;
	}
	else{ret = gcd(b%a,a);}
	
	return ret;
}

/* swaps the values of ptr1 and ptr2 */
void swap_ptr(int **ptr1,int **ptr2){
	int *temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

/*array is shifted to left,1st element becomes last*/
void leftshiftarr(int *arr,int n){
	int arr0 = arr[0];
	for(int i=0;i<n-1;i++){
		arr[i] = arr[i+1];
	}
	arr[n-1] = arr0;
	return;
}

/*array is shifted to right,last element becomes 1st*/
void rightshiftarr(int *arr,int n){
	int arrn_1 = arr[n-1];
	for(int i=n-1;i>0;i--){
		arr[i] = arr[i-1];
	}
	arr[0] = arrn_1;
	return;
}

/* reverses an array of n elements*/
void revarr(int *arr,int n){
	int temp;
	for(int i=0;i<=((n-1)/2);i++){
		temp = arr[i];
		arr[i] = arr[(n-1)-i];
		arr[(n-1)-i] = temp;
	}
}

/* prints n elements od arr followed by \n */
void printarr(int *arr,int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

/* copies n elements from old to neu*/
void copyarr (int *old,int *neu,int n){
	for(int i=0;i<n;i++){
		neu[i] = old[i];
	}
}

/* prints all possible permutations of elements of array starting from index j to nth element
(tested only for j=0,n=total no. of elements*/
void permutate (int j,int n,int *arr){
	if(j==(n-1)){printarr(arr,n);return;}
	
	for(int i=j;i<=(n-1);i++){
		int temp[n];
		copyarr(arr,temp,n);
		anticlock_cycle(i,j,temp);
		premutate(j+1,n,temp);
	}
	return;
}

/* Returns 1 if 'search' is in arr, 0 otherwise
arr is an array of n integers in descending order. */
int bisectionSearch(int n, int arr[], int search) {
	
	if ((search > arr[0])||(search < arr[n-1])){
		return 0;
	}
	
	int low=n-1;
	int high=0;
	while(low-high > 1){
		if(search > (arr[(low+high)/2])){low = (low + high)/2;}
		else if (search < (arr[(low+high)/2])){high = (low + high)/2;}
		else if (search == (arr[(low+high)/2])){return 1;}
	}
	if ((arr[low] == search)||(arr[high] == search)){return 1;}
	else {return 0;}
}

/* returns 1 if composite, 0 if not*/
int isComposite (int n) {
	for (int i = 2; i <= n/2; i++) {
		if (n%i == 0){
			return 1;
		}
	}
	return 0;
}

/*returns factorial of n(no input checking)*/
int factorial (int n) {
	if (n == 0) {return 1;}
	for (int i = n-1; i >= 1; i--){
		n *= i;
	}
	return n;
}

/*checks if there is a sub array(in arr[n])whose sum of elements is k, returns 1 if true or 0 if false*/
int check_subarr_sum (int k,int n,int *arr){
	for(int elements=1;elements<=n;elements++){
		int sum = 0;
		for(int i=0;i<elements;i++){
			sum += arr[i];
		}
		if(sum == k){return 1;}
		for(int i=0;i<(n-elements);i++){
			sum -= arr[i];
			sum += arr[(i+elements)];
			if(sum == k){return 1;}
		}
		
	}
	return 0;
}

/*prints space separated starting position of every occurence of pat in str(length n), if no occurance found prints -1,terminates with \n */
void print_substring_pos(char *pat,char *str,int n){
	int rep=0;
	for(int i=0;(i<n)&&(str[i]!='\0');i++){
		for(int j=0;j<=n;j++){
			if((pat[j] != '\0')&&(pat[j] != str[i+j])){break;}
			if(pat[j] == '\0'){printf("%d ",i);rep++;break;}
		}
	}
	if(rep==0){printf("-1 ");}
	printf("\n");
	return;
}

/*converts string to integer*/
int str_to_int(const char *str){
	int num = 0;
	int j = 1;
	if(str[0] == '-'){j = -1;str++;}
	for(int i = (my_strlen(str)-1);i>=0;i--){
		num += (str[i] - 48)*j;
		j *= 10;
	}
	return num;
}