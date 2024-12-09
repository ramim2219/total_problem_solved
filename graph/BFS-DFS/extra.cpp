vector<string> arr = {"Alice", "Bob", "Charlie", "David"};
string target = "Charlie";
arr.erase(remove(arr.begin(), arr.end(), target), arr.end());
