directions = list()
lengths = list()
max_width = 0
max_height = 0
max_width_idx = -1
max_height_idx = -1

K = int(input())

for i in range(6):
    direction, length = map(int, input().split())
    directions.append(direction)
    lengths.append(length)
    if (direction == 1 or direction == 2) and max_width < length:
        max_width = length
        max_width_idx = i
    if (direction == 3 or direction == 4) and max_height < length:
        max_height = length
        max_height_idx = i

small_width = lengths[(max_width_idx + 3) % 6]
small_height = lengths[(max_height_idx + 3) % 6]

print(K * (max_width * max_height - small_width * small_height))