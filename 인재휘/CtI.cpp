#include <iostream>
#include <vector>
using namespace std;

int main(){
    int woman, man, intern, diff;
    int result = 0;
    cin >> woman >> man >> intern;

    if(woman > 2 * man)
        diff = woman - 2 * man;
    else{
        diff = man - woman/2;
        man -= diff;
        if(woman % 2 != 0)
            diff += 1;
        
    }
    intern -= diff;

    while(intern > 0){
        intern -= 3;
        man -= 1;
    }
    cout << man << endl;

    return 0;
}