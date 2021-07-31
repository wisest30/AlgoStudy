enum Direction {
  kNone,
  kLeft,
  kRight
};

struct Entity {
  Entity() {}

  Entity(long long _score, int _pos, Direction _direction)
    : score(_score)
    , pos(_pos)
    , direction(_direction) {}

  long long score;
  int pos;
  Direction direction;

  friend bool operator<(const Entity& lhs, const Entity& rhs) {
    return lhs.score < rhs.score;
  }
};

class Solution {
public:
  long long maxPoints(vector<vector<int>>& points) {
    const int m = points.size();
    const int n = points[0].size();

    priority_queue<Entity> pq;
    for (int i = 0; i < n; ++i) {
      pq.push(Entity(points[0][i], i, kNone));
    }

    for (int row = 1; row < m; ++row) {
      vector<Entity> current(n);
      for (int i = 0; i < n; ++i) {
        current[i].score = points[row][i];
        current[i].pos = i;
        current[i].direction = kNone;
      }

      while(!pq.empty()) {
        Entity entity = pq.top();
        pq.pop();

        const int pos = entity.pos;
        if (entity.score + points[row][pos] <= current[pos].score) continue;

        current[pos].score = entity.score + points[row][pos];

        switch (entity.direction) {
          case kNone: {
            if (entity.pos > 0) {
              pq.push(Entity(entity.score - 1, pos - 1, kLeft));
            }
            if (entity.pos < n - 1) {
              pq.push(Entity(entity.score - 1, pos + 1, kRight));
            }
          }
          case kLeft: {
            if (entity.pos > 0) {
              pq.push(Entity(entity.score - 1, pos - 1, kLeft));
            }
          }
          case kRight: {
            if (entity.pos < n - 1) {
              pq.push(Entity(entity.score - 1, pos + 1, kRight));
            }
          }
          default: {
            break;
          }
        }
      }

      for (int i = 0; i < n; ++i) pq.push(current[i]);
    }

    return pq.top().score;
  }
};
