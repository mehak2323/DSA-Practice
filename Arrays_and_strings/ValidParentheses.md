### Valid Parentheses
[Problem Link](https://leetcode.com/problems/valid-parentheses/)

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.
 

Example 1:
```
Input: s = "()"
Output: true
```
Example 2:
```
Input: s = "()[]{}"
Output: true
```
Example 3:
```
Input: s = "(]"
Output: false
``` 

Constraints:
```
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
```

### Solution:

Java:
```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> brackets = new Stack<Character>();
        //To check what should be stack top when closing bracket received
        HashMap<Character,Character> map = new HashMap<>();
        map.put(')','(');
        map.put(']','[');
        map.put('}','{');

        for(int i=0; i<s.length(); i++) {
            //If opening bracket, push
            if(s.charAt(i)=='(' || s.charAt(i)=='[' || s.charAt(i)=='{'){
                brackets.push(s.charAt(i));
            }

            //If closing bracket, match with last and pop
            else {
                if(brackets.isEmpty())
                    return false;
                if(brackets.pop()!=map.get(s.charAt(i)))
                    return false;
            }
        }

        //True for most cases, except S = "["
        return brackets.isEmpty();
    }
}
```

Cpp, previous:
```cpp
class Solution {
public:
    
    //With stack
    bool isValid(string s) {
        
        int n=s.size();
        
        //If length is odd, ans is false
        if(n%2!=0)
            return false;
        
        bool ans = true;
        stack<char> seq;
        
        for(int i=0; i<n; i++){
            //If open bracket, add in list
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                seq.push(s[i]);
            }
            //If closed bracket
            else{
                //If no opened bracket or last opened is 
                //not same as current closing, ans is false
                if(seq.empty() || !((seq.top()=='(' && s[i]==')')||
                    (seq.top()=='[' && s[i]==']')|| (seq.top()=='{' && s[i]=='}')) ){
                    ans=false;
                    break;
                }
                //If last opened matches current closing bracket, remove one opened
                else{
                    seq.pop();
                }
            }
        }
        
        //If some opened brackets remain
        if(!seq.empty()){
            ans=false;
        }
        
        return ans;
    }
    
    /*
    //With vector
    bool isValid(string s) {
        
        int j = 0, n=s.size();
        
        //If length is odd, ans is false
        if(n%2!=0)
            return false;
        
        bool ans = true;
        vector<char> seq(n);
        
        for(int i=0; i<n; i++){
            //If open bracket, add in list
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                seq[j]=s[i];
                j++;
            }
            //If closed bracket
            else{
                //If no opened bracket, ans is false
                if(j==0){
                    ans=false;
                    break;
                }
                //If last opened matches current closing bracket, remove one opened
                else if( (seq[j-1]=='(' && s[i]==')')||(seq[j-1]=='[' && s[i]==']')||
                        (seq[j-1]=='{' && s[i]=='}') ){
                    j--;
                }
                //If last opened not same as current closing, ans false
                else{
                    ans=false;
                    break;
                }
            }
        }
        
        //If some opened brackets remain
        if(j>0){
            ans=false;
        }
        
        return ans;
    }
    */
    
    /*
    //Only for number of brackets not order
    bool isValid(string s) {
        int curved=0, squared=0, curly=0;
        bool ans = true;
        
        for(int i=0; i<s.size(); i++){
            switch(s[i]){
                case '(': curved++; break;
                case '[': squared++; break;
                case '{': curly++; break;
                case ')': curved--; break;
                case ']': squared--; break;
                case '}': curly--; break; 
            }
            if(curved<0 || squared<0 || curly<0){
                ans=false;
                break;
            }
        }
        if(curved>0 || squared>0 || curly>0){
            ans=false;
        }
        
        return ans;
    }*/
};
```

### Approach
Stacks: Add open brackets to stack while traversing, when closed bracket comes, check stack's top is the opening bracket of current closing bracket or not and pop.

- `Time complexity : O(n)` because we simply traverse the given string one character at a time and push and pop operations on a stack take O(1) time.
- `Space complexity : O(n)` as we push all opening brackets onto the stack and in the worst case, we will end up pushing all the brackets onto the stack. e.g. ((((((((((.
