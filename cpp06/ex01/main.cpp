/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:14:01 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/14 17:17:46 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestClass.hpp"
#include <iomanip>

void    dispData(Data* data) {
    std::cout << data->i << std::endl;
    std::cout << data->d << std::endl;
    std::cout << data->ptr << std::endl;
    std::cout << data->c << std::endl;
}

int main()
{
    Serializer* test = new TestClass;
    Data*   data = new Data;
    uintptr_t   r;
    
    std::cout << std::fixed << std::setprecision(1);
    data->c = 'c';
    data->i = 42;
    data->d = 42.0;
    data->ptr = &(data->c);
    dispData(data);
    r = test->serialize(data);
    std::cout << r << std::endl;
    data = test->deserialize(r);
    dispData(data);
}