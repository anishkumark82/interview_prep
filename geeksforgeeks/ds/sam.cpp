int makingAnagrams(string s1, string s2){
    // Complete this function
    unordered_map<char, int> char_map1, char_map2;
    if(s1.empty())
    {
        return s2.size();
    }
    if(s2.empty())
    {
        return s1.size();
    }

    for(int i = 0; i < s1.size(); i++)
    {
        unordered_map<char, int>::iterator itr = char_map1.find(s1[i]);
        if(itr != char_map1.end())
        {
            // already present character
            char_map1[s1[i]] = itr->second+1;
        }
        else
        {
            char_map1[s1[i]] = 1;
        }
    }

    for(int i = 0; i < s2.size(); i++)
    {
        unordered_map<char, int>::iterator itr = char_map2.find(s2[i]);
        if(itr != char_map2.end())
        {
            // same characters for both s1 & s2 so subtract out
            char_map2[s2[i]] = itr->second+1;
        }
        else
        {
            char_map2[s2[i]] = 1;
        }
    }
    for(unordered_map<char, int>::iterator itr = char_map1.begin(); itr != char_map1.end(); itr++)
    {
        cout<<"str 1 : "<<itr->first<<" "<<itr->second<<endl;
    }
    for(unordered_map<char, int>::iterator itr = char_map2.begin(); itr != char_map2.end(); itr++)
    {
        cout<<"str 2 : "<<itr->first<<" "<<itr->second<<endl;
    }

    int count = 0;
    unordered_map<char, int>::iterator itr2 = char_map2.begin();
    for(unordered_map<char, int>::iterator itr1 = char_map1.begin(); itr1 != char_map1.end(); itr1++)
    {
        if(itr2 != char_map2.find(itr1->first))
        {
           cout<<"found dup in str2 : "<<itr1->first<<"str1 : "<<itr1->second<<" str2 : "<<itr2->second<<endl;
           char_map1[itr1->first] = abs(itr1->second - itr2->second);
           char_map2[itr1->first] = 0;
        }
        else
        {
            cout<<"No dups in str2 : "<<itr1->first<<endl;
        }
        count += char_map1[itr1->first];
        cout<<"str 1 After processing : "<<itr1->first<<" "<<itr1->second<<endl;
    }
    for(unordered_map<char, int>::iterator itr = char_map2.begin(); itr != char_map2.end(); itr++)
    {
        count += itr->second;
        cout<<"str 2 After processing : "<<itr->first<<" "<<itr->second<<endl;

    }

    return count;
}
