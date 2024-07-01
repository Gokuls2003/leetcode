bool isPalindrome(int x){
	char arr[100];
	int len = sprintf(arr, "%d", x);
	// Converting number to string stored and storing it in array.
	int lenBy2 = len / 2;

	for (int i = 0; i <= lenBy2; i++) {
		if (arr[i] != arr[len - 1 - i]) {
			return false;
		}
	} return true;
}