LIS (Longest Incresing Sequence) - 최장 증가 수열

LIS 개념을 이해하려면 dp(dynamic programming), binary search 에 대해 먼저 아셔야 합니다.

두 가지를 알고 있다면 구글에서 LIS 검색하시면 많은 자료들 찾으실 수 있습니다.

아래는 검색 된 자료들 중 하나 입니다.

https://shoark7.github.io/programming/algorithm/3-LIS-algorithms

아래는 제가(효성이가) lis의 길이를 구할 때 사용하는 c++코드입니다.
```c++
template<typename T>
int lis_length(const vector<T>& A) {
    auto helper = vector<T>{};

    for(auto a : A) {
        // if equal is allowed change lower_bound to upper_bound.
        auto p = lower_bound(helper.begin(), helper.end(), a) - helper.begin();
        if(p == helper.size()) ret.push_back(a);
        else helper[p] = a;
    }

    return helper.size();
}
```
