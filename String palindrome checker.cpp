bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++) 
    {
        if (S[i] != S[S.length() - i - 1]) 
            return false;
    }
    return true;
}