/* FILENAME: Project2_Champion_mbc0072
* AUTHOR: Madison Champion 
* Solution Briefing
* w3schools for c++ syntax, loops, variables, strings.
* stack overflow to understand how to do test cases
* help from a friend who took the class previously, Josh Hussey, to understand project formatting, structure of design to implement each function.
* Programiz on how to use assert function
* 
*/

#include <iostream> 
#include <stdlib.h> 
#include <assert.h> 
#include <ctime> 
using namespace std;

/* Methods */
void Press_any_key();
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);

/* Tests */
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

/* Variables */
const int A_accuracy = 33;
const int B_accuracy = 50;
const int numbRounds = 10000;
bool aaronAlive = true;
bool bobAlive = true;
bool charlieAlive = true;
int aaronWins1;
int aaronWins2;
int bobWins;
int charlieWins;
int shoot_target_result;



int main() {
    cout << "*** Welcome to Madie's Duel Simulator ***\n";
    srand(time(0));

    /* Test */
    test_at_least_two_alive();
    Press_any_key();
    test_Aaron_shoots1();
    Press_any_key();
    test_Bob_shoots();
    Press_any_key();
    test_Charlie_shoots();
    Press_any_key();
    test_Aaron_shoots2();
    Press_any_key();


/* Strategy 1 */
cout << "Ready to test strategy 1 (run 10000 times):\n";
    Press_any_key();

for (int i = 0; i < numbRounds; i++) {

 aaronAlive = true;
bobAlive = true;
charlieAlive = true;

    while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
        if (aaronAlive) {
            Aaron_shoots1(bobAlive, charlieAlive);
        }

        if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
        } 

        if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive);
        }
    }

    if (aaronAlive) {
        aaronWins1++;
    }

    if (bobAlive) {
        bobWins++;
    }

    if (charlieAlive) {
        charlieWins++;
    }
}

    cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1)/numbRounds * 100 << "%\n" 
    << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins)/numbRounds * 100 << "%\n" 
    << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins)/numbRounds * 100 << "%\n" 
    << endl; 


/* Strategy 2: Aaron intentionally misses his first shot */
cout << "Ready to test strategy 2 (run 10000 times):\n";
    Press_any_key();

for (int i = 0; i < numbRounds; i++) {
    /* Reset status */
    aaronAlive = true;
    bobAlive = true;
    charlieAlive = true;

    while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
        if (aaronAlive) {
            Aaron_shoots2(bobAlive, charlieAlive);
        }

        if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
        
        }

        if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive);
        }


    if (aaronAlive) {
        aaronWins2++;

    }

    if (bobAlive) {
        bobWins++;
    }

    if (charlieAlive) {
        charlieWins++;
    }

 cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / numbRounds * 100 << "%\n" 
    << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / numbRounds * 100 << "%\n" 
    << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / numbRounds * 100 << "%\n" 
    << endl; 

/* Compare Strategies */
if (aaronWins1 > aaronWins2) {
    cout << "Strategy 1 is better than strategy 2.";
}
else {
    cout << "Strategy 2 is better than strategy 1.";
}
return 0; 

}
}
}


/* Implementation of at_least_two_alive() */

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    if (A_alive) {
        
        if (B_alive || C_alive){
            return true;
        }
    }
    else if (B_alive) {
        if (C_alive) {
            return true;
        }
    }
return false;

}

/* Implementation of Aaron_shoots1 */

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    assert(aaronAlive == true);

    int shoot_target_result = rand()%100;
    if (shoot_target_result <= A_accuracy) {
    
    if (C_alive) {
        C_alive = false;
    
    }
    else if (B_alive) {
    B_alive = false;
    }

}
}


/* Implementation of Bob_shoots */
void Bob_shoots(bool& A_alive, bool& C_alive) {
    shoot_target_result = rand()%100;
    assert(bobAlive == true);

    if (shoot_target_result <= B_accuracy) {
        if (C_alive) {
            C_alive = false;
        }
        else {
            A_alive = false;
        }
    }
}

/* Implementation of Charlie_shoots */

void Charlie_shoots(bool& A_alive, bool& B_alive) {

    assert(charlieAlive == true);

        if (B_alive) {
            B_alive = false;
        }
        else {
            A_alive = false;
        }
    }

/* Implementation of Aaronshoots2 */
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
shoot_target_result = rand()%100;

    if (!B_alive || !C_alive) {
    if (shoot_target_result <= A_accuracy) {

        if (C_alive) {
            C_alive = false;
        }
    else {
        B_alive = false;
    }
}
    }
}



/* Implementation of press any key function */
void Press_any_key(void) {
    cout << "Press Enter to continue...";
cin.ignore().get(); 
}


