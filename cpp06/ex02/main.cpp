/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:13:47 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/14 20:53:17 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include <unistd.h>

int main()
{
    Base* generator = new A();
    Base* r;

    for (int i = 0; i < 5; i++)
    {
        r = generator->generate();
        generator->identify(*r);
        generator->identify(r);\
        sleep(2);
        delete r;
    }
    delete generator;
}