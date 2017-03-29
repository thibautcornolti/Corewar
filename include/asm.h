/*
** asm.h for asm in /home/thibrex/Dropbox/delivery/CPE/CPE_2016_corewar
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Fri Mar  3 13:25:17 2017 Thibaut Cornolti
** Last update Wed Mar 29 15:29:00 2017 Thibaut Cornolti
*/

#ifndef ASM_H_
# define ASM_H_

# define MAGIC			0xea83f3
# define NAME_LENGTH		128
# define COMMENT_LENGTH		2048
# define IDX_MOD		512
# define COMMENT_CHAR		'#'
# define LABEL_CHAR		':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','
# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_STRING		".name"
# define COMMENT_STRING		".comment"
# define REG_NUMBER		16

# define T_REG			1
# define T_DIR			2
# define T_IND			4

typedef struct	s_arg
{
  char		type;
  int		arg;
}		t_arg;

typedef struct	s_header
{
  int		magic;
  char		prog_name[NAME_LENGTH + 1];
  int		prog_size;
  char		comment[COMMENT_LENGTH + 1];
}		t_header;

typedef struct	s_data
{
  char		inst;
  t_arg		arg[3];
  struct s_data	*next;
}		t_data;

typedef struct		s_label
{
  char			*lname;
  int			lpos;
  struct s_label	*next;
}			t_label;

int		check_good_label(char *);
char		get_inst(char *);
void		write_endian(int, void *, int);
int		make_header(char **, t_header *);
int		contains_char(char, char *);
int		take_info(char *);
char		type_to_binary(char);
char		type_to_size(char, char);
char		*get_file(char *);
int		pre_start_header(int, t_header *);
int		get_fd_cor(char *);
char		*skip_comm(int);
int		inst_gen(char, t_arg[], int, int);
int		get_info_line(char *, t_data **, t_label **, int);
int		verify_type_arg(char *, int *, t_label *);
int		get_prog_size(t_data *);
void		write_header(int, t_header *);
int		nbr_arg(char);
void		add_octet_to_list(t_label *, int);
int		label(char *, t_label **);
int		get_label_pos(char *, t_label *);
int		get_type_size(char, t_data *);
void		decrease_label(t_label *, t_data *);
void		decrease_label_all(t_label *, t_data *);
void		write_data(int, t_data *);

#endif /* !ASM_H_ */
