#include "dk_tool.h"
int func(char *s, char *seq){
	int count = 0;
	int i;
	int len = strlen(seq);
	char a = *(seq);
	char b = *(seq+1);
	for(i = 0; i<strlen(s); i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = s[i] + 32;
		}
		if((s[i] == *(seq)) && (len == 1)){
			count ++;
		}
		else if((s[i] == *(seq)) && (s[i+1] == *(seq+1))
		 && (len == 2)){
			count ++;
		}
		else if((s[i] == *(seq)) && (s[i+1] == *(seq+1))
		 &&(s[i+2] == *(seq+2)) && (len == 3)){
			count ++;
		}
	}
	printf("Your signs have met %d times \n", count);
	return 0;
}
