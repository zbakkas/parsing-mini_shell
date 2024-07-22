/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-25 18:35:37 by zbakkas           #+#    #+#             */
/*   Updated: 2024-06-25 18:35:37 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <string.h>
#include <readline/readline.h>
#include "libft/libft.h"
#include <stdbool.h>


# define TOKENS_ERROR ": syntax error near unexpected token"
# define NEW_LINE_ERROR ": syntax error near unexpected token `newline'"
// # define HEREDOC_ERROR "minishell: syntax error near unexpected token `<<'"
// # define APPEND_ERROR "minishell: syntax error near unexpected token `>>'"
// # define IN_ERROR "minishell: syntax error near unexpected token `<'"
// # define OUT_ERROR "minishell: syntax error near unexpected token `>'"

# define QUOTES_ERROR ": unexpected EOF while looking for matching"
# define AMBIGUOUS_ERROR ": ambiguous redirect"
// # define SPACE_REDIRECTION_ERROR ": No such file or directory"


/////////////////////////////////////////////////
typedef struct s_envp
{
	char			*env;
	struct  s_envp	*prev;
	struct  s_envp	*next;
}                   t_envp;

/////////////////////////////////////////////

typedef struct  s_quote
{
    int inDoubleQuote ;
    int inSingleQuote ;

}t_quote;


typedef struct s_inp
{
    char *inp;
    bool is_h;

} t_inp;

typedef struct s_out
{
    char *out;
    bool is_a;

} t_out;



typedef struct s_args_n
{
    char **arguments;
    t_inp *inp;
    t_out *out;
    struct s_args_n *next;
    
} t_args_n;


char * get_str_redline();

char	**ft_split_pip(char  *s, char c);
char **split_part(char *s);
char *set_speece( char *str) ;


// char *get_argumants(char *str);
// char **get_flages(char *str);
// char *get_cmd(char *str);
char *change_var(char * str,int *err);
char **get_args(char **str);
t_out *get_out(char **str);
t_inp *get_inp(char **str);

t_args_n *initialization_list(char *line,t_envp *env);
void	ft_lstadd_backk(t_args_n **lst, t_args_n *new);
t_args_n	*ft_lstnew_one(char **str);
void	ft_lstiterr(t_args_n *lst);
void	clear_list(t_args_n **lst);



int check_errors(char *str,int err);
int chacke_q(char c,t_quote *q);