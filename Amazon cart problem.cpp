
    int main(){
        vector<string> cart;
        cart.push_back("apple");
        cart.push_back("apple");        
        cart.push_back("Mango");
        cart.push_back("apple");
        cart.push_back("orange");
        cart.push_back("Banana");
        vector<vector<string>> codes;
        vector<string> code;
        code.push_back("apple");
        codes.push_back(code);
        vector<string> code1;
        code1.push_back("apple");
        code1.push_back("Mango");
        codes.push_back(code1);
        vector<string> code2;
        code2.push_back("Anything");
        codes.push_back(code2);
        vector<string> code3;
        code3.push_back("Banana");
        codes.push_back(code3);
        for(int i=0;i<cart.size();i++){
            int start = i;
            bool comp = true;
            int j = 0, k = 0;
            while(j<codes.size()){
                if(start==cart.size()){
                        comp = false;
                        break;
                }
                else if(cart[start].compare(codes[j][k])==0 || codes[j][k]=="Anything"){
                    start++;
                    k++;
                    if(k==codes[j].size()){
                        j++;
                        k=0;
                    }
                }else{
                    break;
                }                
            }
            if(comp && start==cart.size())
                cout<<true<<endl;
        }
    }