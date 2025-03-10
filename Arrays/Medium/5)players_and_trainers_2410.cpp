Steps-:
1)Same as s and g -> sorting.  assign cookies.
Code-:
int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int i=0;
        int j=0;
        int n1=players.size();
        int n2=trainers.size();
        int count=0;
        while(i<n1 and j<n2)
        {
            if(players[i]<=trainers[j])
            {
                count++;
                i++;
                j++;
            }
            else
            j++;
        }
        return count;
}