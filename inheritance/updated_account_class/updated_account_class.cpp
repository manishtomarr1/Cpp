#include<iostream>
#include<string>
#include<vector>
using namespace std;
class account {
	friend std::ostream& operator << (std::ostream& os, const account& account) {
		os << "[accountn:" << account.name << ": " << account.balance << "]";
		return os;
	}
protected :
	string name;
	double balance{0.0};
public :
	account(string name_val = "unnamed account", double balance_val = 0.0);
	bool deposite(double ammount); // kyuki jb vector chalega ammount deposite krne wo true falls dekhega
	bool withdraw(double ammount);
	void get_balance() const;
};
account::account(string name_val, double balance_val) 
: name(name_val) , balance (balance_val) {
 //cout << "welcome : " << name << endl;
 //cout << "your available balance is : rs " << balance << endl;
}
    bool account::deposite(double ammount) {
		if (ammount < 0) {
			cout << "invalid ammount! try a valid ammount which is greator then 0" << endl;
			return false;
		}
	else {
	balance += ammount;
//cout << " the ammount : " << ammount << " is credited in your account." << endl;
//cout << "available balance is : " << balance << endl;
		return true;
	}

}
	bool account :: withdraw (double ammount) {
		if ((balance - ammount) >= 0) {
			balance -= ammount;
		//cout << "the ammount : " << ammount << " is debited." << endl;
			return true;
		}
		else
			cout << "insufficient funds" << endl;
		return false;
	}
	void account::get_balance() const {
		cout << "avalible balance is : " << balance << endl;
	}
	class saving_account : public account {
//friend std::ostream& operator<<(std::ostream& os, const saving_account& account) {
//	os << "[account:" << account.name << ": " << 
//	return os;
//	}
	protected :
		string name;
		double def_balance;
		double intr_rate;
	public:
		saving_account(string name_val = "unnammed account", int bal_val = 0, int intr_val = 0)
		:  name(name_val), def_balance(bal_val), intr_rate(intr_val){

		}
		bool deposite(double ammount);
		// withdraw is inherit by base class.
 };
