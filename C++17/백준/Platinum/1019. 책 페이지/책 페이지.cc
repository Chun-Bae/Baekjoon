#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
vec1 cnt(10, 0);

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

void countDigits(ll n) {
    // 1, 10, 100, ...
    ll factor = 1;

    while (n / factor != 0) {
        // n=3564, factor=1
        // higher=356, current=4, lower=0
        // n=3564, factor=10
        // higher=35, current=6, lower=4
        // n=3564, factor=100
        // higher=3, current=5, lower=64
        // n=3564, factor=1000
        // higher=0, current=3, lower=564

        // 현재 자릿 수보다 높은 자릿 수 (왼쪽)
        ll higher = n / (factor * 10);
        // 현재 자릿 수
        ll current = (n / factor) % 10;
        // 현재 자릿 수보다 낮은 자릿 수 (오른쪽)
        ll lower = n % factor;

        // 관찰 자리수를 0부터 9까지 증가시키면서 카운트
        for (int d = 0; d < 10; d++) {
            if (d != 0) {
                if (current > d) {
                    // n=3564, factor=10, d=1,2,3,4,5
                    // 0014~3514: (35+1)*10
                    // 0024~3524: (35+1)*10
                    // 0034~3534: (35+1)*10
                    // 0044~3544: (35+1)*10
                    // 0054~3554: (35+1)*10
                    // 10의 자리가 1,2,3,4,5인 경우에서
                    // 그 10의자리에 나오는 숫자의 개수를 세겠다는 의미임.
                    // 다른 factor검사에서 중복된 전체 숫자가 나올 순 있지만
                    // 자리수의 숫자를 세는 것이므로 중복은 상관없음.
                    cnt[d] += (higher + 1) * factor;
                } else if (current == d) {
                    // d=6, lower=4, higher=35, factor=10
                    // 0064~3564: 35*10+4+1
                    // 즉 0064~3464까지 35*10개의 숫자가 나오고
                    // 3560~3564까지 4+1개의 숫자가 나옴.
                    // 왜 3564가 안되냐면 그 이전에 3554같은 경우는 lower가
                    // 1의 자리 수인 경우 0,1,2,...,9까지 다 되는데
                    // 3564는 4까지만 되기 때문임.
                    cnt[d] += higher * factor + lower + 1;
                } else {
                    // n=3564, factor=10, d=7,8,9
                    // 0074~3474: 35*10
                    // 0084~3484: 35*10
                    // 0094~3494: 35*10
                    cnt[d] += higher * factor;
                }
            } else {
                if (higher == 0) {
                    // 첫 자릿수에서 0은 카운트하지 않음
                    continue;
                }
                if (current > 0) {
                    // d=0, higher=35, factor=10,current=6
                    // d=0이면 오른쪽 첫자리가 0으로 시작할 수 없음
                    // 0104~3504:

                    cnt[0] += higher * factor;
                } else if (current == 0) {
                    // n=3504 factor=10라고할 때
                    // 0104~3404: 34*10
                    // 3500,3501,3502,3503,3504: 5개
                    cnt[0] += (higher - 1) * factor + lower + 1;
                }
            }
        }

        factor *= 10;
    }
}
int main() {
    init();
    int N;
    cin >> N;
    countDigits(N);
    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << " ";
    }
    return 0;
}