#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'interQuartile' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY values
 *  2. INTEGER_ARRAY freqs
 */
 long double median(vector<int> a) {
    return a.size()  & 1?
        a[a.size()/2] :
        // tests force values to be integers
        (a[a.size()/2 - 1] + a[a.size()/2]) / static_cast<long double>(2);
}

template <typename T>
std::vector<T> slice_vector(std::vector<T> const &v, int start, int end) {
  auto first = v.cbegin() + start;
  auto last = v.cbegin() + end;

  std::vector<T> vec(first, last);
  return vec;
}

vector<long double> quartiles(vector<int> a) {
    sort (a.begin(), a.end());
    long double q1, q2, q3;

    q2 = median(a);

    q1 = median(
      slice_vector( a, 0, a.size()/2)
    );

    q3 = median(
      slice_vector(a, a.size()/2 + (a.size() & 1), a.size())
    );

    return vector<long double> {q1, q2, q3};
}


void interQuartile(vector<int> values, vector<int> freqs) {
    vector<int> ua = vector<int>();
    for (int i = 0; i < values.size(); i++){
        for (; freqs[i] > 0; freqs[i] --)
            ua.push_back(values[i]);
    }
    vector<long double> qs = quartiles(ua); 
    long double answer = qs[2] - qs[0];
    cout << fixed << setprecision(1) << answer << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string val_temp_temp;
    getline(cin, val_temp_temp);

    vector<string> val_temp = split(rtrim(val_temp_temp));

    vector<int> val(n);

    for (int i = 0; i < n; i++) {
        int val_item = stoi(val_temp[i]);

        val[i] = val_item;
    }

    string freq_temp_temp;
    getline(cin, freq_temp_temp);

    vector<string> freq_temp = split(rtrim(freq_temp_temp));

    vector<int> freq(n);

    for (int i = 0; i < n; i++) {
        int freq_item = stoi(freq_temp[i]);

        freq[i] = freq_item;
    }

    interQuartile(val, freq);

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

