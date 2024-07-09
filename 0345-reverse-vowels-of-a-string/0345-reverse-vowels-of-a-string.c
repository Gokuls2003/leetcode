char *reverseVowels(char *s)
{
  char vowels[] = "aeiouAEIOU";

  int l = 0, r = strlen(s) - 1;
  while (l < r)
  {
    bool swapReady = true;
    if (strchr(vowels, s[l]) == NULL)
    {
      l++;
      swapReady = false;
    }
    if (strchr(vowels, s[r]) == NULL)
    {
      r--;
      swapReady = false;
    }

    if (!swapReady)
      continue;

    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;

    l++;
    r--;
  }

  return s;
}