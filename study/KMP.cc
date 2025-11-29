#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[]를 계산한다.
// pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatchNaive(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    
    // 단순한 문자열 검색 알고리즘을 구현한다
    for (int begin = 1; begin < m; ++begin) {
        for (int i = 0; i + begin < m; ++i) {
            if (N[begin + i] != N[i]) break;
            // i + 1번째 글자가 서로 대응되었다.
            pi[begin + i] = max(pi[begin + i], i + 1);
        }
    }
    return pi;
}

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;

    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else {
            if (matched == 0) {
                ++begin;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> ret;

    // pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
    vector<int> pi = getPartialMatch(N);

    // begin = matched = 0 에서부터 시작하자
    int begin = 0, matched = 0;
    while (begin <= n - m) {
        // 만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
        if (matched < m && H[begin + matched] == N[matched]) {
            ++matched;
            // 결과적으로 m글자가 모두 일치했다면 답에 추가한다
            if (matched == m) ret.push_back(begin);
        }
        else {
            // 예외 : matched가 0인 경우에는 다음 칸에서부터 계속 , 첫번째 글자부터 틀린 경우
            if (matched == 0) {
                ++begin;
            }
            else {
                begin += matched - pi[matched - 1];
                // begin을 옮겼다고 처음부터 다시 비교할 필요가 없다
                // 옮긴 후에도 pi[matched - 1]만큼은 항상 일치하기 때문이다
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}

vector<int> kmpSearch2(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> ret; // 패턴이 발견된 위치를 저장할 벡터
    vector<int> pi = getPartialMatch(N);

    // 현재 대응된 글자의 수
    int matched = 0;
    
    // 짚더미의 각 글자를 순회한다.
    for (int i=0; i<n; i++) {
        // matched번 글자와 짚더미의 해당 글자가 불일치할 경우,
        // 현재 대응된 글자의 수를 pi[matched-1]로 줄인다
        while (matched > 0 && H[i] != N[matched]) {
            matched = pi[matched - 1];
        }

        // 글자가 대응될 경우
        if (H[i] == N[matched]) {
            ++matched;
            if (matched == m) {
                ret.push_back(i - m + 1);
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

int main() {
    string H = "aabaa";
    string N = "aa";
    vector<int> ret;

    ret = kmpSearch2(H, N);
    
    cout << "개수 : " << ret.size() << '\n';
    for (int i=0; i<ret.size(); i++) {
        cout << ret[i] << " ";
    }
    return 0;
}