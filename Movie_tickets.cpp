#include <iostream>
#include <string>
using namespace std;



const int max_movie = 100000;


const int max_user = 100000;

int booked[max_movie][101]; 


int countbooked[max_movie];

bool BOOK(int X, int Y) {
    
    for(int i = 0; i < countbooked[Y]; i++) {
        if(booked[Y][i] == X)
            return false;
    
}

    if(countbooked[Y] >= 100)
        return false;

    
        booked[Y][countbooked[Y]++] = X;
    return true;
}

        bool CANCEL(int X, int Y) {
    
    for(int i = 0; i < countbooked[Y]; i++) {
        if(booked[Y][i] == X) {
            
            booked[Y][i] = booked[Y][countbooked[Y] - 1];
            countbooked[Y]--;
          
       
            return true;
       
        }
    
    
    }
  
    return false;
}

bool IS_BOOKED(int X, int Y) {
    
    for(int i = 0; i < countbooked[Y]; i++) {
        
        if(booked[Y][i] == X)
            return true;
    }
    
    return false;
}

int AVAILABLE_TICKETS(int Y) {
    
    return 100 - countbooked[Y];
}

int main() {
    
    
    int Q;
    cin >> Q;

   
    while(Q--) {
        
        string query;
        cin >> query;

        if(query == "BOOK") {
            int X, Y;
           
            cin >> X >> Y;
            cout << (BOOK(X, Y) ? "true" : "false") << "\n";
        }
        else if(query == "CANCEL") {
            
            int X, Y;
            cin >> X >> Y;
            
            cout << (CANCEL(X, Y) ? "true" : "false") << "\n";
        }
        else if(query == "IS_BOOKED") {
            int X, Y;
            
            cin >> X >> Y;
           
           
            cout << (IS_BOOKED(X, Y) ? "true" : "false") << "\n";
        }
        else if(query == "AVAILABLE_TICKETS") {
           
            int Y;
            cin >> Y;
            
            cout << AVAILABLE_TICKETS(Y) << "\n";
        }
    }

    
    
    return 0;


}