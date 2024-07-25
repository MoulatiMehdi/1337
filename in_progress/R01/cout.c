#include <stdio.h>


void combine(int* arr,int level)
{

	if(level <= 0)
	{
		int up = 1;
		int down = 1;

		int up_max = arr[0];
		int down_max=arr[3];

		for(int i=1; i < 4 ; i ++)
		{
			if(arr[4 - i - 1] > down_max){
				down_max = arr[4 - i -1];
				down ++;	
			}
			if(arr[i] > up_max){
				up_max = arr[i];
				up ++;	
			}
		}

		if(down == 2)
		{

			printf("%d -> ",up);
			for(int i=0;i< 4 ;i ++)
			{
				printf("%d",arr[i]);
			}
			printf(" <- %d",down);
			printf("\n");
		}
		return ;
	}

	int exist;

	for(int i = 1; i <= 4 ;i++ )
	{
		exist = 0;
		for(int j=0;j<4 -level ;j++)
		{
			if(arr[j] == i)
			{
				exist = 1;
				break;
			}

		}

		if(!exist)
		{
			arr[4 - level] = i;
			combine(arr,level-1);
		}
	}

}

void calc ()
{
	int arr [4] = {0};

	combine(arr,4);

}


int main()
{

	calc();
}
