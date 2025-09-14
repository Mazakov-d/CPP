/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestClass.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:10:47 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/14 17:11:13 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTCLASS_HPP
# define TESTCLASS_HPP

# include "Serializer.hpp"

class TestClass: public Serializer {
    public:
        TestClass();
        TestClass(const TestClass& cpy);
        TestClass& operator=(const TestClass& other);
        ~TestClass();
};

#endif