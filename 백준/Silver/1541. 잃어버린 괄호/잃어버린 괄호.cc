#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string cmd;
    cin >> cmd;

    vector<long long> nums;
    bool bNumEnd = true;        // 숫자가 끝났는지 여부
    bool afterMinus = false;    // 첫 '-' 이후인지 (괄호 구간)
    long long current = 0;      // 현재 숫자 누적
    long long sum = 0;          // 현재 그룹 합 (괄호 내부)
    long long result = 0;       // 최종 결과

    for (char c : cmd) {
        if (c == '+' || c == '-') {
            // 현재까지 만든 숫자를 더한다.
            sum += current;
            current = 0;

            // '-'가 처음 등장한 경우
            if (c == '-') {
                if (afterMinus) {
                    // 이미 - 이후였다면, 이전 그룹을 빼고 새 그룹 시작
                    result -= sum;
                } else {
                    // 첫 - 전까지의 그룹은 더하고
                    result += sum;
                    afterMinus = true;
                }
                sum = 0; // 새 그룹 초기화
            }

            bNumEnd = true;
        }
        else {
            // 숫자 누적
            current = current * 10 + (c - '0');
            bNumEnd = false;
        }
    }

    // 마지막 숫자 처리
    sum += current;

    if (afterMinus)
        result -= sum;
    else
        result += sum;

    cout << result << '\n';
}
