bool isValid(char *s) {
    char stack[100000]; 
    int top = -1; 

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char parenthesis = s[i];
        if (parenthesis == '(' || parenthesis == '{' || parenthesis == '[') {
            stack[++top] = parenthesis;
        } else {
            if (top == -1) return false; // If stack is empty
            char topElement = stack[top--];
            if (parenthesis == ')' && topElement != '(') return false;
            if (parenthesis == '}' && topElement != '{') return false;
            if (parenthesis == ']' && topElement != '[') return false;
        }
    }

    return top == -1; // If stack is empty, return true
}