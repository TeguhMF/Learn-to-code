#include <iostream>
using namespace std;

#define MAX 5

class DStack {
private:
    int top1;
    int top2;
    int ele[MAX];

public:
    DStack();                
    void pushA(int item);    
    void pushB(int item);    
    int popA(int *item);     
    int popB(int *item);  
    
    void displayA();  
    void displayB(); 
};

DStack::DStack() {
    top1 = -1;
    top2 = MAX;
}

void DStack::pushA(int item) {
    if (top2 == top1 + 1) {
        cout << "\nStack Overflow Stack 1";
        return;
    }
    top1++;
    ele[top1] = item;
    cout << "\nItem disisipkan di Stack 1: " << item;
}

void DStack::pushB(int item) {
    if (top2 == top1 + 1) {
        cout << "\nStack Overflow Stack 2";
        return;
    }
    top2--;
    ele[top2] = item;
    cout << "\nItem disisipkan di Stack 2: " << item;
}

int DStack::popA(int *item) {
    if (top1 == -1) {
        cout << "\nStack Underflow Stack 1";
        return -1;
    }
    *item = ele[top1];
    top1--;
    return 0;
}

int DStack::popB(int *item) {
    if (top2 == MAX) {
        cout << "\nStack Underflow Stack 2";
        return -1;
    }
    *item = ele[top2];
    top2++;
    return 0;
}

int main() {
    int item=0;
    DStack s=DStack();

    s.pushA(24);
    s.pushA(10);
    s.pushA(11);
    s.pushB(40);
    s.pushB(13);
    s.pushB(48);

    s.displayA();
    s.displayB();
    cout<<endl;


    if (s.popA(&item) == 0)
        cout << "\nItem di-pop dari Stack 1: " <<item;
    if (s.popA(&item) == 0)
        cout << "\nItem di-pop dari Stack 1: " <<item;
    if (s.popA(&item) == 0)
        cout << "\nItem di-pop dari Stack 1: " <<item;

    if (s.popB(&item) == 0)
        cout << "\nItem di-pop dari Stack 2: " <<item;
    if (s.popB(&item) == 0)
        cout << "\nItem di-pop dari Stack 2: " <<item;
    if (s.popB(&item) == 0)
        cout << "\nItem di-pop dari Stack 2: " <<item;
    s.displayA();
    s.displayB();
    cout<<endl;

    return 0;
}