#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret; : contactCount(0)		~Contact();

		void	displayFirstName();
		void	displayLastName();
		void	displayNickname();
		void	displayPhoneNumber();
		void	displayDarkestSecret();
	
		void	addFirstName(const std::string newFirstName);
		void	addLastName(const std::string newLastName);
		void	addNickname(const std::string newNickname);
		void	addPhoneNumber(const std::string newNumber);
		void	addDarkestSecret(const std::string newDarkestSecret);
};

#endif