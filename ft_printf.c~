#include "ft_printf.h"


int				str_error(t_spesif *spec, int *retval)
{
	char 		*msg;
	int 		i;

	i = 0;

	msg = "(null)";
	if (spec->ac < i)
	{
		if (spec->ac == -2)
			while (spec->width -- > 0)
				ft_write((spec->zero ? "0" : " "), ++(*retval));
		else
			while (msg[i])
				ft_write(&msg[i++], ++(*retval));
	}
	else
		while (spec->ac > i)
			ft_write(&msg[i++], ++(*retval));
	return (1);
}
void			create_flags(t_func *tflag)
{
	tflag->f['D'] = &s_decimal;
	tflag->f['d'] = &s_decimal;
	tflag->f['i'] = &s_decimal;
	tflag->f['O'] = &s_unsig;
	tflag->f['U'] = &s_unsig;
	tflag->f['o'] = &s_unsig;
	tflag->f['u'] = &s_unsig;
	tflag->f['x'] = &s_unsig;
	tflag->f['X'] = &s_unsig;
	tflag->f['b'] = &s_unsig;
	tflag->f['p'] = &s_unsig;
	tflag->f['c'] = &s_char;
	tflag->f['C'] = &s_char;
	tflag->f['s'] = &s_string;
	tflag->f['S'] = &s_string;
	tflag->f['n'] = &s_n;
}


int				read_format(t_format *tform, char *format, va_list ap)
{
	t_func tflag;

	//tflag = (t_func *)malloc(sizeof(t_func));
	tform->i_pos = -1;
	tform->retval = 0;
	create_flags(&tflag);
while (format[++(tform->i_pos)])
		if (format[tform->i_pos] == '%')
		{
			if (format[++tform->i_pos] == '%')
				ft_write("%", ++tform->retval);
			else if (format[tform->i_pos])
				parse_line(&tflag, tform, format, ap);
			else
				break;
		}
		else
			ft_write(&format[tform->i_pos], ++tform->retval);
	return (0);
}


/*
** FT_PRINTF == main func
*/

int				ft_printf(char *format, ...)
{
	va_list		ap;
	t_format	tform;

	if (!format)
		return (0);
	tform.i_pos = -1;
	va_start(ap, format);
	read_format(&tform, format, ap);
	va_end(ap);
	return(tform.retval);
}

#include <stdio.h>
#include <limits.h>

int main()
{
	//kek.cheburek;
	int m, n, c;
	char *b;
	int strlen = 0;
	int f = 0;
	//cheburek.koroche = 15 grn;
	//m = ft_printf("%- 05.5hh\n", 0);
	//printf("%d_________________\n", m);

	int d = 270;
	n = ft_printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\nMY SIZE: %d_________________\n", n);
	m = printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("\nMY SIZE: %d_________________\n", m);
	//t_printf("Hello, World from %d\n", 42);
	//printf("\afgfg\a");
	//printf("%d", sizeof(long int)*64*8);
	//ft_putstr(g);
	return (0);
}

