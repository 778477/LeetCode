
//Accepted	12 ms	cpp
class Solution {
public:
    string simplifyPath(string path) {
        while (!finder.empty()) {
            finder.pop();
        }
        
        string now = "";
        int len = (int)path.length();
        for(int i=0;i<len;i++){
            now += path[i];
            
            if(now.back() == '/'){
                
                string substr = now.substr(0,now.length() - 1 > 0 ? now.length() - 1 : 0);
                if(substr == ".."){
                    if(!finder.empty() && *finder.top() != "/") finder.pop();
                    now.clear();
                    continue;
                }
                else if(substr == "."){
                    now.clear();
                    continue;
                }
                else if(substr == ""){
                    if(!finder.empty()){
                        now.clear();
                        continue;
                    }
                }
                
                finder.push(new string(now));
                now.clear();
            }
        }
        
        if(now == ".."){
            if(!finder.empty()&& *finder.top() != "/") finder.pop();
            now.clear();
        }
        
        if(now == "."){
            now.clear();
        }
        
        while (!finder.empty()) {
            now.insert(0, *finder.top());
            finder.pop();
        }
        
        if(now.length() > 1 && now.back() == '/'){
            now.pop_back();
        }
        
        return now;
    }
    
private:
    stack<string *> finder;
};

