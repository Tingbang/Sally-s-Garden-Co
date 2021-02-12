// Sally's Gardening Program
// Darren Lally
//26/10/2016

#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

char answer;

//Declaration of Methods
void welcome_message();
void user_selection(char choice);
void garden_dimensions(char choice, double price);
void pricing(char choice, double price, float area);
void next_customer();

//Main Method
void main()
{
	system("cls");					//Clears the screen
	answer = 'N';
	do
	{
		system("cls");
		welcome_message();				//Calls the First method to be ran to start the flow of the program
	} while (answer == 'Y');

}

void welcome_message()				// Method that displays a option menu to user and prompts them to make a selection
{
	char choice;

	cout << "\n";
	cout << "===================================================================" << "\n";
	cout << "-------------- Sally's Gardening Tools! ----------------------------" << "\n";
	cout << "===================================================================" << "\n";
	cout << "\n";
	cout << " Price Per Square Metre:" << "\n";
	cout << "A. Grass = " << char(156) << "5.90" << "\n";
	cout << "B. Fake Grass = " << char(156) << "11.30" << "\n";
	cout << "C. Stone = " << char(156) << "6.95" << "\n";
	cout << "\n";
	cout << "Please select from the selections above ";
	cin >> choice;
	choice = toupper(choice);
	user_selection(choice);
}

void user_selection(char choice)		//A Method that processes the user selection and shows them how much the price per square metre is for their item
{
	double price;
	switch (choice)					//Switch Statement
	{
	case 'A':
		price = 5.90;
		break;
	case 'B':
		price = 11.30;
		break;
	case 'C':
		price = 6.95;
		break;
	}

	cout << "You have selected " << choice << ". " << "The price of your selection is: " << char(156) << price << "\n";
	garden_dimensions(choice, price);

} // End userSelection

  //This methods calculates the dimesnsion of the garden
void garden_dimensions(char choice, double price)
{
	float length, width, area;

	cout << "\n";
	cout << "Please enter the dimensions of the garden (in metres)" << endl;
	cout << "Enter the length" << endl;
	cin >> length;
	cout << "Enter the width" << endl;
	cin >> width;

	area = length*width;

	cout << "The total area of your garden is " << area << " metres squared" << endl;
	pricing(choice, price, area);

}

void pricing(char choice, double price, float area)			//Method that prices everything up for the user
{
	//Local variable decleration
	string covering;
	double cost;
	if (choice == 'A')											//If the user selects choice then it will display the selection name in the output
	{
		covering = "Grass";
	}
	else if (choice == 'B')
	{
		covering = "Fake Grass";
	}
	else if (choice == 'C')
	{
		covering = "Stone";
	}

	cost = (area * price) * 1.20;								//Calculation to work out the total cost including VAT

	cout << "Based on your selection of " << covering << "\n";
	cout << "Your price (including fitting) will be = " << char(156) << cost << " inc VAT (@ 20%)" << "\n";
	cout << "Thank you for your custom!" << endl;
	next_customer();
}

void next_customer()
{
	cout << "Do you wish to price another product? (Y/N)" << endl;
	cin >> answer;
	answer = toupper(answer);
}