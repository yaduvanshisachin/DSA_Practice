#include <iostream>
#include <stack>   
#include <vector>
using namespace std;

int main(){
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    
    vector<int> ans;
    stack<int> s;

    for(int i=0; i<price.siz(); i++){
        while(s.size() > 0 && price[i] >= price[s.top]){ // smaller values exists
            s.pop();
        }
        if(st.size() == 0){
            ans[i] = i+1;
        }
        else{
            ans[i] = i - s.top();
        }

        s.push(i);

    }
}