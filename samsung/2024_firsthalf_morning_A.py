from collections import deque

drdc = ((1, 0), (-1, 0), (0, 1), (0, -1))

K, M = 0, 0
tile = []
wall = []

def main():
  K, M = map(int, input().split())
  for _ in range(5):
    line = list(map(int, input().split()))
    tile.append(line)
  wall.extend(list(map(int, input().split())))

  answers = []
  for k in range(K):
    max_score = 0
    max_removed_tiles = []
    # 가장 획득 점수가 큰 회전 기준점 찾기
    for d in (90, 180, 270):
      for c in range(1, 4):
        for r in range(1, 4):
          new_tile = rotate(r, c, d)
          removed_tile = get_tiles_be_removed(new_tile)
          score = get_score(removed_tile)
          if score > max_score:
            max_score = score
            max_removed_tiles = removed_tile
    # 어떤 경우에도 점수를 얻을 수 없다면 강제종료
    if max_score == 0:
      break
    # 연쇄 획득: 타일 채우고 -> 점수 얻고
    while(True):
      fill_tile(max_removed_tiles, wall)
      max_removed_tiles = get_tiles_be_removed(max_removed_tiles)
      score = get_score(max_removed_tiles)
      if score == 0:
        break
      max_score += score
    # 점수 합산
    answers.append(max_score)
    # 변경된 타일을 original에 반영
    for i in range(5):
      for j in range(5):
        tile[i][j] = max_removed_tiles[i][j]

  print(*answers, sep=" ")

def make_tile_copy():
  tile_copy = [[0 for _ in range(5)] for _ in range(5)]
  for i in range(5):
    for j in range(5):
      tile_copy[i][j] = tile[i][j]
  return tile_copy

def rotate(row, column, degree):
  new_tile = make_tile_copy()
  if degree == 90:
    for i in range(row - 1, row + 2):
      for j in range(column - 1, column + 2):
        new_tile[(row - column) + j][(row + column) - i] = tile[i][j]
  elif degree == 180:
    for i in range(row - 1, row + 2):
      for j in range(column - 1, column + 2):
        new_tile[2 * row - i][2 * column - j] = tile[i][j]
  elif degree == 270:
    for i in range(row - 1, row + 2):
      for j in range(column - 1, column + 2):
        new_tile[(row + column) - j][(column - row) + i] = tile[i][j]
  else:
    raise AssertionError
  return new_tile

def get_tiles_be_removed(t):
  visited = [[False for _ in range(5)] for _ in range(5)]

  for r in range(5):
    for c in range(5):
      if visited[r][c]:
        continue
      routes = bfs(r, c, visited, t)
      # 3칸 이상 같은 값들이 붙어 있는 블럭이 존재한다면, 구멍 뚫기
      if len(routes) >= 3:
        for row, column in routes:
          t[row][column] = 0

  return t

def bfs(r, c, visited, t):
  # bfs를 이용해 같은 값이 붙어 있는 블럭을 반환
  dq = deque()

  dq.append((r, c))
  routes = [(r, c)]
  visited[r][c] = True
  while dq:
    curr_r, curr_c = dq.popleft()
    for dr, dc in drdc:
      nr, nc = curr_r + dr, curr_c + dc
      if nr < 0 or nc < 0 or nr >= 5 or nc >= 5 or visited[nr][nc] or t[nr][nc] != t[r][c]:
        continue
      routes.append((nr, nc))
      visited[nr][nc] = True
      dq.append((nr, nc))

  return routes

def get_score(t):
  # 빈 칸 세기
  ret = 0
  for i in range(5):
    for j in range(5):
      if t[i][j] == 0:
        ret += 1
  return ret

def fill_tile(t, wall):
  # 빈 칸들 중 열이 작은 것부터, 행이 큰 것부터 채우기
  for j in range(5):
    for i in range(4, -1, -1):
      if t[i][j] == 0:
        t[i][j] = wall.pop(0)

if __name__ == '__main__':
  main()
