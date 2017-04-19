#ifndef _FT_PRINTF_H_
#define _FT_PRINTF_H_

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

union				u_type
{
	char 			c;
	char 			*s;
	wchar_t 		*ls;
};

typedef struct		s_format
{
	int				i_pos;
	int 			retval;
}					t_format;

typedef struct		s_specif
{
	int				space;
	int				m;
	int				plus;
	int				znak;
	int				hash;
	int 			modif;
	int				zero;
	int 			width;
	int 			ac;
	int 			len;
	long long int	num;
	char 			lol;
	char			type;
	char 			*lick;
	union u_type	slen;

}					t_spesif;

typedef void (*proto)(va_list, t_format*, t_spesif*);

typedef struct 		s_func
{
	proto			f[123];
}					t_func;

int					ft_printf(char *format, ...);


size_t      		ft_wstrlen(wchar_t *s);
int					ft_tolower(int c);
int 			   	ft_isdigit(int c);
char				*ft_unitoabase(unsigned long long int, int,
								   char *lick);
char				*ft_itoabase(long long int, int, char *l);
void				ft_write(char *a, int i);
int					ft_swrite(char *a, t_format *tf, int howmuch);
void				ft_lswrite(int *value, t_format *tf,
							   int howmuch);
char    			*ft_strchr(const char *s, int c);
char        		*ft_kstrchr(const char *s, int c);
void				prf_putstr(char const *s, int* i);

size_t  			ft_strlen(const char *s);
int					str_error(t_spesif *spec, int *retval);
void        		ft_strdel(char **as);
void				s_n(va_list ap, t_format *tform,
						t_spesif *spec);
void				s_decimal(va_list ap, t_format *tform,
							  t_spesif *s);
void				s_unsig(va_list ap, t_format *tform,
							t_spesif *s);
void				s_string(va_list ap, t_format *tform,
							 t_spesif *spec);

void 				s_char(va_list ap, t_format *tform,
						   t_spesif *spec);
unsigned long long	tsize_uns(int i, va_list ap);
long long int		tsize_dec(int i, va_list ap);

long long int		*tsize_n(int i, va_list ap);
int					choose_sys(char b);
void				create_srtuct(t_spesif* spec);
int					ft_checkstr(char *str, t_spesif *spec, int base);
void				little_check(t_spesif *spec, char *format,
								 int *i);
int					parse_line(t_func *flags, t_format *tform,
								  char *f,
								  va_list ap);

#endif
