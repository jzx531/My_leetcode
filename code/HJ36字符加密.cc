#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    std::string orig;
    std::string plain;
    std::string dict;
    cin >> orig;
    cin >> plain;

    std::vector<int> existed(26);
    for (int i = 0; i<orig.length();i++)
    {
        char c = orig[i];
        int idx = static_cast<int>(c - 'a');
        if(!existed[idx]){
            dict.push_back(c);
            existed[idx] = 1;
        }
    }

    for(int i = 0;i < 26; i++)
    {
        if(!existed[i])
        {
            dict.push_back(static_cast<char>('a'+i));
            existed[i] = 1;
        }
    }

    std::string ans;
    for(int i = 0;i < plain.length();i++)
    {
        int idx = static_cast<int>(plain.at(i)-'a');
        ans.push_back(dict[idx]);
    }

    std::cout<<ans<<std::endl;
    return 0;

}
// 64 位输出请用 printf("%lld")