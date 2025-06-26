#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact{
	private:
		std::string	fist_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		Contact();
		~Contact();

		void	displayFirstName();
		void	displayLastName();
		void	displayNickname();
		void	displayPhoneNumber();
		void	displayDarkestSecret();
		void	addFirstName(const std::string first_name);
		void	addLastName(const std::string last_name);
		void	addNickName(const std::string nickname);
		void	addPhoneNumber(const std::string number);
		void	addDarkestSecret(const std::string darkest_secret);
};

#endif