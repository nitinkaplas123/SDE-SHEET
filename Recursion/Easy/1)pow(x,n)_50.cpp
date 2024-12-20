Solution 1-:
Code-:
double myPow(double x, int n) {
        double ans=pow(x,n);
        return ans;
}



Solution 2-:
Code-: Time->O(log(n))
double helper(double x,long long n)
{
        if(n==0)
        return 1;

        double temp=helper(x,n/2);
        temp=temp*temp;
        if(n%2!=0)
        return x*temp;
        else
        return temp;
}

double myPow(double x, int n) {
        if(n<0)
        {
            long long val=(long long)n;
            val=abs(val);
            double res=helper(x,val);
            double ans=1/double(res);
            return ans;
        }
        else
        return helper(x,n);
}