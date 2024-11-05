# include <string>
# include <iostream>
using namespace std;
string disemvowel(std::string str) {
    std::string vowels = "OEUIAeuoia";
    for (int i=0; i<(int)str.size(); i++){
      if (vowels.find(str[i]) != std::string::npos){
        str.erase(i, 1);
      }
    }
  cout << str.size();
  return str;
}

int main(){
  string str = "N ffns bt, Yur wrtng s mng th wrst 'v vr rad";
  cout << disemvowel(str) << endl;
}
