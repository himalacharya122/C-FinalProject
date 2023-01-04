#include<iostream>
#include"SavingsAccount.h"
#include"CheckingAccount.h"
#include"BankAccount.h"
using namespace std;
int main(){
    cout << "SAVINGS ACCOUNT\n\n";   //created a savings account
    double startingBalance;
    double AnnualIntRate;
    cout << "Enter your starting balance of Savings Account: $";
    cin >> startingBalance;
    cout << "\nEnter Annual Interest Rate in %: ";
    cin >> AnnualIntRate;
    AnnualIntRate = AnnualIntRate/100;
    cout << "\n\t\t\t\t\tCreating Savings Account, please wait...";
    cout << "\n\t\t\t\t\tSavings Account has been created successfully!\n";
    SavingsAccount sav_Acc(startingBalance, AnnualIntRate);
    
    double ProcessingCharges;      //setting the value of monthly processing charges
    cout << "Enter monthly processing charges: $";
    cin >> ProcessingCharges;
    sav_Acc.setMonthlyCharges(ProcessingCharges);

    /*using while loops to get the withdrawals and deposits. but this can also implemented as a menu driven program*/
    double deposits = 0, withdrawas = 0;
    double totalDeposits = 0, totalWithdrawas = 0;

    //getting the total monthly deposits
    cout << "\nEnter deposit amount, when finished,";
    cout << " enter 0:" << endl;
    cin >> deposits;

    while(deposits!= 0){
        //adding deposits to total
        totalDeposits += deposits;

        cout << fixed << setprecision(2);
        cout << "Performing deposit...\n";
        sav_Acc.makeDeposit(deposits);
        cout << "Done!\n";

        //displaying data of savings account
        cout << "\nBalance: $" << sav_Acc.getBalance();
        cout << "\nNumber of deposits: " << sav_Acc.getNumDeposits();
        cout << "\nNumber of withdrawals: " << sav_Acc.getNumWithdrawals();
        cout << "\n\nEnter another deposit amount, or 0 to stop: ";
        cin >> deposits;
    }

        //using the same method as diposits to take all the monthly withdrawals
    cout << "\nEnter withdrawals amount, When finished,";
    cout << " enter 0:" << endl;
    cin >> withdrawas;

    while(withdrawas!= 0){
        //adding withdrawals to total
        totalWithdrawas += withdrawas;

        cout << fixed << setprecision(2);
        cout << "Performing withdrawal...\n";
        sav_Acc.makeWithdrawal(withdrawas);
        cout << "Done!\n";

        //displaying the data of savings account
        cout << "\nBalance: $" << sav_Acc.getBalance();
        cout << "\nNumber of deposits: " << sav_Acc.getNumDeposits();
        cout << "\nNumber of withdrawals: " << sav_Acc.getNumWithdrawals();

        cout << "\n\nEnter another withdrawal amount, or 0 to stop: ";
        cin >> withdrawas;
    }

    //displaying the monthly statistics
    cout << "\nDone! Here are the monthly statistics: ";
    cout << "\nBeginning balance: $" << startingBalance;
    cout << "\nNumber of deposits: " << sav_Acc.getNumDeposits();
    cout << "\nTotal amount of deposits: $" << totalDeposits;
    cout << "\nNumber of withdrawals: " << sav_Acc.getNumWithdrawals();
    cout << "\nTotal amount of withdrawals: $" << totalWithdrawas;
    cout << "\nMonthly charges: $" <<ProcessingCharges;

//get the service charges in a structure
//and perform monthly processing
ServiceAndOwed temp = sav_Acc.monthlyProc();

cout << "\nService fees: $" << temp.servCharges;
cout << "\nTotal monthly charges: $" <<ProcessingCharges + temp.servCharges;

//display ending balance
cout << "\nEnding balance: $" << sav_Acc.getBalance();


//---------------------------------------------------------
//now do the same thing for a checking account
//---------------------------------------------------------
cout << "\n\n\nCHECKING ACCOUNT\n\n";

cout << "Enter starting balance of Checking Account: $";
cin >> startingBalance;

cout << "\nEnter Annual Interest Rate in %: ";
cin >> AnnualIntRate;
//update interest rate to be
//correct value because it is in %
AnnualIntRate = AnnualIntRate/100;

//create a checking account object
cout << "\nCreating Checking Account with this data...";
CheckingAccount checkAcc(startingBalance, AnnualIntRate);
cout << "Done!\n";

//set value of monthly processing charges and set it
cout << "Enter monthly processing charges: $";
cin >>ProcessingCharges;
checkAcc.setMonthlyCharges(ProcessingCharges);

//remember, you can only withdraw from this
//checking account
withdrawas = 0;
totalWithdrawas = 0;

//get the withdrawals with the same method
cout << "\nEnter the withdrawals one by one. When finished,";
cout << " enter -1:\n";

cin >> withdrawas;

while(withdrawas != -1){
//add withdrawal to total
totalWithdrawas += withdrawas;

cout << fixed << setprecision(2);
cout << "Performing deposit...\n";
checkAcc.makeWithdrawal(withdrawas);
cout << "Done!\n";

//display data of savings account
cout << "\nBalance: $" << checkAcc.getBalance();
cout << "\nNumber of deposits: " << checkAcc.getNumDeposits();
cout << "\nNumber of withdrawals: " << checkAcc.getNumWithdrawals();

cout << "\n\nEnter another withdrawal amount, or -1 to stop: ";
cin >> withdrawas;
}

//display statistics
cout << "Done! Here are the monthly statistics: ";
cout << "\nBeginning balance: $" << startingBalance;
cout << "\nNumber of withdrawals: $" << checkAcc.getNumWithdrawals();
cout << "\nTotal amount of withdrawals: $" << totalWithdrawas;
cout << "\nInitial monthly charges: $" <<ProcessingCharges;

//get the service charges and owed amount
//in the structure and perform monthly processing
temp = checkAcc.monthlyProc();

cout << "\nService fees: $" << temp.servCharges;
cout << "\nTotal monthly charges: $" <<ProcessingCharges + temp.servCharges;
cout << "\nEnding balance: $" << checkAcc.getBalance();
cout << "\nClient owes to bank: $" << checkAcc.getAmountOwed();
cout << endl;

//return 0 to mark successful termination
return 0;
}