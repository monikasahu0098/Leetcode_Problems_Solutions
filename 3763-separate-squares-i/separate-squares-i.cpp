class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low=1e9;
        double high=-1e9;
        for(auto &sq:squares){
            double y=sq[1];
            double l=sq[2];
            low=min(low,y);
            high=max(high,y+l);
        }
        for(int iter=0;iter<100;iter++){
            double above=0.0;
            double below=0.0;
            double mid=(low+high)/2.0;

            for(auto &sq:squares){
                double yi=sq[1];
                double li=sq[2];
                double top=yi+li;
                double area=li*li;
                if(mid<=yi){
                    above+=area;
                }else if(mid>=top){
                    below+=area;
                }else{
                    below+=(mid-yi)*li;
                    above+=(top-mid)*li;
                }
            }
            if(below<above){
                low=mid;
            }else{
                high=mid;
            }
        }
        return low;
    }
};