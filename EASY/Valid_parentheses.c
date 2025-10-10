/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Example 1:
Input: s = "()"
Output: true
Example 2
Input: s = "()[]{}"
Output: true
Example 3
Input: s = "(]"
Output: false
Example 4:
Input: s = "([])"
Output: true
Example 5:
Input: s = "([)]"
Output: false
Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // Nếu là dấu ngoặc mở → đẩy vào stack
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } 
        // Nếu là dấu ngoặc đóng → kiểm tra với đỉnh stack
        else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) return false; // không có gì để đóng → sai

            char open = stack[top--]; // lấy ngoặc mở ra
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return false; // không khớp
            }
        } 
        // Nếu gặp ký tự lạ → sai
        else {
            return false;
        }
    }

    // Nếu stack rỗng → hợp lệ, ngược lại → sai
    return top == -1;
}
int main() {
    char s[10000];
    scanf("%s", s);
    getchar();
    printf("%d\n", isValid(s));
    return 0;   
}