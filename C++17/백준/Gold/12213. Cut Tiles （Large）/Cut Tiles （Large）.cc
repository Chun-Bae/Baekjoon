#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

struct Rect {
    ll x, y, w, h;
    Rect(ll x, ll y, ll w, ll h) : x(x), y(y), w(w), h(h) {}
};

bool placeTile(vector<Rect>& freeRects, ll tileSize) {
    for (size_t i = 0; i < freeRects.size(); ++i) {
        Rect rect = freeRects[i];
        if (tileSize <= rect.w && tileSize <= rect.h) {
            freeRects.erase(freeRects.begin() + i);

            if (rect.w > tileSize) freeRects.push_back(Rect(rect.x + tileSize, rect.y, rect.w - tileSize, tileSize));
            if (rect.h > tileSize) freeRects.push_back(Rect(rect.x, rect.y + tileSize, tileSize, rect.h - tileSize));
            if (rect.w > tileSize && rect.h > tileSize) freeRects.push_back(Rect(rect.x + tileSize, rect.y + tileSize, rect.w - tileSize, rect.h - tileSize));

            return true;
        }
    }
    return false;
}

int calculateTiles(int N, ll M, vec1& sizes) {
    vector<ll> tileSizes(N);
    for (int i = 0; i < N; ++i) {
        tileSizes[i] = 1LL << sizes[i];
    }

    sort(tileSizes.rbegin(), tileSizes.rend());

    int bigTileCount = 0;
    vector<vector<Rect>> bigTiles;

    for (ll tileSize : tileSizes) {
        bool placed = false;
        for (auto& freeRects : bigTiles) {
            if (placeTile(freeRects, tileSize)) {
                placed = true;
                break;
            }
        }
        if (!placed) {
            bigTileCount++;
            vector<Rect> freeRects;
            freeRects.push_back(Rect(0, 0, M, M));
            if (!placeTile(freeRects, tileSize)) return -1;
            bigTiles.push_back(freeRects);
        }
    }

    return bigTileCount;
}

int main() {
    init();
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        ll M;
        cin >> N >> M;
        vec1 sizes(N);
        for (int i = 0; i < N; ++i) cin >> sizes[i];

        int result = calculateTiles(N, M, sizes);
        cout << "Case #" << t << ": " << result << endl;
    }

    return 0;
}
