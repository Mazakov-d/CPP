#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <contact.hpp>

class PhoneBook {
	private:
		Contact contacts[8];
		int		contactCount;
};

#endif