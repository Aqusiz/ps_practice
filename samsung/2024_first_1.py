drdc = ((-1, 0), (0, 1), (1, 0), (0, -1), (0, 0))
R, C, K = map(int, input().split())
# 0: 빈칸, 1: 일반칸 2: 출구칸
tile = [[0 for _ in range(C + 1)] for _ in range(R + 1)]

def main():
  global tile
  
  answer = 0
  for k in range(1, K + 1):
    column, direction = map(int, input().split())
    row = -1

    while(True):
      if can_straight(row, column):
        row, column = go_straight(row, column, k)
      elif can_left(row, column):
        row, column, direction = go_left(row, column, direction, k)
      elif can_right(row, column):
        row, column, direction = go_right(row, column, direction, k)
      else:
        break

    if out_of_tile():
      tile = [[0 for _ in range(C + 1)] for _ in range(R + 1)]
      continue

    tile[row + drdc[direction][0]][column + drdc[direction][1]] = -k

    answer += get_score(row, column)

  print(answer)

def can_straight(row, column):
  if row == -1:
    return tile[1][column] == 0
  
  cond1 = row + 2 <= R
  return cond1 and tile[row + 1][column - 1] == 0 and tile[row + 2][column] == 0 and tile[row + 1][column + 1] == 0

def can_left(row, column):
  if row == -1:
    return column > 2 and tile[1][column - 1] == 0
  if row == 0:
    return column > 2 and tile[1][column - 2] == 0 and tile[1][column - 1] == 0 and tile[2][column - 1] == 0
  
  cond1 = row + 2 <= R and column > 2
  if not cond1:
    return False
  cond2 = tile[row - 1][column - 1] == 0 and tile[row][column - 2] == 0 and tile[row + 1][column - 1] == 0
  cond3 = tile[row + 1][column - 2] == 0 and tile[row + 2][column - 1] == 0
  return cond2 and cond3

def can_right(row, column):
  if row == -1:
    return column + 2 <= C and tile[1][column + 1] == 0
  if row == 0:
    return column + 2 <= C and tile[1][column + 1] == 0 and tile[1][column + 2] == 0 and tile[2][column + 1] == 0
  
  cond1 = row + 2 <= R and column + 2 <= C
  if not cond1:
    return False
  cond2 = tile[row - 1][column + 1] == 0 and tile[row][column + 2] == 0 and tile[row + 1][column + 1] == 0
  cond3 = tile[row + 1][column + 2] == 0 and tile[row + 2][column + 1] == 0
  return cond2 and cond3

def go_straight(row, column, k):
  new_row, new_column = row + 1, column
  remove_tile(row, column)
  set_tile(new_row, new_column, k)
  return new_row, new_column

def go_left(row, column, direction, k):
  new_row, new_column, new_direction = row + 1, column - 1, direction - 1
  remove_tile(row, column)
  set_tile(new_row, new_column, k)
  if new_direction < 0:
    new_direction = 3
  return new_row, new_column, new_direction

def go_right(row, column, direction, k):
  new_row, new_column, new_direction = row + 1, column + 1, (direction + 1) % 4
  remove_tile(row, column)
  set_tile(new_row, new_column, k)
  return new_row, new_column, new_direction

def remove_tile(row, column):
  for dr, dc in drdc:
    nr, nc = row + dr, column + dc
    if nr < 0 or nc < 0 or nr > R or nc > C:
      continue
    tile[nr][nc] = 0

def set_tile(row, column, k):  
  for dr, dc in drdc:
    nr, nc = row + dr, column + dc
    if nr < 0 or nc < 0 or nr > R or nc > C:
      continue
    tile[nr][nc] = k

def out_of_tile():
  for column in range(1, C + 1):
    if tile[0][column] != 0:
      return True
  
  return False

def get_score(row, column):
  q = []
  visited = [[False for _ in range(C + 1)] for _ in range(R + 1)]
  ret = 0

  q.append((row, column))
  while q:
    r, c = q.pop(0)
    if visited[r][c]:
      continue
    visited[r][c] = True
    ret = max(ret, r)

    for dr, dc in drdc:
      nr, nc = r + dr, c + dc
      if nr < 1 or nc < 1 or nr > R or nc > C or tile[nr][nc] == 0 or visited[nr][nc]:
        continue
      if tile[r][c] == tile[nr][nc] or tile[r][c] == -tile[nr][nc] or tile[r][c] < 0:
        q.append((nr, nc))

  return ret

main()