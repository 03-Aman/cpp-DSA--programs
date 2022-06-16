#include<iostream>
using namespace std;


int main(){
int n,i=1,k=1,j;
    cin>>n;

    while(i<=n){
        k=i;
        j=1;
        while(j<=i){
            cout<<k;
            k--;
            j++;
            
        }
        i++;
        cout<<endl;
    }
    
    
    
      return 0;
  
}


