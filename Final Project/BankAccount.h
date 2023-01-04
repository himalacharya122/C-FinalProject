#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include<iostream>
using namespace std;

struct ServiceAndOwed{                                  //struct a class to return Service Charge and Total amount by monthlyProc       
       double servCharges;
       double totalOwed;
};
class BankAccount{                               
       protected:
       //member variables
       double balance;                     
       int numDeposits;
       int numWithdrawal;
       double annualIntRate;
       double mnCharges;
       double serviceCharges;

       public:
       BankAccount(double bal, double air){             //constructor to accept balance and annual interest rate
              balance = bal;                            //setting annual interest rate and balance to argumented values
              annualIntRate = air;
              //set the other variable to 0
              numDeposits = 0;
              numWithdrawal = 0;
              mnCharges = 0.0;
              serviceCharges = 0.0;
              //check invalid inputs
              if(bal < 0){                                     
                     cout << "Error! Balance cannot start with";
                     cout << " a negative amount!\n";
                     cout << "Now terminating!\n";
                     exit(0);
              }
              if(air < 0){
                     cout << "Error! Annual Interest Rate";
                     cout << " cannot be negative!\n";
                     cout << "Now terminating!\n";
                     exit(0);
              }
       }

       //accessor functions
       double getBalance(){
              return balance;
       }
       int getNumDeposits(){
              return numDeposits;
       }
       int getNumWithdrawals(){
              return numWithdrawal; 
       }
       double getAnnualIntRate(){
              return annualIntRate; 
       }
       double getMonthlyCharges(){
              return mnCharges; 
       }

       //mutator functions
       void setAnnualIntRate(double air){
              annualIntRate = air;
       //validate input using while loop
              while(air < 0){
                     cout << "Negative values for annual interest ";
                     cout << "rates not accepted! Enter again: ";
                     cin >> air;
              }
       }

       void setMonthlyCharges(double mc){
              mnCharges = mc;
       //validate input using while loop
              while(mc < 0){
                     cout << "Negative values for monthly charges ";
                     cout << "are not accepted! Enter again: ";
                     cin >> mc;
              }
       }
       virtual void makeDeposit(double d){       //A virtual function that accepts an argument for the amount of the deposit
              balance += d;
              numDeposits++;
       }
       virtual void makeWithdrawal(double w){     //A virtual function that accepts an argument for the amount of the withdrawal
              balance -= w;
              numWithdrawal++;
       }
       virtual void calcInt(){     //A virtual function that updates the balance by calculating the monthly interest earned by the account, and adding this interest to the balance
              balance += (annualIntRate/12.0)*balance;
       }
       virtual ServiceAndOwed monthlyProc(){     /*  A virtual function that subtracts the monthly service charges from the balance,
                                                 calls the calcInt function, and then sets the variables that hold the number of withdrawals,
                                                 number of deposits, and monthly service charges to zero.*/
              balance -= mnCharges;
                     calcInt();
              numDeposits = 0;
              numWithdrawal = 0;
              mnCharges = 0.0;
              serviceCharges = 0.0;
              ServiceAndOwed temp;
              return temp;
       }
};

#endif