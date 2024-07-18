int countStudents(int* students, int n1, int* sandwiches, int n) {
    int t = n, c = 0, i = 0, j = 0;
    while (j < n && c != t) {
        if (students[i % n] != -1) {
            printf(" 1 ");
            if (students[i % n] == sandwiches[j]) {
                j++;
                students[i%n] = -1;
                c = 0, t--;
            }
            else if (students[i % n] != sandwiches[j]) {
                c++;
            }
        }
        i++;
    }
    return c;
}