#include<iostream>
using namespace std;

struct Term{
    int exp;
    long long coeff;
};

Term poly[100];
int termCount = 0;

Term initTerm(int exp , int coeff){
    Term t;
    t.exp = exp;
    t.coeff = coeff;
    return t;
}

void addTerm(Term t)
{
   
    for(int i = 0; i < termCount; i++) {
        if(poly[i].exp == t.exp) {
            poly[i].coeff += t.coeff;
            return;
        }
    }

    
    if(termCount == 100) {
        cout << "Polynomial is full." << endl;
        return;
    }

    int pos = termCount;
    while(pos > 0 && poly[pos-1].exp < t.exp) 
    {
        poly[pos] = poly[pos-1];
        pos--;
    }
    poly[pos] = t;
    termCount++;
}

void displayPoly(){
    if(termCount == 0) {
        cout << "0" << endl;
        return;
    }
    
    for(int i = 0; i < termCount; i++)
    {
        cout << poly[i].coeff << "x^" << poly[i].exp;
        if(i != termCount - 1)
        {
            cout << " + ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    if(!(cin >> n) || n < 0 || n > 100) {
        cout << "Number of terms must be between 0 and 100." << endl;
        return 1;
    }
    
    cout << "Enter the exponent and coefficient for each term:" << endl;
    for(int i = 0; i < n; i++)
    {
        int exp, coeff;
        if(!(cin >> exp >> coeff)) {
            cout << "Invalid exponent or coefficient." << endl;
            return 1;
        }
        addTerm(initTerm(exp, coeff));
    }
    
    cout << "The polynomial is: ";
    displayPoly();
    
    return 0;
}
