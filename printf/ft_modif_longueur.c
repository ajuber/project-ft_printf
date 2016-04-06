#include "ft_printf.h"

void	ft_modif_longueur(const char *format, t_env1 *env1, t_env2 *env2)
{
	if (!ft_strchr("hljz", format[env1->taille_f]))
		return ;
	if (ft_strncmp(&format[env1->taille_f], "hh", 2) == 0)
	{
		conv->modif = HH;
		env1->taille_f += 2;
		return ;
	}
	if (ft_strncmp(&format[env1->taille_f], "ll", 2) == 0)
	{
		conv->modif = LL;
		env1->taille_f += 2;
		return ;
	}
	else if (format[env1->taille_f] == 'h')
		conv->modif = H;
	else if (format[env1->taille_f] == 'l')
		conv->modif = L;
	else if (format[env1->taille_f] == 'j')
		conv->modif = J;
	else if (format[env1->taille_f] == 'z')
		conv->modif = Z;
}
