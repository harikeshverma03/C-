#include<iostream>
#include <algorithm>
#include <iterator>
using namespace std;
int length(string s){
    int i;
    for (i = 0; s[i]!='\0';i++){}
    cout << "The Length of string is: " << i << endl;
    return i;
}
string lowercase(string s){
    string str = s;
    int i;
    for (i = 0; s[i]!='\0';i++){
        str[i] = str[i] + 32;
        //cout << str[i];
    }  
    return str;
}
string &uppercase(string &s){
    int i;
    for (i = 0; s[i]!='\0';i++){
        s[i] = s[i] - 32;
        //cout << str[i];
    }  
    return s;
}
string &togglecase(string &s){
    int i;
    for (i = 0; s[i]!='\0';i++){
        if(s[i] >=65 && s[i] <=90)
            s[i]+=32;
        else if(s[i] >=97 && s[i] <= 122)
            s[i] = s[i] - 32;
    }  
    return s;
}
int *vowelcons(string s){
    static int vcount[2];
    for(int i = 0; s[i]!= '\0'; i++){
        if(s[i] == 'a' ||s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' ||s[i] == 'A' ||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U')
            vcount[0]++;
        else if((s[i] >=65 && s[i] <=90) ||  (s[i] >=97 && s[i] <= 122))
            vcount[1]++;
    } 
    return vcount;
}
int word (string s){
    int count=0;
    for(int i = 1; s[i]!= '\0'; i++){
        if(s[i] == ' ' & s[i - 1] != ' ')
            count++;
    } 
    return ++count;
}
int valid(string s){
    int i;
    for (i = 0; s[i]!='\0';i++){
        if((s[i] >=65 && s[i] <=90)||(s[i] >=97 && s[i] <= 122)||(s[i] >=48 && s[i] <= 57))
            s[i]+=32;
        else 
            return 0;
    }  
    return 1;
}
void reverse(string &s){
    reverse(s.begin(), s.end());
}
void rev(string &s){
    int i,j;
    for(i = 0;s[i] !='\0'; i++){}
    for(j = i-1, i = 0; j > i; i++, j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
void compare(string a, string b){
    int i,j;
    for(i = 0, j = 0; a[i] !='\0'&& b[i] !='\0'; i++,j++){
        if(a[i] != b[i])
            break;
    }
    if (a[i] ==b[i]) cout << "Equal" << endl;
    else if (a[i] < b[i])  cout << "Smaller" << endl;
    else cout << "Greater" << endl;
}
void palindrome(string a){
    int i,j;
    for(i = 0; a[i] !='\0'; i++){}
    for(j = i-1, i = 0; j > i; i++, j--){
        if(a[i] != a[j]){
            cout << "not a plaindrome"<< endl;
            return;
        }
    }
    cout << "Palindrome" << endl;
}
int* finding(string s){
    static int h[26] = {0};
    for (int i = 0; s[i] != '\0'; i++){
        int temp = (int)s[i] - 97;
        h[temp]++;
    }
    for(int f = 0; f < 26; f++){
        cout << (char)(f+97) << " = " << h[f] << endl;
    }
    return h;
}
void duplicate(string s){
    long int x, h = 0;
    for (int i = 0; s[i] != '\0'; i++){
        x = 1;
        
        int temp = (int)(s[i] - 97);
        
        x = x << temp;
        if ((h&x) > 0)
            cout << s[i] << " is duplicate" << endl;
        else
            h = x | h; 
    }
}
bool anagram(string a, string b){
    int h[26] = {0};
    for (int i = 0; a[i] != '\0'; i++){
        int temp = (int)a[i] - 97;
        h[temp]++;
    }
    for (int i = 0; b[i] != '\0'; i++)
    {
        int temp = (int)b[i] - 97;
        h[temp]--;
    }
    for(int i = 0; i < 26; i++){
        if(h[i] != 0)
            return false;
    }
    return true;
    
}
void perm(string &s, int k){
    static int A[10] = {0};
    static char res[10];
    if(s[k] == '\0'){
        res[k] = '\0';
        cout << res << endl;
        return;
    }
    else{
        for (int i = 0; s[i] != '\0'; i++)
        {
            /* code */
            if (A[i] == 0){
                res[k] = s[i];
                A[i] = 1;
                perm(s, k+1);
                A[i] = 0;
            }
        }
        
    }
}
void swap(char *a, char*b){
            char *temp = a;
            a = b;
            b = temp;
}
void permswap(string &s, int l, int h){
    
    if(l == h)
        cout << s << endl;
    else{
        for(int i = l; i <= h; i++){
            swap(s[i],s[l]);
            permswap(s,l+1,h);
            swap(s[i],s[l]);
        }
    }
}
int main(){
    string str = "WELCOME";
    int i = length(str);
    str = lowercase(str);
    cout << str << endl;
    string s = uppercase(str);
    
    cout << s << endl;
    str = "HARikesh";
    s = togglecase(str);
    str = "hey how are you doing";
    int *j = vowelcons(str);
    cout << "the no of vowels are: " << j[0] <<" And consonants are: " << j[1] <<  endl;
    int k = word(str);
    cout << "The Number of words in: " << str << " are " << k << endl;
    cout << s << endl;
    str ="hari56";
    int l = valid(str);
    cout << l << endl;
    rev(str);
    cout << str <<endl;
    s = "madam";
    str = s;
    reverse(str);
    palindrome(s);
    str = "harikesh";
    int* h = finding(str);
    duplicate(str);
    s = str;
    reverse(str);
    bool t = anagram(str, s);
    cout << t << endl;
    cout << str <<endl;
    str = "ABC";
    perm(str, 0);
    permswap(str,0,length(str)-1);
    return 0;
};