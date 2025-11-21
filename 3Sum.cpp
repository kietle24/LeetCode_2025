class Solution { 
    public :  
    vector<vector<int>>threeSum(vector<int>&nums) { 
        if(nums.empty()|| nums.size() < 3 ) {  // check xem num co rong hay va so luong size check phai nho hon 3
            return vector<vector<int>>() ; // tra ve lai mang 
            
        }
        set<vector<int>>result ; // tao set de luu tru mang vector 
        sort(nums.begin() , nums.end()) ;  // sap xep cac so tu begin den ket thuc 
        for(int i = 0 ; i < nums.size()-2 ; i++ ) {  // su dung vong lop for de co the tao ra mot size 
            int l = i + 1; //khoi tao tro l duyet mang den  
            int r= nums.size()- 1;  //khoi tao bien
            while(l < r ) { 
                int sum = nums[i] + nums[l] + nums[r]; 
                if(sum == 0 ) {
                     result.insert({nums[i], nums[l] , nums[r]}) ; 
                     l++;  
                     r-- ; 
                }else if(sum < 0 ) { 
                    l++ ; 
                }else { 
                    r-- ; 
                }
            }
        }
        return vector<vector<int>>(result.begin() ,result.end()) ;
    }
} ;