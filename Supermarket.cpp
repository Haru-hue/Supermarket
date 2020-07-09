#include <iostream>
#include <cstdlib> // for the use of system ("cls")
#include <ctime> // the use of the delay function
#include <string> // for the lower and toupper
#include <algorithm>
using namespace std;

//Supermarket project, that sells fruits: apples, mangoes, oranges, pineapple and banana
int orange = 100, apple = 200, pineapple = 50, banana = 30, mangoes = 70;
float prices [] = {7.5, 6.0, 8.2, 5.5, 10};
float money;
int number;
float cash;
string fruit;
int begin(); //Didn't want to start rearranging the code
class cashier { //Wasn't necessary but wanted the code to feel advanced
	public:
		string name;
};


void delay (int seconds) { //This is used for the timer
	int mseconds = 1000*seconds;
	clock_t start_time = clock();
	while (clock() < start_time + mseconds);
}

void Receipt () {
	transform(fruit.begin(), fruit.end(), fruit.begin(), ::toupper);
	cashier loopy;
	loopy.name = "Joshua";
	int i = 0;
   // current date/time based on current system: method from tutorialspoint
   time_t now = time(0);

   // convert now to string form
   char* dt = ctime(&now);
	int o=rand()%1000;
	cout<<"Printing Receipt";
	for (i = 0; i<=5; i++) {
		cout<<".";
		delay(1);
	}
	cout<<"\n-----------------------------------------------------------------"<<endl;
	cout<<"\tWALGREENS Supermarket\n\tBEVERLY HILLS, HOLLYWOOD\n\t"<<dt<<"\n\tCHECK #"<<o<<endl;;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Receipt:"<<endl;
	cout<<"ITEM\tQUANTITY\tPRICE"<<endl;
	cout<<fruit<<"\t"<<number<<"\t\t"<<money<<endl;
	cout<<"-----------------------------------------------------------------\n\tTOTAL\t$"<<money<<endl;
	cout<<"You have been served by "<<loopy.name<<endl;
	
	
	delay(1);
	cout<<"Thanks for shopping with us today! Would you like to purchase anymore items?"<<endl;//answer yes or no
	string choice;
	checkout:
	cin>>choice;
	transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
	if(choice == "yes" || choice == "no") {
		if(choice == "yes") {
			system("cls");
			begin();
		} else {
			cout<<"Thank you for shopping with us today, come back soon!"<<endl;
		}
	} else {
		cout<<"Invalid input"<<endl;
		goto checkout;
	}
	}



void fru () {
	string account;
	string pay;
	string payment;
	if (fruit == "banana" && banana >=number || fruit == "pineapple" && pineapple >= number || fruit == "mango" && mangoes >= number || fruit == "apple" && apple >= number || fruit == "orange" && orange >= number) {
		cout<<"How would you like to pay for the items?\nFull payment or Credit payment"<<endl;
		cin>>pay;
		transform(pay.begin(), pay.end(), pay.begin(), ::tolower);
		if (pay == "credit" || pay == "full") {
		if (pay == "credit"){
		delay(0.5);
		cout<<"In how many days will you be able to pay the sum?"<<endl;
		int days;
		cin>>days;
		cout<<"We expect our payment within the time frame of "<<days<<" days with a sum of $"<<money<<endl;
		Receipt();
		}
if (pay == "full") {
	cout<<"How would you like to pay for these items?\nPOS or in cash"<<endl;
	cin>>pay;
	transform(pay.begin(), pay.end(), pay.begin(), ::tolower);
	if(pay == "pos") {
		terminal:
		cout<<"What account will you be using? Savings or current"<<endl;
		cin>>account;
		transform(account.begin(), account.end(), account.begin(), ::tolower);
		if (account == "savings" || account == "current") {
			cout<<"Confirming Transaction of $"<<money<<" to Walgreens Supermarket"<<endl;
			pin:
			cout<<"Enter Transaction PIN"<<endl;
			delay(1);
			int PIN;
			cin>>PIN;
			if (PIN>999 && PIN <=9999) {
				Receipt();
			} else {
				goto pin;
			}
		} else {
			goto terminal;
		}
	} else if (pay == "cash") {
		cout<<"The total cost of these items is $"<<money<<endl;
		cout<<"How much will you be paying?"<<endl;
		float cash;
		cin>>cash;
		if(cash >= money) {
		if(cash>money) {
		cout<<"Here is your change of $"<<cash-money<<endl;
			Receipt();
		} else if (cash == money) {
			Receipt();
		}
	}
		else {
			cout<<"You don't seem to have enough money to pay for that?"<<endl;
			cout<<"Would you like to pay using your credit card?"<<endl;
			string choice;
			cin>>choice;
			if(choice == "yes" || choice == "Yes") {
				delay(0.5);
				goto terminal; //Had to use the goto function here
			} else {
				cout<<"Please come back when you have the means to pay for this item"<<endl;
			}
		}
	}
}
} else {
	cout<<"Please kindly return the items if you have no feasible method of payment"<<endl;
}

} else {
			cout<<"Sorry we dont have that many "<<fruit<<"s or we are out of stock, please come back tomorrow!"<<endl;
		}
}

void TakeRequest () {
	cout<<"What would you like to purchase today?"<<endl;
	cin>>fruit;
	transform(fruit.begin(), fruit.end(), fruit.begin(), ::tolower);
	if (fruit == "banana" || fruit == "pineapple" || fruit == "mango" || fruit == "apple" || fruit == "orange") {
		cout<<"How many would you like to buy?"<<endl;
		cin>>number;
		if(fruit == "banana") money = number * prices[3];
		else if(fruit == "apple") money = number * prices[1];
		else if(fruit == "pineapple") money = number * prices[2];
		else if(fruit == "mango") money = number * prices[4];
		else if(fruit == "orange") money = number * prices[0];
		fru();
	} else {
			cout<<"We don't have that in stock, please come back tomorrow"<<endl;
			system("cls");
			TakeRequest();
	}
}

int begin () {
	cout<<"Welcome to the Walgreens Grocery Store\nHow may I help you today?"<<endl;
	delay(1);
	cout<<"We sell a variety of fruits, but today we have oranges, apples, banana, mangoes and pineapple"<<endl;
	TakeRequest();
}

int main () {
	begin();
}




