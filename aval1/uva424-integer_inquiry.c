#include <stdio.h>
#include <string.h>
#define MAX 256 

char output[MAX];
char number[MAX];

void fill_with_zeros(char *s, int len){
	char tmp[MAX];
	int i;
	strcpy(tmp, s);
	for(i=0; i<MAX-1; i++)
		s[i] = '0';
	s[MAX] = '\0';
	strcpy(s+(MAX-len-1), tmp);
}

int main(){
	int i,j,len, carry;
	int tmp;
	char *pos;
	
	fill_with_zeros(output,MAX);
	while(1){
		fgets(number, MAX, stdin);	
		if ((pos=strchr(number, '\n')) != NULL)
    			*pos = '\0';
		len = strlen(number);
		if(len == 1 && number[0] == '0')
			break;
		
		fill_with_zeros(number, len);
		carry = 0;
		j = strlen(output)-1;
		for(i=strlen(number)-1; i >= 0; --i, --j){
			number[i] = ((number[i] - '0') + carry)+'0';			
			tmp = (number[i] - '0') + (output[j] - '0');
			if(tmp >= 10){
				carry = 1;
				tmp -= 10;
			}else{
				carry = 0;
			}
			output[j] = (tmp)+'0';
		}	
	}
	j=0;
	while(output[j++] == '0');
	for(i=j-1; i<strlen(output); i++)
		printf("%c", output[i]);
	printf("\n");
	return 0;
}
