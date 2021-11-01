int Solution::maxArea(vector<int> &A) {
    int l = 0, r = A.size()-1;
    int ans = INT_MIN;

    if(r == 0) return 0;

    while(l < r){
        ans = max(ans, (r-l)*min(A[r], A[l]));
        if(A[r] < A[l]){
            r--;
        }
        else{
            l++;
        }
    }

    return ans;
}
