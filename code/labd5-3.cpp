/**
 * Simple User Authentication System
 * 
 * Authors:
 * (1) MD Fahad Hossain Tareq (2410003)
 * (2) Nazmul Islam Nice (2410005)
 * (3) Mehedi Rahman Mahi (2410015)
 */

#include <iostream>

using namespace std;

class User
{
	string username;
	string password;

public:
	User(string name, string pass="password")
    {
		username = name;
		password = pass;
	}

	bool login()
    {
		cout<<"Logging in as "<<username<<endl;

		string pass;
		cout<<"Enter password for "<<username<<": ";
		getline(cin, pass);

		if (pass==password)
        {
			cout<<"Login Success!"<<endl;
			return 1;
		}
		else {
			cout<<"Invalid Password!"<<endl;
			return 0;
		}
	}

	void changePassword()
    {
		string pass;
		cout<<"Enter new password for "<<username<<" : ";
		getline(cin, pass);
		password=pass;
		cout<<"Password changed for "<<username<<endl;
	}

	friend class Admin;
};

class Admin
{
public:
	void resetPassword(User& usr)
    {
		usr.password = "";
		cout<<"Password reset for "<<usr.username<<" by admin"<<endl;
	}
};

int main()
{
	Admin admin;

	User u("Fahad");
	if(u.login()==0)
    {
		return 0;
	}
	u.changePassword();

	admin.resetPassword(u);
	u.login();

	return 0;
}