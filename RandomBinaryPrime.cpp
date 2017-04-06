#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

using namespace std;

int PrimeorNah(int n);

int moduloExponentation(int a, int b, int c);


int main(){
    
    
    srand(time(NULL));
    int n, i, numbers;
    int count = 0;
    int secondCount = 0;
    clock_t t;
    //Get the number of bits
    cout << "Enter the number of digits: ";
    cin >> n;
    
    //Get the amount of numbers
    cout << "How many numbers";
    cin >> numbers;
    
    cout << endl;
    
    cout << "Prime numbers:" << endl;
    
    t = clock();
    
    for (int k = 0; k < numbers; k++){
        
        //Allocate an array of n size
        int *binary;
        
        binary = (int *)alloca(sizeof(int) * n);
        
        binary[0] = 1;
        
        //Generate 0 or 1 and place it into the array
        for (i = n - 1; i >= 1; --i)
        {
            binary[i] = rand() % 2;
            
        }
        
        //Convert to base 8
        unsigned long long decimal = 0;
        for (int i = n - 1; i >= 0; i--){
            
            decimal = decimal * 2 + binary[i];
        }
        
        
        
        int result = PrimeorNah(decimal);
        
        if (result == 1){
            count++;
            secondCount++;
            
            for (int i = n - 1; i >= 0; i--){
                cout << binary[i];
            }
            
            cout << "   Decimal Representation: ";
            cout << setw(5);
            cout << decimal;
            
            cout << "  1 prime found after " << secondCount << " numbers";
            cout << endl;
            
            secondCount = 0;
        }
        
        else
            secondCount ++;
        
    }
    
    cout << endl;
    cout << "***********************************" << endl;
    cout << count << " numbers were prime" << endl;
    cout << (numbers - count) << " numbers were not prime" << endl;
    cout << numbers << " numbers were created" << endl;
    
    t = clock() - t;
    printf("%d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
    
    int x;
    cin >> x;
    
    return 1;
    
    
}


/*
 input : positive odd integer N > 2
 output : yes/no
 
 if a^N-1 = 1(modN) or a^n-1 % n = 1
	return yes
 else:
	return no
 */

int moduloExponentation(int a, int b, int c){
    int result = 1;
    
    while (b>0){
        result *= a;
        result %= c;
        b--;
    }
    
    return result;
}

int PrimeorNah(int n){ //tests whether a number is prime or not 
    int i;
    int x;
    
    if (n == 2)
        return 1;
    
    for (i = 0; i<10; i++){
        x = rand() % n;
        if (x == 0 || x == 1)
            x++;
        if (moduloExponentation(x, n - 1, n) != 1)
            return 0;
    }
    
    return 1;
}




