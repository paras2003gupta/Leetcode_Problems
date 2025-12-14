class Solution {
public:
    const int MOD = 1e9 + 7;
    int count(int index , int seats , string& corridor,vector<vector<int>>&cache){
        //if we reach end of the corrridor
        //then this current section is valid if it hv no of seats ==2 ow 0
        if(index==corridor.size()){
            return seats==2?1:0;
        }

        if(cache[index][seats]!=-1){
            return cache[index][seats];;
        }
        //result of subproblem
        int res = 0;

        if(seats==2){
            //hame 2 seats mil gye h 

            //agar curr ele Seat hai toh hme partiton daalna pdega
            if(corridor[index]=='S'){
                res= count(index+1,1,corridor,cache);
            }
            //seats 2 hai but curr element Plant h 
            //do option h ya partiton daal do ya mat daalo
            else{
                int subans=0;
                //partiton daal dia
                subans = (subans+count(index+1,0,corridor,cache))%MOD;
                //nhi daala partiton
                subans=(subans+count(index+1,seats,corridor,cache))%MOD;
                res= subans;
            }
        }
        //no of seats 2 se kam h
        else{
            //partition nahi daal skte because no of seats 2 se kam h

            //if curr element seat hai toh 
            if(corridor[index] == 'S'){
                res= count(index+1,seats+1,corridor,cache);
            }//agr current element plant h toh kuch nhi kr stke aage badho
            else{
                res=count(index+1,seats,corridor,cache);
            }
        }
        cache[index][seats] = res;
        return res;


    }
    int numberOfWays(string corridor) {
        vector<vector<int>>cache(corridor.size()+1,vector<int>(3,-1));
        return count(0,0,corridor,cache);
    }
};