//saving_account :: saving_account (string name_val, double balance_val, double int_rate) 
//   :  name (name_val), def_balance (balance_val) , intr_rate (int_rate) {
//
//
//  	}
	bool saving_account::deposite(double ammount) {
		if (ammount >= 0) {
			ammount += (ammount) * (intr_rate / 100);
			account::deposite(ammount); // use deposite method of the base class jo work wo wha krra tha wohi work yha karainge.
			return true;
		}
		else {
			cout << "enter valid ammount ! " << endl;
		}
		return false;
	}
	class checking_account : public account{
//	friend std::ostream& operator << (std::ostream& os, const account& account) {
//		os << "[accountn:" << account.name << ": " << account.balance << "]";
//		return os;
//	}
	protected:
		string name;
		double balance;
		const double ddt{ 1.50 };
	public:
		checking_account(string name_val , double bal_val )
			 {
			name = name_val;
			balance = bal_val;
		}
		bool withdraw(double ammount) {
			if ((balance - ammount) >= 0) {
				balance -= (ammount + ddt);
				//account::withdraw(ammount);
				cout << balance << endl;
				return true;
			}
			else
				return false;

		}
		bool deposite(double ammount) {
			account::deposite(ammount);
			return true;
		}
		
	};
	class trust_account : public account {
	protected:
		string name;
		double balance;
		const double intr_rate{ 50 };
	public :
		trust_account(string name, double balance) {

		}
		bool deposite(double ammount) {
			if (balance + ammount >= 5000) {
				ammount=  (ammount + intr_rate);
				balance += ammount;
				cout << balance << endl;
			}
			else {
				balance += ammount;
			}
			
			return true;
		}
	
	};
	// utility helper functions for account class.
	void display(vector<account> & account) {

		// display account object in the vector of account object

		//std::cout << "========accounts========" << std:: endl;
		for (const auto & acc : account) {
			std::cout << acc << std:: endl;
		}
	} 
	void deposite(vector <account>& account, double ammount) {
		// deposite ammount to each object of the vector
		std::cout << "========deposite to account ========" << std::endl;
		for (auto & i : account) {
			if (i.deposite(ammount)) // deposite (ammount) naam ka function true hua toh yeh hooga
				std::cout << "deposited " << ammount << " to " << i << std::endl;
			else
				std::cout << "failed deposite of " << ammount << " to " << i << std::endl;
		}
	}
	void withdraw(vector <account>& account, double ammount) {
		// withdraw ammount to each object of the vector
		std::cout << "========withdraw========" << std::endl;
		for (auto& i : account) {
			if (i.withdraw(ammount))
				std::cout << "withdrew " << ammount << " from " <<  i << std::endl;
			else
				std::cout << "failed withdrew of " << ammount << " from " << i << std::endl;
		}
	}

	// utility helper functions for saving account class.

	void display(vector <saving_account>& accounts) {
		std::cout << "========saving accounts========" << std::endl;
		for (const auto& acc : accounts) {
			std::cout << acc << std::endl;
		}
	}
	void deposite(vector <saving_account>& accounts, double ammount) {
		std::cout << "========deposite to account ========" << std::endl;
		for (auto& acc : accounts) {
			if (acc.deposite(ammount)) // deposite (ammount) naam ka function true hua toh yeh hooga
				std::cout << "deposited " << ammount << " to " << acc << std::endl;
			else
				std::cout << "failed deposite of " << ammount << " to " << acc << std::endl;
		}
	}
		void withdraw(vector <saving_account>&account, double ammount) { // yha yeh saving account pae kaam krega
			std::cout << "========withdraw========" << std::endl;
			for (auto& i : account) {
				if (i.withdraw(ammount))
					std::cout << "withdrew " << ammount << " from " << i << std::endl;
				else
					std::cout << "failed withdrew of " << ammount << " from " << i << std::endl;
			}
		}
	//ulility helper function for checking account class
	void display(vector <checking_account>& account) {
		std::cout << "========checking_accounts========" << std::endl;
		for (const auto& acc : account) {
			std::cout << acc << std::endl;
		}
	}
     void withdraw(vector <checking_account>& account, double ammount) {
     	std::cout << "========withdraw========" << std::endl;
     	for (auto& i : account) {
     		if (i.withdraw(ammount))
     			std::cout << "withdrew " << ammount << " from " << i << std::endl;
     		else
     			std::cout << "failed withdrew of " << ammount << " from " << i << std::endl;
     	}
     }
	void deposite(vector<checking_account>& accounts , double ammount ) {
		std::cout << "========deposite to account ========" << std::endl;
		for (auto& acc : accounts) {
				if (acc.deposite(ammount)) // deposite (ammount) naam ka function true hua toh yeh hooga
					std::cout << "deposited " << ammount << " to " << acc << std::endl;
				else
					std::cout << "failed deposite of " << ammount << " to " << acc << std::endl;
			}
		}
	//ulility helper function for checking account class
	void display(vector<trust_account>& account) {
		std::cout << "========trust_accounts========" << std::endl;
		for (const auto& acc : account) {
			std::cout << acc << std::endl;
		}
	}
	void deposite(vector <trust_account>& account , double ammount) {
		std::cout << "========deposite to account ========" << std::endl;
		for (auto& acc : account) {
			if (acc.deposite(ammount)) // deposite (ammount) naam ka function true hua toh yeh hooga
				// aur eski khas baat yeh k jis b class k object ka vector banayenge usi k deposite function ko call krega.
				std::cout << "deposited " << ammount << " to " << acc << std::endl;
			else
				std::cout << "failed deposite of " << ammount << " to " << acc << std::endl;
		}
	}
	int main() {
		vector <account> names{}; // syntax of making a vector of account class or any class
		names.push_back(account{}); // default constructor calls of account class
		display(names); // syntax of passing vector in args.
		names.push_back(account{ "manish" });
		display(names);
		names.push_back(account{ "priyanshu" , 2000 });
		names.push_back(account{ "gaurav" , 5000 });
		display(names);
		deposite(names, 1000);
		withdraw(names, 5000);
	
		vector<saving_account> sav_names{};
		sav_names.push_back( saving_account{});
		sav_names.push_back(saving_account("manish", 5000));
		display(sav_names);
		deposite(sav_names, 2000);

		vector<checking_account> check_names{};
		check_names.push_back(checking_account("manish", 2000));
		display(check_names);
		deposite(check_names, 2000);
		display(check_names);
		withdraw(check_names, 1500);
		withdraw(check_names, 300);
		withdraw(check_names, 100);

		vector <trust_account> tru_name{};
		tru_name.push_back(trust_account("manish", 2000));
		deposite(tru_name, 2000);
		deposite(tru_name, 2000);
		deposite(tru_name, 2000);
		deposite(tru_name, 5000);
		deposite(tru_name, 1000);
		display(tru_name);


		return 0;
	}
