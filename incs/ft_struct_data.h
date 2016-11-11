/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_data.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:16:21 by abary             #+#    #+#             */
/*   Updated: 2016/11/11 13:16:21 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_DATA_H
# define FT_STRUCT_DATA_H

typedef struct			s_data
{
	struct s_dmlx		mlx;
	struct s_dvm		vm;
	struct s_dargs		args[5];
}						t_data;

#endif
