#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<vector<int> > v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << "[";
      for(int j = 0; j <v[i].size(); j++){
         cout << v[i][j] << ", ";
      }
      cout << "],";
   }
   cout << "]"<<endl;
}
class Solution {
public:
   void addAll(vector < vector <int> >& res, vector < vector <int> >& temp){
      for(int i = 0; i < temp.size(); i++)res.push_back(temp[i]);
   }
   vector<vector<int>> fourSum(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      return kSum(nums, 0, 4, target);
   }
   vector < vector <int> > kSum(vector <int>& arr, int start, int k, int target){
      vector < vector <int> > res;
      if(k == 2){
         int left = start;
         int right = arr.size() - 1;
         vector <int> temp(2);
         while(left < right){
            if(arr[left] + arr[right] == target){
               temp[0] = arr[left];
               temp[1] = arr[right];
               res.push_back(temp);
               while(left < right && arr[left] == arr[left + 1])left++;
               while(left < right && arr[right] == arr[right - 1])right--;
               left++;
               right--;
            }
            else if(arr[left] + arr[right] > target)right--;
            else left ++;
         }
      }
      else{
         for(int i = start; i < (int)arr.size() - k + 1; i++){
            if(i > start && arr[i] == arr[i - 1])continue;
            vector < vector <int> > temp = kSum(arr, i + 1, k - 1, target - arr[i]);
            for(int j = 0; j < temp.size(); j++){
               temp[j].push_back(arr[i]);
            }
            addAll(res, temp);
         }
      }
      return res;
   }
};
main(){
   Solution ob;
   vector<int> v = {1,0,-1,0,-2,2};
   print_vector(ob.fourSum(v, 0));
}
