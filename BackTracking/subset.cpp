#include <iostream>
#include <vector>
using namespace std;

void solve(int idx, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp){
    if(idx >= arr.size()){
        ans.push_back(temp);
        return;
    }

    temp.push_back(arr[idx]);
    solve(idx+1, arr, ans, temp); //take
    temp.pop_back();
    solve(idx+1, arr, ans, temp); //skip    

}

vector<vector<int>> subsets(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> temp;

    solve(0, arr, ans, temp);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int &x : arr) cin >> x;

    vector<vector<int>> result = subsets(arr);


    for(int i=0; i<result.size(); i++){
        cout << "[";
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j]<< " ";
        }
        cout << "]";
        cout << endl;
    }
    
    return 0;
}