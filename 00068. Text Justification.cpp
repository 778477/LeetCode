
//	Accepted	0 ms	cpp
class Solution {
public:
    vector<vector<string> > typesetting(vector<string>& words, const int maxWidth){
        vector<vector<string> > ans;
        
        vector<string> buffers;
        long spaceCount = maxWidth;
        for(size_t i = 0;i < words.size();i++){
            long len  = (long)words[i].length();
            if(buffers.size() && len > spaceCount - (long)buffers.size()){
                ans.push_back(buffers);
                buffers.clear();
                spaceCount = maxWidth;
                --i;
            }
            else if (len > spaceCount && !buffers.size()){
                buffers.push_back(words[i].substr(0,maxWidth));
                spaceCount -= maxWidth;
                words[i] = words[i].substr(maxWidth,words[i].length());
                --i;
            }
            else{
                spaceCount = spaceCount - words[i].length();
                buffers.push_back(words[i]);
            }
        }
        
        if(buffers.size()) ans.push_back(buffers);
        
        return ans;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<vector<string> > typedVector = typesetting(words, maxWidth);
        
        for(size_t i=0;i<typedVector.size();i++){
            
            long charCount = 0;
            for_each(typedVector[i].begin(), typedVector[i].end(), [&](const string& str){
                charCount += str.length();
            });
            long surplus = maxWidth - charCount;
            string buffer = "";
//            buffer = "'";
            
            if(i != typedVector.size()-1){
                long cnt = 0,lst = 0;
                if(typedVector[i].size() > 1){
                    cnt = surplus / (typedVector[i].size() - 1);
                    lst = surplus % (typedVector[i].size() - 1);
                }
                else{
                    lst = 0;
                    cnt = maxWidth - (long)typedVector[i][0].length();
                }
                
                
                for(size_t j = 0;j<typedVector[i].size();j++){
                    buffer += typedVector[i][j];
                    if(surplus > 0){
                        for(int k = 0;k<cnt;k++){
                            buffer += " ",surplus--;
                        }
                        if(j < lst){
                            buffer += " ",surplus--;
                        }
                    }
                }
            }
            else{
                for(size_t j = 0,k=maxWidth;j<typedVector[i].size();j++){
                    buffer += typedVector[i][j];
                    k -= typedVector[i][j].length();
                    if(j != typedVector[i].size() - 1){
                        buffer += " ";
                        k--;
                    }
                    else{
                        while (k--) {
                            buffer += " ";
                        }
                    }
                }
            }
//            buffer+="'";
            ans.push_back(buffer);
        }
        return ans;
    }
};

