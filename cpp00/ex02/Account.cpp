/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:57:09 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/06/30 00:04:05 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit) : _nbDeposits(0), _nbWithdrawals(0) {
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << std::to_string(_accountIndex);
	std:: cout << ";amount:" << std::to_string(_amount) << ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << std::to_string(_accountIndex);
	std::cout << ";amount:" << std::to_string(_amount);
	std :: cout << ";closed" << std::endl;
}

int Account::getNbAccounts(void){
	return (_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (_totalAmount);
}

int Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << std::to_string(Account::getNbAccounts());
	std::cout << ";total:" << std::to_string(Account::getTotalAmount());
	std::cout << ";deposits:" << std::to_string(Account::getNbDeposits());
	std::cout << ";withdrawals:" << std::to_string(Account::getNbWithdrawals()) << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << std::to_string(_accountIndex);
	std::cout << ";p_amount:" << std::to_string(_amount);
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:" << std::to_string(deposit);
	std::cout << ";amount:" << std::to_string(_amount);
	std::cout << ";nb_deposits:" << std::to_string(_nbDeposits) << std::endl;
}

bool Account::makeWithdrawal(int withdrawl) {
	_displayTimestamp();
	std::cout << "index:" << std::to_string(_accountIndex);
	std::cout << ";p_amount" << std::to_string(_amount);
	std::cout << ";withdrawal:";
	if (withdrawl <= _amount)
	{
		_amount -= withdrawl;
		_nbWithdrawals++;
		_totalAmount -= withdrawl;
		_totalNbWithdrawals++;
		std::cout << std::to_string(withdrawl);
		std::cout << ";amount:" << std::to_string(_amount);
		std::cout << ";nb_withdrawals:" << std::to_string(_nbWithdrawals) << std::endl;
		return (true);
	}
	else
		std::cout << "refused" << std::endl;
	return (false);
}

int Account::checkAmount(void) const {
	return (_amount);
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << buffer << "] ";
}