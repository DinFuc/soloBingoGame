int sum(vector<int>a)
{
    int res = 0;
    for(int i: a) res += i;
    return res;
}
bool check(vector<vector<int>> arr)
{
    int p1 = 0, p2 = 0;
    for (int col = 0; col < 5; col++){
        if (sum(arr[col]) == 5) return 1;
        int pot = 0;
        for (int row = 0; row < 5; row++)
            pot += arr[row][col];
        if (pot == 5) return 1;
        p1 += arr[col][col];
        p2 += arr[col][5 - col - 1];
    }
    return p1 == 5 || p2 == 5;
}
string soloBingoGame(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B, std::vector<int> search)
{
    vector<vector<int>>arr1(5, vector<int>(5, 0)), arr2(5, vector<int>(5, 0));
    vector<int>a, b;
    for(vector<int>i:A)
        for(int j:i)
            a.push_back(j);
    a.push_back({});
    for(vector<int>i:B)
        for(int j:i)
            b.push_back(j);
    b.push_back({});
    for (int i: search){
        int ind1 = find(a.begin(), a.end(), i) - a.begin(), ind2 = find(b.begin(), b.end(), i) - b.begin();
        int r1 =  ind1 / 5, c1 = ind1 % 5, r2 =  ind2 / 5, c2 =ind2 % 5;
        arr1[r1][c1] = 1;
        arr2[r2][c2] = 1;
        bool k1 = check(arr1), k2 = check(arr2);
        if (k1 && k2) return "Good";
        if (k1) return "Long";
        if (k2) return "Phu";
    }
    return "Good";
}
