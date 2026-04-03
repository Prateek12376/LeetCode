class Solution {
public: 
    bool find_f(int i, int j, vector<int>& one , vector<int>& two){
        while(i<one.size() && j< two.size() && one[i]==two[j]){
            i++;
            j++;
        }
        return j == two.size() || (i < one.size() && one[i] > two[j]);
    }
    vector<int>find_max(int c,vector<int>nums){
        int n=nums.size();
        vector<int>ans(c);
        stack<int>st;
        if(c==0){
            return ans;
        }
        int del = n-c;
        for(int i=0;i<n;i++){
            while(!st.empty() && del>0 && nums[st.top()]<nums[i]){
                st.pop();
                del--;
            }
            st.push(i);
        }
        while(st.size()>c){
            st.pop();
        }
        for(int i=c-1;i>=0;i--){
            ans[i]=nums[st.top()];
            st.pop();
        }
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>ans;
        for(int i1=0;i1<=k;i1++){
            if(i1>nums1.size() || (k-i1)>nums2.size()){
                continue;
            }
            vector<int>one=find_max(i1,nums1);
            vector<int>two= find_max(k-i1,nums2);
            int n1=one.size();
            int n2=two.size();
            vector<int>maxA(n1+n2);
            int ind=0;
            int i=0;
            int j=0;
            while(i<n1 && j<n2){
                if(one[i]>two[j]){
                    maxA[ind]=one[i];
                    i++;
                    ind++;
                }
                else if(two[j]>one[i]){
                    maxA[ind]=two[j];
                    ind++;
                    j++;
                }
                else{
                    bool flg= find_f(i,j,one,two);
                    if(flg==true){
                        maxA[ind]=one[i];
                        ind++;
                        i++;
                    }
                    else{
                        maxA[ind]=two[j];
                        ind++;
                        j++;
                    }
                }
            }
            while(i<n1){
                maxA[ind]=one[i];
                i++;
                ind++;
            }
            while(j<n2){
                maxA[ind]=two[j];
                ind++;
                j++;
            }
            if(ans.empty()|| maxA>ans){
                ans=maxA;
            }
        }
        return ans;
    }
};