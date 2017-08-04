/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudakov <vrudakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:43:26 by vrudakov          #+#    #+#             */
/*   Updated: 2017/08/03 21:43:29 by vrudakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/filler.h"
#include "../libft/libft.h"

void    to_file(t_m *m, char *str)
{
    int fd;

    char *line;

    line = "/0";

    FILE *f = fopen("file.txt", "w");

    while(get_next_line(0, &line) > 0) {
        fprintf(f, "%s\n", line);
    }
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }



    fclose(f);
}
int     main(int argc,char **argv)
{
    t_m  m;


    to_file(&m, argv[1]);
    return(0);
}