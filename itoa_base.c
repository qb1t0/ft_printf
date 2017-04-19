#include "ft_printf.h"

static char			*ft_strnew(size_t size)
{
	char *buf;
	char *lol;

	if (!(buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	lol = buf;
	size++;
	while (size--)
		*buf++ = '\0';
	return (lol);
}

static void			*ft_strrev(char *s)
{
	char *end;
	char *start;
	char c;

	start = s;
	end = s + ft_strlen(s) - 1;
	while (s < end)
	{
		c = *s;
		*s++ = *end;
		*end-- = c;
	}
	return (start);
}

static int          ft_wordnum(long long int n, int base)
{
	int i;

	i = 0;
	(n <= 0 && base == 10) ? (i++) : (0);
	while (n != 0) {
		n /= base;
		i++;
	}
	return (i);
}

char				*ft_itoabase(long long int n, int base, char *l)
{
	char           *buf;
	long long int	lol;
	int				i;
	int				wordnum;

	i = 0;
	wordnum = ft_wordnum(n, base);
	if (n + 1 == -9223372036854775807)
		return("9223372036854775808");
	if (!(buf = ft_strnew((size_t)wordnum)))
		return (NULL);
	(n < 0 && base == 10) ? n *= -1 : 0;
	if ((n == 0) ? buf[0] = '0' : 0)
		i++;
	while (n != 0)
	{
		lol = n % (unsigned long long int)base;
		(lol < 0) ? lol *= -1 : 0;
		(lol > 9) ? lol += 7 : 0;
		buf[i++] = lol + '0';
		n /= base;
	}
	buf[i] = '\0';
	l = ft_strrev(buf);
	ft_strdel(&buf);
	return (l);
}

char				*ft_unitoabase(unsigned long long int n, \
	int base, char *lick)
{
	char           	*buf;
	long long int	lol;
	int				i;
	int				wordnum;

	i = 0;
	wordnum = ft_wordnum(n, base);
	if (!(buf = ft_strnew((size_t)wordnum)))
		return (NULL);
	if ((n == 0) ? buf[0] = '0' : 0)
		i++;
	while (n != 0)
	{
		lol = n % (unsigned long long int)base;
		(lol < 0) ? lol *= -1 : 0;
		(lol > 9) ? lol += 7 : 0;
		buf[i++] = lol + '0';
		n /= base;
	}
	buf[i] = '\0';
	lick = ft_strrev(buf);
	//ft_strdel(&buf);
	return (lick);
}
