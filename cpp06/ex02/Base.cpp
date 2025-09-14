/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:04:42 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/14 20:49:13 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() {}

Base::Base(std::string name): _name(name) {}

Base::~Base() {}

Base* makeA() {
    return new A();
}

Base* makeB() {
    return new B();
}

Base* makeC() {
    return new C();
}

Base* Base::generate(void) {
    int i;
    Base* (*constructors[])() = {makeA, makeB, makeC};
    
    std::srand(std::time(0));
    i = std::rand() % 3;

    return constructors[i]();
}

void    Base::identify(Base& p) {
    A *a;
    B *b;
    C *c;
    
    a = dynamic_cast<A*>(&p);
    b = dynamic_cast<B*>(&p);
    c = dynamic_cast<C*>(&p);
    if (a)
    {
        std::cout << "This is a A class var.";
        std::cout << " Here is the proof: " << p._name << std::endl;
    }
    else if (b)
    {
        std::cout << "This is a B class var.";
        std::cout << " Here is the proof: " << p._name << std::endl;
    }
    else if (c)
    {
        std::cout << "This is a C class var.";
        std::cout << " Here is the proof: " << p._name << std::endl;
    }
}

void    Base::identify(Base* p) {
     A *a;
    B *b;
    C *c;
    
    a = dynamic_cast<A*>(p);
    b = dynamic_cast<B*>(p);
    c = dynamic_cast<C*>(p);
    if (a)
    {
        std::cout << "This is a A class var.";
        std::cout << " Here is the proof: " << p->_name << std::endl;
    }
    else if (b)
    {
        std::cout << "This is a B class var.";
        std::cout << " Here is the proof: " << p->_name << std::endl;
    }
    else if (c)
    {
        std::cout << "This is a C class var.";
        std::cout << " Here is the proof: " << p->_name << std::endl;
    }
}