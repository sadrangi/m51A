#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> inputCombos;

/* *****************************************************

        ATTENTION USERS 

The only function you need to modify to use this script 
for a particular problem is generateOurResultAndTheirs 

Please do not change anything else or else this will break! 


***************************************************** */

void generateInputs(int k, int index, vector<int> curr)
{
    if (index == k)
    {
        inputCombos.push_back(curr);
        return;
    }

    curr[index] = 0;
    generateInputs(k, index + 1, curr);
    curr[index] = 1;
    generateInputs(k, index + 1, curr);
}

void generateOurResultAndTheirs(int &mine, int &theirs, int index)
{
    /*
  Attention users: 
  This is the function you must customize with 
  their expression and your answer (the simplified expression). 

  For example if their expression is (A')'(B')' + (C')' 
  and your simplified version is AB + C, you should 
  define variables mine and theirs as follows: 


  int A = inputCombos[index][0]; 
  int B = inputCombos[index][1]; 
  int C = inputCombos[index][2]; 

  mine = (A && B) || C; 
  theirs = (!(!A) && !(!B)) || !(!C); 


  */
}

void calculate()
{
    bool mismatch = false;
    for (int i = 0; i < inputCombos.size(); i++)
    {
        int mine;
        int theirs;
        generateOurResultAndTheirs(mine, theirs, i);
        if (mine != theirs)
        {
            mismatch = true;
            break;
        }
    }
    if (mismatch)
    {
        cout << "MISMATCH: Your answer is incorrect or you may have entered the equations incorrectly." << endl;
    }
    else
    {
        cout << "Your outputs match instructor's. Great job!" << endl;
    }
}
int main()
{
    cout << "Please enter the number of inputs: ";
    int k;
    cin >> k;

    vector<int> temp(k, -1);
    generateInputs(k, 0, temp);
    calculate();
}
