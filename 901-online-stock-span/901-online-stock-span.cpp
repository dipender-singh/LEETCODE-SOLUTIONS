class StockSpanner {
public:
    //Basically Implementation of Stack using an Array or a Vector
    //We don't have to create a Data Structure here we have to create an Algorithm
    
    StockSpanner() {}
    stack<pair<int,int>> st;
    int size = 0;
    int next(int price) {
        int res = 0;
        while(st.size()!=0 and st.top().first<=price){
            st.pop();
        }
        if(st.size()==0){
            res = size + 1;
            st.push({price,size});
            size++;
        }
        else if(st.size()!=0 and st.top().first > price){
            res = size - st.top().second;
            st.push({price,size});
            size++;
        }
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */