// Using Sieve of Atkin algorithm to find all prime numbers up to 100000 super fast (you can modify it to increase the limit)!

/*
	Contributor: Binit Ghimire (@TheBinitGhimire)
	Output Format: | 2 | 3 | 5 | 7 | 11 | 13 | 17 | 19 | 23 | 29 | ... | ... | ... |
*/

#include <stdio.h>
#include <stdbool.h>

int main(){
    int a=2,b=100000;
    bool s[100000] = {0};
    int i,j;
	
	// Manually specifying 2 and 3!
    printf("| 2 | 3 ");
    for(i=0; i<b; i++) s[i] = 0;
	
	// Sieve of Atkin implementation!
    for(i=1; i*i<b; i++){
        for(j=1;j*j<b;j++){
            int n=(4*i*i)+(j*j);
            if((n<=b) && (n%12==1 || n%12==5)) s[n]^=1;
            n=(3*i*i) + (j*j);
            if(n<=b && n%12==7) s[n]^=1;
            n=(3*i*i) - (j*j);
            if(i>j && n<=b && n%12 ==11) s[n]^=1;
        }
    }

    for(int m=5; m*m<b; m++){
        if(s[m]==1) for(i=m*m; i<b; i+=m*m) s[i]=0;
    }
	
	// Printing the final results!
    for(i=5;i<b;i++) if(s[i]==1) printf("| %d ", i);
    return 0;
}
