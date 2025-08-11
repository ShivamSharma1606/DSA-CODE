// Function to sort the stack using recursion
class sortStack
{
    void insert(stack<int> &st, int pos)
    {
        if (st.empty() || st.top() < pos)
        {
            st.push(pos);
            return;
        }

        // removing all the above element which are greater than our target
        int temp = st.top();
        st.pop();
        insert(st, pos);
        st.push(temp);
    }

    void sortStack(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }

        int top = st.top();
        st.pop();
        // first empty the whole stack
        sortStack(st);
        insert(st, top);
    }
};

// Count good number and power of a number
class goodcount
{
public:
    const long long mod = 1e9 + 7;

    // answer, exp, base
    // I have find the power using recursive method we can also find using normal method check the problem 50. Pow(x, n)
    long long mpow(long long ans, long long n, long long x)
    {

        if (n == 0)
        {
            return ans;
        }

        if (n % 2 == 0)
        {
            long long temp = (x * x) % mod;
            return mpow(ans, n / 2, temp);
        }
        else
        {
            long long temp = (ans * x) % mod;
            return mpow(temp, n - 1, x);
        }
    }

    int countGoodNumbers(long long n)
    {
        const long long mod = 1e9 + 7;
        long long evencount = n / 2;
        long long oddcount = n - evencount;

        long long pow1 = mpow(1, oddcount, 5) % mod;
        long long pow2 = mpow(1, evencount, 4) % mod;

        return (pow1 * pow2) % mod;
    }
};

// Implementation of Atoi
class atoi
{

    long long rans(string s, int n, long long &ans, int sign, int i)
    {

        // checking the length
        if (i == n || !isdigit(s[i]))
        {
            return sign * ans;
        }

        int digit = s[i] - '0';
        ans = (ans * 10) + digit;

        // cheking the bound
        if (ans > INT_MAX)
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        return rans(s, n, ans, sign, i + 1);
    }

public:
    int myAtoi(string s)
    {

        // recursive solution
        int n = s.size();
        int sign = 1;
        int i = 0;
        long long ans = 0;
        // removing whitespace
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        // cheking the sign
        if (i < n && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+')
        {
            i++;
        }
        return rans(s, n, ans, sign, i);

        /*
        //below code is working fine it is iterative solution
        int n = s.size();
        long long ans = 0;
        int i = 0;
        int sign = 1;

        //removing whitespaces
        while( i < n && s[i] == ' ' ){
            i++;
        }

        if( i < n && s[i] == '-'){
            sign = -1;
            i++;
        }else if(i < n && s[i] == '+'){
            i++;
        }

        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            ans = (ans * 10) + digit;
            i++;

            if(ans > INT_MAX){
                return (sign == 1)?INT_MAX : INT_MIN;
            }
        }

        return ans*sign;
        */
    }
};

// Reverse a stacking using recursion
class reverse
{
    void insertB(stack<int> &stack, int temp)
    {
        if (stack.empty())
        {
            stack.push(temp);
            return;
        }

        int top = stack.top();
        stack.pop();
        insertB(stack, temp);
        stack.push(top);
    }

    void reverseStack(stack<int> &stack)
    {
        if (stack.empty())
        {
            return;
        }

        int temp = stack.top();
        stack.pop();
        reverseStack(stack);
        insertB(stack, temp);
    }
};

