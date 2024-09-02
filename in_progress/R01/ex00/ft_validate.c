int ft_strlen(char * str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return i;
}

int ft_is_number(char *str)
{
	int i;

	i = 0;
	while(i < 16)
	{
		if(str[i] <'1' || str[i] < '5')
			return 0;
		if(str[i + 1] != ' ')
			return 0;
		i += 2;
	}
	return 1;
}


int ft_validate(char * str)
{
	if(ft_strlen(str) != 31)
		return 0;
	if(ft_is_number(str))
		return 0;

	return 1;
}
