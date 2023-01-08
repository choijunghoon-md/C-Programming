#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
	
	int T;
	char str[255];
	int r,c;
	int c1,c2;
	int chk1,chk2,chk3;
	int i;
	int N;
	
	scanf("%d%*c",&T);
	
	if(T>=1 && T<=30){
		char **M=(char**)malloc(sizeof(char*)*T);
		for(r=0;r<T;r++)
		{
			scanf("%s%*c",str);
			if(strlen(str)>=3 && strlen(str)<100000)
			{
				M[r]=(char*)malloc(sizeof(char)*(strlen(str)+1));
				strcpy(M[r],str);
			}
			else
				return 0;
		}
		
		
		for(r=0;r<T;r++)
		{
			chk1=0;
			chk2=-1;
			N=strlen(M[r]);
			for(c=0;c<N/2;c++){
				if(M[r][c] == M[r][N+chk2-c]){
					continue;
				}
				else if(M[r][c] != M[r][N+chk2-c]){
					chk1++;
					if(M[r][c] == M[r][N+chk2-1-c]){
						chk2--;
						c--;
						continue;
					}
					else if(M[r][c+1] == M[r][N+chk2-c]){
						chk2++;
						continue;
					}
					else{
						chk1++;
						continue;
					}
				}
				
			}
			if(chk1==0){
					printf("0\n");
			}
			else if(chk1==1){
					printf("1\n");
			}
			else{
					printf("2\n");
			}
			
		}
		
	}
	return 0;
}