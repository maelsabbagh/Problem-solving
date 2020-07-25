#include <bits/stdc++.h>

using namespace std;

const int MAX=1e3+5;
bool visi[MAX];
int ans=0;
// Complete the powerSum function below.
void powerSum(int X, int N, int l)
{
    // base case
    if (X == 0)
    {
        ans++;
        return;
    }
    if (X < 0)return;

    for (int i = l; i < 1000; i++)
    {
        if (pow(i, N) <= X && !visi[i])
        {
            X = X - pow(i, N);
            visi[i] = 1;
            powerSum(X, N,i);
            X = X + pow(i, N);
            visi[i] = 0;
        }
    }


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

     powerSum(X, N,1);
     int result =ans;

    fout << result << "\n";

    fout.close();

    return 0;
}
