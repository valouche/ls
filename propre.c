#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <errno.h>
#include <string.h>


char	*getpath(char *arg, char *file)
{
  if (!ft_strcmp(arg, file))
    return (0);
  char *path;
  path = ft_strjoin(arg, "/");
  path = ft_strjoin(path, file);
  return (path);
}


void	recursiv(DIR *rep, struct dirent *dir)
{
  while ((dir = readdir(rep))) {
    if (!ft_strcmp(dir->d_name, ".") || (!ft_strcmp(dir->d_name, "..")))
      continue;
      if (!ft_strcmp(dir->d_name, "libft"))
	recursiv(opendir(dir->d_name), dir);
       ft_putendl(dir->d_name);
  }
}

int main(int ac, char **av)
{
  (void)ac;
  (void)av;
  struct dirent	*dir = NULL;
  //  DIR  *rep = opendir(av[1]);
  DIR		*rep = opendir(".");
  //struct	stat	stat;
  //t_data	*data = NULL;
  //int		i = 1;
  //t_arg		*arg = NULL;

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
      }
   data = malloc(sizeof(t_data));
     while ((dir = readdir(rep))) {
    if (!ft_strcmp(dir->d_name, ".") || (!ft_strcmp(dir->d_name, "..")))
      continue;
       ft_putendl(dir->d_name);

  // LS basique 
   while (dir) 
    {
      if (!ft_strcmp(dir->d_name, ".") || (!ft_strcmp(dir->d_name, "..")))
	continue;
      printf("%s\n", dir->d_name);
      lstat(getpath(".", dir->d_name), &stat);  
      data->size = stat.st_size;
      dir = readdir(rep);
    
while (i < ac)
   {
     rep = opendir(av[i]);
      if (rep == NULL){
	perror(av[i]);
	return (-1);
	}
     while ((dir = readdir(rep))) {
       if (!ft_strcmp(dir->d_name, ".") || (!ft_strcmp(dir->d_name, "..")))
	 continue;       
	 rep = opendir(dir->d_name);
       ft_putendl(dir->d_name);
       //lstat(getpath(av[i], dir->d_name), &stat);  
       //data->size = stat.st_size;
     }
      i++;

	}*/
  recursiv(rep, dir);
  return (0);
}
