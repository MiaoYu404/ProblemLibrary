#include <bits/stdc++.h>
using namespace std;

// Function to compute min and max subarray sums using Kadane's algorithm
pair<long long, long long> compute_min_max_subarray(const vector<int>& arr) {
    if (arr.empty()) return {0, 0};
    
    long long current_max = arr[0];
    long long max_sum = arr[0];
    long long current_min = arr[0];
    long long min_sum = arr[0];
    
    for(int i = 1; i < arr.size(); ++i){
        current_max = max((long long)arr[i], current_max + arr[i]);
        max_sum = max(max_sum, current_max);
        
        current_min = min((long long)arr[i], current_min + arr[i]);
        min_sum = min(min_sum, current_min);
    }
    return {min_sum, max_sum};
}

// Function to compute min and max suffix sums
pair<long long, long long> compute_min_max_suffix(const vector<int>& arr) {
    long long current_sum = 0;
    long long min_sum = 0;
    long long max_sum = 0;
    for(int i = arr.size()-1; i >=0; --i){
        current_sum += arr[i];
        min_sum = min(min_sum, current_sum);
        max_sum = max(max_sum, current_sum);
    }
    return {min_sum, max_sum};
}

// Function to compute min and max prefix sums
pair<long long, long long> compute_min_max_prefix(const vector<int>& arr) {
    long long current_sum = 0;
    long long min_sum = 0;
    long long max_sum = 0;
    for(int i =0; i < arr.size(); ++i){
        current_sum += arr[i];
        min_sum = min(min_sum, current_sum);
        max_sum = max(max_sum, current_sum);
    }
    return {min_sum, max_sum};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        
        // Find if there is a special x
        int special_idx = -1;
        long long x = 0;
        int count_special =0;
        for(int i=0; i<n; ++i){
            if(a[i] !=1 && a[i] != -1){
                special_idx = i;
                x = a[i];
                count_special++;
                break; // At most one special element
            }
        }
        
        vector<long long> possible_sums;
        possible_sums.push_back(0); // Empty subarray
        
        if(count_special ==0){
            // No special x
            // Check if array contains both 1 and -1
            bool has_one = false, has_minus_one = false;
            for(auto val: a){
                if(val ==1) has_one = true;
                if(val ==-1) has_minus_one = true;
                if(has_one && has_minus_one) break;
            }
            // Compute min and max subarray sums
            pair<long long, long long> minmax = compute_min_max_subarray(a);
            long long min_sum = minmax.first;
            long long max_sum = minmax.second;
            
            if(has_one && has_minus_one){
                for(long long s = min_sum; s <= max_sum; ++s){
                    possible_sums.push_back(s);
                }
            }
            else if(has_one){
                for(long long s =1; s <= (long long)n; ++s){
                    possible_sums.push_back(s);
                }
            }
            else if(a.size() >0 && a[0]==-1){
                // All elements are -1
                for(long long s = -1; s >= -(long long)n; --s){
                    possible_sums.push_back(s);
                }
            }
            // Else, if array is empty, only 0 is already included
        }
        else{
            // There is a special x at index special_idx
            // Split into left and right
            vector<int> left(a.begin(), a.begin() + special_idx);
            vector<int> right(a.begin() + special_idx +1, a.end());
            
            // Compute subarray sums for left
            pair<long long, long long> minmax_sub_left = compute_min_max_subarray(left);
            pair<long long, long long> minmax_suffix_left = compute_min_max_suffix(left);
            
            // Compute subarray sums for right
            pair<long long, long long> minmax_sub_right = compute_min_max_subarray(right);
            pair<long long, long long> minmax_prefix_right = compute_min_max_prefix(right);
            
            // Compute the range of sums containing x
            long long sum_from_x_low = x + minmax_suffix_left.first + minmax_prefix_right.first;
            long long sum_from_x_high = x + minmax_suffix_left.second + minmax_prefix_right.second;
            
            // Add all sums containing x
            for(long long s = sum_from_x_low; s <= sum_from_x_high; ++s){
                possible_sums.push_back(s);
            }
            
            // Compute subarray sums from left side
            if(!left.empty()){
                // Check if left contains both 1 and -1
                bool has_one = false, has_minus_one = false;
                for(auto val: left){
                    if(val ==1) has_one = true;
                    if(val ==-1) has_minus_one = true;
                    if(has_one && has_minus_one) break;
                }
                if(has_one && has_minus_one){
                    for(long long s = minmax_sub_left.first; s <= minmax_sub_left.second; ++s){
                        possible_sums.push_back(s);
                    }
                }
                else if(has_one){
                    for(long long s =1; s <= (long long)left.size(); ++s){
                        possible_sums.push_back(s);
                    }
                }
                else{
                    // All elements are -1
                    for(long long s = -1; s >= -(long long)left.size(); --s){
                        possible_sums.push_back(s);
                    }
                }
            }
            
            // Compute subarray sums from right side
            if(!right.empty()){
                // Check if right contains both 1 and -1
                bool has_one = false, has_minus_one = false;
                for(auto val: right){
                    if(val ==1) has_one = true;
                    if(val ==-1) has_minus_one = true;
                    if(has_one && has_minus_one) break;
                }
                if(has_one && has_minus_one){
                    for(long long s = minmax_sub_right.first; s <= minmax_sub_right.second; ++s){
                        possible_sums.push_back(s);
                    }
                }
                else if(has_one){
                    for(long long s =1; s <= (long long)right.size(); ++s){
                        possible_sums.push_back(s);
                    }
                }
                else{
                    // All elements are -1
                    for(long long s = -1; s >= -(long long)right.size(); --s){
                        possible_sums.push_back(s);
                    }
                }
            }
        }
        
        // Collect all possible sums, sort and remove duplicates
        sort(possible_sums.begin(), possible_sums.end());
        possible_sums.erase(unique(possible_sums.begin(), possible_sums.end()), possible_sums.end());
        
        // Prepare output
        cout << possible_sums.size() << "\n";
        for(auto s: possible_sums){
            cout << s << " ";
        }
        cout << "\n";
    }
}
