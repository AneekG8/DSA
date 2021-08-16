//check if a pattern exists in a text

#include<iostream>
using namespace std;

/*typedef string::iterator itr;

//check if pattern is matched
bool fullMatch(string pat,itr p,string txt,itr t)
{
    if(t==txt.end() && p!=pat.end())
        return false;

    if(p==pat.end())
        return true;

    if(*p==*t)
        return fullMatch(pat,p+1,txt,t+1);
    else
        return false;
}

bool contains(string pat,itr p,string txt,itr t)
{
    if(t==txt.end())
        return false;

    if(*p==*t)
    {
        if(fullMatch(pat,p,txt,t))
            return true;
        else
            return contains(pat,p,txt,t+1);
    }
    else
        return contains(pat,p,txt,t+1);
}

bool contains(string txt,string pat)
{
    return contains(pat,pat.begin(),txt,txt.begin());
}*/

// Recursive C++ program to find if a given pattern is
// present in a text
#include<iostream>
using namespace std;

bool exactMatch(char *text, char *pat)
{
	if (*text == '\0' && *pat != '\0')
		return false;

	// Else If last character of pattern reaches
	if (*pat == '\0')
		return true;

	if (*text == *pat)
		return exactMatch(text + 1, pat + 1);

	return false;
}

// This function returns true if 'text' contain 'pat'
bool contains(char *text, char *pat)
{
	// If last character of text reaches
	if (*text == '\0')
		return false;

	// If current characters of pat and text match
	if (*text == *pat)
		if(exactMatch(text, pat))
			return 1;
		else
		return contains(text + 1, pat);

	// If current characters of pat and tex don't match
	return contains(text + 1, pat);
}


int main()
{
    cout << contains("geeksforgeeks", "geeks") << endl;
    cout << contains("geeksforgeeks", "geeksquiz") << endl;
    cout << contains("geeksquizgeeks", "quiz") << endl;
    return 0;
}
