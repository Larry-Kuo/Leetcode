class Solution {
public:
    string countOfAtoms(string formula) {
        vector<pair<string, int>> elements;
        map<string, int> merged;
        stack<int> paren;
        string ans = "";
        int cnt = 0; //count the elements encountered as idx
        for(auto it = formula.begin(); it!=formula.end(); it++){
            if(isupper(*it)){
                //elements encountered
                string e = "";
                string ec = "1";
                e.push_back(*it);
                if(islower(*next(it))){
                    //parse remaining elements name
                    it++;
                    e.push_back(*it);
                    if(isdigit(*next(it))){
                        //parse following element counts
                        ec.clear();
                        while(isdigit(*next(it))){
                            it++;
                            ec += *it;
                        }
                    }
                }
                else if(isdigit(*next(it))){
                    //parse following element counts from one character elements
                    ec.clear();
                    while(isdigit(*next(it))){
                        it++;
                        ec += *it;
                    }
                }
                elements.push_back({e, stoi(ec)});
                cnt++;
            }
            else{
                //parenthesis encountered
                if(*it=='('){
                    paren.push(cnt);
                }
                else{
                    string parenCnt = "1";
                    if(isdigit(*next(it))){
                        parenCnt.clear();
                        while(isdigit(*next(it))){
                        it++;
                        parenCnt += *it;
                        }
                    }
                    int parenIdx = paren.top();
                    paren.pop();
                    for(int i=parenIdx; i<cnt; ++i){
                        elements[i].second *= stoi(parenCnt);
                    }
                }
            }
        }

        for(auto &it: elements){
            if(merged.find(it.first) != merged.end()){
                merged[it.first] += it.second;
            }
            else{
                merged.insert({it.first, it.second});
            }
        }

        for(auto &it: merged){
            ans += it.first;
            if(it.second>1){
                ans += to_string(it.second);
            }
        }

        return ans;
    }
};