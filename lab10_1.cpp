#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){
	double loan;
	double interest_rate;
	double payment;

	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> interest_rate;
	cout << "Enter amount you can pay per year: ";
	cin >> payment;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

	int year_count = 1;
	double prevbalance = loan;
	double interest;
	double total;
	while(true){
		cout << fixed << setprecision(2);
		cout << setw(13) << left << year_count;
		cout << setw(13) << left << prevbalance;
		interest = prevbalance*interest_rate/100;
		cout << setw(13) << left << interest;
		total = prevbalance+interest;
		cout << setw(13) << left << total;
		if(total <= payment){
			payment = total;
			cout << setw(13) << left << payment;
			prevbalance = total-payment;
			cout << setw(13) << left << prevbalance;
			break;
		}
		cout << setw(13) << left << payment;
		prevbalance = total-payment;
		cout << setw(13) << left << prevbalance;
		cout << endl;
		year_count++;
	}

	/*
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	cout << fixed << setprecision(2); 
	cout << setw(13) << left << 1; 
	cout << setw(13) << left << 1000.0;
	cout << setw(13) << left << 50.0;
	cout << setw(13) << left << 1050.0;
	cout << setw(13) << left << 100.0;
	cout << setw(13) << left << 950.0;
	cout << "\n";
	*/
	
	return 0;
}