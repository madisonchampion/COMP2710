/* FILE NAME: project1_Champion_mbc0072.cpp
* AUTHOR: Madison Champion
* Solution Briefing:
   * Project1_hints 
   * w3schools c++ tutorial, c++ while loop
   * Stack overflow on how to format cout <<
   * ScalerTopics on what endl means
   * Daniweb.com on how to format only accepting positive values
   * cplusplus.com to figure out formula on how to calculate loan balance 
   * after certain amount of time with given interest rate and monthly payment
   * Github for how to clear previous input to fix infinite loop when input is not a double.
*/

#include <iostream>
using namespace std;
int main() {
// VARIABLE INITIALIZATION
   double interestRate;
   double loan;
   double payment;
   double interestM;
   double interestRateC;
   double monthlyPaid;
   double principal;
   double interestTotal;
   int currentMonth = 0;


// CURRENCY FORMATTING
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
  
      // USER INPUT
      // NOTE: For valid input, the loan, interest, and monthly payment must
      // be positive. The monthly payment must also be large enough to
      // terminate the loan.
      
   do {
      
      cout << "\nLoan Amount: ";
      cin >> loan;
      
      if (loan < 0 || !(cin)) {
      
         cout << "Invalid loan, must be positive." << endl;
      }
      
      cin.clear();
      
   }
    
      while (loan < 0 || !(cin));
    
      
   do {
      
      cout << "Interest Rate (% per year): ";
      cin >> interestRate;
      
      if (interestRate < 0) {
      
         cout << "Invalid interest rate, must be positive" << endl;
      }
      cin.clear();
   }
      
      while (interestRate < 0);
   
   
 // GET PROPER INTEREST RATES FOR CALCULATION;
   
   do {
      interestRate /= 12;
      interestRateC = interestRate / 100;
      cout << "Monthly Payments: ";
      cin >> monthlyPaid;
   
      if (monthlyPaid <= (interestRateC * loan)) {
         cout << "Insufficent monthly payment." << endl;
      }
      
      cin.clear();
   }
      while (monthlyPaid < (interestRateC * loan));
   
   

   
// AMORTIZATION TABLE
   cout << "*****************************************************************\n"
      << "\tAmortization Table\n"
      << "*****************************************************************\n"
      << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
      
      
// LOOP TO FILL TABLE

   while (loan > 0) {
   
      if (currentMonth == 0) {
      
         cout << currentMonth++ << "\t$" << loan;
         
         if (loan < 1000) cout << "\t"; // Formatting MAGIC
         cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
      
      } 
      else {
      
         if (loan * (1 + interestRateC) < monthlyPaid) {
            principal = loan;
            interestM = loan * interestRateC; 
            monthlyPaid = principal + interestM;
            loan = 0;
            interestTotal += interestM; 
         }
         
         
      
         if (loan * (1 + interestRateC) >= monthlyPaid) {
            principal = monthlyPaid - (loan * interestRateC);
            interestM = loan * interestRateC;
            loan = loan * (1 + interestRateC) - monthlyPaid;
            interestTotal += interestM;
         }
         
      
         
         cout << currentMonth++ << "\t$" << loan
               << "\t\t" << monthlyPaid << "\t" << interestRate
               << "\t" << interestM << "\t\t" << principal << endl;
         
      } 
   
   }
      
          
   
   cout << "****************************************************************\n";
   cout << "\nIt takes " << --currentMonth << " months to pay off "
         << "the loan.\n"
         << "Total interest paid is: $" << interestTotal;
   cout << endl << endl;
   return 0;
}
