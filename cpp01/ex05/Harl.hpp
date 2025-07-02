/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:38:31 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/06/30 22:45:56 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {
	private:

	void debug ( void );
	void info ( void );
	void warning ( void );
	void error ( void );

	public:

	Harl ();
	~Harl();
	void complain( std::string level );
};

#endif