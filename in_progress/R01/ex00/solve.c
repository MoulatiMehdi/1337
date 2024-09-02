#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_grid(char **arr)
{
	int i;
	int j;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j< 3)
		{
			write(1,&arr[i][j],1);
			write(1," ",1);
			j++;
		}
		write(1,&arr[i][j],1);
		write(1,"\n",1);
		i++;
	}
}

void col_n_up(char** arr,int n,char c,char d)
{
	int j;

	if(c == '1'){
		arr[n][0] = '4';
	}
	else if(c == '4')
	{
		j = 0;
		while(j < 4)
		{
			arr[n][j] = '1' + j;
			j++;
		}
	}
	else if (c == '3')
	{
		if(d == '2')
		{
			arr[n][2] = '4';
			
		}
		else
			arr[n][3] = '4';
	}

}


void col_n_down(char** arr,int n,char c,char d)
{
	int j;

	if(c == '1')
		arr[n][3] = '4';
	if(c == '4')
	{
		j = 3;
		while(j >= 0)
		{
			arr[n][j] = '1' + j;
			j--;
		}
	}
	else if (c == '3')
	{
		if(d == '2')
			arr[n][1] = '4';
		else
			arr[n][2] = '4';
	}
}


void row_n_left(char** arr,int n,char c,char d)
{
	int j;

	if(c == '1')
		arr[0][n] = '4';
	if(c == '4')
	{
		j = 0;
		while(j < 4)
		{
			arr[j][n] = '1' + j;
			j++;
		}
	}
	else if (c == '3')
	{
		if(d == '2')
			arr[2][n] = '4';
		else
			arr[1][n] = '4';
	}
}

void row_n_right(char** arr,int n,char c,char d)
{
	int j;

	if(c == '1')
		arr[3][n] = '4';
	if(c == '4')
	{
		j = 3;
		while(j >= 0)
		{
			arr[j][n] = '1' + j;
			j--;
		}
	}
	else if (c == '3')
	{
		if(d == '2')
			arr[1][n] = '4';
		else
			arr[2][n] = '4';
	}
}

void error(void);
char ** init (void)
{
	int i;
	char **arr;
	int j;
	j = 0;
	i = 0; 
	arr = (char **) malloc(5*sizeof(char *)); 
	while(i < 4)
	{
		arr[i] = (char *) malloc(5*sizeof(char)); 
		i++;
	}

	i  = 0;

	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			arr[i][j] = '0';
			j++;
		}
		arr[i][j] = '\0';
		i++;
	}
	arr[4] = NULL;
	return arr;
}

void solve(char *str)
{
	char** arr;
	int i;

	arr = init();
	i = 0;

	print_grid(arr);
	while(i < 4)
	{
		col_n_up(arr,i,str[i*2],str[8 + i*2]);
		col_n_down(arr,i,str[8 + i*2],str[i*2]);
		row_n_left(arr,i,str[16 + i*2],str[24 + i *2]);
		row_n_right(arr,i,str[24 + i*2],str[16+i*2]);
		i++;
	}

	print_grid(arr);
}

