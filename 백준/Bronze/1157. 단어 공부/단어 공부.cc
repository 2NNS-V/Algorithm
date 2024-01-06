#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[1000000];
	int arr[26]={0};
	int i,j,max,temp=0,check=0;
	int t;
	scanf("%s", str);
	t=strlen(str);
	for(i=0;i<t;i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
		{
			str[i]=str[i]+32;
		}
	}
	for(i=0;i<t;i++)
	{
		j=str[i]-97;
		arr[j]=arr[j]+1;
	}
	
	max=arr[0];  // 초기 최댓값 arr[0] 설정 
	for(i=0;i<26;i++)  // 최댓값이 저장된 i찾기 
	{
		if(max<arr[i])
		{
			max=arr[i];
			temp=i;
		}
	}
	
	for(i=0;i<26;i++)
	{
		if(max==arr[i]&&i!=temp)  
		{                         
			printf("?");
			check=1;              
            break;		
        }
	}
	
	if(check!=1) 
	{
		printf("%c", temp+65);      
	}	
	
return 0;
}