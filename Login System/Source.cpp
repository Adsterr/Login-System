#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

bool isLoggedIn()
{
	string username, password, un, pw;

	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	ifstream read("data.txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	while (true)
	{
		int choice;

		cout << "1: Register\n2: Login\n3: Delete Data\nYour choice: "; cin >> choice;
		if (choice == 1)
		{
			string username, password;

			cout << "Select a username: "; cin >> username;
			cout << "Select a password: "; cin >> password;

			ofstream file;
			file.open("data.txt");
			file << username << endl << password;
			file.close();

			system("PAUSE");
			system("cls");

			main();
		}
		else if (choice == 2)
		{
			bool status = isLoggedIn();

			if (!status)
			{
				cout << "False Login!" << endl;
				system("PAUSE");
				system("cls");
			}
			else
			{
				cout << "Succesfully Logged In!" << endl;
				system("PAUSE");
				system("cls");
			}
		}
		else if (choice == 3)
		{
			if (remove("data.txt") != 0)
			{
				perror("Error deleting file");
				system("PAUSE");
				system("cls");
			}
			else
			{
				puts("File successfully deleted");
				system("PAUSE");
				system("cls");
			}
		}
	}
}