#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quartiles' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int median(vector<int> a) {
    cout << "printing vector:" << endl;
    for (auto x:  a){
        cout << x << " ";        
    }
    cout << endl;
    return a.size()  & 1?
        a[a.size()/2] :
        // tests force values to be integers
        (a[a.size()/2 - 1] + a[a.size()/2]) / 2;
}

template <typename T>
std::vector<T> slice_vector(std::vector<T> const &v, int start, int end) {
  auto first = v.cbegin() + start;
  auto last = v.cbegin() + end;

  std::vector<T> vec(first, last);
  return vec;
}

vector<int> quartiles(vector<int> a) {
    sort (a.begin(), a.end());
    int q1, q2, q3;
    q2 = median(a);    
    q1 = median(
      slice_vector( a, 0, a.size()/2)
    );
    q3 = median(
      slice_vector(a, a.size()/2 + (a.size() & 1), a.size())
    );

    
    
    return vector<int> {q1, q2, q3};
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
    }

    vector<int> res = quartiles(data);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

