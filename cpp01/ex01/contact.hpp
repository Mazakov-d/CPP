#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		~Contact();

		std::string	retFirstName();
		std::string	retLastName();
		std::string	retNickname();
		std::string	retPhoneNumber();
		std::string	retDarkestSecret();
	
		void	addFirstName(const std::string newFirstName);
		void	addLastName(const std::string newLastName);
		void	addNickname(const std::string newNickname);
		void	addPhoneNumber(const std::string newNumber);
		void	addDarkestSecret(const std::string newDarkestSecret);
};

#endif