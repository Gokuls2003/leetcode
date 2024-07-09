#define IS_LOWER(X) ( (X) >= 'a' && (X) <= 'z' )
#define IS_UPPER(X) ( (X) >= 'A' && (X) <= 'Z' )

char * * letterCasePermutation(
	const char * const str,

	int * const pRetsLen
){
	const int strLen = strlen(str);

	int alphaIdxs[strLen];
	int alphaIdxsLen = 0;
	for (int i = 0; i < strLen; i += 1){
		if ( IS_LOWER(str[i]) || IS_UPPER(str[i]) ){
			alphaIdxs[alphaIdxsLen] = i;
			alphaIdxsLen += 1;
		}
	}

	char * * const rets = (char * *)malloc( sizeof (char *) * (1 << alphaIdxsLen) );
	*pRetsLen = 0;

	for (int permutation = (1 << alphaIdxsLen) - 1; permutation >= 0; permutation -= 1){
		char * const ret = (char *)malloc( sizeof (char) * (strLen + 1) );
		memcpy(ret, str, sizeof (char) * strLen);
		ret[strLen] = '\0';

		for (int i = 0; i < alphaIdxsLen; i += 1){
			if ( ( permutation & (1 << i) ) == 0 ){
				ret[ alphaIdxs[i] ] |= 0x20;
			}else {
				ret[ alphaIdxs[i] ] &= ~0x20;
			}
		}

		rets[*pRetsLen] = ret;
		*pRetsLen += 1;
	}

	return rets;
}