#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>

typedef struct s_stack
{
		int				nbr;
		struct	s_stack	*next;
		struct	s_stack	*prv;
}	t_stack;

typedef struct s_var
{
		char			*line;
		char			**split;
		char			**av;
		int				ac;
		int				len;
		int				print;
		int				fd;
		t_stack			*a;
		t_stack			*b;
}	t_var;

void		ft_bzero(void *s, size_t n);
char		**ft_split(const char *str, char cara);
char		*ft_strdup(const char *old_string);
int			ft_isalpha(int character);
size_t		ft_strlen(const char *string);
void		sort_bigger(t_stack **a, t_stack **b, int len, t_var *v);
void		sort_bigger_third(t_stack **a, t_stack **b, int max, t_var *v);
void		sort_bigger_second(t_stack **a, t_stack **b, int len, t_var *v);
void		sort_bigger_first(t_stack **a, t_stack **b, int len, t_var *v);
int			check_pivot(t_stack *a, int pvt, int flag);
int			check_sort(t_stack **a, int len);
void		check_dup(char **av);
void		check_nbr(char **av);
int			check_overf(char *str);
char		**fill_arg(t_var *v, int ac, char **av);
t_stack		*fill_list(t_var *v, char **split, t_stack *tmp);
t_stack		*find_bottom(t_stack *a);
int			find_min(t_stack *stk);
int			find_max(t_stack *stk);
int			find_index(t_stack *stk, int num, int flag);
int			find_pivot(t_stack *stk);
int			ft_abs(float num);
void		ft_free_array(char **array);
void		ft_free_arg(char **arg);
int			ft_strcmp(char *s1, char *s2);
t_var		*init_var(t_var *v);
void		free_stk(t_stack **stk);
int			list_size(t_stack *a);
void		add_list_front(t_stack **top, t_stack *new);
void		add_list_back(t_stack **first, t_stack *new);
void		add_list_back_r(t_stack **top);
int			ft_list_nbr(t_stack **stk, int index);
t_stack		*ft_list_sort(t_stack *stk);
void		ft_list_swap(t_stack *x, t_stack *y);
t_stack		*ft_lst_dup(t_stack *stk);
void		ft_exit(char *str, int err);
void		sort_big_norm_1(t_stack **a, t_stack **b, t_var *v, int pvt);
void		sort_big_norm_2(t_stack **a, t_stack **b, t_var *v, int pvt);
void		op_p_stk(t_stack **a, t_stack **b, t_stack *tmp);
void		op_r_stk(t_stack **top);
void		op_rr_stk(t_stack **top, t_stack *tmp);
void		op_rr_bottom(t_stack **top);
t_stack		*op_rr_swap(t_stack *top, t_stack *tmp);
void		op_s_stk(t_stack **top);
void		first_parsing(t_stack **a, t_stack **b, int nbr, t_var *v);
void		second_parsing(t_stack **a, t_stack **b, int nbr, t_var *v);
void		third_parsing(t_stack **a, t_stack **b, int nbr, t_var *v);
long long	ps_atoll(char *s);
void		sort_short(t_stack **a, t_stack **b, int len, t_var *v);
void		sort_short_short(t_stack **a, t_stack **b, int len, t_var *v);
void		sort_short_3(t_stack **a, t_stack **b, t_var *v, int c);
void		sort_short_big(t_stack **a, t_stack **b, int len, t_var *v);
void		sort_short_big_norm(t_stack **a, t_stack **bb, t_var *v, int min);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);

#endif