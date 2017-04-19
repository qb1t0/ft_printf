#include "ft_printf.h"

/*
**	HERE IS COPY OF STANDART LIBFT FUNCTIONS :
**	ft_tolower | ft_strlen | ft_isdigit | ft_strchr
**/

int         ft_tolower(int c)
{
	return (((c > 64) && (c < 91)) ? (c + 32) : c);
}

size_t      ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int         ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}


char        *ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (!*s)
			break ;
		s++;
	}
	return (0);
}

/*
** V for vendetta, K for kostul'
*/
char        *ft_kstrchr(const char *s, int c)
{
	char *k;

	k = "K";
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (!*s)
			break ;
		s++;
	}
	return (k);
}

