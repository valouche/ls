#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <errno.h>
#include <string.h>

typedef struct	s_arg {
  char		*str;
  struct s_arg	*next;
}		t_arg;

typedef struct	s_data {
  char		*name;
  mode_t	mode;
  nlink_t	nlink;
  uid_t		uid;
  gid_t		gid;
  time_t	mtime;
  off_t		size;
  char		*path;
  struct s_data	*next;
  struct s_data	*prev;
}		t_data;


t_arg	*mklist(char *content)
{
  t_arg *new = malloc(sizeof(t_arg *));
  if (new)
    {
      new->str = content;
      new->next = NULL;
    }
  return (new);
}


void	listend(t_arg *list, char *content)
{
  t_arg	*tmp = NULL;
  t_arg	*new = NULL;
  new = malloc(sizeof(t_arg*));
  if (!new)
    return;
  new->str = content;
  tmp = list;
  while (tmp->next)
      tmp = tmp->next;
  tmp->next = new;
  new->next = NULL;
}


char	*getpath(char *arg, char *file)
{
  if (!ft_strcmp(arg, file))
    return (0);
  char *path;
  path = ft_strjoin(arg, "/");
  path = ft_strjoin(path, file);
  return (path);
}

int	main(int ac, char **av) 
{
  (void)ac;
  (void)av;
  struct dirent	*dir = NULL;
  //  DIR  *rep = opendir(av[1]);
  DIR		*rep = opendir(".");
  struct	stat	stat;
  t_data	*data = NULL;
  //int		i = 1;
  //t_arg		*arg = NULL;

  // parsing arguments
  /*if (ac > 1)
    {
      while(i < ac)
	{ 
	  if (arg == NULL) {
	    arg = mklist(av[1]);
	  }
	  else
	      listend(arg, av[i]);
	  i++;
	  }
      // printf("%s\n", arg->str);
      //      printf("%s\n", arg->next->str);
      }*/
   data = ft_memalloc(sizeof(t_data));
  // dir = readdir(rep);
  // LS basique 
  while ((dir = readdir(rep))) 
    {
      if (!ft_strcmp(dir->d_name, ".") || (!ft_strcmp(dir->d_name, "..")))
	continue;
      printf("%s\n", dir->d_name);
      lstat(getpath(".", dir->d_name), &stat);  
      data->mode = stat.st_mode;
      if (S_ISDIR(data->mode) == 1)
	printf("isok\n");
      
    }

  //LS arg + perrno
     /*while (i < ac)
   {
     rep = opendir(av[i]);
      if (rep == NULL){
	perror(av[i]);
	return (-1);
      }
     while ((dir = readdir(rep))) {
       if (!ft_strcmp(dir->d_name, ".") || (!ft_strcmp(dir->d_name, "..")))
	 continue;
       ft_putendl(dir->d_name);
       lstat(getpath(av[i], dir->d_name), &stat);  
       //data->size = stat.st_size;
     }
     i++;
     }*/

 // Copy struct lstat
 /*lstat(av[1], &stat);
  data->mode = stat.st_mode;
  data->nlink = stat.st_nlink;
  data->uid = stat.st_uid;
  data->mtime = stat.st_mtime;
  data->size = stat.st_size;
  data->name = dir->d_name;
  printf("%lld", data->size);*/
  return (0);
  
}