/* Implementation of the test driver for at_least_two_alive() */

void test_at_least_two_alive(void) {

cout << "Unit Testing 1: Function – at_least_two_alive()\n";

cout << "       Case 1: Aaron alive, Bob alive, Charlie alive\n";
assert(true == at_least_two_alive(true, true, true));
cout << "       Case passed ...\n";

cout << "       Case 2: Aaron dead, Bob alive, Charlie alive\n";
assert(true == at_least_two_alive(false, true, true));
cout << "       Case passed ...\n";

cout << "       Case 3: Aaron alive, Bob dead, Charlie alive\n";
assert((true == at_least_two_alive(true, false, true)));
cout << "       Case passed ...\n";

cout << "       Case 4: Aaron alive, Bob alive, Charlie dead\n";
assert(true == at_least_two_alive(true, true, false));
cout << "       Case passed ...\n";

cout << "       Case 5: Aaron dead, Bob dead, Charlie alive\n";
assert(false == at_least_two_alive(false, false, true));
cout << "       Case passed ...\n";

cout << "       Case 6: Aaron dead, Bob alive, Charlie dead\n";
assert(false == at_least_two_alive(false, true, false));
cout << "       Case passed ...\n";

cout << "       Case 7: Aaron alive, Bob dead, Charlie dead\n";
assert(false == at_least_two_alive(true, false, false));
cout << "       Case passed ...\n";

cout << "       Case 8: Aaron dead, Bob dead, Charlie dead\n";
assert(false == at_least_two_alive(false, false, false));
cout << "       Case passed ...\n";

}

void test_Aaron_shoots1(void) {
bool aaronAlive;
bool bobAlive;
bool charlieAlive;

    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    
    bobAlive = true;
    charlieAlive = true;
    cout << "\tCase 1: Bob alive, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(bobAlive, charlieAlive);
    bobAlive = true;
    assert(true == bobAlive);



    bobAlive = false;
    charlieAlive = true;
      cout << "\tCase 2: Bob dead, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(bobAlive, charlieAlive);
    assert(false == bobAlive);

    bobAlive = true;
    charlieAlive = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n";
    cout << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots1(bobAlive, charlieAlive);
    assert(false == charlieAlive);

}

void test_Bob_shoots() {
    bool aaronAlive;
bool bobAlive;
bool charlieAlive;

 cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
    
    aaronAlive = true;
    charlieAlive = true;
    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(bobAlive, charlieAlive);
    aaronAlive = true;
    assert(true == aaronAlive);
    charlieAlive = true;
    assert(true == charlieAlive);

    aaronAlive = false;
    charlieAlive = true;
    cout << "\tCase 2: Aaron dead, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    aaronAlive = false;
    Bob_shoots(bobAlive, charlieAlive);
    assert(false == aaronAlive);

    aaronAlive = true;
    charlieAlive = false;
    cout << "\tCase 3: Aaron alive, Charlie dead\n";
    cout << "\t\tBob is shooting at Aaron\n";
    Bob_shoots(bobAlive, charlieAlive);
    assert(false == charlieAlive);

}

void test_Charlie_shoots() {
    bool aaronAlive;
bool bobAlive;
bool charlieAlive;


    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

    cout << "\tCase 1: Aaron alive, Bob alive\n";
    cout << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(aaronAlive, bobAlive);
    aaronAlive = true;
    assert(true == aaronAlive);
    bobAlive = true;
    assert(true == bobAlive);

    aaronAlive = false;
    bobAlive = true;
    cout << "\tCase 2: Aaron dead, Bob alive\n";
    cout << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(aaronAlive, bobAlive);
    assert(false == aaronAlive);

    aaronAlive = true;
    bobAlive = false;
    cout << "\tCase 3: Aaron alive, Bob dead\n";
    cout << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(aaronAlive, bobAlive);
    assert(false == bobAlive);

}

void test_Aaron_shoots2() {
bool aaronAlive;
bool bobAlive;
bool charlieAlive;

    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    
    bobAlive = true;
    charlieAlive = true;
    cout << "\tCase 1: Bob alive, Charlie alive\n";
    cout << "\t\tAaron intentionally misses his first shot\n";
     cout << "\t\tBoth Bob and Charlie are alive\n";
    Aaron_shoots2(bobAlive, charlieAlive);
    assert(true == bobAlive);
    assert(true == charlieAlive);

    bobAlive = false;
    charlieAlive = true;
    cout << "\tCase 2: Bob dead, Charlie alive\n";
     cout << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots2(bobAlive, charlieAlive);
    assert(false == bobAlive);

     bobAlive = true;
    charlieAlive = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n";
     cout << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots2(bobAlive, charlieAlive);
    assert(false == charlieAlive);

}



