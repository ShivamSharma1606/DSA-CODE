//using bits
//algo samNotes
//tc: (logn)^2

#include<bits/stdc++.h>
int divideTwoInteger(int dividend, int divisor) {
	// Write your code here.
	if(dividend==divisor)   return 1;

        bool sign=true;

        if(dividend>=0 && divisor<0)    sign=false;
        else if(dividend<=0 && divisor>0)    sign=false;

        long n=abs(dividend) ;
        long d=abs(divisor);
        long ans=0;

        while(n>=d){
            int cnt=0;

            while(n>=(d << (cnt+1))){
                cnt++;
            }

            ans+=(1<<cnt);
            n=n-(d<<cnt);
        }

        if(ans==(1<<31) && sign)    return INT_MAX;
        if(ans==(1<<31) && !sign)    return INT_MIN;

        return sign?ans:(-ans);
} 
