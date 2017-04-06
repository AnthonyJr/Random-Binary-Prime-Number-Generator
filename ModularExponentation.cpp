//
//  main.cpp
//  Homework-2
//
//  Created by Anthony Snow on 9/20/16.
//  Copyright © 2016 Anthony Snow. All rights reserved.
//

#include <iostream>
#include <math.h>       /* pow */


using namespace std;
int doModExp(int base, int exponent, int modN);
int main(int argc, const char * argv[]) {
    // insert code here...
    int x,y,N;
    cout << "x ^ y mod N";
    cout << " Please enter the x^y N ex. 2 256 257" << endl;
    cin >> x;
    cin >> y;
    cin >> N;
    int answer = doModExp(x,y,N);
    cout << answer << endl;
    
}


int doModExp(int base, int exponent, int modN){
    if (exponent == 0) {
        return 1;
    } else {
        int z = doModExp(base, (exponent/2), modN);
        
        if (exponent % 2 == 0) {
            int x = z * z;
            x  = x % modN;
            return x;
        } else {
            int x = (z * z) * base;
            x = x % modN;
            return x;
        }
        
    }
}
