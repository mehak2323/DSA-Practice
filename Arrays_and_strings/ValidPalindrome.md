### Question
[Problem Link](https://leetcode.com/problems/valid-palindrome/)

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```
Example 2:
```
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```
Example 3:
```
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
``` 

Constraints:
```
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
```

### Solution
```java
class Solution {
    public boolean isPalindrome(String s) {

        //Two pointer loop i from start, j from end to check equal
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            //If not aplhabet, ignore till alphabet received, for both i and j
            while (i < j && !Character.isLetterOrDigit(s.charAt(i))) {
                i++;
            }
            while (i < j && !Character.isLetterOrDigit(s.charAt(j))) {
                j--;
            }

            //If aplhabet received both side, check if equal after making lowercase (if upper)
            if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j)))
                return false;
        }

        return true;
    }
}
```

```java
//Incorrect noob code:
    public boolean isPalindrome(String s) {

        //Converting to lowercase or replacing chars with space
        for(int i=0; i<s.length(); i++){
            if(! (s.charAt(i).isAlpha()) ){
                s.charAt(i) = ' ';
            }
            if(s.charAt(i).isUpper())
                s.charAt(i).toLowerCase();
        }

        //Compare ends are equal, ignore space
        for(int i=0,j=s.length()-1; i<=j; i++, j--){
            while(s.charAt(i)==' ') i++;
            while(s.charAt(i)==' ') j--;
            if(s.charAt(i)!=s.charAt(i)) return false;
        }

        return true;
    }

    //Errors: char cannot be dereferenced: if(!s.charAt(i).isAlpha()) / .isUpper()/ .toLowerCase()

    //So, one can say that accessing the state or behaviour of an object using its reference with the help of the . operator is dereferencing.
```

Other way in Editorial, to check methods in java, comapare with reverse:
```java
class Solution {
  public boolean isPalindrome(String s) {
    StringBuilder builder = new StringBuilder();

    for (char ch : s.toCharArray()) {
      if (Character.isLetterOrDigit(ch)) {
        builder.append(Character.toLowerCase(ch));
      }
    }

    String filteredString = builder.toString();
    String reversedString = builder.reverse().toString();

    return filteredString.equals(reversedString);
  }

  /** An alternate solution using Java 8 Streams */
  public boolean isPalindromeUsingStreams(String s) {
    StringBuilder builder = new StringBuilder();

    s.chars()
        .filter(c -> Character.isLetterOrDigit(c))
        .mapToObj(c -> Character.toLowerCase((char) c))
        .forEach(builder::append);

    return builder.toString().equals(builder.reverse().toString());
  }
}
```

### Approach

Pretty basic, two pointer to avoid extra space, compare iterators on both side, do i++ or j-- till you're getting other characters not alphabets.

`Time complexity : O(n)`, in length nnn of the string. We traverse over each character at-most once, until the two pointers meet in the middle, or when we break and return early.

`Space complexity : O(1)`. No extra space required, at all.
