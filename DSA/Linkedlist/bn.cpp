int nCr(int n)
    {
    return fact(n) / (fact(2) * fact(n - 2));
    }
    int fact(int n)
    {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
    }
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int i,j, count;
        sort(arr, arr + n);
        int hash[arr[n-1]] = {0} ;
        for(int i = 0; i < n; i++){
            int key = arr[i] - 1;
            hash[key]++;
        }
        vector <int> t;
        for(int i = 0; i < k; i++){
            if(hash[i] !=0)
                t.push_back(i+1);
        }
        i = count = 0; j = t.size()-1;
        while (i <  j){
            if (t[i] + t[j] == k){
                count = count + hash[t[i] - 1]*hash[t[j] - 1];
                i++;j--;
            }
            else if (t[i] + t[j] > k)
                j--;
            else 
                i++;
        }
        for(int i = 0; i < t.size(); i++){
            if(t[i] + t[i] == k &&  hash[t[i] - 1] > 1)
                count = count + nCr(hash[t[i] - 1]);
        }
        return count;
    }
    if(abs(arr[0] - sum) >= abs(flag - sum)){
                        arr[i] = sub;
                    }
                    else
                        arr[i] = sum;
    for(int j = 0; j < 4; j++){
                    if (temp_min > temp[j]){
                        temp_min = temp[j];
                        z = j;
                    }
                }






 public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr + n);
        int min = arr[n-1] + k;
        int max = 0;
        int flag,t;
        
        int j;
            for(int i = 0; i < n; i++){
                if(arr[i] <= k){
                    arr[i]+=k;
                    flag = arr[i];
                    j = i;
                }
            }
            t = arr[0];
            int temp[4];
            for(int i = j+1; i < n; i++){
                int sum, sub;
                sum = arr[i] + k;
                sub = arr[i] - k;
                temp[0] = abs(flag - sum);
                temp[1] = abs(flag - sub);
                temp[2] = abs(t - sum);
                temp[3] = abs(t - sub);
                int temp_min = INT_MAX;
                int z1, z2, z3;
                if(temp[0] > temp[2])
                    z1 = 0;
                else 
                    z1 = 2;
                if(temp[1] > temp[3])
                    z2 = 1;
                else 
                    z2 = 3;
                if (temp[z1] > temp[z2])
                    z3 = z1;
                else if (temp[z1]  == temp[z2])
                    {arr[i] = sub;z3=-1;}
                else
                    z3 = z2;
                    
                    
                if (z3 == 0 || z3 == 2)
                    arr[i] = sub;
                else 
                    arr[i] = sum;
                if(arr[i] > flag)
                    flag = arr[i];
            }
            
            
            for(int i = 0; i < n; i++){
                cout << arr[i] << endl;
                if(arr[i] > max)
                    max = arr[i];
                if(arr[i] < min)
                    min = arr[i];
            }
            cout << max << " " << min << endl;
            return(max - min);
            
    }





    if (arr[i] > 0){
	            cur_pos = cur_pos * arr[i];
	            cur_neg = (long long)min(cur_neg*arr[i], long long(1));
	        }
	        else if(arr[i] == 0){
	            cur_pos =  cur_neg = 1;
	        }
	        else{
	            int temp;
	            temp = cur_neg;
	            cur_neg = cur_pos*arr[i];
	            cur_pos = (long long)max(temp * arr[i], long long(1));
	            
	        }
	        if (cur_pos > ovmax)
	            ovmax = cur_pos;