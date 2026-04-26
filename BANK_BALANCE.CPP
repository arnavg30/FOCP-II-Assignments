#include <iostream>
#include <string>
using namespace std;

const int Max = 100000;

int userid[Max];

    long long balanceamt[Max];

int totaluser = 0;

int finduser(int X)
{
    for(int i = 0; i < totaluser; i++)
    {
        if(userid[i] == X)
            return i;
    }
    
    return -1;
}

        bool CREATE(int X, long long Y)
{
    int id = finduser(X);

    
    
    if(id != -1)
    {
        balanceamt[id] += Y;
        return false;
    }

    userid[totaluser] = X;
    
    balanceamt[totaluser] = Y;
    
    totaluser++;
    
    return true;
}

bool DEBIT(int X, long long Y)
{
    int id = finduser(X);

    
    if(id == -1 || balanceamt[id] < Y)
        return false;

    balanceamt[id] -= Y;
    
    return true;
}

        bool CREDIT(int X, long long Y)
{
    int id = finduser(X);

    
    if(id == -1)
        return false;

    balanceamt[id] += Y;
    
    
    
    return true;

}



long long BALANCE(int X)
{
    int id = finduser(X);

    
    
    if(id == -1)
        return -1;

    return balanceamt[id];
}

    
    int main()
{
    

    int Q;
    cin >> Q;

        while(Q--)
    {
        string query;
       
        cin >> query;

        
        if(query == "CREATE")
        {
            int X;
            long long Y;
            cin >> X >> Y;

            cout << (CREATE(X, Y) ? "true" : "false") << "\n";
        }
        
        else if(query == "DEBIT")
        {
            int X;
            long long Y;
            cin >> X >> Y;

            cout << (DEBIT(X, Y) ? "true" : "false") << "\n";
        
        }


        else if(query == "CREDIT")
        {
            int X;
            long long Y;
            cin >> X >> Y;

            cout << (CREDIT(X, Y) ? "true" : "false") << "\n";
        }
        else if(query == "BALANCE")
        {
            int X;
            cin >> X;

            cout << BALANCE(X) << "\n";
       
    
    }
    }

    
    return 0;

}