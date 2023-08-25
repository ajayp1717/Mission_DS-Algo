class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n=words.size();
        int i=0,j,linelength,numWords,numSpaces,spaceBetweenWords,extraSpaces;
        string line;
        while(i<n){
            linelength=words[i].size();
            j=i+1;
            while(j<n && linelength+words[j].size()+(j-i)<=maxWidth){
                linelength+=words[j].size();
                j++;
            }

            numWords=j-i;
            numSpaces=maxWidth-linelength;

            if(numWords==1 || j==n){
                line=words[i];
                for(int k=i+1;k<j;k++){
                    line+=' '+words[k];
                }
                line+=string(maxWidth-line.size(),' ');
            }
            else{
                spaceBetweenWords=numSpaces/(numWords-1);
                extraSpaces=numSpaces%(numWords-1);
                line=words[i];
                for(int k=i+1;k<j;k++){
                    line+=string(spaceBetweenWords,' ');
                    if(extraSpaces>0){
                        line+=' ';
                        extraSpaces--;
                    }
                    line+=words[k];
                }
            }
            ans.push_back(line);
            i=j;
        }
        return ans;
    }
};