#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "contact.hpp"

class PhoneBook {
	private:
		Contact _contacts[8];
		int _contactCount;
		int _oldestContact;

	public:
		PhoneBook();
		~PhoneBook();

		int addContact();
		int searchContact();
};

#endif