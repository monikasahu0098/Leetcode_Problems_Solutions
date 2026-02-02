class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll>P;
    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();

        set<P>kminEle;       //stores (k-1) minimum elements
        set<P>remaining;

        ll sum=0;
        int i=1;

        while(i-dist<1){
            kminEle.insert({nums[i],i});
            sum+=nums[i];

            if(kminEle.size()>k-1){
                P temp=*kminEle.rbegin();
                sum -=temp.first;
                remaining.insert(temp);
                kminEle.erase(temp);
            }
            i++;
        }

        ll result=LONG_MAX;   //minimum sum of (k-1) elements
        while(i<n){
            kminEle.insert({nums[i],i});
            sum+=nums[i];

            if(kminEle.size()>k-1){
                P temp=*kminEle.rbegin();
                sum -=temp.first;
                remaining.insert(temp);
                kminEle.erase(temp);
            }
            result=min(result,sum);

            //shift window
            //i-dist wala element will be removed
            P remove={nums[i-dist],i-dist};
            if(kminEle.count(remove)){
                kminEle.erase(remove);
                sum-=remove.first;

                if(!remaining.empty()){
                    P temp=*remaining.begin();
                    kminEle.insert(temp);
                    sum+=temp.first;
                    remaining.erase(temp);
                }
            }else{
                remaining.erase(remove);
            }
            i++;
        }

        return nums[0]+result;
    }
};