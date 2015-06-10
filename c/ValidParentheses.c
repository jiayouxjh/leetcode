/*
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char* s);

int main(void) {
    /* char* test = "({[[]]}))[]{})[]"; */
    char* test = "{{";
    bool ret = isValid(test);
    printf("The string \"%s\" is %s\n", test, (ret ? "valid" : "invalid"));
    return 0;
}

bool isValid(char* s) {
    int len = strlen(s);
    if (len <= 0 || len % 2 == 1) {
        return 0;
    }
    char* temp = (char*)malloc(sizeof(char) * (len / 2));
    int idx = 0;
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            temp[idx++] = c;
        } else {
            char pre = temp[idx - 1];
            if (pre == '(' && c == ')') {
                idx--;
            } else if (pre == '[' && c == ']') {
                idx--;
            } else if (pre == '{' && c == '}') {
                idx--;
            } else {
                return 0;
            }
        }
    }
    return idx == 0;
}
