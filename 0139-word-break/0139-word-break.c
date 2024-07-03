bool wordBreak(
	const char * const str,
	const char * const * const words,
	const int wordsLen
){
	const int strLen = strlen(str);

	int wordLens[wordsLen];
	for (int i = 0; i < wordsLen; i += 1){
		wordLens[i] = strlen(words[i]);
	}

	bool dp[strLen + 1];
	memset( dp, 0, sizeof (bool) * strLen );
	dp[strLen] = true;

	for (int i = strLen - 1; i >= 0; i -= 1){
		const int iToEndLen = strLen - i;

		for (int j = 0; j < wordsLen; j += 1){
			if (
				iToEndLen >= wordLens[j] &&
				!memcmp(str + i, words[j], sizeof (char) * wordLens[j]) &&
				dp[ i + wordLens[j] ]
			){
				dp[i] = true;
				break;
			}
		}
	}

	return dp[0];
}